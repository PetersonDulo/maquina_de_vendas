estudos.exe: estudos.o 
	gcc estudos.o -o estudos.exe
estudos.o: estudos.c
	gcc -c estudos.c
clean:
	rm -rf estudos.exe *.o
run:
	./estudos.exe