CC=gcc
CXX=g++
CCFLAGS=-Wall -Werror -ansi -pedantic -march=native -O3
CPPFLAGS=$(CCFLAGS) -std=c++11 
LDFLAGS=-lm
EXECUTABLES=text_search Driver num_search str_to_bin bin_to_str \
			reverse_string mem_pool missing counting_sort
DRIVER_OBJECTS=Driver.o FileUtils.o TextUtils.o

all: $(EXECUTABLES)

missing: missing.c
	$(CC) $(CCFLAGS) -o $@ $^

counting_sort: counting_sort.c
	$(CC) $(CCFLAGS) -o $@ $^

Driver: $(DRIVER_OBJECTS)
	$(CXX) $(LDFLAGS) $(DRIVER_OBJECTS) -o $@

%.o: %.cpp %.hpp
	$(CXX) -c $(CPPFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLES)
