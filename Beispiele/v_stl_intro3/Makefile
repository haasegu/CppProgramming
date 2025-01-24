SHELL=/bin/bash

WWW_BSP=$(HOME)/public_html/Lectures/Kurs-C/Beispiele

CSOURCES = *.cpp */*.cpp
PROTOCOL = check_all.txt


tarname  = Beispiele
tarfiles = $(CSOURCES) *.mws Makefile check_code.sh input.* */*


default: check

tar: clean
	@tar -czf $(tarname).tgz $(tarfiles)
	@ls -sh $(tarname).tgz


zip: clean
	-@rm -f $(tarname).zip
	@zip -9qr $(tarname).zip $(tarfiles)
	@ls -sh $(tarname).zip

archiv: tar zip


clean:
	@rm -rf *.o *.exe a.out */obj */bin */a.out check_all.txt  */*build_log.html
	
clean_all:
	@rm -rf */doxygen

check:
	-@rm -f $(PROTOCOL)
	@for s in $(CSOURCES); do ./check_code.sh $$s; done &> $(PROTOCOL)

www: archiv
	cp -rup * $(WWW_BSP)
	
