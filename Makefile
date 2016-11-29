
		
main: Process.c Scheduler.c main.c
	gcc -o main main.c process.c scheduler.c -Wall
	
	
	
clean:
	rm -rf *.o

mrproper: clean
	rm -rf main