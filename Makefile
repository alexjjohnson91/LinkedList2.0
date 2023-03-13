CC=g++
CFLAGS=-Wall -Werror -O2 -Iinclude

SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)

all: main

run:
	./main

main: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o main

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm main
	rm main.o
