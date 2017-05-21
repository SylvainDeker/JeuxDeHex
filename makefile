NAME=main
EXEC=JeuxDeHex
FLAG= -Wall #-std=c99 -ansi

#c
#Nom des elements
CRD=Coordonnee
LST=Liste
PLT=Plateau
SVG=Sauvegarde
UND=Undo
ABR=Arbre
SL=Solveur
#Dossier de la strucutre
D_STRUCT=./Structure
#Dossier des elements
D_CRD=${D_STRUCT}/${CRD}
D_LST=${D_STRUCT}/${LST}
D_PLT=${D_STRUCT}/${PLT}
D_SVG=${D_STRUCT}/${SVG}
D_UND=${D_STRUCT}/${UND}
D_ABR=${D_STRUCT}/${ABR}
D_SL=${D_STRUCT}/${SL}
D_IF=./Interface_c_java

#Chemin d'acces des fichiers (des elements) (sans extansions)
F_CRD=${D_CRD}/${CRD}
F_LST=${D_LST}/${LST}
F_PLT=${D_PLT}/${PLT}
F_SVG=${D_SVG}/${SVG}
F_UND=${D_UND}/${UND}
F_ABR=${D_ABR}/${ABR}
F_SL=${D_SL}/${SL}
F_IF=${D_IF}/Interface

#java
D_JAVA=./JavaApplicationInterfaceC
F_JAVA=${D_JAVA}/LaunchGame


all: structure.o main.o

	gcc -o ${EXEC} ${NAME}.o ${F_SL}.o ${F_IF}.o ${F_CRD}.o ${F_LST}.o ${F_PLT}.o ${F_SVG}.o ${F_ABR}.o ${F_UND}.o   ${FLAG}

structure.o:
	make structure.o -C ${D_CRD}
	make structure.o -C ${D_LST}
	make structure.o -C ${D_PLT}
	make structure.o -C ${D_SVG}
	make structure.o -C ${D_UND}
	make structure.o -C ${D_ABR}
	make structure.o -C	${D_IF}
	make structure.o -C ${D_SL}

	make class -C ${D_JAVA}

main.o: ${F_CRD}.h ${F_LST}.h ${F_ABR}.h ${F_PLT}.h ${F_SVG}.h ${F_UND}.h ${F_IF}.h ${F_SL}.h
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
	make clean -C ${D_ABR}
	make clean -C ${D_SL}

	make clean -C ${D_JAVA}


run: all
	mkfifo java_vers_c
	mkfifo c_vers_java
	./${EXEC} &
	make run -C ${D_JAVA}
	make clean

terminal: clean all
	mkfifo java_vers_c
	mkfifo c_vers_java
	xterm ./${EXEC} &
	make run -C ${D_JAVA}
	make clean
