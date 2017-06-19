.PHONY: all

#exercise: complete the make file

all: clean
	g++ -std=c++1y -o main main.cpp Resize.cpp Erosion.cpp Lighten.cpp Darken.cpp Panaroma.cpp Dilation.cpp `pkg-config --cflags --libs opencv` -I.
	#g++ -std=c++1y -o main.o main.cpp Resize.cpp -Wall -O `pkg-config --cflags --libs opencv` -I.
	#g++ -o main main.o `pkg-config --cflags --libs opencv` 

clean:
	rm -f *.o main 

