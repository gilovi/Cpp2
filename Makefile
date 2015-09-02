CC=g++
CPPFLAGS  = -std=c++11 -g -Wextra -Wall
RM=rm -f
TAR = ex2.tar

SRCS= Song.cpp Instrumental.cpp Lyrical.cpp Parameters.cpp SongsFactory.cpp SortHelper.cpp MIR.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

MAIN = MIR

all: $(MAIN)

MIR: $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)
		
Song.o: Song.cpp Song.h Parameters.o

Instrumental.o: Instrumental.cpp Instrumental.h Song.o 

Lyrical.o: Lyrical.cpp Lyrical.h Song.o

Parameters.o: Parameters.h Parameters.cpp 

SongsFactory.o: SongsFactory.h SongsFactory.cpp Parameters.o Lyrical.o Instrumental.o

SortHelper.o: SortHelper.cpp SortHelper.h

MIR.o: MIR.cpp MIR.h Song.o SortHelper.o SongsFactory.o


tar:
	tar cvf $(TAR)  Makefile $(SRCS) Song.h Instrumental.h Lyrical.h Parameters.h SongsFactory.h SortHelper.h


clean:
	$(RM) *.o *~ $(MAIN) $(TAR)
	
	
.PHONY: clean tar all
