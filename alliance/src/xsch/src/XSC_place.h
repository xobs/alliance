/*------------------------------------------------------------\
|                                                             |
| This file is part of the Alliance CAD System Copyright      |
| (C) Laboratoire LIP6 - D�partement ASIM Universite P&M Curie|
|                                                             |
| Home page      : http://www-asim.lip6.fr/alliance/          |
| E-mail support : mailto:alliance-support@asim.lip6.fr       |
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
| 675 Mass Ave, Cambridge, MA 02139, USA.                     |
|                                                             |
\------------------------------------------------------------*/

/*------------------------------------------------------------\
|                                                             |
| Tool    :                    XSCH                           |
|                                                             |
| File    :                   Trace.h                         |
|                                                             |
| Authors :              Miramond  Benoit                     |
| 			 Picault Stephane                     |
|                                                             |
| Date    :                   01.06.96                        |
|                                                             |
\------------------------------------------------------------*/

/*------------------------------------------------------------\
|                                                             |
|                         Include Files                       |
|                                                             |
\------------------------------------------------------------*/

# ifndef XSC_PLACE_H
# define XSC_PLACE_H

/*------------------------------------------------------------\
|                                                             |
|                           Constants                         |
|                                                             |
\------------------------------------------------------------*/

# define XSCH_GRID_X		 4 
# define XSCH_CELL_ROOT_LOINS    0
# define XSCH_CELL_ROOT_LOCON    1

/*------------------------------------------------------------\
|                                                             |
|                             Mask                            |
|                                                             |
\------------------------------------------------------------*/

# define XSCH_WIRE_TAG_MASK  0x01
# define XSCH_WIRE_PATH_MASK 0x02

# define IsXschWireTag( X )     ( ( X )->FLAGS &   XSCH_WIRE_TAG_MASK )
# define SetXschWireTag( X )    ( ( X )->FLAGS |=  XSCH_WIRE_TAG_MASK )
# define ClearXschWireTag( X )  ( ( X )->FLAGS &= ~XSCH_WIRE_TAG_MASK )

# define IsXschWirePath( X )     ( ( X )->FLAGS &   XSCH_WIRE_PATH_MASK )
# define SetXschWirePath( X )    ( ( X )->FLAGS |=  XSCH_WIRE_PATH_MASK )
# define ClearXschWirePath( X )  ( ( X )->FLAGS &= ~XSCH_WIRE_PATH_MASK )

/*------------------------------------------------------------\
|                                                             |
|                             Macro                           |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                            Types                            |
|                                                             |
\------------------------------------------------------------*/

  typedef struct xschpath_list 
  {
    struct xschpath_list *NEXT;
    char                 *FROM;
    char                 *TO;
    char                 *COMMENT;
    long                  LAYER;

  } xschpath_list;

/*------------------------------------------------------------\
|                                                             |
|                          Variables                          |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/

  extern void XschPlaceFigure();

# endif 