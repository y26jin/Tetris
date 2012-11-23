CXX = g++ -m32				# compiler 
CXXFLAGS =  -g -Wall -MMD		# compiler flags
CXXXGUIFLAGE =  -L/usr/X11R6/lib -lX11
#CXBITS = -m32
MAKEFILE_NAME = ${firstword ${MAKEFILE_LIST}} # makefile name

OBJECTS1 = a5.o grid.o block.o blk.o cell.o score.o nextblk.o trie.o blkgen.o window.o	# object files forming executable
EXEC1 = quadris				# executable name

#OBJECTS2 = <partner code>              # object files forming executable
#EXEC2 = rationalnumber			# executable name

#OBJECTS3 = q3driver.o q3player.o q3potato.o q3umpire.o # object files forming executable
#EXEC3 = hotpotato			# executable name

OBJECTS = ${OBJECTS1}  # ${OBJECTS2} ${OBJECTS3}
EXECS = ${EXEC1}  # ${EXEC2} ${EXEC3}
DEPENDS = ${OBJECTS:.o=.d}		# substitute ".o" with ".d"

.PHONY : all clean

all : ${EXECS}

${EXEC1} : ${OBJECTS1}			# link step
	${CXX} ${CXXXGUIFLAGE} $^ -o $@

#${EXEC2} : ${OBJECTS2}			# link step
#	${CXX} $^ -o $@

#${EXEC3} : ${OBJECTS3}			# link step
#	${CXX} $^ -o $@

${OBJECTS} : ${MAKEFILE_NAME}   	# OPTIONAL : changes to this file => recompile

#-include ${DEPENDS}			# include *.d files containing program dependences

clean :					# remove files that can be regenerated
	rm -f ${DEPENDS} ${OBJECTS} ${EXECS}
