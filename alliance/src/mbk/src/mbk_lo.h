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

/* 
 * Purpose : mbk_lo.c header file for functions declarations
 * Date    : 18/12/91
 * Author  : Frederic Petrot <Frederic.Petrot@lip6.fr>
 * Modified by Czo <Olivier.Sirol@lip6.fr> 1997,98
 * $Id: mbk_lo.h,v 1.1 2002/03/08 13:51:05 fred Exp $
 */

#ifndef _MBK_LO_H_
#define _MBK_LO_H_

#ifndef __P
# if defined(__STDC__) ||  defined(__GNUC__)
#  define __P(x) x
# else
#  define __P(x) ()
# endif
#endif

  extern    locon_list * addlocon __P((lofig_list *ptfig, const char *name, losig_list *ptsig, char dir));
  extern    lofig_list * addlofig __P((const char *name));
  extern    loins_list * addloins __P((lofig_list *ptfig, const char *insname, lofig_list *ptnewfig, chain_list *sigchain));
  extern    lofig_list * addlomodel __P((lofig_list *model, const char *name));
  extern    losig_list * addlosig __P((lofig_list *ptfig, long index, chain_list *namechain, char type));
  extern    losig_list * AX_addlosig __P((lofig_list *ptfig, long index, chain_list *namechain, char type));
  extern    lotrs_list * addlotrs __P((lofig_list *ptfig, char type, long x, long y, long width, long length, long ps, long pd, long xs, long xd, losig_list *ptgrid, losig_list *ptsource, losig_list *ptdrain, losig_list *ptbulk, const char *name));
  extern            int  dellocon __P((lofig_list *ptfig, const char *name));
  extern            int  dellofig __P((const char *name));
  extern            int  delloins __P((lofig_list *ptfig, const char *insname));
  extern            int  dellosig __P((lofig_list *ptfig, long index));
  extern            int  dellotrs __P((lofig_list *ptfig, lotrs_list *pttrs));
  extern           void  freelomodel __P((lofig_list *ptmodel));
  extern    locon_list * getlocon __P((lofig_list *ptfig, const char *name));
  extern    lofig_list * getlofig __P((const char *figname, char mode));
  extern    loins_list * getloins __P((lofig_list *ptfig, const char *name));
  extern    lofig_list * getlomodel __P((lofig_list *ptmodel, const char *name));
  extern    losig_list * getlosig __P((lofig_list *ptfig, long index));
	extern    lotrs_list * getlotrs __P((lofig_list *ptfig, const char *name));
	extern           void  lofigchain __P((lofig_list *ptfig));
  extern           void  viewlo __P(());
  extern           void  viewlofig __P((lofig_list *ptfig));
  extern           void  viewlofigcon __P((locon_list *ptcon));
  extern           void  viewloins __P((loins_list *ptins));
  extern           void  viewloinscon __P((locon_list *ptcon));
  extern           void  viewlosig __P((losig_list *ptsig));
  extern           void  viewlotrs __P((lotrs_list *pttrs));
  

#endif
