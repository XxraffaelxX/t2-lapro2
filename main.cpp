// main.cpp (Roland Teodorowitsch / Raffael Rocha Daltoé; 16 nov. 2020)

#include "Aplicacao.hpp"
#include "Filme.hpp"
#include "FilmeComplemento.hpp"
#include "Categoria.hpp"

void inicializacao(Aplicacao *app) {
    Categoria *c;

    c = new Categoria("Melhor filme",2020);
    c->adicionaFilme(new Filme("O Irlandês"),false);
    c->adicionaFilme(new Filme("Adoráveis Mulheres"),false);
    c->adicionaFilme(new Filme("Era Uma Vez em... Hollywood"),false);
    c->adicionaFilme(new Filme("Parasita"),true);
    c->adicionaFilme(new Filme("História de um Casamento"),false);
    c->adicionaFilme(new Filme("1917"),false);
    c->adicionaFilme(new Filme("Coringa"),false);
    c->adicionaFilme(new Filme("Ford vs Ferrari"),false);
    c->adicionaFilme(new Filme("Jojo Rabbit"),false);
    app->adicionaCategoria(c);

    c = new Categoria("Melhor atriz",2020,1);
    c->adicionaFilme(new FilmeComplemento("Adoráveis Mulheres","Saoirse Ronan"),false);
    c->adicionaFilme(new FilmeComplemento("O Escândalo","Charlize Theron"),false);
    c->adicionaFilme(new FilmeComplemento("História de um Casamento","Scarlett Johansson"),false);
    c->adicionaFilme(new FilmeComplemento("Judy - Muito além do Arco-Íris","Renée Zellweger"),true);
    c->adicionaFilme(new FilmeComplemento("Harriet","Cynthia Erivo"),false);
    app->adicionaCategoria(c);

    c = new Categoria("Melhor ator",2020,1);
    c->adicionaFilme(new FilmeComplemento("Dor e Glória","Antonio Banderas"),false);
    c->adicionaFilme(new FilmeComplemento("Era Uma Vez em... Hollywood","Leonardo DiCaprio"),false);
    c->adicionaFilme(new FilmeComplemento("História de um Casamento","Adam Driver"),false);
    c->adicionaFilme(new FilmeComplemento("Dois Papas","Jonathan Pryce"),false);
    c->adicionaFilme(new FilmeComplemento("Coringa","Joaquin Phoenix"),true);
    app->adicionaCategoria(c);
    
    c = new Categoria("Melhor Diretor",2020,1);
    c->adicionaFilme(new FilmeComplemento("O Irlandês","Martin Scorsese"),false);
    c->adicionaFilme(new FilmeComplemento("1917","Sam Mendes"),false);
    c->adicionaFilme(new FilmeComplemento("Parasita","Bong Joon-Ho"),true);
    c->adicionaFilme(new FilmeComplemento("Coringa","Todd Phillips"),false);
    c->adicionaFilme(new FilmeComplemento("Era Uma Vez em... Hollywood","Quentin Tarantino"),false);
    app->adicionaCategoria(c);

    c = new Categoria("Melhor ator coadjuvante",2020,1);
    c->adicionaFilme(new FilmeComplemento("O Irlandês","Joe Pesci"),false);
    c->adicionaFilme(new FilmeComplemento("Era Uma Vez em... Hollywood","Brad Pitt"),true);
    c->adicionaFilme(new FilmeComplemento("O Irlandês","Al Pacino"),false);
    c->adicionaFilme(new FilmeComplemento("Dois Papas","Anthony Hopkins"),false);
    c->adicionaFilme(new FilmeComplemento("Um Lindo Dia na Vizinhança","Tom Hanks"),false);
    app->adicionaCategoria(c);

    c = new Categoria("Melhor atriz coadjuvante",2020,1);
    c->adicionaFilme(new FilmeComplemento("História de um Casamento","Laura Dern"),true);
    c->adicionaFilme(new FilmeComplemento("Jojo Rabbit","Scarlett Johansson"),false);
    c->adicionaFilme(new FilmeComplemento("Adoráveis Mulheres","Florence Pugh"),false);
    c->adicionaFilme(new FilmeComplemento("O Escândalo","Margot Robbie"),false);
    c->adicionaFilme(new FilmeComplemento("O Caso Richard Jewell","Kathy Bates"),false);
    app->adicionaCategoria(c);
    
    c = new Categoria("Melhor filme internacional",2020,1);
    c->adicionaFilme(new FilmeComplemento("Corpus Christi","Polônia"),false);
    c->adicionaFilme(new FilmeComplemento("Honeyland","Macedônia do Norte"),false);
    c->adicionaFilme(new FilmeComplemento("Os Miseráveis","França"),false);
    c->adicionaFilme(new FilmeComplemento("Parasita","Coreia do Sul"),true);
    c->adicionaFilme(new FilmeComplemento("Dor e Glória","Espanha"),false);
    app->adicionaCategoria(c);
    
    c = new Categoria("Melhor Roteiro original",2020);
    c->adicionaFilme(new Filme("Entre Facas e Segredos"),false);
    c->adicionaFilme(new Filme("História de um Casamento"),false);
    c->adicionaFilme(new Filme("1917"),false);
    c->adicionaFilme(new Filme("Parasita"),true);
    c->adicionaFilme(new Filme("Era Uma Vez em... Hollywood"),false);
    app->adicionaCategoria(c);

    c = new Categoria("Melhor Roteiro adaptado",2020);
    c->adicionaFilme(new Filme("Coringa"),false);
    c->adicionaFilme(new Filme("Adoráveis Mulheres"),false);
    c->adicionaFilme(new Filme("Dois Papas"),false);
    c->adicionaFilme(new Filme("Jojo Rabbi"),true);
    c->adicionaFilme(new Filme("O Irlandês"),false);
    app->adicionaCategoria(c);

    c = new Categoria("Melhor Documentário",2020);
    c->adicionaFilme(new Filme("The Cave"),false);
    c->adicionaFilme(new Filme("Democracia em Vertigem"),false);
    c->adicionaFilme(new Filme("Honeyland"),false);
    c->adicionaFilme(new Filme("For Sama"),false);
    c->adicionaFilme(new Filme("Indústria Americana"),true);
    app->adicionaCategoria(c);

    c = new Categoria("Melhor Animação",2020);
    c->adicionaFilme(new Filme("Como Treinar o Seu Dragão 3"),false);
    c->adicionaFilme(new Filme("Toy Story 4"),true);
    c->adicionaFilme(new Filme("Perdi Meu Corpo"),false);
    c->adicionaFilme(new Filme("Klaus"),false);
    c->adicionaFilme(new Filme("Link Perdido"),false);
    app->adicionaCategoria(c);
    
    c = new Categoria("Melhor Canção Original",2020,1);
    c->adicionaFilme(new FilmeComplemento("Rocketman","(I’m Gonna) Love Me Again, Elton John"),true);
    c->adicionaFilme(new FilmeComplemento("Toy Story 4","I Can’t Let You Throw Yourself Away"),false);
    c->adicionaFilme(new FilmeComplemento("Frozen 2","Into The Unknown"),false);
    c->adicionaFilme(new FilmeComplemento("Superação - O Milagre da Fé","I’m Standing With You"),false);
    c->adicionaFilme(new FilmeComplemento("Harriet","Stand Up"),false);
    app->adicionaCategoria(c);
    
    c = new Categoria("Melhor Fotografia",2020);
    c->adicionaFilme(new Filme("O Irlandês"),false);
    c->adicionaFilme(new Filme("O Farol"),false);
    c->adicionaFilme(new Filme("Coringa"),false);
    c->adicionaFilme(new Filme("1917"),true);
    c->adicionaFilme(new Filme("Era Uma Vez em... Hollywood"),false);
    app->adicionaCategoria(c);
    
    c = new Categoria("Melhor Direção de arte",2020);
    c->adicionaFilme(new Filme("1917"),false);
    c->adicionaFilme(new Filme("O Irlandês"),false);
    c->adicionaFilme(new Filme("Era Uma Vez em... Hollywood"),true);
    c->adicionaFilme(new Filme("Jojo Rabbit"),false);
    c->adicionaFilme(new Filme("Parasita"),false);
    app->adicionaCategoria(c);
    
    c = new Categoria("Melhor Trilha sonora original",2020);
    c->adicionaFilme(new Filme("Adoráveis Mulheres"),false);
    c->adicionaFilme(new Filme("História de Um Casamento"),false);
    c->adicionaFilme(new Filme("1917"),false);
    c->adicionaFilme(new Filme("Coringa"),true);
    c->adicionaFilme(new Filme("Star Wars: A Ascensão Skywalker"),false);
    app->adicionaCategoria(c);
    
    c = new Categoria("Melhor Figurino",2020);
    c->adicionaFilme(new Filme("O Irlandês"),false);
    c->adicionaFilme(new Filme("Jojo Rabbit"),false);
    c->adicionaFilme(new Filme("Era Uma Vez em... Hollywood"),false);
    c->adicionaFilme(new Filme("Coringa"),false);
    c->adicionaFilme(new Filme("Adoráveis Mulheres"),true);
    app->adicionaCategoria(c);
    
    c = new Categoria("Melhor Maquiagem e Penteado",2020);
    c->adicionaFilme(new Filme("Malévola: Dona do Mal"),false);
    c->adicionaFilme(new Filme("1917"),false);
    c->adicionaFilme(new Filme("Coringa"),false);
    c->adicionaFilme(new Filme("Judy: Muito Além do Arco-Íris"),false);
    c->adicionaFilme(new Filme("O Escândalo"),true);
    app->adicionaCategoria(c);
    
    c = new Categoria("Melhores Efeitos Visuais",2020);
    c->adicionaFilme(new Filme("Vingadores: Ultimato"),false);
    c->adicionaFilme(new Filme("1917"),true);
    c->adicionaFilme(new Filme("O Irlandês"),false);
    c->adicionaFilme(new Filme("O Rei Leão"),false);
    c->adicionaFilme(new Filme("Star Wars: A Ascensão Skywalker"),false);
    app->adicionaCategoria(c);
    
    c = new Categoria("Melhor Edição de som",2020);
    c->adicionaFilme(new Filme("1917"),false);
    c->adicionaFilme(new Filme("Coringa"),false);
    c->adicionaFilme(new Filme("Star Wars: A Ascensão Skywalker"),false);
    c->adicionaFilme(new Filme("Era Uma Vez em... Hollywood"),false);
    c->adicionaFilme(new Filme("Ford vs Ferrari"),true);
    app->adicionaCategoria(c);
    
    c = new Categoria("Melhor Mixagem de Som",2020);
    c->adicionaFilme(new Filme("Ad Astra "),false);
    c->adicionaFilme(new Filme("Ford vs Ferrari "),false);
    c->adicionaFilme(new Filme("1917"),true);
    c->adicionaFilme(new Filme("Coringa"),false);
    c->adicionaFilme(new Filme("Era Uma Vez em... Hollywood"),false);
    app->adicionaCategoria(c);
    
    c = new Categoria("Melhor Montagem",2020);
    c->adicionaFilme(new Filme("O Irlandês"),false);
    c->adicionaFilme(new Filme("Jojo Rabbit"),false);
    c->adicionaFilme(new Filme("Coringa"),false);
    c->adicionaFilme(new Filme("Parasita"),false);
    c->adicionaFilme(new Filme("Ford vs Ferrari"),true);
    app->adicionaCategoria(c);
    
    c = new Categoria("Melhor Animação em curta-metragem",2020);
    c->adicionaFilme(new Filme("Dcera (Daughter)"),false);
    c->adicionaFilme(new Filme("Kitbull"),false);
    c->adicionaFilme(new Filme("Memorable"),false);
    c->adicionaFilme(new Filme("Hair Love"),true);
    c->adicionaFilme(new Filme("Sister"),false);
    app->adicionaCategoria(c);

    c = new Categoria("Melhor Curta-metragem",2020);
    c->adicionaFilme(new Filme("Brotherhood"),false);
    c->adicionaFilme(new Filme("Nefta Footbal Club"),false);
    c->adicionaFilme(new Filme("The Neighbors’ Window"),true);
    c->adicionaFilme(new Filme("Saria"),false);
    c->adicionaFilme(new Filme("A Sister"),false);
    app->adicionaCategoria(c);
    
    c = new Categoria("Melhor Documentário de curta-metragem",2020);
    c->adicionaFilme(new Filme("Learning to Skateboard in a Warzone (If You’re a Girl)"),true);
    c->adicionaFilme(new Filme("Lifeovertakesme"),false);
    c->adicionaFilme(new Filme("St. Louis Superman"),false);
    c->adicionaFilme(new Filme("Walk Run Cha-Cha"),false);
    c->adicionaFilme(new Filme("In the Absence"),false);
    app->adicionaCategoria(c);
}

int main() {
    Aplicacao *app;
    
    app = new Aplicacao();
    inicializacao(app);
    app->salvaCSV("oscar2020.csv");
    delete app;
    
    app = new Aplicacao();
    app->carregaCSV("oscar2020.csv");
    app->relatorioVencedores();
    app->relatorioIndicacoes();
    app->relatorioPremiacoes();
    delete app;
    
    return 0;
}
