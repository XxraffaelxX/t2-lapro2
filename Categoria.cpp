#include "Categoria.hpp"

Categoria::Categoria(string n = "", int a = 0, int t = 0){
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
  //return nome;
}
void Categoria::adicionaFilme(Filme *f,bool v){
  
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