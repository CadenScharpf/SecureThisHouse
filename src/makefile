CC=g++
CFLAGS=-I.
DEPS = house.hpp
OBJ = secure_house.o house.o
%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

secure_house: $(OBJ)
	$(CC) -o secure_house secure_house.o house.o 