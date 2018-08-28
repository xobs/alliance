/*------------------------------------------------------------\
|                                                             |
| This file is part of the Alliance CAD System Copyright      |
| (C) Laboratoire LIP6 - D�partement ASIM Universite P&M Curie|
|                                                             |
| Home page      : http://www-asim.lip6.fr/alliance/          |
| E-mail         : mailto:alliance-users@asim.lip6.fr       |
|                                                             |
| This progam is  free software; you can redistribute it      |
| and/or modify it under the  terms of the GNU Library General|
| Public License as published by the Free Software Foundation |
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
| Tool    :                     Ctl                           |
|                                                             |
| File    :                 Ctl Errors                        |
|                                                             |
| Ctlhors :                Jacomme Ludovic                    |
|                                                             |
| Date    :                   04.07.96                        |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                         Include Files                       |
|                                                             |
\------------------------------------------------------------*/

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include "mut.h"
# include "aut.h"
# include "vex.h"
# include "ctl.h"
# include "ctlerror.h"

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
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                         Ctl Error Function                  |
|                                                             |
\------------------------------------------------------------*/

void ctl_error( Error, Text1, Text2, File, Line )

  int   Error;
  char *Text1;
  char *Text2;
  char *File;
  long  Line;
{
  char *Name;

  Name = mbkstrdup( File );
  Name[ strlen( File ) - 1 ] = '\0';

  fprintf( stderr, "%s%ld ", Name, Line );

  switch( Error )
  {
    case CTL_UNKNOWN_DECLAR_TYPE :
      fprintf( stderr, "unknown declar type %ld for %s\n", (long)Text1, Text2 );
    break;
    case CTL_DECLAR_EXIST_ERROR   :
      fprintf( stderr, "symbol %s already declared\n", Text1 );
    break;
    case CTL_BAD_DECLAR_TYPE   :
      fprintf( stderr, "bad declaration type %ld\n", (long)Text1 );
    break;
    case CTL_UNDECLARED_SYMBOL   :
      fprintf( stderr, "undeclared symbol %s\n", Text1 );
    break;
    case CTL_ILLEGAL_POSITION_ERROR :
      fprintf( stderr, "illegal position for symbol %s %ld\n", Text1, (long)Text2 );
    break;
    case CTL_ILLEGAL_INDEX_ERROR :
      fprintf( stderr, "illegal index for symbol %s %ld\n", Text1, (long)Text2 );
    break;
    default :

      fprintf( stderr, "unknown internal error %d !\n", Error );
  }

  autexit( 1 );
}

/*------------------------------------------------------------\
|                                                             |
|                         Ctl Warning Function                |
|                                                             |
\------------------------------------------------------------*/

void ctl_warning( Warning, Text1, Text2, File, Line )

  int   Warning;
  char *Text1;
  char *Text2;
  char *File;
  long  Line;
{
  char *Name;

  Name = mbkstrdup( File );
  Name[ strlen( File ) - 1 ] = '\0';

  fprintf( stderr, "%s%ld ", Name, Line );

  switch ( Warning )
  {
    default :

      fprintf( stderr, "unknown internal warning %d !\n", Warning );
  }
}
