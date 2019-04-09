/* * * * * * * * * * * * * * * *
 *  IAED || PROJETO 1 		   *
 *  80832 Margarida Ferreira   *
 *	81805 Duarte David		   *
 * * * * * * * * * * * * * * * */

/* base_dados.h: 
 *	(1) Declaracao de 2 estruturas uteis para a representacao da informacao;
 *	(2) Declaracao de funcoes de interacao com as estruturas;
 */

#ifndef BASE_DADOS
#define BASE_DADOS

#define MAX_AEROPORTOS 	1000	// Numero maximo de aeroportos suportado no sistema;
#define MAX_VOOS 		1000	// Numero maximo de voos suportados num aeroporto;
#define ENCERRADO 		0
#define ABERTO 			1
#define INEXISTENTE 	-1

typedef struct 					// Define um aeroporto:
{
	char id[4]; 				// ID que representa o aeroporto (especificado pelo utilizador);
	int capacidade;				// Numero maximo de voos de entrada ou saida do aeroporto (especificado pelo utilizador);
	unsigned int estado;		// Colocado originalmente a ABERTO, e podendo ser alterado pelo utilizador (ABERTO / FECHADO);
} aeroporto; 

typedef struct 											// Define uma base de dados, que contem a informacao guardada pelo utilizador:
{
	aeroporto aeroportos[MAX_AEROPORTOS];				// Vetor que contem todos os aeroportos adicionados no sistema ate ao momento;
	unsigned int n_aeroportos;							// Numero de aeroportos actualmente guardados no sistema;
	unsigned int voos[MAX_AEROPORTOS][MAX_AEROPORTOS];	// Matriz que representa o esquema de voos. Por exemplo, a posicao voos[aero1][aero2]
} base_dados;											// 	representa o numero de voos com origem em <aero1> e destino a <aero2>. Os indices
														// 	da poosicao de cada aeroporto correspondem aos da sua posicao no vetor <aeroportos>;

int procura_aeroporto(aeroporto aeroportos[], char id[], int n_aeroportos);
// Retorna o indice do aeroporto associado ao <id>;

int conta_voos_ida_entre(unsigned int voos[][MAX_AEROPORTOS], int origem, int destino);
// Retorna o numero de voos com origem em <origem> e destino a <destino>;

int conta_voos_ida(unsigned int voos[][MAX_AEROPORTOS], int origem, int n_aeroportos);
// Retorna o numero total de voos com origem em <origem>;

int conta_voos_volta(unsigned int voos[][MAX_AEROPORTOS], int destino, int n_aeroportos);
// Retorna o numero total de voos com destino a <destino>;

int conta_voos_entre(unsigned int voos[][MAX_AEROPORTOS], int aeroporto1, int aeroporto2);
// Retorna o numero total de voos entre <aeroporto1> e <aeroporto2>;

int conta_voos_total(unsigned int voos[][MAX_AEROPORTOS], int aeroporto, int n_aeroportos);
// Retorna o numero total de voos com origem ou destino a <aeroporto>;

int conta_voos(unsigned int voos[][MAX_AEROPORTOS], int n_aeroportos);
// Retorna o numero de voos atualmente no sistema;

int conta_ligacoes(unsigned int voos[][MAX_AEROPORTOS], int aeroporto, int n_aeroportos);
// Retorna o numero de aeroportos aos quais <aeroporto> esta ligado;

void adiciona_voo(unsigned int voos[][MAX_AEROPORTOS], int origem, int destino);
// Adiciona um voo com origem em <origem> e destino a <destino>;

void remove_voo(unsigned int voos[][MAX_AEROPORTOS], int origem, int destino);
// Remove um voo com origem em <origem> e destino a <destino>;

void adiciona_voo_ida_volta(unsigned int voos[][MAX_AEROPORTOS], int aeroporto1, int aeroporto2);
// Adiciona um voo de ida e volta entre <origem> e <destino>;

void remove_voo_ida_volta(unsigned int voos[][MAX_AEROPORTOS], int aeroporto1, int aeroporto2);
// Remove um voo de ida e volta entre <origem> e <destino>;

void imprime_aeroporto(base_dados* base_atual, int aeroporto);
// Imprime as informacoes relativas a um aeroporto de acordo com a estrutura esperada no comando L;

void ordenaAeroportos(int indices[], aeroporto aeroportos[], int esquerda, int direita);
// Ordena os aeroportos por ordem alfabetica utilizando o quicksort;
// Esta funcao vai ordenar apenas o vetor 'indices', sendo que podemos aceder ao aeroporto ordenado
//  na posicao[i] atraves de aeroportos[indices[i]];

int particaoAeroportos(int indices[], aeroporto aeroportos[], int esquerda, int direita);
// Funcao de particao usada por 'ordenaAeroportos';

#endif