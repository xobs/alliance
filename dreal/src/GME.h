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

/*------------------------------------------------------------\
|                                                             |
| Tool    :                   DREAL                           |
|                                                             |
| File    :                  Gme101.h                         |
|                                                             |
| Author  :                Jacomme Ludovic                    |
|                                                             |
| Date    :                  28.03.95                         |
|                                                             |
\------------------------------------------------------------*/

/*------------------------------------------------------------\
|                                                             |
|                           Constants                         |
|                                                             |
\------------------------------------------------------------*/

# ifndef DREAL_GME 
# define DREAL_GME 

/*------------------------------------------------------------\
|                                                             |
|                            Types                            |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                          Variables                          |
|                                                             |
\------------------------------------------------------------*/

  extern DrealMenuItem  DrealEditMenu[];
  extern DrealMenuItem  DrealWindowMenu[];
  extern DrealPanelItem DrealEditGlobalPanel;
  extern DrealPanelItem DrealWindowGlobalPanel;
  extern DrealPanelItem DrealEditSearchPanel;
  extern DrealPanelItem DrealEditSearchViewPanel;
  extern DrealPanelItem DrealEditIdentifyPanel;
  extern DrealPanelItem DrealEditSelectPanel;
  extern DrealPanelItem DrealModifyRectanglePanel;

  extern int DrealEditGlobalDefaultValues[ 5 ];
  extern int DrealWindowGlobalDefaultValues[ 5 ];
  extern int DrealEditSearchDefaultValues[ 5 ];
  extern int DrealEditIdentifyDefaultValues[ 5 ];
  extern int DrealEditSelectDefaultValues[ 5 ];
  extern int DrealEditSearchViewDefaultValues[ 5 ];
  extern int DrealModifyRectangleDefaultValues[ 5 ];

/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/

  extern void DrealBuidlPanelModify();
  extern void DrealBuildEditDialog();

  extern void DrealEditSelectPointDelete();
  extern void DrealEditSelectWindowDelete();
  extern void DrealEditSelectPointCopy();
  extern void DrealEditSelectWindowCopy();
  extern void DrealEditSelectPointMove();
  extern void DrealEditSelectWindowMove();
  extern void DrealEditSelectPointModify();
  extern void DrealEditSelectWindowModify();

  extern void DrealEditIdentify();
  extern void DrealEditUnselectAll();

  extern void DrealEditSelectPoint();
  extern void DrealEditSelectWindow();
  extern void DrealEditSelectFence();

  extern void DrealEditUndo();
  extern void DrealEditRedo();
  extern void DrealEditCopy();
  extern void DrealEditMove();
  extern void DrealEditDelete();
  extern void DrealEditModify();
  extern void DrealEditStretch();

# endif
