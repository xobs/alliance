/*------------------------------------------------------------\
|                                                             |
| This file is part of the Alliance CAD System Copyright      |
| (C) Laboratoire LIP6 - Département ASIM Universite P&M Curie|
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
| Tool    :                   XFSM                            |
|                                                             |
| File    :                 Dialog.c                          |
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
# include <Xm/SelectioB.h>
# include <Xm/PushBG.h>

# include "mut.h"
# include "aut.h"
# include "abl.h"
# include "bdd.h"
# include "fsm.h"
# include "XSB.h"
# include "XFS.h"
# include "XMX.h"
# include "XTB.h"
# include "XME.h"

# include "XME_dialog.h"
# include "XME_search.h"
# include "XME_edit.h"

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
|                         Search Dialog                       |
|                                                             |
\------------------------------------------------------------*/

  XfsmDialogItem XfsmSearchObjectDialog =

  {
    "Object name",
    XFSM_DIALOG_PROMPT,
    (Widget)NULL,
    (void *)CallbackSearchObjectOk,
    (XtPointer)NULL,
    (void *)CallbackSearchObjectCancel,
    (XtPointer)NULL
  };


/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                      XfsmBuildEditDialog                    |
|                                                             |
\------------------------------------------------------------*/

void XfsmBuildEditDialog()

{
  autbegin();

  XfsmBuildDialog( XfsmMainWindow, &XfsmSearchObjectDialog );

  autend();
}

/*------------------------------------------------------------\
|                                                             |
|                        Search Callback                      |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                        Callback For Object                  |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                      CallbackSearchObjectOk                 |
|                                                             |
\------------------------------------------------------------*/

void CallbackSearchObjectOk( MyWidget, ClientData, CallData )

    Widget                        MyWidget;
    caddr_t                       ClientData;
    XmSelectionBoxCallbackStruct *CallData;
{
  char *NameSet;

  autbegin();

  XmStringGetLtoR(  CallData->value,
                    XmSTRING_DEFAULT_CHARSET,
                   &NameSet );

  XtUnmanageChild( XfsmSearchObjectDialog.WIDGET );

  XfsmExitDialog();

  NameSet = XfsmPostTreatString( NameSet );

  if ( NameSet != (char *)NULL )
  {
    NameSet = namealloc( NameSet );

    XfsmEditSearchObject( NameSet );
  }

  autend();
}

/*------------------------------------------------------------\
|                                                             |
|                    CallbackSearchObjectCancel               |
|                                                             |
\------------------------------------------------------------*/

void CallbackSearchObjectCancel( MyWidget, ClientData, CallData )

    Widget                        MyWidget;
    caddr_t                       ClientData;
    XmSelectionBoxCallbackStruct *CallData;
{
  autbegin();

  XtUnmanageChild( XfsmSearchObjectDialog.WIDGET );

  XfsmExitDialog();

  autend();
}
