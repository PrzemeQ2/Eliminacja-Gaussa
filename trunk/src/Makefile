
main.o: main.c
	gcc -c main.c
	
mat_io.o: mat_io.c
	gcc -c mat_io.c

gauss.o: gauss.c
	gcc -c gauss.c

backsubst.o: backsubst.c
	gcc -c backsubst.c

final: backsubst.o gauss.o mat_io.o main.o
	gcc mat_io.o gauss.o backsubst.o main.o

clean: 
	rm main.o mat_io.o gauss.o backsubst.o a.out

all: final
