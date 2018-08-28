/*
 * This file is part of the Alliance CAD System
 * Copyright (C) Laboratoire LIP6 - D�partement ASIM
 * Universite Pierre et Marie Curie
 *
 * Home page          : http://www-asim.lip6.fr/alliance/
 * E-mail             : mailto:alliance-users@asim.lip6.fr
 *
 * This progam is  free software; you can redistribute it  and/or modify it
 * under the  terms of the GNU  General Public License as  published by the
 * Free Software Foundation;  either version 2 of the License,  or (at your
 * option) any later version.
 *
 * Alliance VLSI  CAD System  is distributed  in the hope  that it  will be
 * useful, but WITHOUT  ANY WARRANTY; without even the  implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 *
 * You should have received a copy  of the GNU General Public License along
 * with the GNU C Library; see the  file COPYING. If not, write to the Free
 * Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/*
 * Tool    : LooN - critical path
 * Date    : 2000
 * Author  : Francois Donnet
 */




#ifndef SIGNAL_CRITICAL_H
#define SIGNAL_CRITICAL_H

#ifndef __P
# ifdef __STDC__ || __GNUC__
#  define __P(x) x
# else
#  define __P(x) ()
# endif
#endif

/***************************************************************************/
/*return the signal with the highest delay                                 */
/***************************************************************************/
extern losig_list* critical_output __P ((lofig_list* lofig));

/***************************************************************************/
/* cost function for lofig                                                 */
/***************************************************************************/
extern double critical_delay __P ((lofig_list* lofig));

/***************************************************************************/
/*return the list of losig with delays which are composing critical path   */
/***************************************************************************/
extern ptype_list* critical_path __P ((lofig_list* lofig));

/***************************************************************************/
/*return the list of losig with delays which are composing critical path   */
/*path do not continue on clock if a flip-flop is met                      */
/***************************************************************************/
extern ptype_list* critical_path_without_clock __P ((lofig_list* lofig));


#endif
