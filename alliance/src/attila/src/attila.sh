#!/bin/sh
#
# $Id: attila.sh,v 1.12 2002/11/27 21:21:20 jpc Exp $
#                                                                        
# /------------------------------------------------------------------\
# |                                                                  |
# |        A l l i a n c e   C A D   S y s t e m                     |
# |             T o o l   I n s t a l l e r                          |
# |                                                                  |
# |  Author    :                      Jean-Paul CHAPUT               |
# |  E-mail    :         alliance-users@asim.lip6.fr                 |
# | ================================================================ |
# |  sh script :         "./attila"                                  |
# | **************************************************************** |
# |  U p d a t e s                                                   |
# |                                                                  |
# \------------------------------------------------------------------/
#




# /------------------------------------------------------------------\
# |                                                                  |
# |                      Functions Definitions                       |
# |                                                                  |
# \------------------------------------------------------------------/


# --------------------------------------------------------------------
# Function  :  `print_usage()'.

 print_usage ()
 {
   echo ""
   echo ""
   echo "Usage : attila [-h] [-L] [-U] [-F] [-A]                          \\"
   echo "               [--help] [--local] [--user] [--full] [--asim]     \\"
   echo "               [--prefix=<INSTALL_DIR>] [--builddir=<BUILD_DIR>] \\"
   echo "               <--tool=<name1> [--tool=<name2> [...]]            \\"
   echo "               [-c- <configure_arg> [...]]                       \\"
   echo "               [-m- <make_arg> [...]]                            \\"
   echo ""
   echo ""
   echo "Options :"
   echo "     o [-h|--help]  : Print this help."
   echo "     o [-L|--local] : Print this help."
   echo "     o [-U|--user]  :"
   echo "         Perform a \"USER\" compilation/installation."
   echo "         The tool(s) will be compiled then installed under the"
   echo "         directory given by the \"--prefix\" argument."
   echo "     o [-F|--full]  :"
   echo "         Compile/install the requested tool(s) for all"
   echo "         avalaibles architectures. Currently only Linux and Solaris"
   echo "         are supported."
   echo "     o [-A|--asim]  :"
   echo "         Install the tool(s) in the ASIM shared direc-"
   echo "         tory (aka \"\$ALLIANCE_TOP\"), this must be used to upgrade"
   echo "         a tool. This option implies \"--full\"."
   echo "           NOTE : it will erase any previous installed version of"
   echo "         the tool. The temporary build directory (--builddir) will"
   echo "         also be erased."
   echo "     o [--prefix=<INSTALL_DIR>] :"
   echo "         Override the default top directory"
   echo "         where the tool will be installed. By defaults tools are"
   echo "         installed under :"
   echo "           \"\$HOME/alliance/\$OS/install\"."
   echo "     o [--builddir=<BUILD_DIR>] :"
   echo "         Override the default top directory"
   echo "         where the tool will be compiled. By defaults tools are"
   echo "         compiled under :"
   echo "           \"\$HOME/alliance/\$OS/build\"."
   echo "     o [--tool=<name1>] :"
   echo "         The name of the tool to be processed, at"
   echo "         least one must be present."
   echo "     o [-c- <configure_arg> [...]] :"
   echo "         Arguments to be directly passed to configure."
   echo "     o [-m- <make_arg> [...]] :"
   echo "         Arguments to be directly passed to make. If there is none,"
   echo "         the default rule for Alliance (i.e. \"install\") will be"
   echo "         called."
   echo ""
   echo ""
 }




# --------------------------------------------------------------------
# Function  :  `alc_banner()'.

 alc_banner ()
 {
   echo ""
   echo ""
   echo "                   @                           @   @@@@            "
   echo "                   @         @        @       @@@    @@            "
   echo "                  @@@       @@       @@        @     @@            "
   echo "                  @@@       @@       @@              @@     @@@@   "
   echo "                 @  @@    @@@@@@@@ @@@@@@@@ @@@@     @@    @@   @  "
   echo "                 @  @@      @@       @@       @@     @@    @@   @@ "
   echo "                @    @@     @@       @@       @@     @@      @@@@@ "
   echo "                @@@@@@@     @@       @@       @@     @@    @@   @@ "
   echo "               @      @@    @@       @@       @@     @@   @@    @@ "
   echo "               @      @@    @@   @   @@   @   @@     @@   @@   @@@ "
   echo "             @@@@    @@@@    @@@@     @@@@  @@@@@@ @@@@@@  @@@@  @@"
   echo ""
   echo "                        A Tool for Install Alliance tools"
   echo ""
   echo "                  Alliance CAD System 5.0,           attila 0.1"
   echo "                  Copyright (c) 2002-2002,       ASIM/LIP6/UPMC"
   echo "                  E-mail :          alliance-users@asim.lip6.fr"
   echo ""
   echo ""
 }



# --------------------------------------------------------------------
# Function  :  `find_self()'.
#
# Usage : find_self <program> <tool> <args>
#
#   Return the absolute path of the binary, and if in case of self
# install switch to the binary in "attila/src" (attila.sh).

 find_self ()
 {
   PROG="$1"
   TOOL="$2"

   shift 2

  # In case of self install, switch to the CVS script.
   if [ "$TOOL" = "attila" ]; then
     if [ "`basename $PROG`" != "attila.sh" ]; then
       SELF="$HOME/alliance/src/attila/src/attila.sh"

       if [ ! -x "$SELF" ]; then
         echo "attila: Self install problem, cannot find source file :"
         echo "        \"$SELF\""
         exit 1
       else
         echo "  o  Self installing, switching to :"
         echo "     $SELF"
         exec -a "$SELF" "$SELF" $*
       fi
     fi
   fi

  # Installing a normal tool, normalise our path.
  # Needed in case of recursive call on other computer (ASIM install).
   CALL_DIR=`echo "$PROG" | sed 's,/[^/]*$,,'`
   REAL_DIR=`(cd $CALL_DIR; pwd)`

   SELF="$REAL_DIR/`basename $PROG`"
 }



# --------------------------------------------------------------------
# Function  :  `guess_os()'.

 guess_os ()
 {
   case "`uname -sr`" in
     Linux*)    echo "Linux";;
     SunOS\ 5*) echo "Solaris";;
     *)         echo "`uname -sr`";;
   esac
 }




# --------------------------------------------------------------------
# Function  :  `guess_gcc()'.

 guess_gcc ()
 {
   case "$1" in
     "Linux")   if which gcc3 > /dev/null 2>&1; then
                  CXX=g++3
                   CC=gcc3
                fi
                ;;
     "Solaris") if [ -x /usr/local/gcc-3.0.4/bin/gcc ]; then
                  CXX=/usr/local/gcc-3.0.4/bin/g++
                   CC=/usr/local/gcc-3.0.4/bin/gcc
                fi
                ;;
   esac
 }




# --------------------------------------------------------------------
# Function  :  `switch_os()'.

 switch_os ()
 {
   TOP_PATH="$1"

   SUBST_PATH="$TOP_PATH"
   for _OS in $ALL_OSS; do
     SUBST_PATH=`echo $SUBST_PATH | sed "s,$_OS,__OS__,"`
   done

   SUBST_PATH=`echo $SUBST_PATH | sed "s,__OS__,$ALLIANCE_OS,"`

   echo "$SUBST_PATH"
 }



# --------------------------------------------------------------------
# Function  :  `load_conf()'.
#
# The two ways to find ALLIANCE_TOP :
#
# 1. - In case of self install, blindly trust the user supplied
#        ALLIANCE_TOP (user must supply it).
#
# 2. - Normal case (attila is installing any other tool) : try to
#        find ALLIANCE_TOP in the user environment. If not set, use
#        the attila install time default ATTILA_ALLIANCE_TOP.

 load_conf ()
 {
   ALLIANCE_OS=`guess_os`
   echo "  o  Guessed OS : $ALLIANCE_OS"

   ALLIANCE_TOP=`switch_os $ALLIANCE_TOP`

   echo "  o  Loading configuration file."

   if [ "$ATTILA_ALLIANCE_TOP" = "__ALLIANCE_INSTALL_DIR__" ]; then
     if [ -z "$ALLIANCE_TOP" ]; then
       echo "attila: \$ALLIANCE_TOP is not set. Please set it up by executing"
       echo "        in the current shell process \"alc_env.sh\" or \"acl_env.csh\"."
       echo "        (thoses scripts can be found under the /etc directory of"
       echo "        your Alliance installation)."

       exit 1
     fi

     echo "     - Skipped during self install."
   else
     if [ -z "$ALLIANCE_TOP" ]; then
       ALLIANCE_TOP="$ATTILA_ALLIANCE_TOP"
     fi

     ATTILA_CONF="$ALLIANCE_TOP/etc/attila.conf"
     if [ "$ATTILA_LOCAL" = "y" ]; then
       ATTILA_CONF="$ATTILA_ALLIANCE_TOP/etc/attila.conf"
     fi

     if [ ! -f "$ATTILA_CONF" ]; then
       echo "attila: \"$ATTILA_CONF\" doesn't exist !"
       echo "        Please check \$ALLIANCE_TOP."

       exit 1
     fi

     if [ "$ATTILA_LOCAL" != "y" ]; then
       if [ ! -d "$ALLIANCE_TOP/bin" ]; then
         echo "attila: \"$ALLIANCE_TOP/bin\" doesn't exist !"
         echo "        Please check \$ALLIANCE_TOP."
  
         exit 1
       fi
     fi

     . "$ATTILA_CONF"
   fi
 }




# --------------------------------------------------------------------
# Function : `get_string()'.

 get_string()
 {
   string=`echo $1 | cut -d '=' -f 2-`

   echo $string
 }




# --------------------------------------------------------------------
# Function : `norm_dir()'.

 norm_dir()
 {
   DIR="$2"

   if [ -z "$DIR" ]; then
     case "$1" in
       "SRC")     DIR="$HOME/alliance/src";;
       "INSTALL") DIR="$HOME/alliance/$ALLIANCE_OS/install";;
       *)         DIR="$HOME/alliance/$ALLIANCE_OS/build" ;;
     esac
   fi

   HEAD=`echo $DIR | cut -b 1`

   if [ "$HEAD" != "/" ]; then
     echo "$HOME/$DIR"
     return
   fi

   echo "$DIR"
 }




# --------------------------------------------------------------------
# Function : `make_dir()'.

 make_dir()
 {
   mkdir -p $1
   if [ $? -ne 0 ]; then exit 1; fi
 }




# --------------------------------------------------------------------
# Function  :  `cvs_check()'.

 cvs_check ()
 {
   echo "  o  Checking CVSROOT."

  # Check the CVROOT variable.
   if [ -z "$CVSROOT" ]; then
     echo "     - CVROOT is not set. Using defaut $ATTILA_CVSROOT."
     CVSROOT="$ATTILA_CVSROOT"; export CVSROOT
   else
     echo "     - Trusting user supplied \$CVSROOT ($CVSROOT)."
   fi


   cd $HOME
  # Check out minimal set of files if needed.
   for file in $CVS_STARTUP_FILES; do
     if [ ! -f $HOME/alliance/src/$file ]; then
       cvs co alliance/src/$file
     fi
   done



  # Checks for tools sources.
   echo "  o  Checking tools sources."
   for TOOL in $TOOLS; do
     echo "     - $HOME/alliance/src/$TOOL."

     if [ ! -d $HOME/alliance/src/$TOOL ]; then
       echo    "       > The tool directory $TOOL doesn't exist."
       echo -n "       > Do you want to check it out from the CVS tree ? [y]/n "

       LOOP="y"
       while [ "$LOOP" = "y" ]; do
         read ANSWER
         case "$ANSWER" in
           "y"|"") ANSWER="y"; LOOP="n";;
           "n")    LOOP="n";;
           *)      echo -n "       > ";;
         esac
       done

       case "$ANSWER" in
         "y") cvs co alliance/src/$TOOL;;
         "n") exit 1;;
       esac
     fi
   done

   echo ""
 }



# --------------------------------------------------------------------
# Function  :  `compile_tool()'.

 compile_tool ()
 {

  # ----------------------------------------------------------------
  # Check environment.

   echo "  o  Compilation environment."

   case "$ALLIANCE_OS" in
     "Linux")   MAKE="make";;
     "Solaris") MAKE="gmake";;
     *) echo "attila: \"$ALLIANCE_OS\" is not supported, only Linux & Solaris"
        echo "        are."

        exit 1
   esac
   export MAKE

   echo "     - OS          := $ALLIANCE_OS"
   echo "     - MAKE        := $MAKE"

   guess_gcc $ALLIANCE_OS
   echo "     - CC          := $CC"
   echo "     - CXX         := $CXX"


       SRC_DIR=`norm_dir SRC     "$SRC_DIR"`
     BUILD_DIR=`norm_dir BUILD   "$BUILD_DIR"`
   INSTALL_DIR=`norm_dir INSTALL "$INSTALL_DIR"`


   echo "  o  Loading Alliance environment."
   if [ -f "$ALLIANCE_TOP/etc/alc_env.sh" ]; then
     echo "     - Using \"$ALLIANCE_TOP/etc/alc_env.sh\"."
     . $ALLIANCE_TOP/etc/alc_env.sh
   else
     echo "     - No \"$ALLIANCE_TOP/etc/alc_env.sh\" found, trusting user environment."
   fi
   echo ""


   if [ "$ASIM" = "y" ]; then INSTALL_DIR="$ALLIANCE_TOP"; fi

   echo "     - SRC_DIR     := $SRC_DIR"
   echo "     - BUILD_DIR   := $BUILD_DIR"
   echo "     - INSTALL_DIR := $INSTALL_DIR"
   echo ""




  # ------------------------------------------------------------------
  # Do the work.


   cd $HOME/alliance/src
   if [ ! -f Makefile.in ]; then
     ./autostuff
   fi

   if [ "$ASIM" = "y" ]; then
     echo "  o  For ASIM install, removing $BUILD_DIR"
     for TOOL in $TOOLS; do
       echo "      - $BUILD_DIR/$TOOL."
       rm -rf $BUILD_DIR/$TOOL
     done
   fi

   if [ ! -d $BUILD_DIR ]; then
     echo "  o  Creating build directory $BUILD_DIR"
     make_dir $BUILD_DIR
   fi

   if [ "$ASIM" != "y" ]; then
     if [ ! -d $INSTALL_DIR ]; then
       echo "  o  Creating local install directory $INSTALL_DIR"
       make_dir $INSTALL_DIR
     fi
   fi

   echo "  o  Building & installing requested tools."
   for TOOL in $TOOLS; do
     cd  $HOME/alliance/src
     if [ ! -f "$TOOL/Makefile.in" ]; then
       echo "     - Making autostuff for $TOOL."
       ./autostuff $TOOL
     fi

     cd $BUILD_DIR
     if [ ! -d $TOOL ]; then
       echo "     - Creating $TOOL directory."
       make_dir $TOOL
     fi
     cd $TOOL

     echo "     - Making rule $RULE for $TOOL."
     $SRC_DIR/$TOOL/configure --prefix=$INSTALL_DIR $ARGS_CONFIGURE
     $MAKE prefix=$INSTALL_DIR $ARGS_MAKE

     cd ..
     if [ "$ASIM" = "y" ]; then
       echo "  o  After an ASIM install, removing $BUILD_DIR"
       echo "     - $BUILD_DIR/$TOOL"
       rm -rf $BUILD_DIR/$TOOL
     fi
   done
 }




# /------------------------------------------------------------------\
# |                                                                  |
# |                  Main Part of the Shell Script                   |
# |                                                                  |
# \------------------------------------------------------------------/


 ATTILA_ALLIANCE_TOP="__ALLIANCE_INSTALL_DIR__"


# --------------------------------------------------------------------
# Variables sets in "attila.conf".


   CVS_STARTUP_FILES=""

 LINUX_TARGET="bip"
     LINUX_CC="gcc3"
    LINUX_CXX="g++3"

 SOLARIS_TARGET="beny"
     SOLARIS_CC="/usr/local/gcc-3.0.4/bin/gcc3"
    SOLARIS_CXX="/usr/local/gcc-3.0.4/bin/g++3"


# --------------------------------------------------------------------
# Internal variables.


             ALL_OSS="Linux Solaris"
                  CC=gcc
                 CXX=g++
              export CC CXX

                 RSH="rsh"

             SRC_DIR="alliance/src"
           BUILD_DIR=""
         INSTALL_DIR=""



               TOOLS=""
      ARGS_CONFIGURE=""
           ARGS_MAKE=""
   ARGS_MAKE_DEFAULT="install"

                ASIM="n"
                FULL="n"
                AUTO="n"
                SELF="$0"
        ATTILA_LOCAL="no"




# --------------------------------------------------------------------
# Process the command line.


# Print the banner.
 alc_banner


 if [ $# -eq 0 ]; then
   print_usage
   exit 0
 fi


 COMMAND_LINE=""
 PARSE_STATE="attila"

 while [ $# -gt 0 ]; do

   case $PARSE_STATE in

     "attila") case $1 in
      # Long arguments.
       --help)        print_usage;
                      exit 0;;
       --ssh)         RSH="ssh";;
       --user)        ASIM="n";;
       --full)        FULL="y";;
       --asim)        ASIM="y"; FULL="y";;
       --asim-noloop) ASIM="y";;
       --local)       ATTILA_LOCAL="y";;
       --prefix=*)    INSTALL_DIR=`get_string $1`
                      if [ $? -ne 0 ]; then
                        echo -n "attila: Bad directory in argument \"$1\"."
                        print_usage
                        exit 1
                      fi;;
       --builddir=*)  BUILD_DIR=`get_string $1`
                      if [ $? -ne 0 ]; then
                        echo -n "attila: Bad directory in argument \"$1\"."
                        print_usage
                        exit 1
                      fi;;
       --tool=*)      TOOL=`get_string $1`
                      if [ "$TOOL" = "attila" ]; then AUTO="attila"; fi
  
                      TOOLS="$TOOLS $TOOL"
                      if [ $? -ne 0 ]; then
                        echo -n "attila: Bad tool name in argument \"$1\"."
                        print_usage
                        exit 1
                      fi;;
       -c-) PARSE_STATE="configure";;
       -m-) PARSE_STATE="make";;
  
      # Short arguments.
       -*) SHORTS="$1"; NB=2; CH=`echo $SHORTS | cut -c$NB`
  
           while [ "$CH" != "" ]; do
             case $CH in
               h) print_usage; exit 0;;
               L) ATTILA_LOCAL="y";;
               S) RSH="ssh";;
               U) ASIM="n";;
               F) FULL="y";;
               A) ASIM="y"; FULL="y";;
  
               *) echo "attila:error: Invalid option \`$CH'."
                  print_usage; exit 1;;
             esac
  
             NB=`expr $NB + 1`
             CH=`echo $SHORTS | cut -c$NB`
           done;;
     esac;;

     "configure") case $1 in
          "-m-") PARSE_STATE="make";;
          "-c-") PARSE_STATE="configure";;
          *)     ARGS_CONFIGURE="$ARGS_CONFIGURE $1";;
        esac;;

     "make") case $1 in
          "-m-") PARSE_STATE="make";;
          "-c-") PARSE_STATE="configure";;
          *)     ARGS_MAKE="$ARGS_MAKE $1";;
        esac;;


   esac

   COMMAND_LINE="$COMMAND_LINE $1"

   shift
 done


 if [ -z "$TOOLS" ]; then
   echo "attila:error: At least one \"--tool=<name>\" argument is required."
   print_usage; exit 1
 fi


 if [ ! -z "$INSTALL_DIR" ]; then
   INSTALL_DIR=`echo $INSTALL_DIR | sed "s,^$HOME/,,"`
 fi

 if [ ! -z "$BUILD_DIR" ]; then
   BUILD_DIR=`echo $BUILD_DIR | sed "s,^$HOME/,,"`
 fi

 if [ -z "$ARGS_MAKE" ]; then
   ARGS_MAKE="$ARGS_MAKE_DEFAULT"
 fi


# --------------------------------------------------------------------
# Do the work.

 find_self "$0" "$AUTO" $COMMAND_LINE

 load_conf

 cvs_check

 if [ "$FULL" = "y" ]; then
  # Recursive call.
   ARGS=""
   if [ ! -z "$INSTALL_DIR" ]; then ARGS="$ARGS   --prefix=$INSTALL_DIR"; fi
   if [ ! -z "$BUILD_DIR"   ]; then ARGS="$ARGS --builddir=$BUILD_DIR"  ; fi
   if [ "$ASIM" = "y" ]; then
     ARGS="$ARGS --asim-noloop"
   else
     ARGS="$ARGS --user"
   fi
   if [ "$ATTILA_LOCAL" = "y" ]; then ARGS="$ARGS --local"; fi

   for TOOL in $TOOLS; do
     ARGS="$ARGS --tool=$TOOL"
   done

   if [ ! -z "$ARGS_CONFIGURE" ]; then ARGS="$ARGS -c- $ARGS_CONFIGURE"; fi
   if [ ! -z "$ARGS_MAKE"      ]; then ARGS="$ARGS -m- $ARGS_MAKE"; fi

   ENVIRONMENT=""
   ENVIRONMENT="$ENVIRONMENT ALLIANCE_TOP=$ALLIANCE_TOP; export ALLIANCE_TOP;"

   $RSH   $LINUX_TARGET "/bin/bash -c \"$ENVIRONMENT $SELF $ARGS\""
   $RSH $SOLARIS_TARGET "/bin/bash -c \". /etc/profile; $ENVIRONMENT $SELF $ARGS\""
 else
  # Out of recursion...
   compile_tool
 fi
