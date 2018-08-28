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
| Tool    :                   XVPN                           |
|                                                             |
| File    :                  dialog.c                         |
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
# include <Xm/FileSB.h>
# include <Xm/MessageB.h>
# include <Xm/SelectioB.h>
# include <Xm/SeparatoG.h>

# include "mut.h"
# include "aut.h"
# include "XTB.h"
# include "XSB.h"
# include "XTB_dialog.h"

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
  
  static int XvpnLockLoop = 0;

  static XvpnDialogItem XvpnWarningDialog =

  {
    "Warning",
    XVPN_DIALOG_WARNING,
    (Widget)NULL,
    (void *)NULL,
    (XtPointer)NULL,
    (void *)NULL,
    (XtPointer)NULL
  };

  static XvpnDialogItem XvpnErrorDialog =

  {
    "Error",
    XVPN_DIALOG_ERROR,
    (Widget)NULL,
    (void *)NULL,
    (XtPointer)NULL,
    (void *)NULL,
    (XtPointer)NULL
  };

/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                 XvpnDestroyDialogCallback                  |
|                                                             |
\------------------------------------------------------------*/

void XvpnDestroyDialogCallback( MyWidget, ClientData, CallData )

    Widget  MyWidget;
    caddr_t ClientData;
    caddr_t CallData;
{
  XvpnLockLoop = 0;
  XvpnExitErrorMessage( 1 );
}

/*------------------------------------------------------------\
|                                                             |
|                   XvpnExitDialogCallback                   |
|                                                             |
\------------------------------------------------------------*/

void XvpnExitDialogCallback()

{
  autbegin();

  XvpnExitDialog();

  autend();
}

/*------------------------------------------------------------\
|                                                             |
|                      XvpnBuildDialog                       |
|                                                             |
\------------------------------------------------------------*/

void XvpnBuildDialog( Father, Dialog )

   Widget           Father;
   XvpnDialogItem *Dialog;
{
  Arg      Args[3];
  XmString Label;

  autbegin();

  Label = XmStringCreateLtoR( Dialog->LABEL, 
                              XmSTRING_DEFAULT_CHARSET );

  if ( Dialog->TYPE < XVPN_DIALOG_FILE )
  {
    XtSetArg( Args[0], XmNmessageString    , Label);
  }
  else
  {
    XtSetArg( Args[0], XmNselectionLabelString, Label);
  }

  XtSetArg( Args[1], XmNdeleteResponse, XmDESTROY );
  XtSetArg( Args[2], XmNtitle, " "                );

  switch ( Dialog->TYPE )
  {
    case XVPN_DIALOG_MESSAGE :

       Dialog->WIDGET = 

          XmCreateMessageDialog( Father, Dialog->LABEL, Args, 3);

       break;

    case XVPN_DIALOG_ERROR :

       Dialog->WIDGET = 

          XmCreateErrorDialog( Father, Dialog->LABEL, Args, 3);

       break;
  
    case XVPN_DIALOG_INFO :

       Dialog->WIDGET = 

          XmCreateInformationDialog( Father, Dialog->LABEL, Args, 3);

       break;

    case XVPN_DIALOG_QUESTION :

       Dialog->WIDGET = 

          XmCreateQuestionDialog( Father, Dialog->LABEL, Args, 3);

       break;

    case XVPN_DIALOG_WARNING :

       Dialog->WIDGET = 

          XmCreateWarningDialog( Father, Dialog->LABEL, Args, 3);

       break;

    case XVPN_DIALOG_WORKING :

       Dialog->WIDGET = 

          XmCreateWorkingDialog( Father, Dialog->LABEL, Args, 3);

       break;

    case XVPN_DIALOG_FILE    :

       Dialog->WIDGET = 

          XmCreateFileSelectionDialog( Father, Dialog->LABEL, Args, 3);

       XtUnmanageChild( XmFileSelectionBoxGetChild( Dialog->WIDGET, 
                        XmDIALOG_FILTER_LABEL ) );

       XtUnmanageChild( XmFileSelectionBoxGetChild( Dialog->WIDGET, 
                        XmDIALOG_FILTER_TEXT  ) );

       break;
  
    case XVPN_DIALOG_PROMPT  :

       Dialog->WIDGET = 

          XmCreatePromptDialog( Father, Dialog->LABEL, Args, 3);

       XtUnmanageChild( XmSelectionBoxGetChild( Dialog->WIDGET, 
                        XmDIALOG_HELP_BUTTON ) );
  }

  XmStringFree( Label );

  XtAddCallback (Dialog->WIDGET, XmNdestroyCallback,
                XvpnDestroyDialogCallback, NULL );

  if ( Dialog->TYPE < XVPN_DIALOG_FILE )
  {
    XtUnmanageChild( XmMessageBoxGetChild( Dialog->WIDGET, 
                     XmDIALOG_HELP_BUTTON ) );
  }

  if ( ( Dialog->CALLBACK_OK     == NULL ) &&
       ( Dialog->CALLBACK_CANCEL == NULL ) )
  {
    XtAddCallback( Dialog->WIDGET, XmNokCallback, 
                   XvpnExitDialogCallback, NULL );
  }
  else
  {
    if ( Dialog->CALLBACK_OK == NULL )
    {
      XtUnmanageChild( XmMessageBoxGetChild( Dialog->WIDGET, 
                       XmDIALOG_OK_BUTTON ) );
    }
    else
    {
      XtAddCallback( Dialog->WIDGET, XmNokCallback, 
                     Dialog->CALLBACK_OK, 
                     Dialog->CALLDATA_OK );
    }
  }

  if ( Dialog->CALLBACK_CANCEL == NULL )
  {
    XtUnmanageChild( XmMessageBoxGetChild( Dialog->WIDGET, 
                     XmDIALOG_CANCEL_BUTTON ) );
  }
  else
  {
    XtAddCallback( Dialog->WIDGET, XmNcancelCallback, 
                   Dialog->CALLBACK_CANCEL, 
                   Dialog->CALLDATA_CANCEL );
  }

  autend();
}

/*------------------------------------------------------------\
|                                                             |
|                      XvpnLimitedLoop                       |
|                                                             |
\------------------------------------------------------------*/

void XvpnLimitedLoop( MyWidget )

  Widget MyWidget;
{
  Widget        DialogShell, WShell;
  XEvent        Event;
  XAnyEvent    *AnyEvent;
  XtAppContext  Context;

  autbegin();

  Context = XtWidgetToApplicationContext( MyWidget );

  XvpnLockLoop = 1;

  for ( WShell = MyWidget; 
        ! XtIsShell( WShell );
        WShell = XtParent( WShell ) );

  while( XvpnLockLoop == 1 )
  {
    XtAppNextEvent( Context, &Event );

    AnyEvent = (XAnyEvent *)( &Event );

    for ( DialogShell = XtWindowToWidget( AnyEvent->display, AnyEvent->window ); 
         ((DialogShell != NULL ) && (!XtIsShell( DialogShell )));
         DialogShell = XtParent(DialogShell));

    switch ( AnyEvent->type )
    {
      case ButtonPress   :
      case ButtonRelease : 
 
        if ( WShell == DialogShell )
        {
          XtDispatchEventToWidget( 
                XtWindowToWidget( AnyEvent->display, AnyEvent->window ), 
			  &Event );
        }

        break;
 
      case KeyPress      :
      case KeyRelease    :

        if ( WShell != DialogShell )
        {
          AnyEvent->window = XtWindow( WShell );
        }
 
      default :

        XtDispatchEvent( &Event );
    }
  }

  autend();
}

/*------------------------------------------------------------\
|                                                             |
|                     XvpnEnterDialog                        |
|                                                             |
\------------------------------------------------------------*/

void XvpnEnterDialog( Dialog )
 
   XvpnDialogItem *Dialog;
{
  autbegin();

  XtManageChild ( Dialog->WIDGET );

  XvpnLimitedLoop( Dialog->WIDGET );

  XtUnmanageChild( Dialog->WIDGET );

  autend();
}

/*------------------------------------------------------------\
|                                                             |
|                     XvpnReEnterDialog                      |
|                                                             |
\------------------------------------------------------------*/

void XvpnReEnterDialog()
{
  XvpnLockLoop = 1;
}

/*------------------------------------------------------------\
|                                                             |
|                      XvpnExitDialog                        |
|                                                             |
\------------------------------------------------------------*/

void XvpnExitDialog()

{
  XvpnLockLoop = 0;
}

/*------------------------------------------------------------\
|                                                             |
|                    XvpnWarningMessage                      |
|                                                             |
\------------------------------------------------------------*/

void XvpnWarningMessage( Father, Subject )
 
    Widget  Father;
    char   *Subject;
{
  XmString Label;

  autbegin();

  if ( XvpnWarningDialog.WIDGET == (Widget)NULL )
  {
    XvpnBuildDialog( Father, &XvpnWarningDialog );
  }

  Label = XmStringCreateLtoR( Subject,
                              XmSTRING_DEFAULT_CHARSET );

  XtVaSetValues( XvpnWarningDialog.WIDGET,
                 XmNmessageString,
                 Label, NULL );

  XmStringFree( Label );

  XvpnEnterDialog( &XvpnWarningDialog );

  autend();
}

/*------------------------------------------------------------\
|                                                             |
|                      XvpnErrorMessage                      |
|                                                             |
\------------------------------------------------------------*/

void XvpnErrorMessage( Father, Subject )

   Widget   Father;
   char    *Subject;
{
  XmString Label;

  autbegin();

  if ( XvpnErrorDialog.WIDGET == (Widget)NULL )
  {
    XvpnBuildDialog( Father, &XvpnErrorDialog );
  }

  Label = XmStringCreateLtoR( Subject,
                              XmSTRING_DEFAULT_CHARSET );

  XtVaSetValues( XvpnErrorDialog.WIDGET,
                 XmNmessageString,
                 Label, NULL );

  XmStringFree( Label );

  XvpnEnterDialog( &XvpnErrorDialog );

  autend();
}
