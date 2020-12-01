EXECUTAVEL=app
CFLAGS=-c -std=c++11

all:		${EXECUTAVEL}

${EXECUTAVEL}:  main.o Filme.o FilmeComplemento.o Categoria.o Aplicacao.o
		g++ main.o Filme.o FilmeComplemento.o Categoria.o Aplicacao.o -o ${EXECUTAVEL}

main.o:		main.cpp Filme.hpp FilmeComplemento.hpp Categoria.hpp Aplicacao.hpp
		@g++ ${CFLAGS} main.cpp

Filme.o:	Filme.cpp Filme.hpp FilmeComplemento.hpp Categoria.hpp Aplicacao.hpp
		@g++ ${CFLAGS} Filme.cpp

FilmeComplemento.o:	FilmeComplemento.cpp Filme.hpp
		@g++ ${CFLAGS} FilmeComplemento.cpp

Categoria.o:		Categoria.cpp Categoria.hpp Filme.hpp
		@g++ ${CFLAGS} Categoria.cpp

Aplicacao.o:    Aplicacao.cpp Categoria.hpp FilmeComplemento.hpp
		@g++ ${CFLAGS} Aplicacao.cpp

run:		${EXECUTAVEL}
		@./${EXECUTAVEL}

clean:
		@rm -f Filme.o FilmeComplemento.o Categoria.o Aplicacao.o main.o ${EXECUTAVEL}
