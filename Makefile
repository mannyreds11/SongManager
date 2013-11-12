CC = g++
CFLAGS = 
LDFLAGS =

OBJS = main.o Songs.o example.o 
 
a.out: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS)

clean: 
	rm $(OBJS) a.out core
