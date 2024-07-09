PROG = sculptor
CC = g++
CPPFLAGS =	-O0 -g -ansi -Wall -pedantic  
OBJS =	main.o sculptor.o
$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o: main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp
sculptor.o: sculptor.cpp sculptor.h
	$(CC) $(CPPFLAGS) -c sculptor.cpp

clean:
	rm -f $(PROG) $(OBJS)

