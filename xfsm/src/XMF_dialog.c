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
# include "XMF.h"

# include "XMF_dialog.h"
# include "XMF_file.h"

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
|                          File Dialog                        |
|                                                             |
\------------------------------------------------------------*/

  XfsmDialogItem XfsmFileOpenDialog =

  {
    "Open File",
    XFSM_DIALOG_FILE,
    (Widget)NULL,
    (void *)CallbackFileOpenOk,
    (XtPointer)NULL,
    (void *)CallbackFileOpenCancel,
    (XtPointer)NULL
  };

  XfsmDialogItem XfsmFileQuitDialog =

  {
    "Do you really want to quit Xfsm ?",
    XFSM_DIALOG_WARNING,
    (Widget)NULL,
    (void *)CallbackFileQuitOk,
    (XtPointer)NULL,
    (void *)CallbackFileQuitCancel,
    (XtPointer)NULL
  };

/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                  XfsmBuildFileDialog                       |
|                                                             |
\------------------------------------------------------------*/

void XfsmBuildFileDialog()

{
  autbegin();

  XfsmBuildDialog( XfsmMainWindow, &XfsmFileOpenDialog   );
  XfsmBuildDialog( XfsmMainWindow, &XfsmFileQuitDialog   );

  autend();
}

/*------------------------------------------------------------\
|                                                             |
|                  CallbackFileQuitOk                         |
|                                                             |
\------------------------------------------------------------*/

void CallbackFileQuitOk( MyWidget, ClientData, CallData )

    Widget                        MyWidget;
    caddr_t                       ClientData;
    caddr_t                       CallData;
{
  autbegin();

  XfsmExitDialog();

  XtCloseDisplay( XtDisplay( XtParent( MyWidget ) ) );
  XfsmExitErrorMessage( 0 );

  autend();
}

/*------------------------------------------------------------\
|                                                             |
|                  CallbackFileQuitCancel                     |
|                                                             |
\------------------------------------------------------------*/

void CallbackFileQuitCancel( MyWidget, ClientData, CallData )

    Widget                        MyWidget;
    caddr_t                       ClientData;
    caddr_t                       CallData;
{
  autbegin();

  XfsmExitDialog();

  autend();
}

/*------------------------------------------------------------\
|                                                             |
|                    CallbackFileOpenOk                       |
|                                                             |
\------------------------------------------------------------*/

void CallbackFileOpenOk( MyWidget, ClientData, FileStruct )

    Widget                            MyWidget;
    caddr_t                           ClientData;
    XmFileSelectionBoxCallbackStruct *FileStruct;
{
  char *FileName;

  autbegin();

  XtUnmanageChild( XfsmFileOpenDialog.WIDGET );

  XfsmExitDialog();

  if ( FileStruct->value != NULL )
  {
    XmStringGetLtoR( FileStruct->value,
                     XmSTRING_DEFAULT_CHARSET,
                     &FileName 
                   );

    FileName = XfsmPostTreatString( FileName ); 

    if ( FileName != (char *)NULL )
    {
      XfsmFileOpen( FileName );

      XfsmChangeEditMode( XFSM_EDIT_MEASURE, 
                           XfsmPromptEditMeasure );
    }
    else
    {
      XfsmErrorMessage( XfsmMainWindow, "Unable to load this file !" );
    }
  }

  autend();
}

/*------------------------------------------------------------\
|                                                             |
|                    CallbackFileOpenCancel                   |
|                                                             |
\------------------------------------------------------------*/

void CallbackFileOpenCancel( MyWidget, ClientData, FileStruct )

    Widget                            MyWidget;
    caddr_t                           ClientData;
    XmFileSelectionBoxCallbackStruct *FileStruct;
{
  autbegin();

  XtUnmanageChild( XfsmFileOpenDialog.WIDGET );

  XfsmExitDialog();

  autend();
}
