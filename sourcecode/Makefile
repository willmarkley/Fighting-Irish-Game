all:	main

main: main.o Room.o
	g++ -o main main.o Room.o -lSDL -lSDL_image

main.o: main.cpp
	g++ -c main.cpp

Room.o:  Room.cpp
	g++ -c Room.cpp

clean:
	rm -f *.o main
