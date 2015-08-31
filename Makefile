CC=g++
CPPFLAGS  = -std=c++11 -g -Wextra -Wall
RM=rm -f
TAR = ex2.tar

SRCS=IntMatrix.cpp IntMatrixDriver.cpp 
OBJS=$(subst .cpp,.o,$(SRCS))

MAIN = MIR

all: $(MAIN)

IntMatrixMainDriver: $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)
	
IntMatrix: IntMatrix.o
	
IntMatrix.o: IntMatrix.cpp IntMatrix.h

IntMatrixDriver.o: IntMatrixDriver.cpp IntMatrix.o

tar:
	tar cvf $(TAR) IntMatrix.h IntMatrix.cpp IntMatrixDriver.cpp Makefile


clean:
	$(RM) *.o *~ $(MAIN) $(TAR)
	
	
.PHONY: clean tar all
