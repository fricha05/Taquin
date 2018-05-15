CC=gcc
CFLAGS = -g -O2 -Wall -ansi 
LDLIBS = -lm -lMLV


taquin: plateau.o main.o control.o graphics.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDLIBS)

control.o : control.c control.h plateau.h

graphics.o : graphics.c graphics.h plateau.h

plateau.o: plateau.c plateau.h

main.o: main.c plateau.h graphics.h control.h

%.o: %.c
	$(CC) -c $< $(CFLAGS) $(LDLIBS)

clean:
	-rm -rf $(TARGET)

