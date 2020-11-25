// FilmeComplemento.hpp (Roland Teodorowitsch; 16 nov. 2020)

#ifndef _FILMECOMPLEMENTO_HPP_
#define _FILMECOMPLEMENTO_HPP_

#include "Filme.hpp"

class FilmeComplemento : public Filme {
private:
    string complemento;
public:
    FilmeComplemento(string n = "", string c = "") ;
    void defineComplemento(string c);
    string obtemComplemento();
    string str();
    string csv();
};

#endif
