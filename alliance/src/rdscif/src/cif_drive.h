#ifndef __P
# if defined(__STDC__) ||  defined(__GNUC__)
#  define __P(x) x
# else
#  define __P(x) ()
# endif
#endif
/*------------------------------------------------------------\
|                                                             |
| Tool    :                    RDSCIF                         |
|                                                             |
| File    :                 cif_drive.h                       |
|                                                             |
| Authors :       Petrot Frederic & Jacomme Ludovic           |
|                   ---------                                 |
| Date    :    The king ^     04/07/93                        |
|                                                             |
\------------------------------------------------------------*/

# ifndef RDSCIF_DRIVE
# define RDSCIF_DRIVE

/*------------------------------------------------------------\
|                                                             |
|                           Constants                         |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                            Macro                            |
|                                                             |
\------------------------------------------------------------*/
/* See the comment in CifComputUnit for the 2 * CIF_UNIT here */
# define RDS_TO_CIF_UNIT( X )                                 \
                                                              \
   ( ( ( ( X ) * 2 * CIF_UNIT / RDS_UNIT) * CIF_DS_B ) / CIF_DS_A )

# define ABSOLUTE( X )                                        \
                                                              \
   ( ( ( X ) > 0 ) ? ( X ) : -( X )                           )

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

# endif