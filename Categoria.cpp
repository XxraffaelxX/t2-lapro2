#include "Categoria.hpp"
#include <sstream>
#include <iostream>
using namespace std;

Categoria::Categoria(string n , int a , int t ){
  nome = n;
  ano = a;
  tipo = t;
  if(tipo == 0)vencedor = 0;
  vencedor = 1;
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
  f->maisUmaIndicacao(); 
  filmes.push_back(f);  
  if(v == true){
    f->maisUmaPremiacao();
    for(int i=0;i<filmes.size();i++){
      if(filmes[i]->obtemNome() == f->obtemNome()){
        vencedor = i;
        break;
      }
    }
  }
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
  return vencedor;
}
Filme *Categoria::obtemFilmeVencedor(){
  int aux=obtemIndiceFilmeVencedor();
  return filmes[aux];
}
string Categoria::geraCSV(){
  stringstream csv;
  int i=0;
  for (vector<Filme*>::iterator it = filmes.begin ();it!= filmes.end();++it){
      csv<<obtemNome()<<";"<<obtemAno()<<";"<<obtemTipo()<<";";    
      if(obtemTipo() == 1){
        csv<<filmes[i]->csv()<<";"<<filmes[i]->obtemNumPremiacoes()<<endl;
      }
      else{
        csv<<filmes[i]->obtemNome()<<";"<<filmes[i]->obtemNumPremiacoes()<<endl;
      }
      i++;
  }
  return csv.str();
}
bool Categoria::operator==(Categoria &c){
  if( nome == c.obtemNome() && ano == c.obtemAno() && tipo == c.obtemTipo())return true;
  return false;

}