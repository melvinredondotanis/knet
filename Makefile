CC = gcc
CFLAGS = -Wall -Wextra
SRC = src/main.c src/params.c
OUT = knet

all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

clean:
	rm -f $(OUT)

.PHONY: all clean
