NAME=Main


FLAG= -Wall #-std=c99 -ansi

COORDONNEE=./Coordonnee/Coordonnee
LISTE=./Liste/Liste
PLATEAU=./Plateau/Plateau
SAUVEGARDE=./Sauvegarde/Sauvegarde
UNDO=.∕Undo/Undo

all: main.o
    make structure.o -C ./UNDO
    gcc -o ${NAME} ${SAUVEGARDE}.o ${UNDO}.o ${COORDONNEE}.o ${LISTE}.o ${LISTE}.o

main.o ${SAUVEGARDE}.h ${UNDO}.h ${COORDONNEE}.h ${LISTE}.h ${LISTE}.h
    gcc -o ${NAME}.o -c ${NAME}.c ${FLAG}

clean:
    rm -f *.o
    rm -f ${NAME}
    make clean -C ./Coordonnee
    make clean -C ./Liste
    make clean -C ./Plateau
    make clean -C ./Sauvegarde
    make clean -C ./Undo
