CC=gcc
STDFLAGS=-std=c11 -Wall -Werror -Wextra 
TEST_CFLAGS= -g $(STDFLAGS) #-fsanitize=address
GCOV_FLAGS=-fprofile-arcs -ftest-coverage
LINUX_FLAGS=-lpthread -lcheck -pthread -lrt -lm
LIBS=-lcheck
VALGRIND_FLAGS=--trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose

TARGET=math.a

SRC=$(wildcard *.c)
OBJ=$(patsubst %.c,%.o, ${SRC})
# HEADER=$(wildcard *.h)

OS := $(shell uname -s)
USERNAME=$(shell whoami)

ifeq ($(OS),Linux)
  OPEN_CMD = xdg-open
endif
ifeq ($(OS),Darwin)
  OPEN_CMD = open
endif

all: clean $(TARGET)

$(TARGET): ${SRC}
	$(CC) -c $(STDFLAGS) $(SRC)
	ar rc $@ $(OBJ)
	ranlib $@
	cp $@ lib$@

clang:
	clang-format -style=Google -n *.c *.h;

clean_obj:
	rm -rf *.o

clean_lib: 
	rm -rf *.a

clean: clean_lib clean_lib clean_obj
	rm -rf unit_test
	rm -rf RESULT_VALGRIND.txt
