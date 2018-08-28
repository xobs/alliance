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
| Tool    :                     K2F                           |
|                                                             |
| File    :                  k2f_error.c                      |
|                                                             |
| Authors :                Jacomme Ludovic                    |
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
# include "mut.h"
# include "aut.h"
# include "k2f_error.h"

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
|                      Private variables                      |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                       K2fDisplayError                       |
|                                                             |
\------------------------------------------------------------*/

void K2fDisplayError( File, Line, Error, Text )

   char *File;
   int   Line;
   int   Error;
   char *Text;
{
  char *Name;

  Name = mbkstrdup( File );
  Name[ strlen( File ) - 1 ] = '\0';

  fprintf( stderr, "%s%d ", Name, Line );

  switch( Error )
  {
    default : fprintf( stderr, "Internal error number %d\n", Error );
  }

  autexit( 1 );
}

/*------------------------------------------------------------\
|                                                             |
|                       K2fDisplayWarning                     |
|                                                             |
\------------------------------------------------------------*/

void K2fDisplayWarning( File, Line, Warning, Text )

   char *File;
   int   Line;
   int   Warning;
   char *Text;
{
  char *Name;

  Name = mbkstrdup( File );
  Name[ strlen( File ) - 1 ] = '\0';

  fprintf( stderr, "%s%d ", Name, Line );

  switch ( Warning )
  {
    default : fprintf( stderr, "Internal warning number %d\n", Warning );
  }
}
