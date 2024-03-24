CC=gcc
CFLAGS=-I. -g
CPPFLAGS = -I. -g -std=c++11
DEPS = ultron.h
OBJ = ultron.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

%.o: %.cpp $(DEPS)
	g++ -c -o $@ $< $(CPPFLAGS)

default: $(OBJ)
	$(CC) -o ultron $^ $(CFLAGS)

clean:
	rm -f *.o *.out

run: default
	./ultron

test-build: ultron.o test/test_main.o
	g++ -o ultron_test $^ $(CPPFLAGS)

test: test-build
	./ultron_test

test-create: test-build
	./ultron_test Ultron.Creating

test-loading: test-build
	./ultron_test Ultron.Loading

test-adding: test-build
	./ultron_test Ultron.Adding

test-subtracting: test-build
	./ultron_test Ultron.Subtracting

test-branching: test-build
	./ultron_test Ultron.Branching

test-looping: test-build
	./ultron_test Ultron.Looping

test-counting-program: test-build
	./ultron_test Ultron.CountingProgram

test-count-u: default
	./ultron -f count.u
