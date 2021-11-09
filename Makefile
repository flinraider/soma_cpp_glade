TARGET=soma
CC=g++
DEBUG=-g
OPT=-O0
WARN=-Wall
CCFLAGS=$(DEBUG) $(OPT) $(WARN)
OBJS= soma.o 
GTKFLG=`pkg-config gtkmm-3.0 --cflags --libs`

all: $(OBJS)
	$(CC) -o $(TARGET) $(OBJS) $(GTKFLG)
 
soma.o: soma.cpp
	$(CC) -c $(CCFLAGS) $(GTKFLG) soma.cpp -o soma.o
 
clean:
	@rm -f *.o