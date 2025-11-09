CC = g++
CFLAGS = -std=c++17 -Wall -O2
SRC = src/main.cpp
OUT = myshell

all:
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)
