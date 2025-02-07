#
# use GNU-Compiler tools
COMPILER=GCC_
# alternatively from the shell
# export COMPILER=GCC_
# or, alternatively from the shell
# make COMPILER=GCC_

# use Intel compilers
#COMPILER=ICC_

# use PGI compilers
# COMPILER=PGI_

# use CLANG compilers
# COMPILER=CLANG_


SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

PROGRAM	= main.${COMPILER}

# uncomment the next to lines for debugging and detailed performance analysis
CXXFLAGS += -g
LINKFLAGS += -g
# do not use -pg with PGI compilers

ifndef COMPILER
  COMPILER=GCC_
endif

include ../${COMPILER}default.mk


