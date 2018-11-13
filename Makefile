CC = g++
OTHERDIR=Engine
OTHERDIRMAIN=Application
CFLAGS = -Wall
RM=rm -f


all: main 
	$(RM) *.o

main: main.o PFX_init.o
	$(CC) $(CFLAGS)  main.o PFX_init.o -o main

PFX_init.o: $(OTHERDIR)/PFX_init.cpp
	$(CC) -c $(CFLAGS) $(OTHERDIR)/PFX_init.cpp
main.o: $(OTHERDIRMAIN)/main.cpp
	$(CC) -c $(CFLAGS) $(OTHERDIRMAIN)/main.cpp



clean:
	${RM} *.o main

