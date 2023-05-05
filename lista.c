//LISTA --> Linked List
#include <stdio.h>
#include <stdlib.h>

//criando uma estrutura
struct st_no{
int info;           //campo que recebe a informação
struct st_no *prox; //ponteiro que aponta para a mesma estrutura
};

typedef struct st_no no; //definindo um tipo


no* insereInicio(no *P){
 
    no *novo = (no*) malloc(sizeof(no));
   
    printf("Informe o valor: ");
scanf("%d", &novo->info);
novo->prox = NULL;

if(!vazia(P)){
novo->prox = P;
}
P = novo;
system("pause");

return P;
}

void insereFim(no *P){

if(vazia(P)){
printf("Lista vazia!!");
system("pause");
}else{
no *novo = (no*) malloc(sizeof(no));

printf("Informe o valor: ");
scanf("%d", &novo->info);
novo->prox = NULL;

no *T = P;

while(T->prox != NULL){
T = T->prox;
}
T->prox = novo;
}
}

void insereMeio(no *P){

int valor;
if(vazia(P)){
printf("Lista vazia!!");
system("pause");
}else{

printf("Depois de qual valor deseja inserir um novo elemento?");
scanf("%d", &valor);

no *novo = (no*) malloc(sizeof(no));

printf("Informe o valor: ");
scanf("%d", &novo->info);
novo->prox = NULL;

no *T = P;

for(T = P; T != NULL; T = T->prox){
if(T->info == valor){
novo->prox = T->prox;
T->prox = novo;
}
}
}
}

void exibe(no *P){

if(vazia(P)){
printf("Lista vazia!!");
}else{

no *T = P; //T aponta para o primeiro elemento da lista
do{
printf("  %d  ", T->info);
T = T->prox;
}while(T != NULL);
printf("\n\n");
}
system("pause");

}

int vazia(no *P){
if(P == NULL){  //se o campo prox não esta apontando para ninguem
return 1;  //lista vazia
}else{
return 0;  
}
}


no* removeInicio(no *P){

if(vazia(P)){
printf("Lista vazia!!");
}else{
no *T = P;
P = T->prox;
free(T);
}
system("pause");
return P;
}

no* removeFinal(no *P){
if(vazia(P)){
printf("Lista vazia!");
}
else
{
no* T = P;
no* anterior = T;

while(T->prox != NULL){
anterior = T;
T = T->prox;
}
anterior->prox = NULL;
free(T);

system("pause");
}
}
int main(){

//alocando na memória um ponteiro para uma estrutura no
no *P = (no*) malloc(sizeof(no));

P = NULL;
int op;
do{
system("cls");
printf("Menu de opcoes \n\n");
printf("1 - Inserir no inicio da lista: \n");
printf("2 - Inserir no final da lista: \n");
printf("3 - Inserir no meio da lista: \n");
printf("4 - Remover um elemento do inicio da lista: \n");
printf("5 - Remover um elemento do final da lista: \n");
printf("7 - Exibir a lista: \n");
printf("0 - Sair: \n");
scanf("%d",&op);

switch(op){
case 0:
printf("Finalizando o programa!!");
break;
case 1:
//Inserir no inicio
P = insereInicio(P);
break;
case 2:
//Inserir no final
insereFim(P);
break;
case 3:
//Inserir no meio
insereMeio(P);
break;
case 4:
//Remover no inicio
P = removeInicio(P);
break;

case 5:
//Remover no final
removeFinal(P);
break;

case 7:
//Exibir
exibe(P);
break;
default:
printf("Opcao Invalida!!\n");
system("pause");
}
}while(op != 0);

free(P);  //desalocando o ponteiro
P = NULL;
return 0;
}

