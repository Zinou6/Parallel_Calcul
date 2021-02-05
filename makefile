all:	OUT

OUT:	main.o creationMatrix.o displayMatrix.o calculator.o
	gcc main.o creationMatrix.o displayMatrix.o calculator.o -o OUT -lpthread

main.o:	main.c
	gcc -c main.c -o main.o 

initMatrix.o:	creationMatrix.c
	gcc -c creationMatrix.c -o creationMatrix.o
	
displayMatrix.o:	displayMatrix.c
	gcc -c displayMatrix.c -o displayMatrix.o	

ThreadCalcul.o:	calculator.c
	gcc -c calculator.c -o calculator.o
	
clean:
	rm -fr OUT *.o
