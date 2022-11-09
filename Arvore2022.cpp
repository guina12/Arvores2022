#include<stdio.h>
#include<stdlib.h>


struct nodo{
int valor;
struct nodo *left;
struct nodo *righ;

};


typedef struct nodo Nodo;

Nodo *create(int valor){
	Nodo *n =(Nodo*) malloc(sizeof(Nodo)); //Criaçao da funçao para gerar Nós.
	n->valor=valor;
	n->left=NULL;
	n->righ=NULL;
	return n;
}

void add(Nodo *n , int valor){ // Criação Da função para  inserção , a inserção funciona , com uma condição de existência 
                               //se for maior que nó raíz então vai para direita , senão vai para directa, porém usamos a recursividade
                               //para verificar se já existe um valor a esquerda ou mesmo a directa.
	if(valor < n->valor){
		if(n->left==NULL)
			n->left=create(valor);
		else
			add(n->left,valor);
		}else if(n->righ==NULL){
		   n->righ=create(valor);
		}
	else
		add(n->righ,valor);
}


void show(Nodo *n){//A função de impressão também funciona de maneira recursiva , ou seja , enquanto a arvoré for diferente de NULL 
                   // dependeno da verificação de adição ele ira percorrer uma única extremidade da raíz até que encontre um valor que seja NULL
                   //Quando ele encontrar este mesmo valor , vai retornar a função que tinha chamado e vai apresentar o mesmo  valor.
	if(n==NULL)
		return ;
	show(n->left);
	printf("%d\n",n->valor);
	show(n->righ);
}

void remov(Nodo *n,int valor){ //Existe  3 casos para função de remoção:
	Nodo*filho=n;
	Nodo *pai;
	
	do{
		pai=filho;                         
		     if(valor < filho-> valor) // Nestá linha ira se percorrer e verificar se o valor que se dejesa remover está a esquerda ou a direita
			  filho=filho->left;
		      else if(valor > filho->valor)
			     filho=filho->righ;
		        }while(filho!=NULL && filho->valor!=valor);// caso  o filho for NULL e filho->valor = valor que o usúario queira remover , então
		                                                    //quer dizer que se encontrou o valor que se quer remover da árvore.
	
        if(filho!=NULL){
					
				if(filho->left==NULL && filho->righ==NULL){ //1-caso:O pai , não tem filhos.
					if(pai->left==filho) pai->left=NULL;
					if(pai->righ==filho) pai->righ=NULL;
				}
					  if(filho->left!=NULL && filho->righ==NULL){
						if(pai->left == filho) pai->left=filho->left; //2-caso: O pai tem um filho a direita.
						if(pai->righ ==filho) pai->righ=filho->left;
					}

                                if(filho->righ!=NULL && filho->left==NULL){ //2-Caso:O pai tem um filho a esquerda.
								if(pai->righ==NULL) pai->righ=filho->righ;
								if(pai->left==NULL) pai->left=filho->righ;
							}
					
					      if(filho->left!=NULL && filho->righ!=NULL){ //3-caso:O pai tem dois filhos , a esquerda e a direita.
									if(filho->left->righ==NULL){
								     filho->valor=filho->left->valor;
								}else{
									 Nodo*p=filho->left;
									 Nodo*aux=p;
									while(p->righ!=NULL){
										aux=p;
										p=p->righ;
									}
									aux->righ=NULL;
									filho->valor=p->valor;
					}
			   }
         }
	}
  
  
		 
		 

int main(void){

	

  Nodo*root=create(5);
	
	add(root,1);
	add(root,6);
	add(root,2);
	add(root,3);
	add(root,8);
    remov(root,8);
	
	show(root);

	
	return 0;

}
