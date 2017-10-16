all: hw06.c hw06.h
	gcc hw06.c hw06.h -o hw06
run: all
	./hw06
clean:
	rm *.0
	rm *~
