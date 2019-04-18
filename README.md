# Introdução aos Algoritmos e Estruturas de Dados 

**Instituto Superior Técnico - 2º Semestre 2015/16**

Projetos e exercícios de programação da disciplina.


## Projetos:

### Proj1: 
Programa em C que registe e manipule a informação referente à gestão de uma 
rede de aeroportos, modelando-a na forma de um grafo. Cada aeroporto é 
representado por um vértice, enquanto que as arestas entre vértices representam 
ligações aéreas entre dois aeroportos.

Compilação:

```console
cd Proj1
gcc -o airport.out base_dados.c comandos.c main.c
 ```
 
 Exemplo de interação:
 ```console
./airport.out 
A LIS 20
A LAX 10       
A OPO 30
F LAX LIS
F LIS OPO
G LAX OPO
G OPO LAX
N LAX OPO
  Voos entre cidades LAX:OPO:1:1
R LAX OPO
S LAX OPO
  *Impossivel remover voo RT LAX OPO
C LAX
N LAX OPO
  Voos entre cidades LAX:OPO:0:0
O LAX
N LAX OPO
  Voos entre cidades LAX:OPO:0:0
L 1
  LAX:10:0:0
  LIS:20:1:1
  OPO:30:1:1
X
  2:3
 ```
 
Para mais exemplos de interacção consultar os ficheiros de exemplo.

Autores:
- [Duarte David](https://github.com/drcd1)
- [Margarida Ferreira](https://github.com/Marghrid)

Abril 2016

----------


### Proj2:

Programa em linguagem C para contagem do número de ocorrências de cada _hashtag_ num conjunto de mensagens dadas.


Compilação:

```console
cd Proj2
gcc -o hashtag.out comandos.c hashtable.c hashtag.c main.c

```

Exemplo de interação:
 ```console
 
 ./hashtag.out
a A #computer would deserve to be called #intelligent if it could deceive a human into believing that it was human. #turing
a The first principle is that you must not fool #yourself and you are the easiest person to fool. #feynman
m
#computer 1
a Prediction is very difficult, especially about the #future. #bohr
a #Science is a differential equation. #Religion is a boundary condition. #turing
m
#turing 2
a A man provided with paper, pencil, and rubber, and subject to strict discipline, is in effect a #universal #machine. #turing
l
#turing 3
#bohr 1
#computer 1
#feynman 1
#future 1
#intelligent 1
#machine 1
#religion 1
#science 1
#universal 1
#yourself 1
s
11 13
x
```

Para mais exemplos de interacção consultar os ficheiros de exemplo.

Autores:
- [Duarte David](https://github.com/drcd1)
- [Margarida Ferreira](https://github.com/Marghrid)

Maio 2016
