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
| Tool    :                   XFSM                           |
|                                                             |
| File    :                   Menu.c                          |
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
# include <Xm/Xm.h>
# include <Xm/PushBG.h>

# include "mut.h"
# include "aut.h"
# include "abl.h"
# include "bdd.h"
# include "fsm.h"
# include "XTB.h"
# include "XSB.h"
# include "XMH.h"
# include "XMX.h"

# include "XMH_menu.h"
# include "XMH_panel.h"

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
|                          Help Menu                          |
|                                                             |
\------------------------------------------------------------*/

   XfsmMenuItem XfsmHelpMenu[] =

         {
           {
             "About Xfsm",
             'G',
             NULL,
             NULL,
             &xmPushButtonGadgetClass,
             False,
             False,
             False,
             CallbackHelpAbout,
             (XtPointer)NULL,
             (Widget)NULL,
             (Widget)NULL,
             (XfsmMenuItem *)NULL
           }
           ,
           NULL
        };

/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                      CallbackHelpAbout                      |
|                                                             |
\------------------------------------------------------------*/

void CallbackHelpAbout( MyWidget, ClientData, CallData )

     Widget  MyWidget;
     caddr_t ClientData;
     caddr_t CallData;
{
  autbegin();

  XfsmEnterPresentPanel();

  autend();
}