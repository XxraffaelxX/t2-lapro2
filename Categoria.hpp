// Categoria.hpp (Roland Teodorowitsch; 16 nov. 2020)

#ifndef _CATEGORIA_HPP_
#define _CATEGORIA_HPP_

#include <string>
#include <vector>
#include "Filme.hpp"

using namespace std;

class Categoria {
private:
    string nome;
    int ano;
    int tipo; // 0 = normal, 1 = +complemento
    vector<Filme *> filmes;
    int vencedor;
public:
    Categoria(string n = "", int a = 0, int t = 0);
    ~Categoria();
    void defineNome(string n);
    string obtemNome();
    void defineAno(int a);
    int obtemAno();
    void defineTipo(int t);
    int obtemTipo();
    string str();
    void adicionaFilme(Filme *f,bool v);
    int numFilmes();
    Filme *obtemFilme(int i);
    bool ehVencedor(int i);
    int obtemIndiceFilmeVencedor();
    Filme *obtemFilmeVencedor();
    string geraCSV();
    bool operator==(Categoria &c);
};

#endif
