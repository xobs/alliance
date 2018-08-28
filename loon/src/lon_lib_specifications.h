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
 * Tool    : LooN - cell properties
 * Date    : 2000
 * Author  : Francois Donnet
 */




#ifndef LIB_SPECIFICATIONS_H
#define LIB_SPECIFICATIONS_H

#ifndef __P
# ifdef __STDC__ || __GNUC__
#  define __P(x) x
# else
#  define __P(x) ()
# endif
#endif


/******************************************************************************/
/*                      return the area cell in lambda� size                  */
/******************************************************************************/
extern int getgenericarea __P ((befig_list* befig));

/******************************************************************************/
/*                         set the area cell in lamda� size                   */
/******************************************************************************/
extern void putgenericarea __P ((befig_list* befig, int value));

/******************************************************************************/
/*             return the setup Time of an entry in pico second (exp-12)      */
/******************************************************************************/
extern double getgenericT __P ((befig_list* befig, char* name));

/******************************************************************************/
/*             return the setup in high value of an entry in pico second      */
/******************************************************************************/
extern double getgenericTh __P ((befig_list* befig, char* name));

/******************************************************************************/
/*             return the setup in low value of an entry in pico second       */
/******************************************************************************/
extern double getgenericTl __P ((befig_list* befig, char* name));

/******************************************************************************/
/*                set the setup Times of an entry in pico second  (exp-12)    */
/******************************************************************************/
extern void putgenericT __P ((befig_list* befig, char* name, double Thl_value, double Tll_value, double Tlh_value, double Thh_value));

/******************************************************************************/
/*             return the Capacitance of an entry in pico Farad (exp-12)      */
/******************************************************************************/
extern double getgenericC __P ((befig_list* befig, char* name));

/******************************************************************************/
/*                set the Capacitance of an entry in pico Farad               */
/******************************************************************************/
extern void putgenericC __P ((befig_list* befig, char* name, double C_value));

/******************************************************************************/
/*return the average of Resistivity in Ohm of path from input to output cell  */
/******************************************************************************/
extern int getgenericR __P ((befig_list* befig, char* name));

/******************************************************************************/
/*return the Rup in Ohm of path from input to output cell                     */
/******************************************************************************/
extern int getgenericRup __P ((befig_list* befig, char* name));

/******************************************************************************/
/*return the Rdown in Ohm of path from input to output cell                   */
/******************************************************************************/
extern int getgenericRdown __P ((befig_list* befig, char* name));

/******************************************************************************/
/*         set Resistivity in Ohm of path from input to output cell           */
/******************************************************************************/
extern void putgenericR __P ((befig_list* befig, char* name, double Rup_value, double Rdown_value));

/******************************************************************************/
/*         return the average of Capacitance of all inputs in pico Farad      */
/******************************************************************************/
extern int getaverageC __P ((befig_list* befig));

/******************************************************************************/
/*  Y a t- il eu une erreur                                                   */
/******************************************************************************/
extern int IsLibError __P(());

/******************************************************************************/
/*  initialiser la detection d'erreur                                         */
/******************************************************************************/
extern void InitLibError __P(());



#endif
