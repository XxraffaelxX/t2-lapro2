#include "FilmeComplemento.hpp"
#include <sstream>

using namespace std;

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
      ss<<obtemComplemento();   
    return ss.str();
}
string FilmeComplemento::csv(){
  stringstream csv;
      csv<<obtemNome()<<"#";
      csv<<obtemComplemento();   
    return csv.str();
}