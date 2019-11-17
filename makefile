all: open_dir.o
	gcc -o program open_dir.o

open_dir.o: open_dir.c
	gcc -c open_dir.c

run: 
	./program

clean: 
	rm program
	rm *.o