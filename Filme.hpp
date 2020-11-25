// Filme.hpp (Roland Teodorowitsch; 16 nov. 2020)

#ifndef _FILME_HPP_
#define _FILME_HPP_

#include <string>

using namespace std;

class Filme {
protected:
    string nome;
    int numIndicacoes;
    int numPremiacoes;
public:
    Filme(string n = "") ;
    void defineNome(string n);
    string obtemNome();
    virtual string str();
    virtual string csv();
    int obtemNumIndicacoes();
    int obtemNumPremiacoes();
    void maisUmaIndicacao();
    void maisUmaPremiacao();
};

#endif
