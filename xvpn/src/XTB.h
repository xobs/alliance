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
| File    :                   XTB.h                           |
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
/*------------------------------------------------------------\
|                                                             |
|                           Constants                         |
|                                                             |
\------------------------------------------------------------*/

# ifndef XVPN_XTB
# define XVPN_XTB

/*------------------------------------------------------------\
|                                                             |
|                        MouseCursors                         |
|                                                             |
\------------------------------------------------------------*/

# define XVPN_NORMAL_CURSOR     0
# define XVPN_WATCH_CURSOR      1
# define XVPN_PIRATE_CURSOR     2 
# define XVPN_CROSS_CURSOR      3 
# define XVPN_NO_CURSOR         4

# define XVPN_MAX_CURSOR        5

/*------------------------------------------------------------\
|                                                             |
|                        DialogBoxType                        |
|                                                             |
\------------------------------------------------------------*/

# define XVPN_DIALOG_MESSAGE   0
# define XVPN_DIALOG_ERROR     1
# define XVPN_DIALOG_INFO      2
# define XVPN_DIALOG_QUESTION  3
# define XVPN_DIALOG_WARNING   4
# define XVPN_DIALOG_WORKING   5
# define XVPN_DIALOG_FILE      6
# define XVPN_DIALOG_PROMPT    7
 
/*------------------------------------------------------------\
|                                                             |
|                            Types                            |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                         XvpnDialogBox                       |
|                                                             |
\------------------------------------------------------------*/

  typedef struct XvpnDialogItem

  {
    char       *LABEL;
    short       TYPE;
    Widget      WIDGET;
    void        (*CALLBACK_OK)(); 
    XtPointer   CALLDATA_OK;
    void        (*CALLBACK_CANCEL)(); 
    XtPointer   CALLDATA_CANCEL;

  } XvpnDialogItem;

  
/*------------------------------------------------------------\
|                                                             |
|                         XvpnMenuItem                       |
|                                                             |
\------------------------------------------------------------*/

  typedef struct XvpnMenuItem

  {
    char                 *LABEL;
    short                 MNEMONIC; 
    char                 *SHORT_KEY;
    char                 *SHORT_KEY_TEXT;
    WidgetClass          *CLASS; 
    Boolean               SEPARATOR; 
    Boolean               TITLE;  
    Boolean               HELP;
    void                  (*CALLBACK)(); 
    XtPointer             CALLDATA;
    Widget                BUTTON;
    Widget                MENU;
    struct XvpnMenuItem *NEXT;

  } XvpnMenuItem;

/*------------------------------------------------------------\
|                                                             |
|                      XvpnPanelButtonItem                   |
|                                                             |
\------------------------------------------------------------*/

  typedef struct XvpnPanelButtonItem 

  {
    char                       **LABEL;
    char                        *TEXT;
    char                        *BITMAP;
    int                          WIDTH;
    int                          HEIGHT;
    char                       **FOREGROUND;
    char                       **BACKGROUND;
    unsigned short               X;
    unsigned short               Y;
    unsigned short               DX;
    unsigned short               DY;
    void                         (*CALLBACK)(); 
    XtPointer                    CALLDATA;
    Widget                       BUTTON;

  } XvpnPanelButtonItem;

/*------------------------------------------------------------\
|                                                             |
|                          XvpnPanelItem                      |
|                                                             |
\------------------------------------------------------------*/

  typedef struct XvpnPanelItem

  {
    char                  *TITLE;
    short                  COMPUTE;
    short                  MANAGED;
    int                    X;
    int                    Y;
    int                    WIDTH;
    int                    HEIGHT;
    unsigned short         COLUMN;
    unsigned short         ROW;
    Widget                 PANEL;
    Widget                 PANEL_FORM;
    Widget                 FRAME;
    Widget                 FORM;
    XvpnPanelButtonItem  *LIST; 

  } XvpnPanelItem;

/*------------------------------------------------------------\
|                                                             |
|                          Variables                          |
|                                                             |
\------------------------------------------------------------*/

 extern char *XvpnPanelButtonDisable;

/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/

  extern void   XvpnDestroyDialogCallback();
  extern void   XvpnExitDialogCallback();

  extern void   XvpnSetMouseCursor();
  extern Pixmap XvpnCreatePixmap();
  extern void   XvpnSetIcon();
  extern void   XvpnBuildMenus();
  extern void   XvpnBuildPanel();
  extern void   XvpnEnterPanel();
  extern void   XvpnExitPanel();
  extern void   XvpnBuildDialog();
  extern void   XvpnEnterDialog();
  extern void   XvpnReEnterDialog();
  extern void   XvpnExitDialog();
  extern void   XvpnWarningMessage();
  extern void   XvpnErrorMessage();
  extern void   XvpnLimitedLoop();

# endif
