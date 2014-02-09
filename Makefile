
CC     = gcc
CFLAGS = -Wall -std=c99 -c
LFLAGS = -Wall
DEBUG  = -g

OBJS   = main.o list.o queue.o

adt : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o adt

%.o : %.c
	$(CC) $(CFLAGS) $<

clean:
	rm -f *.o


