/* 
 * This file is part of the Alliance CAD System
 * Copyright (C) Laboratoire LIP6 - D�partement ASIM
 * Universite Pierre et Marie Curie
 * 
 * Home page          : http://www-asim.lip6.fr/alliance/
 * E-mail support     : mailto:alliance-support@asim.lip6.fr
 * 
 * This library is free software; you  can redistribute it and/or modify it
 * under the terms  of the GNU Library General Public  License as published
 * by the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * Alliance VLSI  CAD System  is distributed  in the hope  that it  will be
 * useful, but WITHOUT  ANY WARRANTY; without even the  implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General
 * Public License for more details.
 * 
 * You should have received a copy  of the GNU General Public License along
 * with the GNU C Library; see the  file COPYING. If not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
 
/******************************************************************************/
/*                                                                            */
/*                    CAO & VLSI's cad tools chain Alliance                   */
/*                                                                            */
/*     Product  : Standard Cell Placer                                        */
/*     File     : scp_time.c                                                  */
/*     Contents : timing gunctions                                            */
/*                                                                            */
/*     (c) Copyright 1992 Laboratoire MASI equipe CAO & VLSI                  */
/*     All rights reserved                                                    */
/*     Hot line  : cao-vlsi@masi.ibp.fr (e-mail)                              */
/*                                                                            */
/*     Author(s)   : Xavier Picat                       Date : 02/07/1993     */
/*                                                                            */
/******************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/times.h>
#include "scp_time.h"

#define HZ	50
/*---------------------------------------------------------\
					Les variables locales
\---------------------------------------------------------*/
static struct tms start_time;

/*---------------------------------------------------------\
					set_time
\---------------------------------------------------------*/
void set_time ()
{
	times (&start_time);
} /* fin de set_time */

/*---------------------------------------------------------\
					get_time
\---------------------------------------------------------*/
float get_time ()
{
	struct tms end_time;

	times (&end_time);
	return ((float) (end_time.tms_utime - start_time.tms_utime)/(float) HZ
	      + (float) (end_time.tms_stime - start_time.tms_stime)/(float) HZ);
} /* fin de get_time */
