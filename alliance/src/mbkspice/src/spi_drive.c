/* 
 * This file is part of the Alliance CAD System
 * Copyright (C) Laboratoire LIP6 - D�partement ASIM
 * Universite Pierre et Marie Curie
 * 
 * Home page          : http://www-asim.lip6.fr/alliance/
 * E-mail support     : mailto:alliance-support@asim.lip6.fr
 * 
 * This library is free software; you  can redistribute it and/or modify it
 * under the terms  of the GNU Library General Public  License as published
 * by the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * Alliance VLSI  CAD System  is distributed  in the hope  that it  will be
 * useful, but WITHOUT  ANY WARRANTY; without even the  implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 * 
 * You should have received a copy  of the GNU General Public License along
 * with the GNU C Library; see the  file COPYING. If not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */


/*******************************************************************************
*                                                                              *
*  Tool        : Spice parser / driver v 7.00                                  *
*  Author(s)   : Gregoire AVOT                                                 *
*  Updates     : August, 17th 1998                                             *
*                                                                              *
*******************************************************************************/

#define SPI_MAX_COL 80

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <varargs.h>
#include <time.h>
#include <ctype.h>
#include <mut.h>
#include <mlo.h>
#include <rcn.h>

#include "msl.h"
#include "spi_drive.h"
#include "spi_int.h"
#include "spi_msg.h"
#include "spi_global.h"

static char    *TNMOS,
               *TPMOS;
char           *SPI_NETNAME;
char            SPI_NAMEDNODES;

#define SPI_NONODES (-1l)
#define SPI_MAXSTATICNAME 16

char*           spinamednode( losig, node )
losig_list      *losig;
long            node;
{
  static char    names[SPI_MAXSTATICNAME][255];
  static int     curnames = 0;

  ptype_list    *ptptype;
  convindex	*cvx;

  curnames++;
  if( curnames == SPI_MAXSTATICNAME )
    curnames=0;
  
  if( SPI_NAMEDNODES == TRUE ) {
    if( node == SPI_NONODES ) {
      if( losig->NAMECHAIN )
        sprintf( names[curnames], "%s", (char*)(losig->NAMECHAIN->DATA) );
      else
        sprintf( names[curnames], "sig%ld", losig->INDEX );
    }
    else {
      if( losig->NAMECHAIN ) {
        sprintf( names[curnames], "%s%c%ld", (char*)(losig->NAMECHAIN->DATA),
                                             SEPAR,
                                             node
               );
      }
      else {
        sprintf( names[curnames], "sig%ld%c%ld", losig->INDEX,
                                                 SEPAR,
                                                 node
               );
      }
    } 
  }
  else {
    ptptype = getptype( losig->USER, SPI_DRIVER_PTYPE );
    cvx     = (convindex*)(ptptype->DATA);
    if( node == SPI_NONODES )
      sprintf( names[curnames], "%d", cvx->premier );
    else
      sprintf( names[curnames], "%ld", cvx->premier + node - 1 );
  }

  return( names[curnames] );
}

void		cherche_alim( ptfig, vdd, vss )
lofig_list	*ptfig;
char		**vdd;
char		**vss;
{
  locon_list	*scancon;
  losig_list	*signal;
  static char    stvss[255], stvdd[255];

  *vdd = 0;
  *vss = 0;

  for( scancon = ptfig->LOCON ;
       scancon && !(*vdd && *vss) ;
       scancon = scancon->NEXT
     )
  {
    if( isvdd( scancon->NAME ) )
    {
      signal  = scancon->SIG;
      if( scancon->PNODE )
        strcpy( stvdd, spinamednode( signal, scancon->PNODE->DATA ) );
      else
        strcpy( stvdd, spinamednode( signal, SPI_NONODES ) );
      
      *vdd = stvdd;
    }

    if( isvss( scancon->NAME ) )
    {
      signal  = scancon->SIG;
      if( scancon->PNODE )
        strcpy( stvss, spinamednode( signal, scancon->PNODE->DATA ) );
      else
        strcpy( stvss, spinamednode( signal, SPI_NONODES ) );
      
      *vss = stvss;
    }
  }
}

void            sortrcn( ptfig, df, vss )
lofig_list	*ptfig;
FILE		*df;
char            *vss;
{
  losig_list	*scanlosig;
  int		 nbr;
  convindex	*cvx;
  ptype_list	*ptptype;
  lowire_list	*scanlowire;
  int            nbctc;
  chain_list    *scanchain;
  chain_list    *headctc;
  loctc_list    *ptctc;

  nbctc = 0;
  
  for( scanlosig = ptfig->LOSIG ; scanlosig ; scanlosig = scanlosig->NEXT )
  {
    if( !scanlosig->PRCN )
      continue;
    
    ptptype = getptype( scanlosig->USER, SPI_DRIVER_PTYPE );
    cvx     = (convindex*)(ptptype->DATA);
   
    if( scanlosig->PRCN->PWIRE || scanlosig->PRCN->PCTC )
    {
      nbr = 1;


      for( scanlowire = scanlosig->PRCN->PWIRE ;
           scanlowire ;
           scanlowire = scanlowire->NEXT )
      {
        tooutput( df,
                  "R%d_%d %s %s %g\n",
                  scanlosig->INDEX,
                  nbr,
                  spinamednode( scanlosig, scanlowire->NODE1 ),
                  spinamednode( scanlosig, scanlowire->NODE2 ),
                  scanlowire->RESI < RESIMINI ? RESIMINI : scanlowire->RESI
                );

	/* HSpice ne supporte pas 1e-6P : Il ne prendra pas en compte le P, et
	 * on aura 1 micron au lieu de 1e-18. */

        if( scanlowire->CAPA / 2.0 >= CAPAMINI )
        {
          tooutput( df,
                    "C%d_%d1 %s %s %g\n",
                    scanlosig->INDEX,
                    nbr,
                    spinamednode( scanlosig, scanlowire->NODE1 ),
                    vss,
                    scanlowire->CAPA / 2.0 * 1e-12
                  );

          tooutput( df,
                    "C%d_%d2 %s %s %g\n",
                    scanlosig->INDEX,
                    nbr,
                    spinamednode( scanlosig, scanlowire->NODE2 ),
                    vss,
                    scanlowire->CAPA / 2.0 * 1e-12
                  );
        }

        nbr++;
      }
    }
    
    /* On ne sort la capa totale que si on a ni RCN, ni CTC */

    if( !scanlosig->PRCN->PWIRE && !scanlosig->PRCN->PCTC )
    {
      if( scanlosig->PRCN->CAPA >= CAPAMINI )
      {
        tooutput( df,
                  "C%d %s %s %g\n",
                  scanlosig->INDEX,
                  spinamednode( scanlosig, SPI_NONODES ),
                  vss,
                  scanlosig->PRCN->CAPA * 1e-12
                );
      }
    }
  }

  headctc = getallctc( ptfig );

  for( scanchain = headctc ; scanchain ; scanchain = scanchain->NEXT )
  {
    ptctc = (loctc_list*)scanchain->DATA ;

    if( ptctc->CAPA >= CAPAMINI )
    {
      tooutput( df,
                "C_ctc_%d %s %s %g\n",
                nbctc,
                spinamednode( ptctc->SIG1, ptctc->NODE1 > 0 ? ptctc->NODE1 :
                                                              SPI_NONODES    ),
                spinamednode( ptctc->SIG2, ptctc->NODE2 > 0 ? ptctc->NODE2 :
                                                              SPI_NONODES    ),
                ptctc->CAPA * 1e-12
              );
    }

    nbctc++;
  }

  freechain( headctc );
}

void		signalnoeud( ptfig )
lofig_list	*ptfig;
{
  losig_list	*scanlosig;
  convindex	*nouveau;
  int		 dernier;

  dernier = 1;

  for( scanlosig = ptfig -> LOSIG ; scanlosig ; scanlosig = scanlosig->NEXT )
  {
    nouveau          = ( convindex* ) mbkalloc( sizeof( convindex ) );
    nouveau->sig     = scanlosig;
    nouveau->premier = dernier;

    if( scanlosig->PRCN && scanlosig->PRCN->NBNODE > 0 )
      dernier += scanlosig->PRCN->NBNODE ;
    else
      dernier++; 

    scanlosig->USER = addptype( scanlosig->USER, SPI_DRIVER_PTYPE, nouveau );
  }
}

int		sortconnecteur( df, c, position )
FILE		*df;
locon_list	*c;
int             position;
{
  losig_list	*signal;
  ptype_list	*pt;
  convindex	*noeudbase;
  num_list	*tetenum,*scannum;
  char           v[1024];
  int            lgmot;

  signal    = c->SIG;
  pt        = getptype( signal->USER, SPI_DRIVER_PTYPE );
  noeudbase = (convindex*)(pt->DATA);

  if( c->PNODE )
  {
    tetenum = c->PNODE;
    for( scannum = tetenum ; scannum ; scannum = scannum->NEXT )
    {
      sprintf( v,"%s ", spinamednode( signal, scannum->DATA) );
      lgmot = strlen(v);
      if( lgmot + position >= SPI_MAX_COL - 2 )
      {
        tooutput( df, "\n+ " );
        position = lgmot+2;
      }
      else
        position = position + lgmot;

      tooutput( df, v );
    }
  }
  else
  {
    lgmot = strlen(v);
    if( lgmot + position >= SPI_MAX_COL - 2 )
    {
      tooutput( df, "\n+ " );
      position = lgmot+2;
    }
    else
      position = position + lgmot;
    sprintf( v, "%s ", spinamednode( signal, SPI_NONODES ) );
    tooutput( df, v );
  }

  return( position );
}

int             sortconnecteur_ordre( df, ordre, liste, position )
FILE            *df;
chain_list      *ordre;
locon_list      *liste;
int              position;
{
  chain_list    *scanordre;
  locon_list    *scanlocon;
  int            num;
  int            n;
  chain_list    *cpteordre;
  losig_list    *signal;
  ptype_list    *pt;
  convindex     *noeudbase;
  num_list      *scannum;
  num_list      *tetenum;
  char           v[1024];
  int            lgmot;
  
  for( scanordre = ordre ; scanordre ; scanordre = scanordre->NEXT )
  {
    for( scanlocon = liste ; scanlocon ; scanlocon = scanlocon->NEXT )
      if( scanlocon->NAME == ((char*)(scanordre->DATA)) )
        break;

    if( !scanlocon )
    {
      fflush( stdout );
      fprintf( stderr, "%s.\n", SPIMSG(5) );
      EXIT(1); 
    }

    num = 0;
    for( cpteordre = ordre ;
         cpteordre != scanordre ;
         cpteordre = cpteordre->NEXT 
       )
      if( ((char*)(cpteordre->DATA)) == scanlocon->NAME )
        num++;

    signal    = scanlocon->SIG;
    pt        = getptype( signal->USER, SPI_DRIVER_PTYPE );
    noeudbase = (convindex*)(pt->DATA);

    if( scanlocon->PNODE )
    {
      tetenum = scanlocon->PNODE;
      for( scannum = tetenum, n=0 ; n<num ; scannum = scannum->NEXT, n++ );
      sprintf( v, "%s ", spinamednode( signal, scannum->DATA ) );
    }
    else
      sprintf( v, "%s ", spinamednode( signal, SPI_NONODES ) );

    lgmot = strlen(v);
    if( lgmot + position >= SPI_MAX_COL )
    {
      tooutput( df, "\n+ " );
      position = lgmot + 2;
    }
    else
      position = position + lgmot;

    tooutput( df, v );
  }

  return( position );
}

void		sortnet( ptfig, df )
lofig_list	*ptfig;
FILE		*df;
{
  losig_list	*scanlosig;
  locon_list	*scanlocon;
  chain_list	*scanchain;
  ptype_list	*ptl;
  convindex	*conv;
  num_list	*scannum;
  loctc_list	*ptctc;
  int		 i;

  for( scanlosig = ptfig->LOSIG ; scanlosig ; scanlosig = scanlosig->NEXT )
  {
    ptl  = getptype(scanlosig->USER,SPI_DRIVER_PTYPE);
    conv = (convindex*)(ptl->DATA);
    if( scanlosig->TYPE == EXTERNAL )
    {

      if( scanlosig->TYPE == EXTERNAL )
      {
        ptl = getptype( scanlosig->USER, LOFIGCHAIN );
        
        if( !ptl )
        {
          fflush( stdout );
          fprintf( stderr, "*** spi error *** : LOFIGCHAIN missing.\n" );
          EXIT(1); 
        }

        for( scanchain = (chain_list*)(ptl->DATA) ; 
             scanchain ;
             scanchain = scanchain->NEXT
           )
        {
          scanlocon = (locon_list*)scanchain->DATA ;
          if( scanlocon->ROOT == ptfig )
          {
            if( scanlocon->PNODE )
            {
              for( scannum = scanlocon->PNODE ;
                   scannum ;
                   scannum = scannum->NEXT
                 )
              {
                spi_vect( scanlocon->NAME );
                tooutput( df, 
                          "* %s %d = %s\n", 
                          SPI_NETNAME, 
                          scannum->DATA + conv->premier - 1 ,
                          scanlocon->NAME
                        );
              }
            }
            else
            {
              spi_vect( scanlocon->NAME );
              tooutput( df,
                        "* %s %d = %s\n", 
                        SPI_NETNAME, 
                        conv->premier,
                        scanlocon->NAME
                      );
            }
          }
        }
      }
    }
    else
    if( scanlosig->NAMECHAIN )
    {
      i = 0 ;
      if( scanlosig->PRCN )
      {
        if( scanlosig->PRCN->PWIRE )
          i = scanlosig->PRCN->PWIRE->NODE1 ;
        else
        if( scanlosig->PRCN->PCTC )
        {
          ptctc = (loctc_list*)scanlosig->PRCN->PCTC->DATA;
          if( ptctc->SIG1 == scanlosig )
            i = ptctc->NODE1;
          else
            i = ptctc->NODE2;
        }

        if( i != 0 )
          i = i + conv->premier - 1 ;
      }

      if( i == 0 );
        i = conv->premier ;

      spi_vect( (char*)scanlosig->NAMECHAIN->DATA );
      tooutput( df,
                "* %s %d = %s\n",
                SPI_NETNAME,
                i,
                (char*)scanlosig->NAMECHAIN->DATA
              ) ;
    }
  }
}

void		sortinstance( ptfig, df )
lofig_list	*ptfig;
FILE		*df;
{
  loins_list	*scanloins;
  locon_list	*scanloconins;
  ptype_list    *pt;
  char           v[1024];
  int            lgmot;
  int            colonne;

  for( scanloins = ptfig->LOINS ; scanloins ; scanloins = scanloins->NEXT )
  {
    sprintf( v, "x%s ", scanloins->INSNAME );
    colonne = strlen( v );
    tooutput( df, v );
    
    /* L'ordre des connecteurs entre la lofig et sa version instanci�e n'est 
       pas le meme */

    pt = getptype( scanloins->USER, PH_INTERF );    
    if( pt )
      colonne = sortconnecteur_ordre( df,
                                      (chain_list*)(pt->DATA),
                                      scanloins->LOCON,
                                      colonne
                                    );
    else
      for( scanloconins = scanloins->LOCON ;
           scanloconins ;
           scanloconins = scanloconins->NEXT
         )
        colonne = sortconnecteur( df, scanloconins, colonne );
   
    sprintf( v, "%s\n", scanloins->FIGNAME );
    lgmot = strlen(v);
    if( lgmot+colonne >= SPI_MAX_COL -2 )
      tooutput( df, "\n+" );
    tooutput( df, v );
  }
}

void            sorttransistormos( ptfig, df, vss, vdd )
lofig_list      *ptfig;
FILE            *df;
char            *vss;
char            *vdd;
{
  lotrs_list	*scantrs;
  int		 nb;
  ht            *trname;
  char           name[1024], *ptr ;

  for( scantrs = ptfig->LOTRS, nb=1 ; scantrs ; scantrs = scantrs->NEXT, nb++ );

  trname = addht(nb);

  nb = 0;

  for( scantrs = ptfig->LOTRS; scantrs; scantrs = scantrs->NEXT )
  {
    if( scantrs->TRNAME )
    {
      if( gethtitem( trname, scantrs->TRNAME ) != EMPTYHT )
      {
        do
        {
          nb++;
          sprintf( name, "%s_%d", scantrs->TRNAME, nb );
          ptr = namealloc( name );
        }
        while( gethtitem( trname, ptr ) != EMPTYHT );
        addhtitem( trname, ptr, 1 );
        tooutput( df, "M%s ", name );    
      }
      else
      {
        tooutput( df, "M%s ", scantrs->TRNAME );
        addhtitem( trname, scantrs->TRNAME, 1 );
      }
    }
    else
    {
      do
      {
        nb++;
        sprintf( name, "%d", nb );
        ptr = namealloc( name );
      }
      while( gethtitem( trname, ptr ) != EMPTYHT );
      tooutput( df, "M%s ", name );
      addhtitem( trname, ptr, 1 );
    }

    sortconnecteur( df, scantrs->DRAIN,1  );
    sortconnecteur( df, scantrs->GRID,1   );
    sortconnecteur( df, scantrs->SOURCE,1 );
    if( scantrs->BULK->SIG )
    {
      sortconnecteur( df, scantrs->BULK,1  );
    }
    else
    {
      if( IsTransN(scantrs->TYPE) )
      {
        if( !vss )
        {
          fflush( stdout );
          fprintf( stderr,
                   "*** spi error *** : Can't find signal VSS on figure %s.\n",
                   ptfig->NAME
                 );
          EXIT(1);
        }

        tooutput( df, "%s ", vss );
      }
      else
      {
        if( !vdd )
        {
          fflush( stdout );
          fprintf( stderr,
                   "*** spi error *** : Can't find signal VDD on figure %s.\n",
                   ptfig->NAME
                 );
          EXIT(1);
        }

        tooutput( df, "%s ", vdd );
      }
    }

    tooutput( df, "%s ", spitransmodel( scantrs->TYPE ) );

    if(scantrs->LENGTH!=0)
      tooutput( df, "L=%gU ", (float)scantrs->LENGTH/SCALE_X );

    if(scantrs->WIDTH!=0)
      tooutput( df, "W=%gU ", (float)scantrs->WIDTH/SCALE_X );
    
    if( scantrs->XS != 0 )
      tooutput( df,
                "AS=%gP ",
                (float) scantrs->XS * scantrs->WIDTH / ( SCALE_X * SCALE_X )
              );

    if( scantrs->XD != 0 )
      tooutput( df,
                "AD=%gP ",
                (float) scantrs->XD * scantrs->WIDTH / ( SCALE_X * SCALE_X )
              );

    if( scantrs->PS != 0 )
      tooutput( df, "PS=%gU ", (float)scantrs->PS/SCALE_X );
 
    if( scantrs->PD != 0 )
      tooutput( df, "PD=%gU ", (float)scantrs->PD/SCALE_X );

    tooutput( df, "\n" );
  }

  delht( trname );
}

void		sortcircuit( ptfig, df )
lofig_list	*ptfig;
FILE		*df;
{
  char          *vdd, *vss;
  locon_list	*scancon;
  ptype_list    *pt;
  int            colonne;
  char           v[1024];

  cherche_alim( ptfig, &vdd, &vss );

  /* Sortie des instances et des transistors */

  sprintf( v, "\n.subckt %s ", ptfig->NAME );
  colonne = strlen( v );
  
  tooutput( df, v );

  pt = getptype( ptfig->USER, PH_INTERF );
  if( pt )
    colonne = sortconnecteur_ordre( df,
                                    (chain_list*)(pt->DATA),
                                    ptfig->LOCON,
                                    colonne
                                  );
  else
    for( scancon = ptfig->LOCON ; scancon ; scancon = scancon->NEXT )
      colonne = sortconnecteur( df, scancon, colonne );

  tooutput( df,"\n" );

  if( SPI_NAMEDNODES == FALSE ) {
    sortnet( ptfig, df );
  }

  sortinstance( ptfig, df );
  sorttransistormos( ptfig, df, vss, vdd);
  sortrcn( ptfig, df, vss );

  tooutput( df, ".ends %s\n\n", ptfig->NAME );
}

void		spicesavelofig( ptfig )
lofig_list	*ptfig;
{
  FILE		*df;		/* descripteur de fichier de sortie */
  chain_list    *scanchain;
  locon_list    *scancon;
  num_list      *scannum;
  char		 v[1024];
  ptype_list    *pt;
  char          *nom;
  time_t         secondes;
  struct tm     *jours;
  char          *env;
  int            colonne;
  int            lgmot;

  env = mbkgetenv( "MBK_SPI_TN" );

  if(env)
    TNMOS = env;
  else
    TNMOS    = "TN";

  env = mbkgetenv( "MBK_SPI_TP" );

  if(env)
    TPMOS = env;
  else
    TPMOS    = "TP";
 
  env = mbkgetenv( "MBK_SPI_NETNAME" );

  if( env )
    SPI_NETNAME = env;
  else
    SPI_NETNAME = "NET";

  env = mbkgetenv( "MBK_SPI_NAMEDNODES" );

  if( env )
    SPI_NAMEDNODES = TRUE ;
  else
    SPI_NAMEDNODES = FALSE ;

  spi_init_lang();

  /* Ouverture du fichier de sortie */
  df = mbkfopen( ptfig->NAME, OUT_LO, WRITE_TEXT );
  if( !df )
  {
    fflush( stdout );
    fprintf( stderr, "*** mbk error : savelofig impossible.\n" );
    fprintf( stderr,
             "Can't open file %s.%s for writing.\n",
             ptfig->NAME,
             OUT_LO
           );
    EXIT(1);
  }
  

  time( &secondes );
  jours = localtime( &secondes );

  tooutput( df, "* Spice description of %s\n", ptfig->NAME );
  tooutput( df, "* Spice driver version %d\n",VERSION );
  tooutput( df,
           "* Date ( dd/mm/yyyy hh:mm:ss ): %2d/%02d/%04d at %2d:%02d:%02d\n\n",
            jours->tm_mday,
            jours->tm_mon+1,
            jours->tm_year+1900,
            jours->tm_hour,
            jours->tm_min,
            jours->tm_sec
          );

  /* On va travailler sur les fonctions RCN : */
  lofigchain( ptfig );
  
  signalnoeud( ptfig );		/* Calcule les noeuds Spice */

  /* Sort la ligne *interf */

  colonne = strlen( "* INTERF " );
  tooutput( df, "* INTERF " );
 
  pt = getptype( ptfig->USER, PH_INTERF );
  if( pt )
  {
    for( scanchain = (chain_list*)(pt->DATA) ;
         scanchain ;
         scanchain = scanchain->NEXT
       )
    {
      nom = ((char*)(scanchain->DATA));
      strcpy( v, nom );
      spi_vect( v );

      lgmot = strlen(v)+1;
      if( colonne+lgmot >= SPI_MAX_COL-2 )
      {
        colonne = strlen( "* INTERF " );
        tooutput( df, "\n* INTERF " );
      }
      colonne = colonne + lgmot;

      tooutput( df, "%s ", v );

    }
  }
  else
  {
    for( scancon = ptfig->LOCON ; scancon ; scancon = scancon->NEXT )
    {
      if( scancon->PNODE )
      {
        for( scannum = scancon->PNODE ; scannum ; scannum = scannum->NEXT )
        {
          strcpy( v, scancon->NAME );
          spi_vect( v );

          lgmot = strlen(v)+1;
          if( colonne+lgmot >= SPI_MAX_COL-2 )
          {
            colonne = strlen( "* INTERF " );
            tooutput( df, "\n* INTERF " );
          }
          colonne = colonne + lgmot;

          tooutput( df, "%s ", v );

        }
      }
      else
      {
        strcpy( v, scancon->NAME );
        spi_vect( v );
        
        lgmot = strlen(v)+1;
        if( colonne+lgmot >= SPI_MAX_COL-2 )
        {
          colonne = strlen( "* INTERF " );
          tooutput( df, "\n* INTERF " );
        }
        colonne = colonne + lgmot;

        tooutput( df, "%s ", v );
      }
    }
  }

  tooutput( df, "\n\n" );

  /* Sort les .include */
  
  for( scanchain = ptfig->MODELCHAIN; scanchain; scanchain = scanchain->NEXT )
  {
    tooutput( df, ".INCLUDE %s.%s\n", (char*)scanchain->DATA, OUT_LO ); 
  }

  sortcircuit( ptfig, df );

  if( fclose(df) == -1 )
  {
    fflush( stdout );
    fprintf( stderr,
             "*** mbk error *** : Can't close file %s.\n,",
             ptfig->NAME
           );
    EXIT(1);
  }
}

void            tooutput( va_alist )
va_dcl
{
  va_list       index;
  FILE          *fd;
  char          *fmt;

  va_start( index );
  
  fd  = va_arg( index, FILE* );
  fmt = va_arg( index, char* );

  if( vfprintf( fd, fmt, index ) < 0 )
  {
    fflush( stdout );
    fprintf( stderr, "*** spi error *** : Error while writing file.\n" );
    perror( "System say " );
    EXIT( 1 );
  }
}

void spi_vect( s )
char *s;
{
  int i,p1;

  if( s == NULL )
    return;
  if( s[0] == '\0' )
    return;

 
  /* Positionne i sur le premier caractere non espace a la fin de la chaine */
  i = strlen( s ) ;
  do
    i--;
  while( s[i] == ' ' && i >0 );

  /* passe un eventuel paquet de nombres */
  if( i )
  {
    p1 = i;
    while( isdigit( (int)s[i] ) && i >0 )
      i--;
    if( p1 != i && s[i] == ' ' )
    {
      s[i]    = '[';
      s[p1+1] = ']';
      s[p1+2] = '\0' ;
    }
  }
}