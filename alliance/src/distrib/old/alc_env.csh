# -*- Mode: Shell-script     -*- 
# -*- vim: set filetype=csh: -*-
#             ,,,
#            (o o)
####=====oOO--(_)--OOO=========================================####
#
#  Alliance CAD system environnement
#  Usage (in C-shell) : > source alc_env.csh
#  (C) 1997 Czo  -- <Olivier.Sirol@lip6.fr>
#  $Id: alc_env.csh,v 1.1 2002/04/29 14:15:27 czo Exp $
#  Generated from alc_env.csh.in on Wed Feb 27 11:25:31 CET 2002

# $ALLIANCE_OS and $ALLIANCE_TOP are the only variables you will
# have to modify if something goes wrong

# Which platform for Alliance CAD

# WARNING : if changing this remember to do it on the 3 config files :
# configure.in alc_env.sh.in and alc_env.csh.in

switch (`uname`)
 case Linux*:
  if ( `uname -r` =~ 1.* ) then
      setenv ALLIANCE_OS Linux_aout
  else
   if ( `uname -r` =~ 2.0* ) then
      setenv ALLIANCE_OS Linux_elf
   else
      setenv ALLIANCE_OS Linux
   endif
  endif
 breaksw

 case SunOS*:
  if ( `uname -r` =~ 5* ) then
      setenv ALLIANCE_OS Solaris
  else
      setenv ALLIANCE_OS SunOS
  endif
 breaksw

 case FreeBSD*:
      setenv ALLIANCE_OS FreeBSD
 breaksw

 case NetBSD*:
      setenv ALLIANCE_OS NetBSD
 breaksw

 case HP-UX*:
      setenv ALLIANCE_OS HPUX
 breaksw

 case OSF1*:
      setenv ALLIANCE_OS OSF
 breaksw

 case CYGWIN*:
      setenv ALLIANCE_OS Cygwin
 breaksw

default:
  setenv ALLIANCE_OS Unknown
 breaksw
endsw

# Where the Alliance CAD is installed

setenv ALLIANCE_TOP /users/soft5/newlabo/alliance-4.9.4/archi/$ALLIANCE_OS

# User def 

setenv MBK_IN_LO         vst
setenv MBK_OUT_LO        vst
setenv MBK_IN_PH         ap
setenv MBK_OUT_PH        ap

setenv MBK_WORK_LIB      .
setenv MBK_CATAL_NAME    CATAL

setenv MBK_SCALE_X 100

setenv VH_MAXERR 10
setenv VH_BEHSFX vbe
setenv VH_PATSFX pat
setenv VH_DLYSFX dly

setenv MBK_CATA_LIB      .:$ALLIANCE_TOP/cells/sxlib:$ALLIANCE_TOP/cells/dp_sxlib:$ALLIANCE_TOP/cells/padlib
setenv MBK_TARGET_LIB    $ALLIANCE_TOP/cells/sxlib
setenv MBK_C4_LIB        ./cellsC4 

setenv MBK_VDD           vdd
setenv MBK_VSS           vss

setenv XPAT_PARAM_NAME   $ALLIANCE_TOP/etc/xpat.par
setenv XFSM_PARAM_NAME   $ALLIANCE_TOP/etc/xfsm.par
setenv XSCH_PARAM_NAME   $ALLIANCE_TOP/etc/xsch.par

setenv RDS_IN cif
setenv RDS_OUT cif

setenv DREAL_TECHNO_NAME   $ALLIANCE_TOP/etc/cmos_7.dreal
setenv GRAAL_TECHNO_NAME   $ALLIANCE_TOP/etc/cmos_12.graal
setenv GENVIEW_TECHNO_NAME $ALLIANCE_TOP/etc/cmos_11.genview

setenv RDS_TECHNO_NAME   $ALLIANCE_TOP/etc/cmos_12.rds
setenv ELP_TECHNO_NAME   $ALLIANCE_TOP/etc/prol035.elp

# Update PATH and MANPATH
if $?PATH then
 setenv PATH $ALLIANCE_TOP/bin:$PATH
else
 setenv PATH $ALLIANCE_TOP/bin
endif

if $?MANPATH then
 setenv MANPATH $ALLIANCE_TOP/man:$MANPATH
else
 setenv MANPATH $ALLIANCE_TOP/man:/usr/share/man:/usr/man:/usr/local/man:/usr/X11R6/man:/usr/lib/perl5/man
endif

# EOF 
