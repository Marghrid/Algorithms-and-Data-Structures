/* * * * * * * * * * * * * * * *
 *  IAED || PROJETO 2 		   *
 *  80832 Margarida Ferreira   *
 *	81805 Duarte David		   *
 * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>
#include "comandos.h"
int main()
{
	char command;
	
	// Inicializacao da estrutura de dados:
	data current_data;
	current_data.htable = ht_init(128);
	current_data.hashtags_total = current_data.hashtags_different = 0;
	current_data.best_htag = NULL;

	while (1) 
	{
		command = getchar();
		
		switch (command)
		{      
			case 's':            
				// Comando s - mostra o numero total de hashtags distintas em memoria
				//             e o numero total de ocorrencias de todas as hashtags;
				executa_s(&current_data);
				getchar();
				break;
			
			case 'm':
				// Comando m - mostra a hashtag mais popular e o respetivo numero de
				//             ocorrencias;  
				executa_m(&current_data);
				getchar();
				break;
			
			case 'l':
				// Comando l - lista todas as hashtags em memoria por ordem decrescente
				//    		   segundo o numero de ocorrencias, e por ordem alfabetica 
				//             em caso de este ser igual.
				executa_l(&current_data);
				getchar();
				break;
		
			case 'x':
				// Comando x - sai do programa;
				executa_x(&current_data);
				return EXIT_SUCCESS;

			case 'a':
				// Comando a - le uma mensagem inserida pelo utilizador, interpretando 
				//			   e processando as hashtags;
				if(getchar()==' ')
				{ 
					executa_a(&current_data);
					break;
  				}

			default:
				printf("ERRO: Comando desconhecido\n");   
				while(getchar()!='\n');
		}
				 
	}    
	return EXIT_FAILURE;
} 
