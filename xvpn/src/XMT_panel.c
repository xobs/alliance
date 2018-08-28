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
| Tool    :                   XVPN                            |
|                                                             |
| File    :                   Panel.c                         |
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

# include <stdio.h>
# include <string.h>
# include <Xm/Xm.h>
# include <Xm/FileSB.h>
# include <Xm/Text.h>
# include <Xm/SelectioB.h>
# include <Xm/PushBG.h>

# include "mut.h"
# include "aut.h"
# include "vex.h"
# include "vpn.h"
# include "XSB.h"
# include "XVP.h"
# include "XMX.h"
# include "XTB.h"
# include "XMT.h"

# include "XMT_panel.h"
# include "XMT_message.h"
# include "XMT_dialog.h"
# include "XMT_tools.h"

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
|                       Panel Message                         |
|                                                             |
\------------------------------------------------------------*/

   static char *XvpnPanelMessageButtonName[] =

   {
     "Text",
     "Close"
   };

 XvpnPanelButtonItem XvpnToolsMessageButton[] =

         {
           {
             &XvpnPanelMessageButtonName[0],
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
             &XvpnPanelMessageButtonName[1],
             NULL, NULL, 0, 0,
             NULL,
             NULL,
             3, 9,
             2, 1,
             CallbackToolsCloseMessage,
             (XtPointer)NULL,
             (Widget)NULL
           }
           ,
           { NULL }
         };

   XvpnPanelItem XvpnToolsMessagePanel =

         {
           "Message",
           1,
           0,
           XVPN_TOOLS_MESSAGE_X,
           XVPN_TOOLS_MESSAGE_Y,
           360,
           250,
           8,
           10,
           (Widget)NULL,
           (Widget)NULL,
           (Widget)NULL,
           (Widget)NULL,
           XvpnToolsMessageButton
         };

   int XvpnToolsMessageDefaultValues[ 5 ] =

         {
           XVPN_TOOLS_MESSAGE_X,
           XVPN_TOOLS_MESSAGE_Y,
           360, 250, 0
         };

/*------------------------------------------------------------\
|                                                             |
|                     Callback For Message                    |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                    CallbackToolsCloseMessage                |
|                                                             |
\------------------------------------------------------------*/

void CallbackToolsCloseMessage( MyWidget, ClientData, CallData )

     Widget  MyWidget;
     caddr_t ClientData;
     caddr_t CallData;
{
  autbegin();

  XvpnExitPanel( &XvpnToolsMessagePanel );

  autend();
}

/*------------------------------------------------------------\
|                                                             |
|                   XvpnDisplayToolsMessage                   |
|                                                             |
\------------------------------------------------------------*/

void XvpnDisplayToolsMessage()
{
  char *Message;

  autbegin();

  Message = XvpnGetErrorMessage();

  if ( Message != (char *)NULL )
  {
    XmTextSetString( XvpnToolsMessageButton[0].BUTTON, Message );

    XvpnEnterPanel( &XvpnToolsMessagePanel );
  }
  else
  {
    XmTextSetString( XvpnToolsMessageButton[0].BUTTON, ""      );
  }

  autend();
}
