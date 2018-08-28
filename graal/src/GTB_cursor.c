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
| File    :                  cursor.c                         |
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
# include <X11/cursorfont.h>
# include <X11/Intrinsic.h>
# include <Xm/Xm.h>
# include "mut.h"
# include "rds.h"
# include "GTB.h"
# include "GTB_cursor.h"

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

  static GraalMouseCursor GraalMouseCursorArray [ GRAAL_MAX_CURSOR ] =

         {
           { XC_left_ptr      , True  },
           { XC_watch         , True  },
           { XC_pirate        , True  },
           { XC_cross_reverse , True  },
           { 0                , True  } 
         };

  static char  GraalCursorMaskOr [ 8 ] =

  {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };

  static char  GraalCursorMaskAnd [ 8 ] =

  {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
  };

/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                      GraalSetMouseCursor                    |
|                                                             |
\------------------------------------------------------------*/

void GraalSetMouseCursor( MainWidget, CursorType )

     Widget MainWidget;
     char   CursorType;
{
  Display          *DisplayId;
  Window            MainWindow;
  XColor            White;
  XColor            Black;
  XColor            ForgetIt;
  Colormap          ColorMap;
  Pixmap            MaskOr;
  Pixmap            MaskAnd;
  Cursor            Type;
  Cursor            NewCursor;

  rdsbegin();

  DisplayId  = XtDisplay( MainWidget );
  MainWindow = XtWindow( MainWidget  );

  Type = GraalMouseCursorArray[ (int)CursorType ].CURSOR;

  if ( GraalMouseCursorArray[ (int)CursorType ].MAKE == True )
  {
    if ( Type != 0 )
    {
      NewCursor = XCreateFontCursor( DisplayId, Type );
    }
    else
    {
      ColorMap = DefaultColormapOfScreen ( XtScreen( MainWidget ) );

      XAllocNamedColor( DisplayId, ColorMap, "black", &Black, &ForgetIt );
      XAllocNamedColor( DisplayId, ColorMap, "white", &White, &ForgetIt );

      MaskOr = 

        XCreatePixmapFromBitmapData( DisplayId,
                                     MainWindow,
                                     GraalCursorMaskOr,
                                     8, 8,
                                     Black.pixel,
                                     White.pixel, 1 );

      MaskAnd =

        XCreatePixmapFromBitmapData( DisplayId,
                                     MainWindow,
                                     GraalCursorMaskAnd,
                                     8, 8,
                                     Black.pixel,
                                     White.pixel, 1 );

      NewCursor = XCreatePixmapCursor( DisplayId, 
                                       MaskAnd, MaskOr,
                                       &Black, &White, 0, 0 );
    }

    GraalMouseCursorArray[ (int)CursorType ].CURSOR = NewCursor;
    GraalMouseCursorArray[ (int)CursorType ].MAKE   = False;

    Type = NewCursor;
  }

  XDefineCursor( DisplayId, MainWindow, Type );

  XmUpdateDisplay( MainWidget );

  rdsend();
}
