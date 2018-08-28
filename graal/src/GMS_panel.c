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
| Tool    :                   GRAAL                           |
|                                                             |
| File    :                   Panel.c                         |
|                                                             |
| Author  :                Jacomme Ludovic                    |
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
# include <string.h>
# include <Xm/Xm.h>
# include <Xm/Text.h>
# include <Xm/FileSB.h>
# include <Xm/SelectioB.h>
# include <Xm/PushBG.h>

# include "mut.h"
# include "mph.h"
# include "rds.h"
# include "rpr.h"
# include "rfm.h"
# include "GTB.h"
# include "GSB.h"
# include "GRM.h"
# include "GMS.h"

# include "GMS_panel.h"
# include "GME_dialog.h"

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
|                            Panel                            |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                    Panel Informations                       |
|                                                             |
\------------------------------------------------------------*/

 GraalPanelButtonItem GraalSetupInformationsButton[] =

         {
           {
             "Text",
             "Nothing", NULL, 0, 0,
             NULL,
             NULL,
              0, 0,
              8, 9,
             NULL,
             (XtPointer)NULL,
             (Widget)NULL
           }
           ,
           {
             "Close",
             NULL, NULL, 0, 0,
             NULL,
             NULL,
             3, 9,
             2, 1,
             GraalExitDialogCallback,
             (XtPointer)NULL,
             (Widget)NULL
           }
         };

   GraalPanelItem GraalSetupInformationsPanel =

         {
           "Informations",
           1,
           0,
           GRAAL_SETUP_INFORMATIONS_X,
           GRAAL_SETUP_INFORMATIONS_Y,
           360,
           250,
           8,
           10,
           (Widget)NULL,
           (Widget)NULL,
           (Widget)NULL,
           (Widget)NULL,
           2,
           GraalSetupInformationsButton
         };

   int GraalSetupInformationsDefaultValues[ 5 ] =

         {
           GRAAL_SETUP_INFORMATIONS_X,
           GRAAL_SETUP_INFORMATIONS_Y,
           360, 250, 0
         };

/*------------------------------------------------------------\
|                                                             |
|                Callback For Informations                    |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                   GraalDisplayInformations                  |
|                                                             |
\------------------------------------------------------------*/

void GraalDisplayInformations()

{
  char *Message;

  rdsbegin();

  Message = GraalGetInformations();

  XmTextSetString( GraalSetupInformationsButton[0].BUTTON, Message );

  GraalEnterPanel( &GraalSetupInformationsPanel );

  GraalLimitedLoop( GraalSetupInformationsPanel.PANEL );

  GraalExitPanel( &GraalSetupInformationsPanel );

  rdsend();
}
