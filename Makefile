CPP=g++
CPPFLAGS=-Wall -Werror -ansi -pedantic -O2
LDFLAGS=-lm
EXECUTABLES=text_search Driver
DRIVER_OBJECTS=Driver.o FileUtils.o TextUtils.o

all: $(EXECUTABLES)

text_search: text_search.o
	$(CPP) $(LDFLAGS) text_search.o -o $@

Driver: $(DRIVER_OBJECTS)
	$(CPP) $(LDFLAGS) $(DRIVER_OBJECTS) -o $@

%.o: %.cpp 
	$(CPP) -c $(CPPFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLES)
