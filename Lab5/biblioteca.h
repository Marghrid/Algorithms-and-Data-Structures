#pragma once
#include <string.h>
#define NUMEROLIVROS 100 
#define MAXTITULO 40 
#define MAXNOME 20 

typedef struct { 
  int dia; 
  int mes; 
  int ano; 
} Data; 

typedef struct { 
  char titulo[MAXTITULO+1]; 
  char autor[MAXNOME+1]; 
  long int isbn; 
  int anoPublicacao; 
  int numeroDaCopia; 
  Data dataEmprestimo; 
  Data dataRetorno; 
} Livro; 


void imprime_menu();
void insere_livro(Livro livros[NUMEROLIVROS], int* n_act_livros);
void mostra_livro(Livro meu_livro);
void mostra_todos_livros(Livro livros[NUMEROLIVROS], int n_act_livros);
int procura_livro(Livro livros[NUMEROLIVROS], long int isbn, int n_act_livros);
int procura_livro_titulo(Livro livros[NUMEROLIVROS], char titulo[], int n_act_livros);
void altera_titulo(Livro* original, char novo_titulo[]);
void elimina_livro(Livro livros[NUMEROLIVROS], long int isbn, int* n_act_livros);
void regista_emprestimo(Livro* livrete, Data datete);
void regista_retorno(Livro* livrex, Data datex);
