all: sum_nbo
sum_nbo: sum_nbo.o main.o   
	g++ -o sum_nbo sum_nbo.o main.o

main.o: sum_nbo.h main.cpp

sum.o: sum_nbo.h sum_nbo.cpp

clean:
	rm -f sum_nbo
	rm -f *.o
