# AV2 de Programação em C

## Exercicios:

01. (2.5) Fazer uma agenda de contatos, onde deve ser possivel realizar as seguintes operacoes:
  1. inserir um contato
  2. remover um contato dado o email
  3. listar todos os contatos
  4. listar os contatos dado parte do nome, email ou telefone.

Cada contato tem: Nome, email e telefone
Precisa usar arquivo (texto ou binario) no inicio do programa. Se o arquivo existir, este deve ser lido e no final deve ser gravado.  

02. (3.0) Sua empresa foi contratada para fazer um programa para controlar o estoque de uma loja de brinquedos.  
   Para cada brinquedo temos:   
	codigo: inteiro,  
	categoria : string[20],  
	nome : string[30],  
	preco : real,  
	quantidade : inteiro   

   No programa dever ser possivel realizar as seguintes operacoes:  

   1 - inserir brinquedo  
	 Dado o código do brinquedo veja se ele já existe ou não
   Se já existir, solicite a quantidade e adicione a quantidade lida ao brinquedo já existente.
   Se não existir, solicite todos os dados e adicione o novo brinquedo.  
   2 - remover brinquedo  (dado o código e a quantidade)  
      Se a quantidade for 0, remover o registro do brinquedo  
      Se a quantidade foi maior do que 0, diminuir a quantidade (validar se tem aquela quantidade)   
   3 - atualizar dados do brinquedo  
   4 - listar todos  
   5 - listar todos de uma categoria  
   6 - listar filtrando por parte do nome ou categoria
   
03. (2.5) Fazer o jogo da velha para 2 dois jogadores  

04. (2.0) Fazer um programa que leia dois conjuntos de números reais A e B (no máximo 100), na sequência mostre  
   I - a união dos conjuntos A U B  
  II - a interseção entre os conjuntos A  B  
 III - a diferença de A - B  
	
Obs: conjuntos não tem elementos repetidos, logo isso deve ser garantido em todas as operações.  
