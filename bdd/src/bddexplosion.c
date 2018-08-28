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
| Tool    :                     Bdd                           |
|                                                             |
| File    :                   bddexplosion.c                  |
|                                                             |
| Date    :                   03.12.96                        |
|                                                             |
| Author  :               Jacomme Ludovic                     |
| Modif   : Arnaud Caron - 16 Oct 1998                        |
|           Suppression des bddvartrees.                      |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                         Include Files                       |
|                                                             |
\------------------------------------------------------------*/

# include "mut.h"
# include "aut.h"
# include "abl.h"
# include "bdd.h"

# include <stdio.h>
# include "bddexplosion.h"
# include "bdderror.h"

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
|                   explosion Bdd System Restart              |
|                                                             |
\------------------------------------------------------------*/

void explosionbddsystemrestart( BddSystem )

  bddsystem *BddSystem;
{
  setbddlocalsystem( BddSystem );

  BddLocalSystem->HASH_OPER->TABLE_FREEZE = 0;
  ClearBddSystemExplosion( BddLocalSystem );
}

/*------------------------------------------------------------\
|                                                             |
|                   explosion Bdd System Dynamic              |
|                                                             |
\------------------------------------------------------------*/

void explosionbddsystemdynamic( BddSystem, ExplosionFunc, ExplosionLimit )

  bddsystem *BddSystem;
  void     (*ExplosionFunc)();
  long       ExplosionLimit;
{
  setbddlocalsystem( BddSystem );

  if ( ExplosionLimit <= 0 )
  {
    ClearBddSystemExplosionOn( BddLocalSystem );
  }
  else
  {
    SetBddSystemExplosionOn( BddLocalSystem );

    BddLocalSystem->EXPLOSION_FUNC    = ExplosionFunc;
    BddLocalSystem->EXPLOSION_LIMIT   = ExplosionLimit;
  }

  ClearBddSystemExplosion( BddLocalSystem );
}
