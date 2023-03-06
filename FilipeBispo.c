//Filipe Bispo Da Silva Menezes      UC 21200457
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include <locale.h>
#define MAX_JOGOS 450
#define TAM_CIDADE 120
#define MAX_PRE 50

typedef struct{
 int identifica;
 float valor;
 char cidade[TAM_CIDADE];
}tJogos;

FILE *abrirArquivo(char[]);
void validaNome();
void menuInicial();
void incluirIdentificador(tJogos jogo[], int i);
void incluirValor(tJogos jogo[], int i);
void incluirCidade(tJogos jogo[], int i);
void listarJogo(tJogos jogo[]);
void consultarJogo(tJogos jogo[]);

int main(){
	setlocale(LC_ALL, "Portuguese");
 char var;
 printf("\nOlá, Bem-vindo\n");
 printf("\nPrimeiro digite o nome do presidente e depois selecione a opção desejada.\n");
 printf("\nPressione qualquer tecla para continuar ou espaço para sair.\n\n");
 var = getch();
 if(var == 32)
 exit(0);
 validaNome();
 menuInicial();
 return 0;
}
void validaNome(){
 FILE *arqJogo;
 char nome[MAX_PRE];
 char nomeNormal[MAX_PRE];
 int i;
 do{
 fflush(stdin);
 printf("Dígite o nome do presidente da CBF: ");
 gets(nome);

 while(nome[i] != '\0'){

 if(nome[i-1] == ' ')
 nome[i] = toupper(nome[i]);
 else
 nome[i] = tolower(nome[i]);
 
 i++;
 }
 nome[0] = toupper(nome[0]);

 if((nome[0] == '\0') || (strlen(nome) > MAX_PRE)){

 printf("\n\n ---------> INVÁLIDO <-----> Digite novamente...\n\n");
 system("pause");
 }
 printf("\n\n%s\n\n", nome);
 
 }while((nome[0] == '\0') || (strlen(nome) > MAX_PRE));
 arqJogo = abrirArquivo("jogo.txt");
 if(arqJogo == NULL){

 printf("\n\n---ERRO ---\n\n");
 exit(0);
}
 fprintf(arqJogo, "Presidente da CBF: %c", nome);
}
void menuInicial(){
 tJogos jogo[MAX_JOGOS];
 int opcao, i, cont;
 char continuar;
 jogo[MAX_JOGOS].identifica = 0;
 jogo[MAX_JOGOS].valor = 0.0;

 cont = 0;
 do{

 printf("\n--------CONTROLE DE ARRECADACÕES CBF--------\n");
 printf("\n 1. Incluir um jogo \n");
 printf("\n 2. Lista de jogos \n");
 printf("\n 3. Consultar jogos cadastrados \n");
 printf("\n 0. Encerrar o programa \n");
 printf("\nEscolha sua opção: ");
 scanf("%d", &opcao);

 if(opcao == 1){

 do{
 incluirIdentificador(jogo, cont);
 incluirValor(jogo, cont);
 incluirCidade(jogo, cont);

 cont++;

 fflush(stdin);
 printf("\n\nDeseja adicionar mais um jogo? sim (s) ou não (n)... ");
 scanf("%c", &continuar);

 if((cont > MAX_JOGOS) && (continuar =='s')){

 printf("\n\n\t--->Limite de jogos foi atingido\a\a\n\n");
 system("pause");
 }

 }while((cont < MAX_JOGOS) && (continuar =='s'));

 }else{
 if(opcao == 2){
 listarJogo(jogo);
 }else{
 if(opcao == 3){
 consultarJogo(jogo);
 }else{
 if(opcao == 0){
 printf("\n\n\t--->Fim de execuçãoo!!!\n\n\a\a\a");
 system("pause");
 }else
 printf("\n\n\t--->Opção inválida!!! Digite novamente...\n\n\a\a");
 }
 }
 }
 }while(opcao != 0);
}
FILE *abrirArquivo(char arquivo[]) {
 FILE *arq = fopen(arquivo, "r+b");
 if (arq == NULL)
arq = fopen(arquivo, "w+b");
return arq;
}
void incluirIdentificador(tJogos jogo[], int i){
 int bandeira = 0, j;

 do{
 do{

 fflush(stdin);
 printf("\n\nNúmero de identificação do jogo: ");
 scanf("%d", &jogo[i].identifica);

 if(i != 0){

 for(j = 0; j <= i; j++){
 if(jogo[i].identifica ==jogo[j].identifica){
 bandeira = 1;
 printf("\n\n\t--->Identificador repetido<---\n\n");
 system("pause");
 }else
 bandeira = 0;
 break;
 }
 }
 }while(bandeira != 0);
 if((jogo[i].identifica > 10000) || (jogo[i].identifica <300)){
 printf("\n\n--->ERRO o valor deve estar entre 10000 e 300, dígite novamente...\n\n\a\a");
 system("pause");
 }
 }while((jogo[i].identifica > 10000) || (jogo[i].identifica <300));
}
void incluirValor(tJogos jogo[], int i){
	
 do{
 printf("\nDígite o valor arrecadado do jogo: ");
 scanf("%f", &jogo[i].valor);
 if((jogo[i].valor < 1000.0) || (jogo[i].valor >1000000.0)){
 printf("\n\n--->ERRO = valor inválido, valor deve estar entre 1.000,00 e 1.000.000,00 - digite novamente...\n\n\a\a");
 system("pause");
 }
 }while((jogo[i].valor < 1000.0) || (jogo[i].valor > 1000000.0));
}
void incluirCidade(tJogos jogo[], int i){
 int aux;
 
 do{
 fflush(stdin);
 printf("\nCidade onde o jogo foi realizado: ");
 gets(jogo[i].cidade);
 while(jogo[i].cidade[aux] != '\0'){

 if(jogo[i].cidade[aux-1] == ' ')
 jogo[i].cidade[aux] =
toupper(jogo[i].cidade[aux]);
 else
 jogo[i].cidade[aux] =
tolower(jogo[i].cidade[aux]);
 aux++;
 }
 jogo[i].cidade[0] = toupper(jogo[i].cidade[0]);

 if((jogo[i].cidade[0] == '\0') ||(strlen(jogo[i].cidade) > TAM_CIDADE)){
 printf("\n\nNome vazio ---------> INVÁLIDO <-----> Digite novamente...\n\n");
 system("pause");
 }
 }while((jogo[i].cidade[0] == '\0') || (strlen(jogo[i].cidade) >TAM_CIDADE));
}
void listarJogo(tJogos jogo[]){
 int i;

 printf("\n\n----------------------------\nCidade Identificador Valor\n----------------------------\n\n");
 for(i = 0; i <= MAX_JOGOS; i++){
 printf("%-12s %-18d %.2f\n", jogo[i].cidade,jogo[i].identifica, jogo[i].valor);
 }
}
void consultarJogo(tJogos jogo[]){
 char continuar;
 int identificador, i;
 do{
 fflush(stdin);
 printf("\n\nDÍgite o número do identificador para a realização da consulta: ");
 scanf("%d", &identificador);

 for(i = 0; i < MAX_JOGOS; i++){
 if(jogo[i].identifica == identificador){
 printf("\n\nJogo Encontrado: \n");
 printf("\n----------------------------\nCidade Identificador Valor\n----------------------------\n");
 printf("\n%-12s %-18d %.2f\n",jogo[i].cidade, jogo[i].identifica, jogo[i].valor);
 break;
 }
 }
 fflush(stdin);
 printf("\n\nFazer nova consulta? sim (s) ou não (n): ");
 scanf("%c", &continuar);
 }while(continuar == 's');
}
