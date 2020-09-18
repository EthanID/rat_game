CXX:=g++

LIBS:=-lSDL2
OBJECTS:=main.o sdl_handler.o

main: $(OBJECTS)
	$(CXX) $^ $(LIBS) -o $@

%.o: %.cpp
	$(CXX) -c $^ -o $@

install: main
	install -m 0755 main /usr/local/bin/rat_game

uninstall:
	rm /usr/local/bin/rat_game

clean:
	rm -f *.o main

.PHONY: clean install uninstall
