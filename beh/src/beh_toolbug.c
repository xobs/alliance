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
/* file		: beh_toolbug.c						*/
/* date		: Feb 29 2000						*/
/* version	: v111							*/
/* authors	: Pirouz BAZARGAN SABET					*/
/* content	: low-level function					*/
/* ###--------------------------------------------------------------### */

#include <stdio.h>
#include "mut.h"

/* ###--------------------------------------------------------------### */
/* function	: beh_toolbug						*/
/* description	: print an error message on the standard error output	*/
/* called func.	: none							*/
/* ###--------------------------------------------------------------### */

void beh_toolbug (code, str1, str2, nbr1)

int   code;
char *str1;
char *str2;
int   nbr1;

  {
  fprintf (stderr,"Fatal error %d executing `%s`: ", code, str1);
  switch (code)
    {
    case 1:
      fprintf (stderr,"unknown operator\n");
      break;
    case 2:
      fprintf (stderr,"cannot create empty atom\n");
      break;
    case 3:
      fprintf (stderr,"cannot build NOT of empty expression\n");
      break;
    case 4:
      fprintf (stderr,"cannot combine empty expressions\n");
      break;
    case 5:
      fprintf (stderr,"cannot find terminal\n");
      break;
    case 10:
      fprintf (stderr,"cannot drive empty or erroneous description\n");
      break;
    case 15 :
      fprintf (stderr,"illegal bit string value : `%c`\n",(char)nbr1);
      break;
    case 16 :
      fprintf (stderr,"the same expression cannot be used twice\n");
      break;
    case 19:
      fprintf (stderr,"empty guard expression: `%s`\n",str2);
      break;
    case 20:
      fprintf (stderr,"empty waveform expression: `%s`\n",str2);
      break;
    case 100 :
      fprintf (stderr, "illegal use of attribute STABLE\n");
      break;
    case 101 :
      fprintf (stderr, "unknown terminal operand `%s`\n", str2);
      break;
    case 102 :
      fprintf (stderr, "unknown operator `%d`\n", nbr1);
      break;
    case 103 :
      fprintf (stderr, "empty expression\n");
      break;
    default:
      fprintf (stderr, "BUG\n");
    }
  EXIT (1);
  }
