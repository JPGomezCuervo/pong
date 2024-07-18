CC = gcc
OP =  -o0
FLAGS = -Wall -Wextra -pedantic -ggdb -Wunused-function -Wmissing-prototypes
OBJECTS = main.o 
CFILES = main.c 
BINARY = pong

all: $(BINARY)

$(BINARY): $(OBJECTS)
	$(CC) $(FLAGS) -o $@ $^ -lraylib -lm

%.o:%.c 
	$(CC) $(FLAGS) -c -o $@ $<

