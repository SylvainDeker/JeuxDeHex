NAME=Interface
FLAG= -Wall #-std=c99 -ansi

F_BIN=./
F_EXEC=./


COORDONNEE=../Structure/Coordonnee/Coordonnee
LISTE=../Structure/Liste/Liste
PLATEAU=../Structure/Plateau/Plateau
SAUVEGARDE=../Structure/Sauvegarde/Sauvegarde
ARBRE=../Structure/Arbre/Arbre


all: structure.o test_structure.o
	make structure.o -C ../Structure/Coordonnee
	make structure.o -C ../Structure/Plateau
	make structure.o -C ../Structure/Sauvegarde
	make structure.o -C ../Structure/Arbre
	gcc -o TEST_${NAME} ${SAUVEGARDE}.o ${ARBRE}.o ${COORDONNEE}.o ${LISTE}.o ${PLATEAU}.o ${F_BIN}${NAME}.o ${F_BIN}test_${NAME}.o ${FLAG}


structure.o: ${NAME}.h ${SAUVEGARDE}.h ${COORDONNEE}.h ${LISTE}.h ${LISTE}.h ${ARBRE}.h

	gcc -o ${F_BIN}${NAME}.o -c ${NAME}.c ${FLAG}

test_structure.o: ${NAME}.h
	gcc -o ${F_BIN}test_${NAME}.o -c test_${NAME}.c ${FLAG}

clean:
	rm -f ${F_BIN}*.o
	rm -f ${F_EXEC}TEST_${NAME}

run: all
	valgrind ${F_EXEC}TEST_${NAME}
	make clean
