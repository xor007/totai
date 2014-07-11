#############################[ INCUS DATA ]###########################
#                                                                    #
# Example Makefile for the Thing demonstration project.           #
#                                                                    #
# NOTE: The syntax is based on GNU's make. It will work for make     #
#       supplied with the MingW version of GCC and binutils. It      #
#       should also work for a Cygwin installation (under bash).     #
#                                                                    #
#       It depends on either native or Cygwin versions of some       #
#       GNU file & text utilities, e.g. rm and cp. These are easy    #
#       to obtain, even if one is not prepared to install the        #
#       Cygwin option ... check out unxutil.sourceforge.net or       #
#       gnuwin32.sourceforge.net for native Win32 versions.          #
#                                                                    #
##[ 2005-MAR ]###############################################[ BRX ]##

## COMMON VARIABLES ##
#
CC=g++
CPPFLAGS=-Wall -Wextra -pedantic-errors -std=c++11
LDFLAGS=
DBG=-DNDEBUG
BIN=bin
SRC=src
OBJ=obj
RES=res
EXE1=Thing.exe

## GENERIC RULE FOR C TO OBJECT ##
#
#  GNU's make supports more than one syntax for specifying generic
#  rules. This is the one closest to the way some other make programs
#  work.
#
%.c %.o:
	@echo COMPILING "$?" TO "$*.o"
	$(CC) $(DBG) $(CPPFLAGS) -c -o $(OBJ)/$*.o $(SRC)/$?


## A P P L I C A T I O N 1 #############################################
#
# NOTE: The $? below provides a list of all dependends.
# 
$(BIN)/$(EXE1): $(OBJ)/Thing.o
	@echo LINKING $? TO GET $@
	$(CC) -o $(BIN)/Thing $? $(LDFLAGS) 

$(OBJ)/Thing.o: $(SRC)/Thing.cpp
	@echo COMPILING "$?" TO "$*.o"
	$(CC) $(DBG) $(CPPFLAGS) -c -o $*.o $?

## D O C U M E N T A T I O N #########################################
#
# Note: This part depends on the availability of doxygen and (option-
#       ally), graphviz -- both freely available and portable.
#


## PSEUDO TARGETS ##
#
.PHONY: all, clean

all: $(EXE1)

clean:
	-@rm -f $(OBJ)/*.o $(BIN)/* 2>&1 > /dev/null
	-@rm -f $(DOX)/html/* 2>&1 > /dev/null

##[ EOF ]##
