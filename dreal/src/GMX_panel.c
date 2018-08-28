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
| File    :                   Panel.c                         |
|                                                             |
| Authors :              Jacomme Ludovic                      |
|                                                             |
| Date    :                  28.03.95                         |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                         Include Files                       |
|                                                             |
\------------------------------------------------------------*/

# include <stdio.h>
# include <Xm/Xm.h>
# include <Xm/PushB.h>
# include <Xm/Form.h>
# include <Xm/Frame.h>
 
# include "mut.h"
# include "mph.h"
# include "rds.h"
# include "rpr.h"
# include "GSB.h"
# include "GTB.h"
# include "GMF.h"
# include "GME.h"
# include "GMC.h"
# include "GMV.h"
# include "GMT.h"
# include "GMS.h"
# include "GMH.h"
# include "GMX.h"

# include "GMX_panel.h"
# include "GME_panel.h"

/*------------------------------------------------------------\
|                                                             |
|                           Constants                         |
|                                                             |
\------------------------------------------------------------*/
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
|                    DrealInitializePanel                     |
|                                                             |
\------------------------------------------------------------*/

void DrealInitializePanel()

{
  rdsbegin();

  DrealBuildPanelLayer();
  DrealBuildPanelModify();
  DrealBuildPanelCreate();

  DrealBuildPanel( DrealMainWindow, &DrealToolsMessagePanel     );

  DrealBuildPanel( DrealMainWindow, &DrealViewArrowsPanel       );
  DrealBuildPanel( DrealMainWindow, &DrealViewZoomPanel         );
  DrealBuildPanel( DrealMainWindow, &DrealViewLayerPanel        );
  DrealBuildPanel( DrealMainWindow, &DrealViewGridPanel         );

  DrealBuildPanel( DrealMainWindow, &DrealCreateRectanglePanel );

  DrealBuildPanel( DrealMainWindow, &DrealEditGlobalPanel        );
  DrealBuildPanel( DrealMainWindow, &DrealWindowGlobalPanel      );
  DrealBuildPanel( DrealMainWindow, &DrealEditSelectPanel        );
  DrealBuildPanel( DrealMainWindow, &DrealEditSearchPanel        );
  DrealBuildPanel( DrealMainWindow, &DrealEditSearchViewPanel    );
  DrealBuildPanel( DrealMainWindow, &DrealEditIdentifyPanel      );

  DrealBuildPanel( DrealMainWindow, &DrealModifyRectanglePanel   );

  DrealBuildPanel( DrealMainWindow, &DrealSetupInformationsPanel );

  DrealBuildPresentPanel();

  rdsend();
}
