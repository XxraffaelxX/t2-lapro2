#include "Aplicacao.hpp"
#include <fstream>
#include <iostream>
#include "FilmeComplemento.hpp"

using namespace std;

Aplicacao::Aplicacao(){

}
Aplicacao::~Aplicacao(){
  //categorias.erase(categorias.begin(),categorias.end());
  categorias.clear();
}
void Aplicacao::adicionaCategoria(Categoria *c){
  int i=0;
  for(vector<Categoria*>::iterator it = categorias.begin ();it!= categorias.end();++it)i++;
  c->defineNome(c->obtemNome());
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
  int i=0,j=0,identificador=0;
  fstream fp;
  fp.open(nomeArquivo,ios::in);
  if(!fp.is_open())return false;
  else{
    int k=0;
    string define="";
    string aux=""; // string auxiliar
    while(!fp.eof()){
      getline(fp,aux); // pega a linha do arq
      i=0;
      j=i; // j pega o valor atual de i 
      while(aux[i]!= '\n'){ // enquanto for diferente do quebra de linha
        while(aux[i]!= ';')i++; // se o indice da palavra for diferente de ';', i++
        if(aux[i] == ';' && identificador == 0){ // categorias  
          define.assign(aux,0,i-1); // copia o aux para define
          j =i;
          int v=0;  // variavel auxiliar
          vector<Categoria*>::iterator it = categorias.begin (); // cit assume o começo do vector
          for(;it!= categorias.end();++it){//inicia no começo e vai até o fim do vetor
            if(categorias[v]->obtemNome() == define){identificador++;i++;break;} // se achou o nome, break
            v++; // avança o auxiliar até tentar achar
          }
          if(it == categorias.end() && identificador == 0){ // se não achou, e o it é igual ao fim
            categorias[k]->defineNome(define); // define o nome 
            identificador++; // avança o identificador 
            i++;
            continue;
          }
        }
        else if(aux[i] == ';' && identificador == 1){ // ano
          define.assign(aux,j+1,i-1);
          j=i;
          i++;
          int aux = stoi(define);
          categorias[k]->defineAno(aux);
          identificador++;
          continue;
        }
        else if(aux[i] == ';' && identificador == 2){ // complemento + filme + vencedor
          if(aux[i+1] == '1'){ // para pegar o complemento
            while(aux[i]!= '#')i++;
            define.assign(aux,j+1,i-1);
            j=i;
            i++;
            while(aux[i]!= ';') i++;
            string define_complemento;
            define_complemento.assign(aux,j+1,i-1); // complemento
            if( aux[i+1] == '1'){ // é vencedor da categoria
              categorias[k]->adicionaFilme(new FilmeComplemento(define,define_complemento),true);
            }
            else{ // não é vencedor da categoria
              categorias[k]->adicionaFilme(new FilmeComplemento(define,define_complemento),false);
            }
          }
          else{ //não tem complemento
            while(aux[i]!= ';') i++;
            define.assign(aux,j+1,i-1);
             if( aux[i+1] == '1'){ // é vencedor da categoria
              categorias[k]->adicionaFilme(new Filme(define),true);
            }
            else{ // não é vencedor da categoria
              categorias[k]->adicionaFilme(new Filme(define),false);
            }
          }
          k++;
          identificador =0;
        }
        i++;        
      }   
    }
    return true;
  }
}
void Aplicacao::relatorioVencedores(){
  int k=0;
  for(vector<Categoria*>::iterator it = categorias.begin ();it!= categorias.end();++it){
    
    k++;
  }
}
void Aplicacao::relatorioIndicacoes(){

}
void Aplicacao::relatorioPremiacoes(){
  
}