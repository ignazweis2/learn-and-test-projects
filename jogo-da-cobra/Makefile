# executável
TARGET = snake

# compilador
CC = gcc

# flags de compilação
CFLAGS = -Wall
# -lncurses -ltinfo

# arquivos .c
SRC = snake.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) 

# limpar arquivos gerados
clean:
	rm -f $(TARGET)
