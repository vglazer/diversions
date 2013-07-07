CPP=g++
CPPFLAGS=-Wall -Werror -ansi -pedantic -O2
LDFLAGS=-lm
EXECUTABLE=Driver

all: $(EXECUTABLE)

$(EXECUTABLE): Driver.o FileUtils.o
	$(CPP) $(LDFLAGS) *.o -o $@

FileUtils.o: FileUtils.cpp FileUtils.hpp
	$(CPP) $(CPPFLAGS) -c FileUtils.cpp -o $@

Driver.o: Driver.cpp FileUtils.hpp
	$(CPP) $(CPPFLAGS) -c Driver.cpp -o $@

clean:
	rm -rf *.o $(EXECUTABLE)