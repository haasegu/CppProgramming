#DIRS_EX=intro_function intro_loops intro_secretnumber intro_file_io \
#        intro_vector_densematrix intro_crsmatrix intro_class_area stream densematrices_libs
#DIRS_TASKS=div_3_5 goldbach VecVsList VecVsList_T2 Kahan Means Means_File densematrices Dictionary

DIRS_EX=`ls -d */ |grep -v Guide| grep -v June|grep -v try`
#
WWW_ROOT=${HOME}/public_html/Lectures/Kurs-C/SS24

clean:
	@for i in ${DIRS_EX}; do cd $${i}; make clean_all; cd ..; done
#	rm *.tar

doc:
	@for i in ${DIRS_EX}; do cd $${i}; make doc; cd ..; done

zip:
	@for i in ${DIRS_EX}; do cd $${i}; make zip; cd ..; done
	
tar:
	@for i in ${DIRS_EX}; do cd $${i}; make tar; cd ..; done

www: clean zip doc
	cp *_default.mk ${WWW_ROOT}
#	cp -aur Data ${WWW_ROOT}
	@for i in ${DIRS_EX};\
	do \
	  cp -aur $${i} ${WWW_ROOT}; 	\
	  done
	mv *.zip ${WWW_ROOT}
	cp -aur *.cpp ${WWW_ROOT}

#tasks:
#	@for i in ${DIRS_TASKS}; \
#	do \
#	  cd $${i}; \
#	  make task; \
#	  cd ..; \
#	  mkdir -p ${WWW_ROOT}/$${i};\
#	  cp $${i}/task.pdf ${WWW_ROOT}/$${i};\
#	  done
#	cp goldbach/mayer_primes.h ${WWW_ROOT}/goldbach


# https://www.deadlinkchecker.com/
# https://www.deadlinkchecker.com/
