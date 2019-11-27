contigua.o: mercadito.c
	gcc mercadito.c -c
main.o: main.c
	gcc main.c -c

a.out: main.o mercadito.o
	gcc main.o mercadito.o

run: a.out
	./a.out

clean:
	rm -f a.out main.o mercadito.o
