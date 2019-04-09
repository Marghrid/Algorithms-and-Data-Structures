#include <stdio.h>
#include "biblioteca.h"


void imprime_menu()
{
	puts("****BIBLIOTECA DO IST****                               ");
	puts("1 - Inserir novo livro                                  ");
	puts("2 - Listar livros                                       ");
	puts("3 - Procurar livro por isbn                             ");
	puts("4 - Procurar livro por título                           ");
	puts("5 - Alterar título do livro                             ");
	puts("6 - Apagar livro pelo isbn                              ");
	puts("7 - Registar data de empréstimo de um livro pelo isbn   ");
	puts("8 - Registar data de retorno de um livro pelo isbn      ");
	puts("0 - Sair                                                ");
	puts("*************************                               ");
}

void insere_livro(Livro livros[NUMEROLIVROS], int* n_act_livros)
{
	puts("Insira um novo livro:");
	printf("\tTitulo: ");
	scanf("%s", livros[*n_act_livros].titulo);
	printf("\tAutor: ");
	scanf("%s", livros[*n_act_livros].autor);
	printf("\tIsbn: ");
	scanf("%ld", &livros[*n_act_livros].isbn);
	printf("\tAno da Publicacao: ");
	scanf("%d", &livros[*n_act_livros].anoPublicacao);
	printf("\tNumero da Copia: ");
	scanf("%d", &livros[*n_act_livros].numeroDaCopia);
	livros[*n_act_livros].dataEmprestimo=(Data){0,0,0};
	livros[*n_act_livros].dataRetorno=(Data){0,0,0};
	printf("n_act_livros=%d\n", *n_act_livros);
	++*n_act_livros;
	printf("n_act_livros=%d\n", *n_act_livros);
}

void mostra_livro(Livro meu_livro)
{	
	printf("\tTitulo: '%s'\n", meu_livro.titulo);
	printf("\tAutor: %s\n", meu_livro.autor);
	printf("\tIsbn: %ld\n", meu_livro.isbn);
	printf("\tAno da Publicacao: %d\n", meu_livro.anoPublicacao);
	printf("\tNumero da Copia: %d\n", meu_livro.numeroDaCopia);
	printf("\tData de Emprestimo: %02d/%02d/%04d\n", meu_livro.dataEmprestimo.dia,meu_livro.dataEmprestimo.mes,meu_livro.dataEmprestimo.ano);
	printf("\tData de Retorno: %02d/%02d/%04d\n", meu_livro.dataRetorno.dia,meu_livro.dataRetorno.mes,meu_livro.dataRetorno.ano);
	
}

void mostra_todos_livros(Livro livros[NUMEROLIVROS], int n_act_livros)
{
	int i;
	printf("n_act_livros=%d\n", n_act_livros);
	for(i=0; i<n_act_livros;i++)
	{
		mostra_livro(livros[i]);
		printf("\n");
	}
}

int procura_livro(Livro livros[NUMEROLIVROS], long int isbn, int n_act_livros)
{
	int i;
	for(i=0; i<n_act_livros;i++)
	{
		if(livros[i].isbn==isbn)
			return i;
	}
	return -1;
}

int procura_livro_titulo(Livro livros[NUMEROLIVROS], char titulo[], int n_act_livros)
{
	int i;
	for(i=0; i<n_act_livros;i++)
	{
		if(strcmp(livros[i].titulo, titulo)==0)
			return i;
	}
	return -1;
}

void altera_titulo(Livro* original, char novo_titulo[])
{
	sprintf(original->titulo, "%s", novo_titulo);
}

void elimina_livro(Livro *livros, long int isbn, int* n_act_livros)
{
	int indice=procura_livro(livros, isbn, *n_act_livros);
	--*n_act_livros;
	sprintf(livros[indice].titulo, "%s", livros[*n_act_livros].titulo);
	sprintf(livros[indice].autor, "%s", livros[*n_act_livros].autor);
	livros[indice].isbn = livros[*n_act_livros].isbn;
	livros[indice].anoPublicacao = livros[*n_act_livros].anoPublicacao;
	livros[indice].numeroDaCopia = livros[*n_act_livros].numeroDaCopia;
	livros[indice].dataEmprestimo = (Data){livros[*n_act_livros].dataEmprestimo.dia, livros[*n_act_livros].dataEmprestimo.mes, livros[*n_act_livros].dataEmprestimo.ano};
	livros[indice].dataRetorno = (Data){livros[*n_act_livros].dataRetorno.dia, livros[*n_act_livros].dataRetorno.mes, livros[*n_act_livros].dataRetorno.ano};
	
	
}

void regista_emprestimo(Livro* livrete, Data datete)
{
	livrete->dataEmprestimo=(Data){datete.dia, datete.mes, datete.ano};
}

void regista_retorno(Livro* livrex, Data datex)
{
	livrex->dataRetorno=(Data){datex.dia, datex.mes, datex.ano};
}