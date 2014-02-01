

OBJS = main.o list.o queue.o
CC = gcc
CFLAGS = -Wall -std=c99 -c
LFLAGS = -Wall
DEBUG = -g

adt : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o adt

%.o : %.c
	$(CC) $(CFLAGS) $<

clean:
	rm -rf *.o


