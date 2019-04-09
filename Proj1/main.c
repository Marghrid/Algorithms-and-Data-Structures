/* * * * * * * * * * * * * * * *
 *  IAED || PROJETO 1 		   *
 *  80832 Margarida Ferreira   *
 *	81805 Duarte David		   *
 * * * * * * * * * * * * * * * */

#include <stdio.h> 
#include <stdlib.h>
#include "base_dados.h"
#include "comandos.h"

int main()
{
	base_dados base_atual;			// Declaracao da estrutura com todos os dados atuais;
	base_atual.n_aeroportos = 0;

	char command;
	
	while (1) 
	{
		command = getchar(); 		// Le o comando;
		
		switch (command)
		{      
			case 'A':
				// Comando A - adiciona aeroporto; 
				executa_A(&base_atual);
				break;
			
			case 'I':            
				// Comando I - altera a capacidade de um aeroporto;
				executa_I(&base_atual);
				break;
			
			case 'F':
				// Comando F - adiciona voo de ida e volta;  
				executa_F(&base_atual);
				break;
			
			case 'G':
				// Comando G - adiciona rota;
				executa_G(&base_atual);
				break;
			
			case 'R':
				// Comando R - remove voo;
				executa_R(&base_atual);
				break;
			
			case 'S':
				// Comando S - remove voo de ida e volta;
				executa_S(&base_atual);
				break;
			
			case 'N':
				// Comando N - numero de voos;
				executa_N(&base_atual);
				break;
			
			case 'P':
				// Comando P - aeroporto com maior numero de voos;
				executa_P(&base_atual);
				break;
			
			case 'Q':
				// Comando Q - aeroporto mais conectado;
				executa_Q(&base_atual);
				break;
			
			case 'V':
				// Comando V - voo mais popular;
				executa_V(&base_atual);
				break;
			
			case 'C':
				// Comando C - encerra aeroporto;
				executa_C(&base_atual);
				break;
			
			case 'O':
				// Comando O - reabre aeroporto;
				executa_O(&base_atual);
				break;
			
			case 'L':
				// Comando L - emite listagem;
				executa_L(&base_atual);
				break;
			
			case 'X':
				// Comando X - sai do programa;
				executa_X(&base_atual);
				return EXIT_SUCCESS;	// Termina o programa com sucesso;
  
			default:
				printf("ERRO: Comando desconhecido\n");   
		}
		while(getchar()!='\n');		// Le o '\n' introduzido pelo utilizador, bem como quaisquer caracteres que ainda nao lidos;  
	}    
	return EXIT_FAILURE; 			// Termina o programa, retornando um erro (nao e suposto);
} 
