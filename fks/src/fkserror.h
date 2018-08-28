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
#ifndef __P
# if defined(__STDC__) ||  defined(__GNUC__)
#  define __P(x) x
# else
#  define __P(x) ()
# endif
#endif
/*------------------------------------------------------------\
|                                                             |
| Tool    :                     FSM                           |
|                                                             |
| File    :                  fkserror.c                       |
|                                                             |
| Author  :                 Jacomme Ludovic                   |
|                                                             |
| Date    :                   04.12.96                        |
|                                                             |
\------------------------------------------------------------*/

# ifndef FKS_ERROR_H
# define FKS_ERROR_H

# include <libgen.h>

/*------------------------------------------------------------\
|                                                             |
|                           Constants                         |
|                                                             |
\------------------------------------------------------------*/

# define KISS_ERROR_OPEN_FILE   0
# define KISS_ERROR_PARSE       1
# define KISS_ERROR_END         2
# define KISS_ERROR_VALUE       3
# define KISS_ERROR_NAME        4
# define KISS_ERROR_PORT        5
# define KISS_ERROR_STATE       6
# define KISS_ERROR_FSM_STACK   7

# define KISS_MAX_ERROR         8

/*------------------------------------------------------------\
|                                                             |
|                            Macro                            |
|                                                             |
\------------------------------------------------------------*/

# define fkserror( E, V ) (fks_error( (long)(E), (char *)(V), autbasename(__FILE__,NULL), __LINE__ ))

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

  extern           void  fks_error __P((char Error, char *Text, char *File, long Line));

# endif
