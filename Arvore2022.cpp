#include<stdio.h>
#include<stdlib.h>


struct nodo{
int valor;
struct nodo *left;
struct nodo *righ;

};


typedef struct nodo Nodo;

Nodo *create(int valor){
	Nodo *n =(Nodo*) malloc(sizeof(Nodo)); //Cria�ao da fun�ao para gerar N�s.
	n->valor=valor;
	n->left=NULL;
	n->righ=NULL;
	return n;
}

void add(Nodo *n , int valor){ // Cria��o Da fun��o para  inser��o , a inser��o funciona , com uma condi��o de exist�ncia 
                               //se for maior que n� ra�z ent�o vai para direita , sen�o vai para directa, por�m usamos a recursividade
                               //para verificar se j� existe um valor a esquerda ou mesmo a directa.
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


void show(Nodo *n){//A fun��o de impress�o tamb�m funciona de maneira recursiva , ou seja , enquanto a arvor� for diferente de NULL 
                   // dependeno da verifica��o de adi��o ele ira percorrer uma �nica extremidade da ra�z at� que encontre um valor que seja NULL
                   //Quando ele encontrar este mesmo valor , vai retornar a fun��o que tinha chamado e vai apresentar o mesmo  valor.
	if(n==NULL)
		return ;
	show(n->left);
	printf("%d\n",n->valor);
	show(n->righ);
}

void remov(Nodo *n,int valor){ //Existe  3 casos para fun��o de remo��o:
	Nodo*filho=n;
	Nodo *pai;
	
	do{
		pai=filho;                         
		     if(valor < filho-> valor) // Nest� linha ira se percorrer e verificar se o valor que se dejesa remover est� a esquerda ou a direita
			  filho=filho->left;
		      else if(valor > filho->valor)
			     filho=filho->righ;
		        }while(filho!=NULL && filho->valor!=valor);// caso  o filho for NULL e filho->valor = valor que o us�ario queira remover , ent�o
		                                                    //quer dizer que se encontrou o valor que se quer remover da �rvore.
	
        if(filho!=NULL){
					
				if(filho->left==NULL && filho->righ==NULL){ //1-caso:O pai , n�o tem filhos.
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
