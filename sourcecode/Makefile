all:	main

main: main.o Room.o Character.o Item.o
	g++ -o main main.o Room.o Character.o Item.o -lSDL -lSDL_image

main.o: main.cpp
	g++ -c main.cpp

Room.o:  Room.cpp
	g++ -c Room.cpp

Character.o:  Character.cpp
	g++ -c Character.cpp

Item.o: Item.cpp
	g++ -c Item.cpp

clean:
	rm -f *.o main
