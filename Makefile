

  CC = gcc 


  CFLAGS = -std=gnu99 -Wall -pedantic -I/usr/include -I/usr/local/include

  ifeq "x$(MSYSTEM)" "x"
   LIBS = -lpthread
  else
   LIBS = -lwsock32 -lpthreadGC2
  endif
  
  ifeq "x$(PREFIX)" "x"
   PREFIX = $(PS4SDK)
  endif

  all: bin/ps4client

  clean:
	rm -f obj/*.o bin/*client*

  install: bin/ps4client
	strip bin/*client*
	cp bin/*client* $(PREFIX)/bin

 ####################
 ## CLIENT MODULES ##
 ####################

  OFILES += obj/network.o
  obj/network.o: src/network.c src/network.h
	@mkdir -p obj
	$(CC) $(CFLAGS) -c src/network.c -o obj/network.o

  OFILES += obj/ps4link.o
  obj/ps4link.o: src/ps4link.c src/ps4link.h
	@mkdir -p obj
	$(CC) $(CFLAGS) -c src/ps4link.c -o obj/ps4link.o

  OFILES += obj/utility.o
  obj/utility.o: src/utility.c src/utility.h
	@mkdir -p obj
	$(CC) $(CFLAGS) -c src/utility.c -o obj/utility.o

 #####################
 ## CLIENT PROGRAMS ##
 #####################


  bin/ps4client: $(OFILES) src/ps4client.c
	@mkdir -p bin
	$(CC) $(CFLAGS) $(OFILES) src/ps4client.c -o bin/ps4client $(LIBS)
