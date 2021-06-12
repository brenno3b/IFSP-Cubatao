#include <iostream>

#include "classes/Contato.h"
#include "classes/Data.h"

using namespace std;

void requestContactInfo(string &nome, string &email, string &telefone) {
	cout << "Digite seu nome: ";
	cin >> nome;

	cout << "Digite seu email: ";
	cin >> email;

	cout << "Digite seu telefone: ";
	cin >> telefone;
	
	cout << endl;
}

void requestContactDtnasc(int& diaNasc, int& mesNasc, int& anoNasc) {
	cout << "Digite o dia do seu nascimento: ";
	cin >> diaNasc;

	cout << "Digite o mês do seu nascimento: ";
	cin >> mesNasc;

	cout << "Digite o ano do seu nascimento: ";
	cin >> anoNasc;
	
	cout << endl;
}

void showContactInfo(Contato contato1) {
	cout << "Nome: " << contato1.getNome() << endl;
	cout << "Email: " << contato1.getEmail() << endl;
	cout << "Telefone: " << contato1.getTelefone() << endl;
	cout << "Idade: " << contato1.getIdade() << endl;
}

int main() {
	int diaNasc, mesNasc, anoNasc;
	string nome, email, telefone;

	requestContactInfo(nome, email, telefone);
	requestContactDtnasc(diaNasc, mesNasc, anoNasc);

	Data date = Data(diaNasc, mesNasc, anoNasc);
	Contato contato1 = Contato(email, nome, telefone, date);

	showContactInfo(contato1);

	return 0;
}