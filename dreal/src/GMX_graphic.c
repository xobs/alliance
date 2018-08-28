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
| File    :                 Graphic.c                         |
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
# include <Xm/Form.h>
# include <Xm/Frame.h>
# include <Xm/DrawingA.h>
 
# include "mut.h"
# include "mph.h"
# include "rds.h"
# include "rpr.h"
# include "GSB.h"
# include "GTB.h"
# include "GMX.h"

# include "GMX_graphic.h"
# include "GMX_view.h"
# include "GMX_grid.h"

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

  Widget   DrealGraphicFrame;
  Widget   DrealGraphicWindow;
  Display *DrealGraphicDisplay = (Display *)NULL;

  Dimension  DrealGraphicDx    = 0;
  Dimension  DrealGraphicDy    = 0;
  Dimension  DrealOldGraphicDx = 0;
  Dimension  DrealOldGraphicDy = 0;

  Pixmap     DrealGraphicPixmap   = (Pixmap)NULL;

/*------------------------------------------------------------\
|                                                             |
|                           Functions                         |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                 DrealInitializeGraphicWindow                |
|                                                             |
\------------------------------------------------------------*/

void DrealInitializeGraphicWindow()
 
{
  rdsbegin();

  XtVaGetValues( DrealGraphicWindow,
                 XmNwidth, &DrealGraphicDx,
                 XmNheight, &DrealGraphicDy,
                 NULL
               );

  DrealOldGraphicDx = DrealGraphicDx;
  DrealOldGraphicDy = DrealGraphicDy;

  DrealGraphicPixmap =

     XCreatePixmap ( DrealGraphicDisplay,
                     RootWindowOfScreen( XtScreen ( DrealGraphicWindow ) ),
                     DrealGraphicDx,
                     DrealGraphicDy,
                     DefaultDepthOfScreen ( XtScreen ( DrealGraphicWindow ) )
                   );

  DrealClearGraphicWindow( 0, 0, DrealGraphicDx, DrealGraphicDy );
  DrealInitializeLambdaGrid();

  DrealSetMouseCursor( DrealGraphicWindow, DREAL_NORMAL_CURSOR );

  rdsend();
}

/*------------------------------------------------------------\
|                                                             |
|                     DrealClearGraphicWindow                 |
|                                                             |
\------------------------------------------------------------*/

void DrealClearGraphicWindow( GraphicX, GraphicY, GraphicDx, GraphicDy )

   long GraphicX;
   long GraphicY;
   long GraphicDx;
   long GraphicDy;
{
  XFillRectangle( DrealGraphicDisplay,
                  DrealGraphicPixmap,
                  DrealBackgroundGC, 
                  GraphicX, GraphicY,
                  GraphicDx,
                  GraphicDy );
}

/*------------------------------------------------------------\
|                                                             |
|                     DrealRefreshGraphicWindow               |
|                                                             |
\------------------------------------------------------------*/

void DrealRefreshGraphicWindow( GraphicX, GraphicY, GraphicDx, GraphicDy )

   Dimension GraphicX;
   Dimension GraphicY;
   Dimension GraphicDx;
   Dimension GraphicDy;
{
  rdsbegin();

  DrealUndisplayCursor();

  XCopyArea( DrealGraphicDisplay,
             DrealGraphicPixmap,
             XtWindow ( DrealGraphicWindow ),
             DrealBackgroundGC,
             GraphicX, GraphicY,
             GraphicDx, GraphicDy,
             GraphicX, GraphicY 
           ); 

  DrealDisplayLambdaGrid( GraphicX, GraphicY, 
                          GraphicX + GraphicDx, 
                          GraphicY + GraphicDy );
  DrealUndisplayCursor();

  rdsend();
}


/*------------------------------------------------------------\
|                                                             |
|                     DrealResizeGraphicWindow                |
|                                                             |
\------------------------------------------------------------*/

void DrealResizeGraphicWindow()

{
  Pixmap    OldPixmap;
  Dimension SourceY;
  Dimension TargetY;
  Dimension TargetDx;
  Dimension TargetDy;

  rdsbegin();

  DrealOldGraphicDx = DrealGraphicDx;
  DrealOldGraphicDy = DrealGraphicDy;

  XtVaGetValues( DrealGraphicWindow,
                 XmNwidth, &DrealGraphicDx,
                 XmNheight, &DrealGraphicDy,
                 NULL
               );   

  if ( ( DrealOldGraphicDx != DrealGraphicDx ) ||
       ( DrealOldGraphicDy != DrealGraphicDy ) )
  {
    OldPixmap = DrealGraphicPixmap;

    DrealGraphicPixmap = 

      XCreatePixmap ( DrealGraphicDisplay,
                      RootWindowOfScreen( XtScreen ( DrealGraphicWindow ) ),
                      DrealGraphicDx,
                      DrealGraphicDy,
                      DefaultDepthOfScreen ( XtScreen ( DrealGraphicWindow ) )
                    );

    DrealClearGraphicWindow( 0, 0, DrealGraphicDx, DrealGraphicDy );

    DrealResizeLambdaGrid();

    if ( DrealOldGraphicDx < DrealGraphicDx )
    {
      TargetDx = DrealOldGraphicDx;

      DrealDisplayFigure( TargetDx, 0, 
                          DrealGraphicDx, DrealGraphicDy );
    }
    else
    {
      TargetDx = DrealGraphicDx;
    }
    
    if ( DrealOldGraphicDy < DrealGraphicDy )
    {
      SourceY  = 0;
      TargetDy = DrealOldGraphicDy;
      TargetY  = DrealGraphicDy - DrealOldGraphicDy;

      DrealDisplayFigure( 0, TargetDy, 
                          TargetDx, DrealGraphicDy ); 
    }
    else
    {
      TargetDy = DrealGraphicDy;
      TargetY  = 0;
      SourceY  = DrealOldGraphicDy - DrealGraphicDy;
    }

    XCopyArea( DrealGraphicDisplay,
               OldPixmap,
               DrealGraphicPixmap,
               DrealBackgroundGC,
               0, SourceY,
               TargetDx, TargetDy, 
               0, TargetY
             );

    XFreePixmap( DrealGraphicDisplay, OldPixmap );
  }

  rdsend();
}

/*------------------------------------------------------------\
|                                                             |
|                    DrealInitializeGraphic                   |
|                                                             |
\------------------------------------------------------------*/

void DrealInitializeGraphic()

{
  rdsbegin();

  DrealGraphicFrame = XtVaCreateManagedWidget( "DrealGraphicFrame",
                                               xmFrameWidgetClass,
                                               DrealMainForm,
                                               XmNshadowType       , XmSHADOW_ETCHED_IN,
                                               XmNtopAttachment    , XmATTACH_POSITION,
                                               XmNtopPosition      , 1,
                                               XmNbottomAttachment , XmATTACH_POSITION,
                                               XmNbottomPosition   , 191,
                                               XmNleftAttachment   , XmATTACH_POSITION,
                                               XmNleftPosition     , 1,
                                               XmNrightAttachment  , XmATTACH_POSITION,
                                               XmNrightPosition    , 199,
                                               NULL );

  DrealGraphicWindow = XtVaCreateManagedWidget(
                                                "DrealGraphicWindow",
                                                xmDrawingAreaWidgetClass,
                                                DrealGraphicFrame,
                                                XmNtopAttachment,    XmATTACH_FORM,
                                                XmNrightAttachment,  XmATTACH_FORM,
                                                XmNbottomAttachment, XmATTACH_FORM,
                                                XmNleftAttachment,   XmATTACH_FORM,
                                                XmNbackground,       1,
                                                XmNforeground,       0,
                                                NULL
                                             );
  DrealGraphicDisplay = XtDisplay( DrealGraphicWindow );

  rdsend();
}
