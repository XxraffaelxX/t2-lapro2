#include "Aplicacao.hpp"
#include <fstream>

using namespace std;

Aplicacao::Aplicacao(){

}
Aplicacao::~Aplicacao(){
  //categorias.erase(categorias.begin(),categorias.end());
  categorias.clear();
}
void Aplicacao::adicionaCategoria(Categoria *){
  int i=0;
  for(vector<Categoria*>::iterator it = categorias.begin ();it!= categorias.end();++it)i++;
  categorias[i]->obtemNome();
}
bool Aplicacao::salvaCSV(string nomeArquivo){
  int i=0;
  fstream fp;
  fp.open(nomeArquivo,ios::ate);
  if(!fp.is_open())return false;
  else{
    for(vector<Categoria*>::iterator it = categorias.begin ();it!= categorias.end();++it){
      fp<<categorias[i]->geraCSV()<<endl;
      i++;
    }
    fp.close();
    return true;
  }
}
bool Aplicacao::carregaCSV(string nomeArquivo){
  int i=0;
  fstream fp;
  fp.open(nomeArquivo,ios::in);
  if(!fp.is_open())return false;
  else{
    while(!fp.eof()){
      
    }
    return true;
  }
}
void Aplicacao::relatorioVencedores(){

}
void Aplicacao::relatorioIndicacoes(){

}
void Aplicacao::relatorioPremiacoes(){
  
}