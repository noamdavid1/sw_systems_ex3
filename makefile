CC=gcc
FLAGS=-Wall -g
AR=ar -rcs
OBJECTS_MAIN=main.o

all: stringProg

stringProg: $(OBJECTS_MAIN) ex3.a
	$(CC) $(FLAGS) -o stringProg $(OBJECTS_MAIN) ex3.a 

ex3.a: ex3.o
	$(AR) ex3.a ex3.o	

main.o: main.c ex3.h
	$(CC) $(FLAGS) -c main.c

ex3.o: ex3.c ex3.h 
	$(CC) $(FLAGS) -c ex3.c

.PHONY: clean 

clean:
	rm -f *.o *.a stringProg

# run:
# 	./stringProg	