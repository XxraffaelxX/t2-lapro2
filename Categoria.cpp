#include "Categoria.hpp"
#include <sstream>
Categoria::Categoria(string n , int a , int t ){
  nome = n;
  ano = a;
  tipo = t;
  vencedor = 0;
}
Categoria::~Categoria(){
  nome = "";
  ano = 0;
  tipo = 0;
  vencedor = 0;
}
void Categoria::defineNome(string n){
  nome = n;
}
string Categoria::obtemNome(){
  return nome;
}
void Categoria::defineAno(int a){
    ano = a;
}
int Categoria::obtemAno(){
  return ano;
}
void Categoria::defineTipo(int t){
  tipo = t;
}
int Categoria::obtemTipo(){
  return tipo;
}
string Categoria::str(){
  stringstream ss;
      ss<<obtemNome()<<"  (";
      ss<<obtemAno()<<")"<<endl;   
    return ss.str();
}
void Categoria::adicionaFilme(Filme *f,bool v){  
    filmes.push_back(f);
    int i=0;
    for (vector<Filme*>::iterator it = filmes.begin ();it!= filmes.end();++it)i++;
    if(v == true)ehVencedor(i);
}
int Categoria::numFilmes(){
  
}
Filme Categoria::*obtemFilme(int i){

}
bool Categoria::ehVencedor(int i){

}
int Categoria::obtemIndiceFilmeVencedor(){

}
Filme Categoria::*obtemFilmeVencedor(){

}
string Categoria::geraCSV(){

}
bool Categoria::operator ==(Categoria &c){

}