/*------------------------------------------------------------\
|                                                             |
| This file is part of the Alliance CAD System Copyright      |
| (C) Laboratoire LIP6 - D�partement ASIM Universite P&M Curie|
|                                                             |
| Home page      : http://www-asim.lip6.fr/alliance/          |
| E-mail         : mailto:alliance-users@asim.lip6.fr       |
|                                                             |
| This progam is  free software; you can redistribute it      |
| and/or modify it under the  terms of the GNU General Public |
| License as  published by the Free Software Foundation;      |
| either version 2 of the License, or (at your option) any    |
| later version.                                              |
|                                                             |
| Alliance VLSI  CAD System  is distributed  in the hope that |
| it  will be useful, but WITHOUT  ANY WARRANTY;              |
| without even the  implied warranty of MERCHANTABILITY or    |
| FITNESS FOR A PARTICULAR PURPOSE. See the GNU General       |
| Public License for more details.                            |
|                                                             |
| You should have received a copy  of the GNU General Public  |
| License along with the GNU C Library; see the file COPYING. |
| If not, write to the Free Software Foundation, Inc.,        |
| 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.                     |
|                                                             |
\------------------------------------------------------------*/

#include <stdio.h>
#include "rds.h"
#include "mut.h"
#include "inter.h"

int Intersect(Rec_A, Rec_B)
rdsrec_list *Rec_A, *Rec_B;
{
  long xa1,ya1,xa2,ya2;  /*Coordonnees du rectangle A */
  long xb1,yb1,xb2,yb2;  /*Coordonnees du rectangle B */
  int  DirA, DirB;       /*Direction des mediannes des rectangles */

  xa1=Rec_A->X;                 xb1=Rec_B->X;
  xa2=Rec_A->X+Rec_A->DX;       xb2=Rec_B->X+Rec_B->DX;
  ya1=Rec_A->Y;                 yb1=Rec_B->Y;
  ya2=Rec_A->Y+Rec_A->DY;       yb2=Rec_B->Y+Rec_B->DY;

  if(GetRdsLayer(Rec_A)!=GetRdsLayer(Rec_B)  &&
     !((GetRdsLayer(Rec_A)==RDS_POLY && GetRdsLayer(Rec_B)==RDS_GATE)||
       (GetRdsLayer(Rec_A)==RDS_GATE && GetRdsLayer(Rec_B)==RDS_POLY)  ))
    return(NON_INTERSECT);
  if((ya2<yb1)||(yb2<ya1)||(xa2<xb1)||(xb2<xa1))
    return(NON_INTERSECT);

  DirA=GETDIRECTION(Rec_A);
  DirB=GETDIRECTION(Rec_B);

  if(DirA!=DirB)
    return(PERPEN);
  else
    return(PARAL);
}
