CC=clang++
PARAM=-std=c++11 -fcxx-exceptions -Wno-deprecated-register
OUTPUT=pca
EIGEN_PATH=/lib/eigen

all: clang

clang: *.cpp *.h
	${CC} -I ${EIGEN_PATH} -o ${OUTPUT} *.cpp ${LLVMPARAM} ${PARAM}

clean:
	rm ${OUTPUT}
