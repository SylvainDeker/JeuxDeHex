NAME=Undo
FLAG= -Wall #-std=c99 -ansi

F_BIN=./
F_EXEC=./


COORDONNEE=../Coordonnee/Coordonnee
LISTE=../Liste/Liste
PLATEAU=../Plateau/Plateau
SAUVEGARDE=../Sauvegarde/Sauvegarde


all: structure.o test_structure.o
	make structure.o -C ../Coordonnee
	make structure.o -C ../Liste
	make structure.o -C ../Plateau
	make structure.o -C ../Sauvegarde
	gcc -o TEST_${NAME} ${SAUVEGARDE}.o ${COORDONNEE}.o ${LISTE}.o ${PLATEAU}.o ${F_BIN}${NAME}.o ${F_BIN}test_${NAME}.o ${FLAG}


structure.o: ${NAME}.h ${SAUVEGARDE}.h ${COORDONNEE}.h ${LISTE}.h ${LISTE}.h

	gcc -o ${F_BIN}${NAME}.o -c ${NAME}.c ${FLAG}

test_structure.o: ${NAME}.h
	gcc -o ${F_BIN}test_${NAME}.o -c test_${NAME}.c ${FLAG}

clean:
	rm -f ${F_BIN}*.o
	rm -f ${F_EXEC}TEST_${NAME}

run: all
	valgrind ${F_EXEC}TEST_${NAME}
	make clean
