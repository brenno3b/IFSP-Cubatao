#include <iostream>
#include <locale.h>
#include <stdlib.h>

#include "classes/Contato.h"
#include "classes/Data.h"

using namespace std;

void requestContactInfo(Contato listOfContacts[]) {
	string nome, email, telefone;
	int diaNasc, mesNasc, anoNasc;
	
	for(int i = 0; i < 10; i++) {
		cout << "Digite seu nome: ";
		cin >> nome;
		
		cout << "Digite seu email: ";
		cin >> email;
		
		cout << "Digite seu telefone: ";
		cin >> telefone;
		
		cout << endl;
		
		cout << "Digite o dia do seu nascimento: ";
		cin >> diaNasc;
	
		cout << "Digite o mês do seu nascimento: ";
		cin >> mesNasc;
	
		cout << "Digite o ano do seu nascimento: ";
		cin >> anoNasc;
		
		cout << endl;
		
		listOfContacts[i] = Contato(email, nome, telefone, Data(diaNasc, mesNasc, anoNasc));
		
		system("CLS");
	}
	system("CLS");
}

void showContactInfo(Contato listOfContacts[]) {
	
	for(int i = 0; i < 10; i++) {
		cout << "Nome: " << listOfContacts[i].getNome() << endl;
		cout << "Email: " << listOfContacts[i].getEmail() << endl;
		cout << "Telefone: " << listOfContacts[i].getTelefone() << endl;
		cout << "Idade: " << listOfContacts[i].getIdade() << endl;
		
		cout << endl;
	}
}

void calcAverageAge(Contato listOfContacts[], int &media) {
	
	for(int i = 0; i < 10; i++) {		
		media += listOfContacts[i].getIdade();
	}
	
	media = media / 10;
	
	cout << "Idade média: " << media << endl;
}

void showContactNameMoreThanAvg(Contato listOfContacts[],int media) {
	cout << "Nomes com idade acima da média: " << endl;
	
	for(int i = 0; i < 10; i++) {		
		if(listOfContacts[i].getIdade() > media) {
			cout << listOfContacts[i].getNome() << ";" << endl;
		}
	}
}

void showContactCountMoreThanLegalAge(Contato listOfContacts[]) {
	int quant = 0;
	
	for(int i = 0; i < 10; i++) {		
		if(listOfContacts[i].getIdade() > 18) {
			quant ++;
		}
	}
	
	cout << "Quantidade de contatos maiores de idade: " << quant << endl;
}

void showOldestContact(Contato listOfContacts[]) {
	int aux = 0;
	
	for(int i = 0; i < 10; i++) {
		if(listOfContacts[i].getIdade() > aux) {
			aux = listOfContacts[i].getIdade();
		}
	}
	
	cout << "Contato(s) mais velho(s): " << endl;
	
	for(int i = 0; i < 10; i++) {
		if(listOfContacts[i].getIdade() == aux) {
			
			cout << "Nome: " << listOfContacts[i].getNome() << endl;
			cout << "Email: " << listOfContacts[i].getEmail() << endl;
			cout << "Telefone: " << listOfContacts[i].getTelefone() << endl;
			cout << endl;
		}
	}
}

int main() {
	int media = 0;
	setlocale(LC_ALL, "");
	
	Contato listOfContacts[10];
	
	requestContactInfo(listOfContacts);
	calcAverageAge(listOfContacts, media);
	showContactNameMoreThanAvg(listOfContacts, media);
	showContactCountMoreThanLegalAge(listOfContacts);
	showOldestContact(listOfContacts);

	return 0;
}