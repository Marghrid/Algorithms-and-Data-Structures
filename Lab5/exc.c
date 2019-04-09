#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"

int
main()
{
	int n_act_livros=0;
	int indice;
	long int isbn;
	char c;
	Data datete;
	char titulo[MAXTITULO+1];
	Livro livros[NUMEROLIVROS];
	
	imprime_menu();
	
	while(1)
	{
		c=getchar();
		switch(c)
		{
			case '1':
				insere_livro(livros, &n_act_livros);
				break;
			case '2':
				mostra_todos_livros(livros, n_act_livros);
				break;
			case '3':
				printf("ISBN: ");
				scanf("%ld", &isbn);
				mostra_livro(livros[procura_livro(livros, isbn, n_act_livros)]);
				break;
			case '4':
				printf("Titulo: ");
				scanf("%s", titulo);
				mostra_livro(livros[procura_livro_titulo(livros, titulo, n_act_livros)]);
				break;
			case '5':
				printf("Titulo Antigo: ");
				scanf("%s", titulo);
				indice=procura_livro_titulo(livros, titulo,n_act_livros);
				printf("Titulo Novo: ");
				scanf("%s", titulo);
				
				altera_titulo(&livros[indice], titulo);
				break;
			case '6':
				
				printf("ISBN do livro a eliminar: ");
				scanf("%ld", &isbn);

				elimina_livro(livros, isbn, &n_act_livros);
				break;
			case '7':
				printf("ISBN: ");
				scanf("%ld", &isbn);
				indice=procura_livro(livros, isbn, n_act_livros);
				printf("Data de emprestimo: ");
				scanf("%d%d%d", &datete.dia, &datete.mes, &datete.ano);
				regista_emprestimo(&livros[indice], datete);
				break;
			case '8':
				printf("ISBN: ");
				scanf("%ld", &isbn);
				indice=procura_livro(livros, isbn, n_act_livros);
				printf("Data de Retorno: ");
				scanf("%d%d%d", &datete.dia, &datete.mes, &datete.ano);
				regista_retorno(&livros[indice], datete);
				break;
			case '0':
				return EXIT_SUCCESS;
				break;
			default:
				printf("COMANDO DESCONHECIDO!\n");
		}
		while(getchar()!='\n');
	}
	return EXIT_FAILURE;
}