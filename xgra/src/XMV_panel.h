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
| Tool    :                    XGRA                           |
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

# ifndef XGRA_VIEW_PANEL
# define XGRA_VIEW_PANEL

/*------------------------------------------------------------\
|                                                             |
|                           Constants                         |
|                                                             |
\------------------------------------------------------------*/

# define XGRA_VIEW_ARROWS_X     990
# define XGRA_VIEW_ARROWS_Y      80
# define XGRA_VIEW_ZOOM_X       990
# define XGRA_VIEW_ZOOM_Y       230
# define XGRA_VIEW_GRID_X       470
# define XGRA_VIEW_GRID_Y       330
# define XGRA_VIEW_LAYER_X      430
# define XGRA_VIEW_LAYER_Y      190

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
  extern void CallbackNameVisible();
  extern void CallbackNameInvisible();
  extern void CallbackLayerApply();
  extern void CallbackCloseLayer();

  extern void XgraInitializeLayer();
  extern void XgraSetLayerVisible();
  extern void XgraSetLayerInvisible();
  extern void XgraSetNameVisible();
  extern void XgraSetNameInvisible();
  extern void XgraLayerAllVisible();
  extern void XgraLayerAllInvisible();

# endif 
