CC=g++
CPPFLAGS= -O3 -fsanitize=address -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format

all: hello

hello: main.o function.o text.o print.o simplify.o norma.o solution.o number.o
	$(CC) $(CPPFLAGS) main.o function.o text.o print.o simplify.o norma.o solution.o number.o

main.o: main.cpp
	$(CC) $(CPPFLAGS) -g -c main.cpp

function.o: function.cpp
	$(CC) $(CPPFLAGS) -c function.cpp

text.o: text.cpp
	$(CC) $(CPPFLAGS) -c text.cpp

print.o: print.cpp
	$(CC) $(CPPFLAGS) -c print.cpp

simplify.o: simplify.cpp
	$(CC) $(CPPFLAGS) -c simplify.cpp

solution.o: solution.cpp
	$(CC) $(CPPFLAGS) -c solution.cpp

norma.o: norma.cpp
	$(CC) $(CPPFLAGS) -c norma.cpp

number.o: number.cpp
	$(CC) $(CPPFLAGS) -c number.cpp

clean:
	rm -rf *.o hello

