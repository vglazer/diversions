CPP=g++
CPPFLAGS=-Wall -Werror -ansi -pedantic -O2
LDFLAGS=-lm
EXECUTABLE=Driver

all: $(EXECUTABLE)

$(EXECUTABLE): Driver.o FileUtils.o TextUtils.o
	$(CPP) $(LDFLAGS) *.o -o $@

FileUtils.o: FileUtils.cpp FileUtils.hpp
	$(CPP) $(CPPFLAGS) -c FileUtils.cpp -o $@

TextUtils.o: TextUtils.cpp TextUtils.hpp
	$(CPP) $(CPPFLAGS) -c TextUtils.cpp -o $@

Driver.o: Driver.cpp FileUtils.hpp TextUtils.hpp
	$(CPP) $(CPPFLAGS) -c Driver.cpp -o $@

clean:
	rm -rf *.o $(EXECUTABLE)