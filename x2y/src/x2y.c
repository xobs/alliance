/*
 * This file is part of the Alliance CAD System
 * Copyright (C) Laboratoire LIP6 - D�partement ASIM
 * Universite Pierre et Marie Curie
 * 
 * Home page          : http://www-asim.lip6.fr/alliance/
 * E-mail             : mailto:alliance-users@asim.lip6.fr
 * 
 * This progam is  free software; you can redistribute it  and/or modify it
 * under the  terms of the GNU  General Public License as  published by the
 * Free Software Foundation;  either version 2 of the License,  or (at your
 * option) any later version.
 * 
 * Alliance VLSI  CAD System  is distributed  in the hope  that it  will be
 * useful, but WITHOUT  ANY WARRANTY; without even the  implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 * 
 * You should have received a copy  of the GNU General Public License along
 * with the GNU C Library; see the  file COPYING. If not, write to the Free
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ident "$Id: x2y.c,v 1.6 2012/05/14 14:20:41 alliance Exp $"
#include <stdio.h>
#include <string.h>
#include "mut.h"
#include "mlo.h"
#include "mlu.h"
#include "mph.h"
#include "mpu.h"

/*

al              ALLIANCE    netlist
ap              ALLIANCE    layout
cct             HILO        netlist
cp              VTI         layout
edi             EDIF        netlist or layout
fne             VTI         extracted netlist
hns             VTI         netlist
spi, sp, cir    SPICE       netlist
vlg             VERILOG     netlist
vst             VHDL        netlist

 */

void addloinscon(struct loins *ptfig,  const char *cname, losig_list *ptsig, char dir) {
   locon_list  *ptcon; 
   ptcon            = (locon_list *)mbkalloc(sizeof(locon_list));
   ptcon->NAME      = cname;
   ptcon->TYPE      = 'E';
   ptcon->SIG       = ptsig;
   ptcon->ROOT      = (void *)ptfig;
   ptcon->DIRECTION = dir;
   ptcon->USER      = NULL;
   ptcon->NEXT      = ptfig->LOCON;
   ptcon->PNODE     = NULL;
   ptfig->LOCON     = ptcon;
}

int main( argc, argv )

  int argc;
  char **argv;
{
  lofig_list *LogicalFigure;
  struct loins *ptfig;
  losig_list *sigvss, *sigvdd;
  phfig_list *PhysicalFigure;
  char       *InputName;
  char       *OutputName;
  char       *FigureName;
  char       *InputFormat;
  char       *OutputFormat;
  int         MbkIn;
  int         MbkOut;

  mbkenv();

  alliancebanner ("x2y", "1.4", "MBK Format Translator", "1990", ALLIANCE_VERSION);

  if ( argc != 5 && argc != 6 && argc != 7)
  {
    fprintf( stdout,
"Syntax: x2y in_format out_format in_file out_file [[fig_name] addpcon]\n"
"Where format is one of:\n"
"    al              ALLIANCE    netlist\n"
"    ap              ALLIANCE    layout\n"
"    cct             HILO        netlist\n"
"    cp              VTI         layout\n"
"    edi             EDIF        netlist or layout\n"
"    fne             VTI         extracted netlist\n"
"    hns             VTI         netlist\n"
"    spi, sp, cir    SPICE       netlist\n"
"    vlg             VERILOG     netlist\n"
"    vst             VHDL        netlist\n"
 );
    return( 1 );
  }

  InputFormat  = namealloc( argv[ 1 ] );
  OutputFormat = namealloc( argv[ 2 ] );
  InputName    = namealloc( argv[ 3 ] );
  OutputName   = namealloc( argv[ 4 ] );
  if(argc>=6)
	  FigureName   = namealloc( argv[ 5 ] );

  if ( ( !strcmp( InputFormat, "al"  ) ) ||
       ( !strcmp( InputFormat, "vst" ) ) ||
       ( !strcmp( InputFormat, "cct" ) ) ||
       ( !strcmp( InputFormat, "edi" ) ) ||
       ( !strcmp( InputFormat, "vlg" ) ) ||
       ( !strcmp( InputFormat, "spi" ) ) ||
       ( !strcmp( InputFormat, "sp"  ) ) ||
       ( !strcmp( InputFormat, "cir" ) ) ||
       ( !strcmp( InputFormat, "fne" ) ) ||
       ( !strcmp( InputFormat, "hns" ) ) )
  {
    MbkIn = 1; strcpy( IN_LO, InputFormat );
  }
  else
  if ( ( !strcmp( InputFormat, "ap" ) ) ||
       ( !strcmp( InputFormat, "cp" ) ) )
  {
    MbkIn = 2; strcpy( IN_PH, InputFormat );
  }
  else
  {
    fprintf( stderr, "Bad mbk input file format %s\n", InputFormat );
    return( 1 );
  }

  if ( ( !strcmp( OutputFormat, "al"  ) ) ||
       ( !strcmp( OutputFormat, "vst" ) ) ||
       ( !strcmp( OutputFormat, "cct" ) ) ||
       ( !strcmp( OutputFormat, "edi" ) ) ||
       ( !strcmp( OutputFormat, "vlg" ) ) ||
       ( !strcmp( OutputFormat, "spi" ) ) ||
       ( !strcmp( OutputFormat, "sp"  ) ) ||
       ( !strcmp( OutputFormat, "cir" ) ) ||
       ( !strcmp( OutputFormat, "fne" ) ) ||
       ( !strcmp( OutputFormat, "hns" ) ) )
  {
    MbkOut = 1; strcpy( OUT_LO, OutputFormat );
  }
  else
  if ( ( !strcmp( OutputFormat, "ap" ) ) ||
       ( !strcmp( OutputFormat, "cp" ) ) )
  {
    MbkOut = 2; strcpy( OUT_PH, OutputFormat );
  }
  else
  {
    fprintf( stderr, "Bad mbk output file format %s\n", InputFormat );
    return( 1 );
  }

  if ( MbkOut != MbkIn )
  {
    fprintf( stderr, "Incompatible mbk input/output file format !\n" );
    return( 1 );
  }

  fprintf( stdout, "\t--> Conversion of %s(%s) to %s(%s)\n", 
           InputName, InputFormat, OutputName, OutputFormat );

  if ( MbkIn  == 1 ) {
		     LogicalFigure  = getlofig( InputName, 'A' );
		     if(argc>=6)
			     LogicalFigure  = getlofig( FigureName, 'A' );
  }
  else               PhysicalFigure = getphfig( InputName, 'A' );
  if(argc == 7 && !strcmp(argv[6],"addpcon")) {
     struct locon  *LOCON; 
     sigvss=NULL;
     sigvdd=NULL;
     for (LOCON = LogicalFigure->LOCON; LOCON; LOCON = LOCON->NEXT) {
      if(!strcmp(LOCON->NAME,"vss")) sigvss=LOCON->SIG;
      if(!strcmp(LOCON->NAME,"vdd")) sigvdd=LOCON->SIG;
     }
     for (ptfig = LogicalFigure->LOINS; ptfig; ptfig = ptfig->NEXT) {
        for (LOCON=ptfig->LOCON; LOCON && strcmp(LOCON->NAME,"vss"); LOCON = LOCON->NEXT) ;
     if(!LOCON) {
        addloinscon( ptfig, namealloc( "vdd" ), sigvdd, 'X' );
        addloinscon( ptfig, namealloc( "vss" ), sigvss, 'X' );
     }
   }
  }

  if ( MbkOut == 1 ) 
  {
    LogicalFigure -> NAME = OutputName;
    savelofig( LogicalFigure  );
  }
  else
  { 
    PhysicalFigure -> NAME = OutputName;
    savephfig( PhysicalFigure );
  } 
  fprintf( stdout, "\t--> File format translation's done !\n" );

  return( 0 );
}
