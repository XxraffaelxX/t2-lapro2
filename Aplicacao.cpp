#include "Aplicacao.hpp"
#include <fstream>
#include <iostream>
#include "FilmeComplemento.hpp"
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

Aplicacao::Aplicacao(){}
Aplicacao::~Aplicacao(){
  categorias.clear();
}
void Aplicacao::adicionaCategoria(Categoria *c){
  categorias.push_back(c);
}
bool Aplicacao::salvaCSV(string nomeArquivo){
  int i=0;
  fstream fp;
  fp.open(nomeArquivo,ios::out);
  if(!fp.is_open()){
    cout<<"abertura do arquivo houve algum problema"<<endl;
    return false;
  }
  else{ 
    for(vector<Categoria*>::iterator it = categorias.begin ();it!= categorias.end();++it){
      fp<<categorias[i]->geraCSV();
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
    int k=0,flag=0;
    Categoria *c;
    string categ="",ano="",comple="",filme="",indicacao="";
    string aux=""; // string auxiliar
    while(!fp.eof()){
      flag=0;
      getline(fp,aux); // pega a linha do arq
      //cout<<aux<<endl;
      i=0;
      j=i; // j pega o valor atual de i 
      while(1){ // enquanto for diferente do quebra de linha
        //cout<<"1- aux[i]= "<<aux[i]<<endl;
        while(aux[i]!=';')i++; // nome da categ
        categ.assign(aux,j,i);
        i++;
        j=i;
        while(aux[i]!=';')i++; // ano
        ano.assign(aux,j,i-j);
        int aninho = stoi(ano);
        i++;
        j=i;
        while(aux[i]!=';')i++; // complemento
        comple.assign(aux,j,i-j);
        i++;
        j=i;
        for(int i=0;i<categorias.size();i++){
          if(categorias[i]->obtemNome() == categ){// se ja existir a categoria
            flag++;
            break;
          }
        }
        if(flag ==0){ // se não, vai la e cria ela
          c = new Categoria(categ,aninho);          
          adicionaCategoria(c); 
        }
          if(comple == "1"){ // se tiver complemento
            while(aux[i]!= '#')i++;
              filme.assign(aux,j,i-j); 
              //cout<<"1- peguei o filme = "<<filme<<endl;
              i++;
              j=i;
              //i++;
              while(aux[i]!= ';') i++;
              string define_complemento;
              define_complemento.assign(aux,j,i-j); // 
              //cout<<"aux = "<<aux[i]<<endl;
              
              if( aux[i] == '1'){ // é vencedor da categoria
                c->adicionaFilme(new FilmeComplemento(filme,define_complemento),true);
              }
              else{ // não é vencedor da categoria
                c->adicionaFilme(new FilmeComplemento(filme,define_complemento),false);
              }
          }
          else{
            while(aux[i]!= ';')i++;
              filme.assign(aux,j,i-j);
              //cout<<"2- peguei o filme = "<<filme<<endl;
              i++; 
              j=i;
              //cout<<"aux[i] = "<<aux[i]<<endl;
              if( aux[i] == '1'){ // é vencedor da categoria
                c->adicionaFilme(new Filme(filme),true);
              }
              else{ // não é vencedor da categoria
                c->adicionaFilme(new Filme(filme),false);
              }
          }
          break; // terminou de pegar a linha aqui
      }
    }
  }
  return true;
}

void Aplicacao::relatorioVencedores(){
  Filme *aux;
  cout<<endl<<"Relatório dos Vencedores:" <<endl<<endl;
  for(int i=0;i<categorias.size();++i){
    aux = categorias[i]->obtemFilmeVencedor(); //adiciona o filme vencedor em aux
    cout<<aux->obtemNome()<<endl;
  }
  cout<<endl<<"|*********************************************|"<<endl;
}

void Aplicacao::relatorioIndicacoes(){
  int i=0,j=0;
  vector<Filme *> aux;
  Categoria *ca;
  cout<<endl<<"Relatório dos Indicacoes:" <<endl<<endl;
  for(vector<Categoria*>::iterator it = categorias.begin ();it!= categorias.end();++it){
    ca = categorias[i];
    while(categorias[i]->obtemFilme(j)!=nullptr){
      aux.push_back(categorias[i]->obtemFilme(j)); //adiciona o filme c/ indicacao em aux
      //utilizar multi-set
      j++;
    }
      j=0;
      i++;
  }
  //multiset<Filme*> multiset (aux.begin(),aux.end());

  
  i=0;
  for(vector<Filme*>::iterator it = aux.begin ();it!= aux.end();++it){
    if(it+1 == aux.end()-1)break;
    cout<<aux[i]->str()<<";"<<aux[i]->obtemNumPremiacoes()<<endl;
    i++;
  }
  cout<<endl<<"|*********************************************|"<<endl;
}

void Aplicacao::relatorioPremiacoes(){
  
}