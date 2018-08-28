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
| File    :                   bddflag.c                       |
|                                                             |
| Date    :                   03.12.96                        |
|                                                             |
| Author  :               Jacomme Ludovic                     |
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
# include "bddflag.h"
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

  static bddflag BddFlagMask       = 0;
  static long    BddFlagNumberNode = 0;

/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                    Local Flag Bdd Node                      |
|                                                             |
\------------------------------------------------------------*/

static void loc_flagbdd( BddNode )

  bddnode *BddNode;
{
  if ( BddNode->INDEX >= BDD_INDEX_MIN )
  {
    if ( ! ( BddNode->FLAG & BddFlagMask ) )
    {
      BddNode->FLAG |= BddFlagMask;
      BddFlagNumberNode++;

      loc_flagbdd( BddNode->LOW  );
      loc_flagbdd( BddNode->HIGH );
    }
  }
}

/*------------------------------------------------------------\
|                                                             |
|                        Bdd Unflag Node                      |
|                                                             |
\------------------------------------------------------------*/

static void loc_unflagbdd( BddNode )

  bddnode *BddNode;
{
  if ( BddNode->INDEX >= BDD_INDEX_MIN )
  {
    if ( BddNode->FLAG & BddFlagMask )
    {
      BddNode->FLAG &= ~BddFlagMask;
      BddFlagNumberNode++;

      loc_unflagbdd( BddNode->LOW  );
      loc_unflagbdd( BddNode->HIGH );
    }
  }
}

/*------------------------------------------------------------\
|                                                             |
|                        Bdd Flag Node                        |
|                                                             |
\------------------------------------------------------------*/

long flagbddnode( BddSystem, BddNode, Flag )

  bddsystem *BddSystem;
  bddnode   *BddNode;
  bddflag    Flag;
{
  setbddlocalsystem( BddSystem );

  BddFlagMask       = Flag;
  BddFlagNumberNode = 0;

  loc_flagbdd( BddNode );

  return( BddFlagNumberNode );
}

/*------------------------------------------------------------\
|                                                             |
|                        Bdd Flag Node                        |
|                                                             |
\------------------------------------------------------------*/

long unflagbddnode( BddSystem, BddNode, Flag )

  bddsystem *BddSystem;
  bddnode   *BddNode;
  bddflag    Flag;
{
  setbddlocalsystem( BddSystem );

  BddFlagMask       = Flag;
  BddFlagNumberNode = 0;

  loc_unflagbdd( BddNode );

  return( BddFlagNumberNode );
}

/*------------------------------------------------------------\
|                                                             |
|                         Get Node Size                       |
|                                                             |
\------------------------------------------------------------*/

static void loc_getbddsize( BddNode )

  bddnode *BddNode;
{
  if ( BddNode->INDEX >= BDD_INDEX_MIN )
  {
    BddFlagNumberNode++;

    loc_getbddsize( BddNode->LOW  );
    loc_getbddsize( BddNode->HIGH );
  }
}


/*------------------------------------------------------------\
|                                                             |
|                         Get Bdd Node Num                    |
|                                                             |
\------------------------------------------------------------*/

long getbddnodenum( BddSystem, BddNode )

  bddsystem *BddSystem;
  bddnode   *BddNode;
{
  long NumberNode;

  NumberNode = flagbddnode( BddSystem, BddNode, BDD_FLAG_NUM_MASK );
  unflagbddnode( BddSystem, BddNode, BDD_FLAG_NUM_MASK );

  return( NumberNode );
}

/*------------------------------------------------------------\
|                                                             |
|                         Get Bdd Node Size                   |
|                                                             |
\------------------------------------------------------------*/

long getbddnodesize( BddSystem, BddNode )

  bddsystem *BddSystem;
  bddnode   *BddNode;
{
  setbddlocalsystem( BddSystem );

  BddFlagNumberNode = 0;
  loc_getbddsize( BddNode );

  return( BddFlagNumberNode );
}
