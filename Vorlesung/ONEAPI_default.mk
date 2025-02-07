# Basic Defintions for using INTEL compiler suite sequentially
# requires setting of COMPILER=ICC_

CUDA_DIR = /opt/cuda/targets/x86_64-linux
CUDA_INC = ${CUDA_DIR}/include
CUDA_LIB = ${CUDA_DIR}/lib

# https://software.intel.com/content/www/us/en/develop/tools/oneapi/components/onemkl/link-line-advisor.html
# requests to run
#    source /opt/intel/oneapi/setvars.sh
#BINDIR = /opt/intel/oneapi/compiler/latest/linux/bin/
MKL_ROOT = /opt/intel/oneapi/mkl/latest

CC	= ${BINDIR}icc
CXX     = ${BINDIR}dpcpp
F77	= ${BINDIR}ifort
LINKER  = ${CXX}

WARNINGS = -Wall -Weffc++ -Woverloaded-virtual -Wfloat-equal -Wshadow -pedantic
WARNINGS += -Wpessimizing-move -Wredundant-move

#-wd2015,2012,2014 -wn3
#    -Winline -Wredundant-decls -Wunreachable-code
#CXXFLAGS += -O3 -xnative -fargument-noalias -std=c++17  -DNDEBUG -msse3 ${WARNINGS} -mkl ${FOUND_CONFIG}
#CXXFLAGS += -O3 -xnative -flto -fopenmp -std=c++17 -DNDEBUG -mkl -isystem /usr/local/magma/include -DADD_ ${WARNINGS}
#CXXFLAGS += -O3 -flto -fopenmp -std=c++17 -DNDEBUG -DADD_ ${WARNINGS}
CXXFLAGS +=  -fopenmp -std=c++20 -DNDEBUG ${WARNINGS}
#-DADD_ 
#CXXFLAGS += -DMKL_ILP64  -I"${MKLROOT}/include"
#CXXFLAGS += -DMKL_ILP32  -I"${MKLROOT}/include"

# profiling tools
#CXXFLAGS  += -pg
#LINKFLAGS += -pg
# -vec-report=3
# -qopt-report=5 -qopt-report-phase=vec
# -guide -parallel
# -guide-opts=string  -guide-par[=n]  -guide-vec[=n]
# -auto-p32 -simd

LINKFLAGS += -O3

#CXXFLAGS  += -ipo
#LINKFLAGS += -ipo

# BLAS/LAPACK: use MKL by INTEL
# LINKFLAGS += -L${BINDIR}../composer_xe_2013.1.117/mkl/lib/intel64 -lmkl_intel_lp64 -lmkl_sequential -lmkl_core -lpthread
#LINKFLAGS += -qmkl=sequential
#LINKFLAGS += -fsycl-device-code-split=per_kernel  ${MKLROOT}/lib/intel64/libmkl_sycl.a -Wl,-export-dynamic -Wl,--start-group ${MKLROOT}/lib/intel64/libmkl_intel_ilp64.a ${MKLROOT}/lib/intel64/libmkl_sequential.a ${MKLROOT}/lib/intel64/libmkl_core.a -Wl,--end-group -lsycl -lOpenCL -lpthread -lm -ldl

# use MKL by INTEL
# https://software.intel.com/content/www/us/en/develop/tools/oneapi/components/onemkl/link-line-advisor.html
CXXFLAGS +=  -qmkl=sequential
# LINKFLAGS += -L${BINDIR}../composer_xe_2013.1.117/mkl/lib/intel64 -lmkl_intel_lp64 -lmkl_sequential -lmkl_core -lpthread
LINKFLAGS += -O3 -qmkl=sequential -lmkl_intel_lp64 -lmkl_sequential -lmkl_core -lpthread

OPENMP = -qopenmp
CXXFLAGS += ${OPENMP}
LINKFLAGS += ${OPENMP}

# CUDA-libs
#CXXFLAGS  += -isystem ${CUDA_INC}
#LINKFLAGS += -L${CUDA_LIB} -lcudart -lcublas -lcusolver -lmagma -L/usr/local/magma/lib -lmagma

default:	${PROGRAM}

${PROGRAM}:	${OBJECTS}
	$(LINKER)  $^  ${LINKFLAGS} -o $@

clean:
	rm -f ${PROGRAM} ${OBJECTS}

clean_all:: clean
	@rm -f *_ *~ *.bak *.log *.out *.tar

run: clean ${PROGRAM}
	./${PROGRAM}

# tar the current directory
MY_DIR = `basename ${PWD}`
tar: clean_all
	@echo "Tar the directory: " ${MY_DIR}
	@cd .. ;\
	tar cf ${MY_DIR}.tar ${MY_DIR} *default.mk ;\
	cd ${MY_DIR}
# 	tar cf `basename ${PWD}`.tar *

doc:
	doxygen Doxyfile

#########################################################################

.cpp.o:
	$(CXX) -c $(CXXFLAGS) -o $@ $<

.c.o:
	$(CC) -c $(CFLAGS) -o $@ $<

.f.o:
	$(F77) -c $(FFLAGS) -o $@ $<

##################################################################################################
# #    some tools
# # Cache behaviour (CXXFLAGS += -g  tracks down to source lines)
# cache: ${PROGRAM}
# 	valgrind --tool=callgrind --simulate-cache=yes ./$^
# #	kcachegrind callgrind.out.<pid> &
#
# # Check for wrong memory accesses, memory leaks, ...
# # use smaller data sets
# mem: ${PROGRAM}
# 	valgrind -v --leak-check=yes --tool=memcheck --undef-value-errors=yes --track-origins=yes --log-file=$^.addr.out --show-reachable=yes ./$^
#
# #  Simple run time profiling of your code
# #  CXXFLAGS += -g -pg
# #  LINKFLAGS += -pg
# prof: ${PROGRAM}
# 	./$^
# 	gprof -b ./$^ > gp.out
# #	kprof -f gp.out -p gprof &
#


#https://software.intel.com/content/www/us/en/develop/documentation/vtune-help/top/analyze-performance/microarchitecture-analysis-group/memory-access-analysis.html

mem: inspector
prof: vtune
cache: inspector

gap_par_report:
	${CXX}  -c -guide -parallel $(SOURCES) 2> gap.txt

# GUI for Memory and Thread analyzer (race condition)
inspector: ${PROGRAM}
#	echo 0 | sudo tee /proc/sys/kernel/yama/ptrace_scope
#	inspxe-gui &
	vtune-gui ./${PROGRAM} &

advisor:
	source /opt/intel/oneapi/advisor/2021.2.0/advixe-vars.sh
#	/opt/intel/oneapi/advisor/latest/bin64/advixe-gui &
	advisor --collect=survey ./${PROGRAM} 
#	advisor --collect=roofline ./${PROGRAM} 
	advisor --report=survey --project-dir=./ src:r=./ --format=csv --report-output=./out/survey.csv

vtune:
	echo 0 | sudo tee /proc/sys/kernel/yama/ptrace_scope
	vtune -collect hotspots ./${PROGRAM}
	vtune -report hotspots -r r001hs > vtune.out
#	vtune-gui ./${PROGRAM} &	

icc-info:
	icpc -# main.cpp

# MKL on AMD
# https://www.computerbase.de/2019-11/mkl-workaround-erhoeht-leistung-auf-amd-ryzen/
#
# https://sites.google.com/a/uci.edu/mingru-yang/programming/mkl-has-bad-performance-on-an-amd-cpu
# export MKL_DEBUG_CPU_TYPE=5
# export MKL_NUM_THRAEDS=1
# export MKL_DYNAMIC=false
#  on Intel compiler
# http://publicclu2.blogspot.com/2013/05/intel-complier-suite-reference-card.html
