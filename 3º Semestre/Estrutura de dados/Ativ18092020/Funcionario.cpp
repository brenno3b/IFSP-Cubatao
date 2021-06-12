#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

struct Funcionario {
	int prontuario;
	string nome;
	double salario;
	struct Funcionario *prox;
};

Funcionario* init() {
	return NULL;
}

int isEmpty(Funcionario* func) {
	return (func == NULL);
}

//M�todo inserir
Funcionario* insert(Funcionario* func, int i, string nome, double salario) {
	Funcionario* novo = new Funcionario;
	novo->prontuario = i;
	novo->nome = nome;
	novo->salario = salario;
	novo->prox = func;
	return novo;
}

//M�todo listar
void print(Funcionario* func){
	double salarioTotal = 0;
	Funcionario* aux;
	aux = func;
	while (aux != NULL) {
		cout << "Prontu�rio: " << aux->prontuario << endl;
		cout << "Nome: " << aux->nome << endl;
		cout << "Sal�rio: R$" << fixed << setprecision(2) << aux->salario << endl;
		salarioTotal += aux->salario;
		aux = aux->prox;
		cout << endl;		
	}
	
	cout << "Sal�rio total: R$" << fixed << setprecision(2) << salarioTotal << endl;
}

//M�todo pesquisar
Funcionario* find(Funcionario* func, int i) {
	Funcionario* aux;
	aux = func;
	while (aux != NULL && aux->prontuario != i)
	{
		aux = aux->prox;
	}
	if (aux == NULL)
	{
		aux = new Funcionario;
		aux->prontuario = -1;
		aux->prox = NULL;
	}
	return aux;
}

//M�todo excluir
Funcionario* remove(Funcionario* func, int i) {
	Funcionario *ant = NULL;
	Funcionario *aux;
	
	aux = func;
	
	while (aux != NULL && aux->prontuario != i) {
		ant = aux;
		aux = aux->prox;
	}
	if (aux == NULL) {
		return func;
	}
	if (ant == NULL) {
		func = aux->prox;
	}
	else {
		ant->prox = aux->prox;
	}
	free(aux);
	return func;
}

void freeList(Funcionario* func) {
	Funcionario* aux;
	aux = func;
	
	while(aux != NULL) {
		Funcionario *ant = aux->prox;
		free(aux);
		aux = ant;
	}
}

void exitProgram(int &option) {
	string opt;
	cout << endl;
	cout << "Deseja efetuar outra opera��o ? (Y/N)" << endl;
	cout << "Resposta: ";
	cin >> opt;
	if(opt == "N" || opt == "n") {
		option = 0;
	}
}

int main() {
	setlocale(LC_ALL, "");
	Funcionario *funcionario;
	funcionario = init();
	int option, prontuario;
	string nome;
	double salario;	
	
	while(option != 0) {
		cout << "0. Sair" << endl;
		cout << "1. Incluir" << endl;
		cout << "2. Excluir" << endl;
		cout << "3. Pesquisar" << endl;
		cout << "4. Listar" << endl;
		cout << endl;
		cout << "Op��o: ";
		cin >> option;
		system("cls");
		
		if(option == 1) {
			bool isDuplicated = true;
			while(isDuplicated == true) {
				cout << "Digite o prontu�rio: ";
				cin >> prontuario;
				
				Funcionario* procurado = find(funcionario, prontuario);
				if(procurado->prontuario != -1) {
					cout << "Funcionario duplicado, insira outro prontu�rio !" << endl;
					cout << endl;					
				}
				else{
					isDuplicated = false;
				}
			}
			
			cout << "Digite o nome: ";
			cin >> nome;
			cout << "Digite o sal�rio: ";
			cin >> salario;	
			
			funcionario = insert(funcionario, prontuario, nome, salario);	
			
			prontuario = 0;
			nome = "";
			salario = 0;
			
			system("cls");
		}
		if(option == 2) {
			cout << "Digite o prontu�rio: ";
			cin >> prontuario;
			
			funcionario = remove(funcionario, prontuario);
			
			prontuario = 0;
			
			system("cls");
		}
		if(option == 3) {
			cout << "Digite o prontu�rio: ";
			cin >> prontuario;
			
			cout << endl;
			
			Funcionario* procurado = find(funcionario, prontuario);
			if (procurado->prontuario > -1) {
				cout << "Funcion�rio: {" << endl;
				cout << "  Prontu�rio: " << procurado->prontuario << endl;
				cout << "  Nome: " << procurado->nome << endl;
				cout << "  Sal�rio: R$" << fixed << setprecision(2) << procurado->salario << endl;
				cout << "}" << endl;
			}
			else if (procurado->prontuario == -1){
				cout << "N�o encontrado" << endl;
			}
			
			prontuario = 0;
			
			exitProgram(option);
			
			system("cls");
		}
		if(option == 4) {
			print(funcionario);
			
			exitProgram(option);
			
			system("cls");
		}
	}
	return 0;
}