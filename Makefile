CC=gcc
CFLAGS=-g -O2 -Wall
OBJS=obj/Main.o obj/MatIO.o obj/MatArith.o obj/LibFt.o
EXEC=

all: MultMat

MultMat: $(OBJS)
	$(CC) -o MultMat $(LDFLAGS) $(OBJS)

obj/Main.o: src/Main.c src/../include/MatArith.h src/../include/MatIO.h
	$(CC) -o obj/Main.o -c $(CFLAGS) src/Main.c

obj/MatIO.o: src/MatIO.c src/../include/MatIO.h
	$(CC) -o obj/MatIO.o -c $(CFLAGS) src/MatIO.c

obj/MatArith.o: src/MatArith.c src/../include/MatArith.h
	$(CC) -o obj/MatArith.o -c $(CFLAGS) src/MatArith.c

obj/LibFt.o: src/LibFt.c src/../include/LibFt.h
	$(CC) -o obj/LibFt.o -c $(CFLAGS) src/LibFt.c

clean:
	rm -f obj/Main.o
	rm -f obj/MatIO.o
	rm -f obj/MatArith.o
	rm -f obj/LibFt.o

fclean:
	rm -f MultMat

re:			fclean all

.PHONY:	all clean fclean re
