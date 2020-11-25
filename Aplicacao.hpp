// Aplicacao.hpp (Roland Teodorowitsch; 16 nov. 2020)

#ifndef _APLICACAO_HPP_
#define _APLICACAO_HPP_

#include <string>
#include "Categoria.hpp"

using namespace std;

class Aplicacao {
private:
    vector<Categoria *> categorias;
public:
    Aplicacao();
    ~Aplicacao();
    void adicionaCategoria(Categoria *);
    bool salvaCSV(string nomeArquivo);
    bool carregaCSV(string nomeArquivo);
    void relatorioVencedores();
    void relatorioIndicacoes();
    void relatorioPremiacoes();
};

#endif
