CC = clang                   # Use clang instead of gcc
CFLAGS = -Wall -Wextra -g
SRC = src/main.c src/engine.c
OBJ = $(SRC:.c=.o)
OUT = build/game_engine

all:  $(OUT)  

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(OUT)
