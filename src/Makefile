EXEC = wav
LIB  = libwav.a
LIB_HEADER = wav.h

MAIN = main.c
SRC = audiotrack.c  wav.c musictrack.c


.PHONY: build run lib


build:
	gcc $(MAIN) $(SRC) -o $(EXEC) -lm
	mv $(EXEC) ../bin

run:
	@cd .. && ./bin/$(EXEC)


lib:
	gcc -c $(SRC) -lm
	ar rcs ../$(LIB) *.o
	mv $(LIB_HEADER) ../

	rm -rf *.o
