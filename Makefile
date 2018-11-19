CC = clang++
OTHERDIR=Engine
OTHERDIRMAIN=Application
CFLAGS =-Wall
FRAMEWORKS = -framework OpenGl -framework IOKit -framework Cocoa -framework Carbon
LIBS = -lglfw -lglew
RM=rm -f
all: main 
	

main: main.o PFXInit.o PFXController.o Shader.o Buffer.o
	$(CC) $(CFLAGS) $(FRAMEWORKS) $(LIBS) main.o PFXInit.o Buffer.o PFXController.o Shader.o -o main

PFXInit.o: $(OTHERDIR)/PFXInit.h
	$(CC) -c $(CFLAGS)  $(OTHERDIR)/PFXInit.cpp
main.o: $(OTHERDIRMAIN)/main.cpp
	$(CC) -c $(CFLAGS) $(OTHERDIRMAIN)/main.cpp
PFXController.o: $(OTHERDIR)/PFXController.h
	$(CC) -c $(CFLAGS) $(OTHERDIR)/PFXController.cpp
Shader.o: $(OTHERDIR)/Shader.h
	$(CC) -c $(CFLAGS) $(OTHERDIR)/Shader.cpp
Buffer.o: $(OTHERDIR)/Buffer.h
	$(CC) -c $(CFLAGS) $(OTHERDIR)/Buffer.cpp
clean:
	${RM} *.o main

