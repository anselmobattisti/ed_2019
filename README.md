# Estrutura de Dados

## Datas Importantes

```diff
+ P1: 16/05/2019 (devido aos embargos infringentes)
- P2: 27/06/2019
- Entrega de todas as notas da disciplina: 04/07/2019
```

## Informações do Repositório

Esse repositório contém os exemplos e exercícios feitos na disciplina de Estrutura de Dados do primeiro semestre de 2019.

Professora Isabel Rosseti.
http://www.ic.uff.br/~rosseti/

Quem estiver usando o windows 10, ele tem um ubuntu lite que dá pra ativar, dentro do ubuntu só dar um

```
apt-get update
sudo apt-get install gcc
```

Pra compilar:

```
gcc -o exemplo_1.sh exemplo_1.c
```

Para executar:

```
./exemplo1_sh
```

Para executar passando um arquivo como entrada stdin:

```
./exemplo1_sh < arquivo
```

Se for usar a lib math.h ao compliar o programa é necessário passar como parâmetro -lm

```
gcc test.c -o test -lm
```

A biblioteca de utilidades (utils) contém as seguintes funções:
 ```
 *  void imprime(int *vet, int n);
```

 Para saber como adicioná-la ao seu programa veja[aqui](https://link)

## Links Importantes

1 - Link para os exemplos em sala no github
https://github.com/anselmobattisti/ed_2019

2 - Link para repositório com alguns livros inclusive o do Waldemar Celes (incompleto).
https://www.dropbox.com/sh/bpdjglj5eywmrjd/AADnfRUejiPGjJwn2FJwwvERa?dl=0

3 - Link para o site da Rosseti!:
http://www.ic.uff.br/~rosseti/EDA_PG/2019-1/index.html

4 - Link para o livro do Ceres com as anotações de aula do Anselmo:
https://bit.ly/2USO70g

4.1 - link para slides do livro http://www.inf.puc-rio.br/~inf1620/material.html

5 - Livro de fundamentos em C
https://www.dropbox.com/s/dphguvs8i9k96bl/fundamentos_da_programa.pdf

## Ementa da Disciplina

http://www.ic.uff.br/~rosseti/EDA_PG/2015-2/index.html

## Conteúdos

* Introdução: revisão de C, recursividade e complexidade de algoritmos;
* Listas lineares com alocações sequencial e encadeada;
* pilhas e filas com alocações sequencial e encadeada;
* Árvores: árvores binárias e árvores balanceadas;
* Heaps; e
* Tabelas hash.

### Critério de avaliação
O sistema de avaliação da disciplina consiste na realização de duas provas (P1 e P2) e de um trabalho computacional de grande porte (T). PX, PY e M são calculados como segue: PX = min{P1, P2}, PY = max{P1, P2} e M = {[(PX + T)/2] + PY}/2. Se M ≥ 6.0 e T ≥ 4.0, o aluno será aprovado e a média final (MF), isto é, a nota que consta no histórico escolar do discente será igual a M. Senão se T < 4.0, o aluno será reprovado com MF igual ao mínimo entre 5.9 e M. Senão, o aluno será reprovado com MF igual a M. As provas serão realizadas nos horários de aula.

# Questões da prova P1

* A primeira questão foi a criação de uma estrutura de prateleira e uma estrutura produto. A prateleira tinha um campo peso_total e o produto um campo peso. Foram 4 questões:
a) definir a estrutura
b) criar uma prateleira
c) inserir um produto na prateleira desde que isso não deixasse o peso total da prateleira maior do que o limite dela
e) remover um produto da prateleira

* A segunda questão era dado um n e m, se existir no intervalo de uma lista duplamente encadeada n e m então os seus nós intermediários deviam trocar de lugar de forma inversa:
 lista original a -> b -> c -> d -> e -> f
 se n = c e m = f então a lista final dever ser
 lista final a -> b -> c -> e -> d -> f

* Em uma lista simples dado um número x, para cada ocorrência do número x trocar o seu anterior pelo seu próximo
lista original a -> d -> c -> d -> e -> f
seja n = d
lista final primeiro n c -> d -> a -> d -> e -> f
lista final segundo  n c -> d -> e -> d -> a -> f

* quarta questão: não lembro

* A quinta questão era o Josephus, qual é a posição que ele deve estar para sobreviver ao suicício coletivo.

# Quadro de Estrelinhas

* [Wilker](https://www.github.com/wilker "Wilker")
  * 1 estrela: 'grande contribuição sobre entrada de dados via arquivos'
* Ricardo Machado;
  * 1 estrela: compartilhamento de compilador online de C https://repl.it/languages/c;
* Jane:
  * 1 estrela: muito gentilmente tirou fotos do livro de C para a galera
* Raissa:
  * 1 estrela: achou slide de todos os capítulos do livro do Ceres. http://www.inf.puc-rio.br/~inf1620/material.html
* Samuel:
  * 1 estrela: pelas contribuições de natureza ampla que permitiram um upgrade no status quo intelectual dos membros da irmandade do whatsapp!
* Bruno:
  * compartilhou o link para o site https://www.cs.usfca.edu/~galles/visualization/AVLtree.html