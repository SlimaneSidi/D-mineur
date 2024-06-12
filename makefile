demineur : demineur.o genBombes.o menu.o Niveau1.o Niveau2.o Niveau3.o time.o
	gcc -o main main.o fonc.o 

demineur.o : demineur.c
	gcc -g -Wall -c demineur.c 

menu.o : menu.c
	gcc -g -Wall -c menu.c 

genBombes.o : genBombes.c
	gcc -g -Wall -c genBombes.c 

Niveau1.o : Niveau1.c
	gcc -g -Wall -c Niveau1.c

Niveau2.o : Niveau2.c
	gcc -g -Wall -c Niveau2.c

Niveau3.o : Niveau3.c
	gcc -g -Wall -c Niveau3.c

time.o : time.c
	gcc -g -Wall -c time.c

clean :
	rm demineur *.o genBombes *.o menu *.o Niveau1 *.o Niveau2 *.o Niveau3 *.o time *.o