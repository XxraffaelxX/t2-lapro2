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
    cout<<categorias[i]->obtemNome()<<" = "<<aux->obtemNome()<<endl;
  }
  cout<<endl<<"|*********************************************|"<<endl;
}

static bool compara(Filme *x,Filme *y){
  return x->obtemNumIndicacoes() > y->obtemNumIndicacoes();
}

void Aplicacao::relatorioIndicacoes(){
  int i=0,j=0,k=0;
  vector<Filme *> aux;
  Filme *NomeFilmeTemp;
  cout<<endl<<"Relatório das Indicacoes:" <<endl<<endl;
  for(i=0;i<categorias.size();++i){
      if(aux.size() == 0)aux.push_back(categorias[i]->obtemFilme(j));
      while(1){
        NomeFilmeTemp = categorias[i]->obtemFilme(j);
        if(NomeFilmeTemp == nullptr)break;
        cout<<"nome do filme = "<<NomeFilmeTemp->obtemNome()<<" j = "<<j<<endl;
        //cout<<"Filmes que ja tem no aux="<<aux[k]->obtemNome()<<endl;
        if(aux[k] == nullptr){
          cout<<"vim ver essa porra"<<endl;
          aux.push_back(categorias[i]->obtemFilme(j));
        }
        if(NomeFilmeTemp->obtemNome() == aux[k]->obtemNome()){
          cout<<"vim aqui acrescentar"<<endl;
          aux[k]->maisUmaIndicacao();
        }
        else{
          cout<<"vim adicionar"<<endl;
          aux.push_back(categorias[i]->obtemFilme(j));
          cout<<"consegui adicionar!"<<endl;
        }
        j++;
        k++;
      }
      k=0;
      j=0;
      i++;
  }
  
  //sort(aux.begin(),aux.end(),compara);

  i=0;
  for(vector<Filme*>::iterator it = aux.begin ();it!= aux.end();++it){
    if(it+1 == aux.end()-1)break;
    cout<<aux[i]->str()<<";"<<aux[i]->obtemNumIndicacoes()<<endl;
    i++;
  }
  cout<<endl<<"|*********************************************|"<<endl;
}

void Aplicacao::relatorioPremiacoes(){
  
}