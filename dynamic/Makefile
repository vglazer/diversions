CFLAGS  = -std=c99 -pedantic -Wall -O2 -fPIC
LDLIBS  = 

all : loader libdynamic.so

main : loader.c dynamic.h
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $< $(LDLIBS)

libdynamic.so : dynamic.c dynamic.h
	$(CC) $(CFLAGS) -shared $(LDFLAGS) -o $@ $< $(LDLIBS)

test : loader libdynamic.so
	./$<

clean :
	$(RM) *.o *.so loader
