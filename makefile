all: HWK6.o
	g++ -o HWK6 HWK6.o

HWK6.o: HWK6_tranr5.cpp Addition.h Subtraction.h Multiplication.h Division.h Number.h
	g++ -Wall -c HWK6_tranr5.cpp