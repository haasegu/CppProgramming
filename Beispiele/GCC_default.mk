# Basic Defintions for using GNU-compiler suite sequentially
# requires setting of COMPILER=GCC_

CC	= gcc
CXX     = g++
F77	= gfortran
LINKER  = ${CXX}

#  https://gcc.gnu.org/onlinedocs/gcc/Warning-Options.html
WARNINGS = -Wall -pedantic -Wextra -Weffc++ -Woverloaded-virtual -Wshadow \
           -Wredundant-decls -fmax-errors=1
#WARNINGS += -Wfloat-equal -Wunreachable-code -Winline
WARNINGS += -Wdouble-promotion -Wconversion -Wstrict-overflow=4 -Wstringop-overflow=3 -Wsuggest-attribute=const
WARNINGS += -Wmisleading-indentation -Wmissing-attributes -Wparentheses -Wduplicated-branches -Wduplicated-cond
WARNINGS += -Wvector-operation-performance -Wvla -Wdisabled-optimization 
#  -Wunreachable-code
#CXXFLAGS += -ffast-math -O3 -march=native -funroll-all-loops ${WARNINGS}
CXXFLAGS += -O3 -std=c++17 ${WARNINGS}
# -funroll-all-loops 
#-msse3
# -ftree-vectorizer-verbose=2  -DNDEBUG
# -ftree-vectorizer-verbose=5
# -ftree-vectorize -fdump-tree-vect-blocks=foo.dump  -fdump-tree-pre=stderr

# CFLAGS	= -ffast-math -O3 -DNDEBUG -msse3 -fopenmp -fdump-tree-vect-details
# CFLAGS	= -ffast-math -O3 -funroll-loops -DNDEBUG -msse3 -fopenmp -ftree-vectorizer-verbose=2
# #CFLAGS	= -ffast-math -O3 -DNDEBUG -msse3 -fopenmp
# FFLAGS	= -ffast-math -O3 -DNDEBUG -msse3 -fopenmp
# LFLAGS  = -ffast-math -O3 -DNDEBUG -msse3 -fopenmp


# profiling tools
#CXXFLAGS  += -pg
#LINKFLAGS += -pg

default: ${PROGRAM}

${PROGRAM}:	${OBJECTS}
	$(LINKER)  $^  ${LINKFLAGS} -o $@

clean:
	@rm -f ${PROGRAM} ${OBJECTS} 

clean_all:: clean
	@rm -f *_ *~ *.bak *.log *.out *.aux *.tar *.orig
	@rm -rf  html bin obj
	@rm -f *.*_
#	doxygen

run: clean ${PROGRAM}
#	time  ./${PROGRAM}
	./${PROGRAM}

CHECKFLAGS=--enable=all --inconclusive --language=c++ --std=c++11 --std=posix --suppress=missingIncludeSystem
#CHECKFLAGS=--enable=all --inconclusive --std=c++17 --suppress=missingIncludeSystem
check: 
	cppcheck ${CHECKFLAGS} *.cpp *.h

# tar the current directory
MY_DIR = `basename ${PWD}`
tar: clean_all
	@echo "Tar the directory: " ${MY_DIR}
	@cd .. ;\
	tar cf ${MY_DIR}.tar ${MY_DIR} *default.mk ;\
	cd ${MY_DIR}
# 	tar cf `basename ${PWD}`.tar *

zip: clean_all
	@echo "Zip the directory: " ${MY_DIR}
	@cd .. ;\
	zip ${MY_DIR}.zip ${MY_DIR}/* *default.mk ;\
	cd ${MY_DIR}

doc:
	doxygen Doxyfile

#########################################################################

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $<

.c.o:
	$(CC) -c $(CFLAGS) $<

.f.o:
	$(F77) -c $(FFLAGS) $<

##################################################################################################
#    some tools
# Cache behaviour (CXXFLAGS += -g  tracks down to source lines; no -pg in linkflags)
cache: ${PROGRAM}
	valgrind --tool=callgrind --simulate-cache=yes ./$^
#	kcachegrind callgrind.out.<pid> &
	kcachegrind `ls -1tr  callgrind.out.* |tail -1`

# Check for wrong memory accesses, memory leaks, ...
# use smaller data sets
mem: ${PROGRAM}
	valgrind -v --leak-check=yes --tool=memcheck --undef-value-errors=yes --track-origins=yes --log-file=$^.addr.out --show-reachable=yes ./$^

#  Simple run time profiling of your code
#  CXXFLAGS += -g -pg
#  LINKFLAGS += -pg
prof: ${PROGRAM}
	./$^
	gprof -b ./$^ > gp.out
#	kprof -f gp.out -p gprof &

#Trace your heap:
#> heaptrack ./main.GCC_
#> heaptrack_gui heaptrack.main.GCC_.<pid>.gz
heap: ${PROGRAM}
	heaptrack ./$^
	heaptrack_gui  `ls -1tr  heaptrack.$^.*.gz |tail -1`

########################################################################
#  get the detailed  status of all optimization flags
info:
	echo "detailed  status of all optimization flags"
	$(CXX) --version
	$(CXX) -Q $(CXXFLAGS) --help=optimizers
