#	make a4_1

CC = g++
#CC = icc
CFLAGS = -Wall -g\
-Weffc++ -Woverloaded-virtual -Wextra -Wfloat-equal -Wshadow \
-Wredundant-decls -Wunreachable-code -Winline


PROG1 = a4_1
SRC1 = a4_1.cpp employ.cpp

PROG2 = a4_2
SRC2 = a4_2.cpp employ2.cpp

PROG3 = a4_3
SRC3 = a4_3.cpp employ2.cpp liste.cpp bestech.cpp

default: $(PROG1)

# 	Abh�gigkeit des Executable von Objektfiles
$(PROG1): $(SRC1:.cpp=.o)
	@echo "Linke aus  " $^ "  das Programm  " $@
	$(CC) -o $@ $^

$(PROG2): $(SRC2:.cpp=.o)
	@echo "Linke aus  " $? "  das Programm  " $@
	@echo "ist falsch und compilieren schlaegt fehl, weil nur aus den sourcen gelinkt wird die sich geaendert haben: Linke aus  " $? "  das Programm  " $@
	@echo "richtig ist: Linke aus  " $^ "  das Programm  " $@
	$(CC) -o $@ $?

$(PROG3): $(SRC3:.cpp=.o)
	@echo "Linke aus  " $^ "  das Programm  " $@
	$(CC) -o $@ $^


clean:
	@rm -f *.o a.out ${PROG1} ${PROG2} ${PROG3}

all:	$(PROG1) $(PROG2) $(PROG3)

#-------------------------------------------------------
.PRECIOUS: .cpp .hpp
.SUFFIXES: .cpp .o
#
#	Abh�gigkeit des Objektfiles vom Sourcefile
.cpp.o:
	@echo "Compiliere: " $<
	$(CC) -c $(CFLAGS)  $<



DOCDIR = docu
DOCINPUT = employ2.hpp bestech.hpp


doc:
	-@rm -rf $(DOCDIR)
	kdoc -p -d $(DOCDIR) -f check $(DOCINPUT)
	kdoc -p -d $(DOCDIR) $(DOCINPUT)
#	kdoc -p -d tex -f latex $(DOCINPUT)

