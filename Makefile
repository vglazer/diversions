CXX=g++
CPPFLAGS=-Wall -Werror -ansi -pedantic -O2 -std=c++11
LDFLAGS=-lm
EXECUTABLES=text_search Driver num_search str_to_bin bin_to_str \
			reverse_string
DRIVER_OBJECTS=Driver.o FileUtils.o TextUtils.o

all: $(EXECUTABLES)

Driver: $(DRIVER_OBJECTS)
	$(CXX) $(LDFLAGS) $(DRIVER_OBJECTS) -o $@

%.o: %.cpp %.hpp
	$(CXX) -c $(CPPFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLES)
