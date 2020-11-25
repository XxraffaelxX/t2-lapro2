#include "FilmeComplemento.hpp"

FilmeComplemento::FilmeComplemento(string n = "", string c = "") {
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

}
string FilmeComplemento::csv(){
  
}