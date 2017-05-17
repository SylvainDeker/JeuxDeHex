NAME=main
EXEC=JeuxDeHex
FLAG= -Wall #-std=c99 -ansi

#Nom des elements
CRD=Coordonnee
LST=Liste
PLT=Plateau
SVG=Sauvegarde
UND=Undo
#Dossier de la strucutre
D_STRUCT=./Structure
#Dossier des elements
D_CRD=${D_STRUCT}/${CRD}
D_LST=${D_STRUCT}/${LST}
D_PLT=${D_STRUCT}/${PLT}
D_SVG=${D_STRUCT}/${SVG}
D_UND=${D_STRUCT}/${UND}


#Chemin d'acces des fichiers (des elements) (sans extansions)
F_CRD=${D_CRD}/${CRD}
F_LST=${D_LST}/${LST}
F_PLT=${D_PLT}/${PLT}
F_SVG=${D_SVG}/${SVG}
F_UND=${D_UND}/${UND}


all: structure.o main.o
	mkfifo java_vers_c
	mkfifo c_vers_java
	gcc -o ${EXEC} ${NAME}.o ${F_CRD}.o ${F_LST}.o ${F_PLT}.o ${F_SVG}.o ${F_UND}.o Interface_c_java/Interface.o  ${FLAG}

structure.o:
	make structure.o -C ${D_CRD}
	make structure.o -C ${D_LST}
	make structure.o -C ${D_PLT}
	make structure.o -C ${D_SVG}
	make structure.o -C ${D_UND}

	make structure.o -C Interface_c_java/

main.o: ${F_CRD}.h ${F_LST}.h ${F_PLT}.h ${F_SVG}.h ${F_UND}.h Interface_c_java/Interface.h
	gcc -o ${NAME}.o -c ${NAME}.c ${FLAG}

clean:
	rm -f *.o
	rm -f ${EXEC}
	rm -f java_vers_c
	rm -f c_vers_java
	make clean -C ${D_CRD}
	make clean -C ${D_LST}
	make clean -C ${D_PLT}
	make clean -C ${D_SVG}
	make clean -C ${D_UND}

run: all
	valgrind ./${EXEC}
	make clean
