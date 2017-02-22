all: ieee754.h
	gcc ieee754.c -c
	gcc add.c ieee754.o -o ieee754_test

clean:
	rm ieee754.o ieee754_test
