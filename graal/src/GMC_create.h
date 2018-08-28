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
| File    :                  Create.h                         |
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

# ifndef GRAAL_CREATE
# define GRAAL_CREATE

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
|                        Segment & Wire                       |
|                                                             |
\------------------------------------------------------------*/

  extern char  GraalSegmentLayer;
  extern float GraalSegmentWidth;
  extern char *GraalSegmentName;
  extern char  GraalSegmentWire;

/*------------------------------------------------------------\
|                                                             |
|                              Via                            |
|                                                             |
\------------------------------------------------------------*/

  extern char  GraalViaType;
  extern char *GraalViaName;

/*------------------------------------------------------------\
|                                                             |
|                           Big Via                           |
|                                                             |
\------------------------------------------------------------*/

  extern char  GraalBigViaType;
  extern char *GraalBigViaName;

/*------------------------------------------------------------\
|                                                             |
|                           Transistor                        |
|                                                             |
\------------------------------------------------------------*/

  extern char  GraalTransistorType;
  extern char *GraalTransistorName;
  extern float GraalTransistorWidth;
  extern char  GraalTransistorWire;

/*------------------------------------------------------------\
|                                                             |
|                           Connector                         |
|                                                             |
\------------------------------------------------------------*/

  extern char  GraalConnectorLayer; 
  extern float GraalConnectorWidth; 
  extern char *GraalConnectorName;  
  extern char  GraalConnectorOrient;

/*------------------------------------------------------------\
|                                                             |
|                           Reference                         |
|                                                             |
\------------------------------------------------------------*/

  extern char  GraalReferenceType;  
  extern char *GraalReferenceName;  

/*------------------------------------------------------------\
|                                                             |
|                           Instance                          |
|                                                             |
\------------------------------------------------------------*/

 extern char  GraalInstanceSym;
 extern char *GraalInstanceName;
 extern char *GraalInstanceModel;

/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/

# endif 
