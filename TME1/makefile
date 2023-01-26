e1:
	gcc -c findLargestNum.c
	gcc findLargestNum.o -o findLargestNum

e2: mainTab.o tab.o
	gcc mainTab.o tab.o -o mainTab

tab.o: tab.c tab.h
	gcc -c tab.c -o tab.o

mainTab.o: mainTab.c tab.h
	gcc -c mainTab.c -o mainTab.o

clean:
	rm -f *.o tme_q1