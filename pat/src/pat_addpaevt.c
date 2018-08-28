/* 
 * This file is part of the Alliance CAD System
 * Copyright (C) Laboratoire LIP6 - D�partement ASIM
 * Universite Pierre et Marie Curie
 * 
 * Home page          : http://www-asim.lip6.fr/alliance/
 * E-mail             : mailto:alliance-users@asim.lip6.fr
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
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */


/* ###--------------------------------------------------------------### */
/* file		: pat_addpaevt.c					*/
/* date		: Jul 23 1993						*/
/* version	: v104							*/
/* authors	: Pirouz BAZARGAN SABET					*/
/* content	: low-level pat function				*/
/* ###--------------------------------------------------------------### */

#include "mut.h"
#include "pat.h"

/* ###--------------------------------------------------------------### */
/* function	: pat_addpaevt						*/
/* description	: create a PAEVT (input-output event) structure at the	*/
/*		  top of a list						*/
/* called func.	: mbkalloc						*/
/* ###--------------------------------------------------------------### */

struct paevt *pat_addpaevt (lastpaevt, index, usrval)

struct paevt   *lastpaevt;	/* pointer on the last paevt structure	*/
unsigned short  index;		/* index of the input-output		*/
char            usrval;		/* user predicted value			*/

  {
  struct paevt *ptevt;

  ptevt         = (struct paevt *) mbkalloc (sizeof(struct paevt));
  ptevt->INDEX  = index;
  ptevt->USRVAL = usrval;
  ptevt->SIMVAL = usrval;
  ptevt->NEXT   = lastpaevt;

  return (ptevt);
  }
