#include <iostream>
using namespace std;

struct No {
	float dado;
	struct No *prox;
};

struct Fila {
	No *ini;
	No *fim;
};

Fila* init() {
	Fila *f = new Fila;
	f->ini =NULL;
	f->fim =NULL;
	return f;
}

int isEmpty(Fila *f){
	return (f->ini==NULL);
}

void enqueue(Fila *f, float v) {
	No *no = new No;
	no->dado = v;
	no->prox = NULL;
	if (isEmpty(f)){
		f->ini=no;
	}
	else
	{
		f->fim->prox=no;
	}
	f->fim=no;
}

float dequeue(Fila *f) {
	float ret;
	No *no = f->ini;
	ret = no->dado;
	f->ini = no->prox;
	if(f->ini==NULL){
		f->fim =NULL;
	}
	free(no);
	return ret;
}

void print(Fila *f) {
	No *no;
	no = f->ini;
	while (no != NULL) {
		cout << no->dado << endl;
		no = no->prox;
	}
	cout << "------------------" << endl;
}

int count(Fila *f) {
	int qtde = 0;
	No *no;
	no = f->ini;
	while (no != NULL) {
		qtde++;
		no = no->prox;
	}
	return qtde;
}

int main(int argc, char** argv)
{
	int op=1; 
	int senha=0;
	Fila *senhasGeradas;
	Fila *senhasAtendidas;
	senhasGeradas = init();
	senhasAtendidas = init();
	
	do
	{
		senha++;
		cout << "Escolha uma opcao: " << endl;
		cout << "0 para finalizar" << endl;
		cout << "1 para gerar senha" << endl;
		cout << "2 para Realizar Atendimento" << endl;
		cout << "Senhas aguardando atendimento: " << count(senhasGeradas) <<endl;
		cout << endl;
		
		cin >> op;
		
		if(op==1)
		{
			enqueue(senhasGeradas, senha);
		}
		
		if(op==2)
		{
			if(isEmpty(senhasGeradas)){
				cout << "Fila está vazia!" << endl;
				cout << "----------------------" << endl;
			}
			else
			{
				enqueue(senhasAtendidas, dequeue(senhasGeradas)); 
			}
		}
		
		if(op==0)
		{
			if(isEmpty(senhasGeradas)){
				op=3;
			}
			else{
				cout << "Para sair, a fila deve estar vazia!" << endl;
				cout << endl;
			}
		}

	}
	while(op!=3);
	
	
	
	return 0;
}