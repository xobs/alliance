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
| Tool    :                    XPAT                           |
|                                                             |
| File    :                  Panel.h                          |
|                                                             |
| Authors :              Jacomme Ludovic                      |
|                                                             |
| Date    :                   04.12.96                        |
|                                                             |
\------------------------------------------------------------*/

/*------------------------------------------------------------\
|                                                             |
|                         Include Files                       |
|                                                             |
\------------------------------------------------------------*/

# ifndef XPAT_VIEW_PANEL
# define XPAT_VIEW_PANEL

/*------------------------------------------------------------\
|                                                             |
|                           Constants                         |
|                                                             |
\------------------------------------------------------------*/

# define XPAT_VIEW_ARROWS_X     990
# define XPAT_VIEW_ARROWS_Y      80
# define XPAT_VIEW_ZOOM_X       990
# define XPAT_VIEW_ZOOM_Y       230
# define XPAT_VIEW_GRID_X       470
# define XPAT_VIEW_GRID_Y       330
# define XPAT_VIEW_LAYER_X      430
# define XPAT_VIEW_LAYER_Y      190

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
/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                       Callback View Panel                   |
|                                                             |
\------------------------------------------------------------*/

  extern void CallbackLeftArrow();
  extern void CallbackRightArrow();
  extern void CallbackUpArrow();
  extern void CallbackDownArrow();
  extern void CallbackMoveSet();
  extern void CallbackCloseArrows();

  extern void CallbackZoomRefresh();
  extern void CallbackZoomPrevious();
  extern void CallbackZoomLess();
  extern void CallbackZoomMore();
  extern void CallbackZoomSet();
  extern void CallbackZoomIn();
  extern void CallbackZoomFit();
  extern void CallbackZoomCenter();
  extern void CallbackZoomGoto();
  extern void CallbackZoomPan();
  extern void CallbackCloseZoom();

  extern void CallbackSetGridX();
  extern void CallbackSetGridY();
  extern void CallbackGridOnOff();
  extern void CallbackCloseGrid();

  extern void CallbackLayerAllVisible();
  extern void CallbackLayerAllInvisible();
  extern void CallbackLayerVisible();
  extern void CallbackLayerInvisible();
  extern void CallbackLayerCursor();
  extern void CallbackLayerForceDisplay();
  extern void CallbackLayerScale();
  extern void CallbackNameVisible();
  extern void CallbackNameInvisible();

  extern void CallbackLayerApply();
  extern void CallbackCloseLayer();

  extern void XpatChangeForceDisplay();
  extern void XpatChangeCursor();

  extern void XpatInitializeLayer();
  extern void XpatSetLayerVisible();
  extern void XpatSetLayerInvisible();
  extern void XpatSetNameVisible();
  extern void XpatSetNameInvisible();
  extern void XpatLayerAllVisible();
  extern void XpatLayerAllInvisible();

# endif 
