#Fichero: makefile
#Este makefile se encargar de generar el ejecutable del ej6 de la práctica 4 de MP
#Además elimina los .o generados en su creación

libMemoria.a: reservaMemoria.o liberaMemoria.o
	ar -rsv libMemoria.a reservaMemoria.o liberaMemoria.o

crucigrama.x: main.o ficheros.o crucigrama.o libMemoria.a
	gcc -o crucigrama.x main.o ficheros.o crucigrama.o libMemoria.a

reservarMemoria.o: reservaMemoria.c
	gcc -c reservaMemoria.c

liberaMemoria.o: liberaMemoria.c
	gcc -c liberaMemoria.c

ficheros.o: ficheros.c
	gcc -c ficheros.c

crucigrama.o: crucigrama.c
	gcc -c crucigrama.c

main.o: main.c
	gcc -c main.c

clean:
	@echo Borrando los ficheros .o
	@rm *.o
