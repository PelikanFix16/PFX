CC = clang++
OTHERDIR=Engine
OTHERDIRMAIN=Application
CFLAGS =-Wall
FRAMEWORKS = -framework OpenGl -framework IOKit -framework Cocoa -framework Carbon
LIBS = -lglfw -lglew 
RM=rm -f
all: main 
	

main: main.o PFXInit.o PFXController.o Shader.o Buffer.o Texture.o stb_image.o
	$(CC) $(CFLAGS) $(FRAMEWORKS) $(LIBS) main.o PFXInit.o Buffer.o PFXController.o Shader.o Texture.o stb_image.o -o main

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
Texture.o: $(OTHERDIR)/Texture.h
	$(CC) -c $(CFLAGS) $(OTHERDIR)/Texture.cpp 
stb_image.o: $(OTHERDIR)/stb_image.h
	$(CC) -c $(OTHERDIR)/stb_image.cpp
clean:
	${RM} *.o main

