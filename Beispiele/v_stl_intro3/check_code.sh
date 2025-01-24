#!/bin/bash
# checks a source file "*.cpp" with several tools

# for k in *.cpp; do ./check_code.sh $k; done &> check_all.txt

CXXFLAGS="-c -pedantic -std=c++17 -Weffc++ -Wall -Wextra -pedantic -Wswitch-default -Wfloat-equal -Wundef -Wredundant-decls -Winit-self -Wshadow -Wparentheses -Wshadow -Wunreachable-code -Wuninitialized -Wmaybe-uninitialized"
# -Wmissing-declarations
CHECKFLAGS="--enable=all --inconclusive --std=c++11 --std=posix --suppress=missingIncludeSystem"
CLANGFLAGS="-fsyntax-only -std=c++17 -Weverything -pedantic -Wno-c++98-compat -Wno-c++98-compat-pedantic"
#CLANGFLAGS="-fsyntax-only -std=c++17 -Wdocumentation -Wconversion -Wshadow -Wfloat-conversion -pedantic"

TIDYFLAGS="-checks=llvm*,-llvm-header-guard -header-filter=.* -enable-check-profile -extra-arg="-std=c++17" -extra-arg="-fopenmp""

ICPCFLAGS="-fsyntax-only -std=c++17 -Wall -Weffc++ -Woverloaded-virtual -Wfloat-equal -Wshadow -wd2015,2012"

if [ $# -lt 1 ]
  then
  echo "  "
  echo "$0 checks C++ codes with a variance of tools."
  echo "  "
  echo "Correct call:   $0  foo.cpp"
  echo "  "
  exit 9
fi

#RES_FILE=`basename $1 .cpp`.check.txt       # hard coded name of result file
#rm -f $RES_FILE
#echo $RES_FILE


echo "#########  " $1 "  #########"
echo " "

echo "---------  G++  ---------"
echo g++ $CXXFLAGS $1
echo " "
g++ $CXXFLAGS $1

echo "---------  cppcheck  ---------"
echo cppcheck $CHECKFLAGS $1
echo " "
cppcheck $CHECKFLAGS $1

echo "---------  clang  ---------"
echo /usr/bin/clang++-9 $CLANGFLAGS $1
echo " "
/usr/bin/clang++-9 $CLANGFLAGS $1

echo "---------  clang-tidy  ---------"
echo /usr/bin/clang-tidy-9 $TIDYFLAGS $1
echo " "
/usr/bin/clang-tidy-9 $TIDYFLAGS $1

echo "---------  INTEL  ---------"
echo icpc $ICPCFLAGS $1
echo " "
icpc $ICPCFLAGS $1






exit 0






