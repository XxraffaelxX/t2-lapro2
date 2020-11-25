#include "FilmeComplemento.hpp"
#include <sstream>

FilmeComplemento::FilmeComplemento(string n , string c ) {
  nome = n;
  complemento = c;
}
void FilmeComplemento::defineComplemento(string c){
  complemento = c;
}
string FilmeComplemento::obtemComplemento(){
  return complemento;
}
string FilmeComplemento::str(){
  stringstream ss;
      ss<<obtemNome()<<" - ";
      ss<<obtemComplemento()<<endl;   
    return ss.str();
}
string FilmeComplemento::csv(){
  stringstream csv;
      csv<<obtemNome()<<" # ";
      csv<<obtemComplemento()<<endl;   
    return csv.str();
}