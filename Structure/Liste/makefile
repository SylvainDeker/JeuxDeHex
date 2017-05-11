NAME=Liste
FLAG= -Wall #-std=c99 -ansi
F_BIN=./
F_EXEC=./

all: structure.o test_structure.o
	gcc -o TEST_${NAME} ${F_BIN}${NAME}.o ${F_BIN}test_${NAME}.o ${FLAG}


structure.o: ${NAME}.h
	gcc -o ${F_BIN}${NAME}.o -c ${NAME}.c ${FLAG}

test_structure.o: ${NAME}.h
	gcc -o ${F_BIN}test_${NAME}.o -c test_${NAME}.c ${FLAG}

clean:
	rm -f ${F_BIN}*.o
	rm -f ${F_EXEC}TEST_${NAME}

run: all
	valgrind ${F_EXEC}TEST_${NAME}
	make clean
