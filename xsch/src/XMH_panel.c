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
| Tool    :                    XSCH                           |
|                                                             |
| File    :                  Panel.c                          |
|                                                             |
| Authors :              Jacomme Ludovic                      |
|                                                             |
| Date    :                   01.06.96                        |
|                                                             |
\------------------------------------------------------------*/

/*------------------------------------------------------------\
|                                                             |
|                         Include Files                       |
|                                                             |
\------------------------------------------------------------*/

# include <stdio.h>
# include <X11/Intrinsic.h>
# include <Xm/Xm.h>
# include <Xm/Frame.h>
# include <Xm/Form.h>
# include <Xm/List.h>
# include <Xm/Text.h>
# include <Xm/TextF.h>
# include <Xm/PushB.h>
# include <Xm/DialogS.h>
# include <Xm/Label.h>
# include <Xm/LabelG.h>
 
# include "mut.h"
# include "aut.h"
# include "mlo.h"
# include "XSB.h"
# include "XTB.h"
# include "XMX.h"
# include "XMH.h"

# include "XMH_panel.h" 
# include "LIP6bw.h" 

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

   XschPanelItem XschHelpPresentPanel =

         {
           "Xsch present",
           1,
           0,
           XSCH_HELP_PRESENT_X,
           XSCH_HELP_PRESENT_Y,
           700,
           360,
           0,
           0,
           (Widget)NULL,
           (Widget)NULL,
           (Widget)NULL,
           (Widget)NULL,
           (XschPanelButtonItem *)NULL
         };

   int XschHelpPresentDefaultValues[ 5 ] =

         {
           XSCH_HELP_PRESENT_X,
           XSCH_HELP_PRESENT_Y,
           700, 360, 0
         };

/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                    XschBuildPresentPanel                   |
|                                                             |
\------------------------------------------------------------*/

void XschBuildPresentPanel()

{
  Widget       PanelLabel;
  Widget       PanelButton;
  Pixmap       PanelPixmap;
  XmString     PanelString;
  XmString     PanelString1;
  XmString     PanelString2;
  XmFontList   PanelFontList;
  XFontStruct *PanelFont;
  Display     *PanelDisplay;
  char         Buffer[ 64 ];
  Arg          Args[3];

  autbegin();
  
  PanelDisplay  = XtDisplay( XschMainWindow );
  PanelFont     = XLoadQueryFont( PanelDisplay, "-*-helvetica-bold-o-*--24-*" );
  PanelFontList = XmFontListCreate( PanelFont, "Panel_charset1" );
  PanelFont     = XLoadQueryFont( PanelDisplay, "-*-helvetica-bold-r-*--18-*" );
  PanelFontList = XmFontListAdd( PanelFontList, PanelFont, "Panel_charset2" );
  PanelFont     = XLoadQueryFont( PanelDisplay, "-*-helvetica-bold-r-*--12-*" );
  PanelFontList = XmFontListAdd( PanelFontList, PanelFont, "Panel_charset4" );

  XtSetArg( Args[0], XmNshadowType    , XmSHADOW_ETCHED_IN );
  XtSetArg( Args[1], XmNdeleteResponse, XmDO_NOTHING       );
  XtSetArg( Args[2], XmNtitle         , "Xsch present"    );

  XschHelpPresentPanel.PANEL = 

    XmCreateFormDialog( XschMainWindow, XschHelpPresentPanel.TITLE, Args, 3);

  XtAddCallback( XschHelpPresentPanel.PANEL, XmNdestroyCallback,
                 XschDestroyDialogCallback, NULL );

  XschHelpPresentPanel.PANEL_FORM = 

     XtVaCreateManagedWidget( "",
                              xmFormWidgetClass,
                              XschHelpPresentPanel.PANEL,
                              XmNtopAttachment    , XmATTACH_FORM,
                              XmNbottomAttachment , XmATTACH_FORM,
                              XmNleftAttachment   , XmATTACH_FORM,
                              XmNrightAttachment  , XmATTACH_FORM,
                              NULL
                            );

  XschHelpPresentPanel.FRAME = 

     XtVaCreateManagedWidget( "",
                              xmFrameWidgetClass,
                              XschHelpPresentPanel.PANEL_FORM,
                              XmNtopAttachment   , XmATTACH_POSITION,
                              XmNtopPosition     , 05,
                              XmNbottomAttachment, XmATTACH_POSITION,
                              XmNbottomPosition  , 95,
                              XmNleftAttachment  , XmATTACH_POSITION,
                              XmNleftPosition    , 05,
                              XmNrightAttachment , XmATTACH_POSITION,
                              XmNrightPosition   , 95,
                              NULL
                            );

  XschHelpPresentPanel.FORM = 

    XtVaCreateManagedWidget( "",
                             xmFormWidgetClass,
                             XschHelpPresentPanel.FRAME,
                             XmNtopAttachment   , XmATTACH_POSITION,
                             XmNtopPosition     , 05,
                             XmNbottomAttachment, XmATTACH_POSITION,
                             XmNbottomPosition  , 95,
                             XmNleftAttachment  , XmATTACH_POSITION,
                             XmNleftPosition    , 05,
                             XmNrightAttachment , XmATTACH_POSITION,
                             XmNrightPosition   , 95,
                             NULL
                           );

  PanelPixmap = XschCreatePixmap( XschMainWindow,
                                  LIP6bw_bits,
                                  LIP6bw_width,
                                  LIP6bw_height);

  PanelLabel = XtVaCreateManagedWidget( "",
                                        xmLabelGadgetClass, 
                                        XschHelpPresentPanel.FORM,
                                        XmNlabelType   , XmPIXMAP,
                                        XmNlabelPixmap , PanelPixmap,
                                        NULL
                                      );

  sprintf( Buffer, "ALLIANCE CAD SYSTEM  %s\n", ALLIANCE_VERSION );

  PanelString = XmStringCreateLtoR( Buffer, "Panel_charset2" );

  PanelLabel = XtVaCreateManagedWidget( "",
                                        xmLabelWidgetClass,
                                        XschHelpPresentPanel.FORM,
                                        XmNfontList        , PanelFontList,
                                        XmNlabelString     , PanelString,
                                        XmNtopAttachment   , XmATTACH_POSITION,
                                        XmNtopPosition     , 15,
                                        XmNrightAttachment , XmATTACH_POSITION,
                                        XmNrightPosition   , 75,
                                        XmNleftAttachment  , XmATTACH_POSITION,
                                        XmNleftPosition    , 25,
                                        NULL
                                      );
  XmStringFree( PanelString );

  PanelString1 = XmStringCreateLtoR( "Xsch"         , "Panel_charset1" );
  PanelString2 = XmStringCreateLtoR( "\n( Touch Me )", "Panel_charset4" );
  PanelString  = XmStringConcat( PanelString1, PanelString2 );

  PanelButton = XtVaCreateManagedWidget( "",
                                          xmPushButtonWidgetClass, 
                                          XschHelpPresentPanel.FORM,
                                          XmNfontList        , PanelFontList,
                                          XmNlabelString     , PanelString,
                                          XmNshadowThickness , 3,
                                          XmNtopAttachment   , XmATTACH_WIDGET,
                                          XmNtopWidget       , PanelLabel,
                                          XmNtopOffset       , 5,
                                          XmNrightAttachment , XmATTACH_POSITION,
                                          XmNrightPosition   , 60,
                                          XmNleftAttachment  , XmATTACH_POSITION,
                                          XmNleftPosition    , 40,
                                          NULL
                                        );
  XmStringFree( PanelString  );
  XmStringFree( PanelString1 );
  XmStringFree( PanelString2 );

  XtAddCallback( PanelButton, 
                 XmNactivateCallback,
                 XschExitDialogCallback, NULL );

  sprintf( Buffer, "\nGraphic Schematic Viewer\nVersion %s", VERSION );

  PanelString = XmStringCreateLtoR( Buffer, "Panel_charset2" );

  PanelLabel = XtVaCreateManagedWidget( "",
                                         xmLabelWidgetClass,
                                         XschHelpPresentPanel.FORM,
                                         XmNfontList        , PanelFontList,
                                         XmNlabelString     , PanelString,
                                         XmNtopAttachment   , XmATTACH_WIDGET,
                                         XmNtopWidget       , PanelButton,
                                         XmNtopOffset       , 5,
                                         XmNrightAttachment , XmATTACH_POSITION,
                                         XmNrightPosition   , 75,
                                         XmNleftAttachment  , XmATTACH_POSITION,
                                         XmNleftPosition    , 25,
                                         NULL
                                       );
  XmStringFree( PanelString );

  PanelString = XmStringCreateLtoR( "copyright \251 1996-2004 ASIM, \
CAO-VLSI Team\nWritten by Ludovic Jacomme\nE-mail        :  alliance-users@asim.lip6.fr", "Panel_charset4" );

  PanelLabel = XtVaCreateManagedWidget( "",
                                         xmLabelWidgetClass,
                                         XschHelpPresentPanel.FORM,
                                         XmNfontList        , PanelFontList,
                                         XmNlabelString     , PanelString,
                                         XmNtopAttachment   , XmATTACH_WIDGET,
                                         XmNtopWidget       , PanelLabel,
                                         XmNtopOffset       , 5,
                                         XmNrightAttachment , XmATTACH_FORM,
                                         XmNleftAttachment  , XmATTACH_FORM,
                                         NULL
                                       );
  XmStringFree( PanelString );

  autend();
}

/*------------------------------------------------------------\
|                                                             |
|                    XschEnterPresentPanel                   |
|                                                             |
\------------------------------------------------------------*/

void XschEnterPresentPanel()

{
  autbegin();

  XschEnterPanel( &XschHelpPresentPanel );

  XschLimitedLoop( XschHelpPresentPanel.PANEL );

  XschExitPanel( &XschHelpPresentPanel );

  autend();
}
