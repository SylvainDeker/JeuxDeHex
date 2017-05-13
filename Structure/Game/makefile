NAME=Game


FLAG= -Wall #-std=c99 -ansi

COORDONNEE=../Coordonnee/Coordonnee
LISTE=../Liste/Liste
PLATEAU=../Plateau/Plateau
SAUVEGARDE=../Sauvegarde/Sauvegarde
UNDO=..∕Undo/Undo

all: structure.o
	make structure.o -C ../Coordonnee
	make structure.o -C ../Liste
	make structure.o -C ../Plateau
	make structure.o -C ../Sauvegarde
	gcc -o TEST_${NAME} ${SAUVEGARDE}.o ${COORDONNEE}.o ${LISTE}.o ${PLATEAU}.o ${NAME}.o ${FLAG}


structure.o: ${SAUVEGARDE}.h ${COORDONNEE}.h ${LISTE}.h ${LISTE}.h
	gcc -o ${NAME}.o -c ${NAME}.c ${FLAG}

clean:
	make clean -C ../Coordonnee
	make clean -C ../Liste
	make clean -C ../Plateau
	make clean -C ../Sauvegarde
	rm -f *.o
	rm -f TEST_${NAME}

run: all
	valgrind ./TEST_${NAME}
	make clean
