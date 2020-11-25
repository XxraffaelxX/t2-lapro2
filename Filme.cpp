#include "Filme.hpp"

Filme::Filme(string n ){
  nome = n;
  numIndicacoes = 0;
  numPremiacoes=0;
}
void Filme::defineNome(string n){
  nome = n;
}
string Filme::obtemNome(){
  return nome;
}
int Filme::obtemNumIndicacoes(){
  return numIndicacoes;
}
int Filme::obtemNumPremiacoes(){
  return numPremiacoes;
}
void Filme::maisUmaIndicacao(){
  numIndicacoes++;
}
void Filme::maisUmaPremiacao(){
  numPremiacoes++;
}