#include "Categoria.hpp"
#include <sstream>
using namespace std;

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
  filmes.clear();
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
  if(v == true)vencedor=1;
  vencedor =0;
}
int Categoria::numFilmes(){
  int i=0;
  for (vector<Filme*>::iterator it = filmes.begin ();it!= filmes.end();++it)i++;
  return i;
}
Filme *Categoria::obtemFilme(int i){
  if(filmes[i]!= nullptr)return filmes[i];
  return nullptr;
}
bool Categoria::ehVencedor(int i){
  if(obtemIndiceFilmeVencedor() == i) return true;
  return false;
}
int Categoria::obtemIndiceFilmeVencedor(){
  int i=0;
  for (vector<Filme*>::iterator it = filmes.begin ();it!= filmes.end();++it){
    if(filmes[i]->obtemNumPremiacoes() ==1 )return i;
    i++;
  }
  return -1;
}
Filme *Categoria::obtemFilmeVencedor(){
  int i=0;
  for (vector<Filme*>::iterator it = filmes.begin ();it!= filmes.end();++it){
    if(filmes[i]->obtemNumPremiacoes() ==1 )return filmes[i];
    i++;
  }
  return nullptr;
}
string Categoria::geraCSV(){
  stringstream csv;
  int i=0;
  for (vector<Filme*>::iterator it = filmes.begin ();it!= filmes.end();++it){
      csv<<nome<<";"<<ano<<";"<<tipo<<";"<<filmes[i]->obtemNome()<<";";
      csv<<filmes[i]->obtemNumPremiacoes()<<endl;
      /*if(tipo >= 1)csv<<"#"<<filmes[i]->
      csv<<";"<<filmes[i]->obtemNumPremiacoes()<<endl;
      else{
        csv<<";"<<filmes[i]->obtemNumPremiacoes()<<endl;
      }*/
      i++;
  }
  return csv.str();
}
bool Categoria::operator ==(Categoria &c){
  return c.nome == nome && c.ano == ano && c.tipo == tipo;
}