

OBJS = main.o list.o queue.o
CC = gcc
CFLAGS = -Wall -std=c99 -c
LFLAGS = -Wall
DEBUG = -g

adt : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o adt

main.o : main.c list.h queue.h
	$(CC) $(CFLAGS) main.c

list.o : list.c list.h
	$(CC) $(CFLAGS) list.c

queue.o : queue.c queue.h list.h
	$(CC) $(CFLAGS) queue.c

clean:
	rm -rf *.o