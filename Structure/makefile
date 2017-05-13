NAME=Game


FLAG= -Wall #-std=c99 -ansi

COORDONNEE=./Coordonnee/Coordonnee
LISTE=./Liste/Liste
PLATEAU=./Plateau/Plateau
SAUVEGARDE=./Sauvegarde/Sauvegarde
UNDO=.∕Undo/Undo

all: structure.o test_structure.o
	make structure.o -C ./Coordonnee
	make structure.o -C ./Liste
	make structure.o -C ./Plateau
	make structure.o -C ./Sauvegarde
	gcc -o TEST_${NAME} ${SAUVEGARDE}.o ${COORDONNEE}.o ${LISTE}.o ${PLATEAU}.o ${NAME}.o test_${NAME}.o ${FLAG}


structure.o: ${SAUVEGARDE}.h ${COORDONNEE}.h ${LISTE}.h ${LISTE}.h # ${NAME}.h

	gcc -o ${F_BIN}${NAME}.o -c ${NAME}.c ${FLAG}

test_structure.o: ${NAME}.h
	gcc -o ${F_BIN}test_${NAME}.o -c test_${NAME}.c ${FLAG}
