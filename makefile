CC=gcc
FLAGS=-Wall -g
AR=ar -rcs
OBJECTS_MAIN=main.o

all: stringProg


# .PHONY: run
# run: ex3.c 
# 	 gcc ex3.c -lm
# 	./a.out



stringProg: $(OBJECTS_MAIN) ex3.a
	$(CC) $(FLAGS) -o stringProg $(OBJECTS_MAIN) ex3.a 

ex3.a: ex3.o
	$(AR) ex3.a ex3.o	

main.o: main.c ex3.h
	$(CC) $(FLAGS) -c main.c

ex3.o: ex3.c ex3.h 
	$(CC) $(FLAGS) -c ex3.c

.PHONY: 

clean:
	rm -f *.o *.a stringProg

run:
	./stringProg	