#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

#include "../libs/DataAtual.h"
#include "Data.h"

using namespace std;

#ifndef CONTATO.H
#define CONTATO.H

class Contato {
private:
	string email;
	string nome;
	string telefone;
	Data dtnasc;

public:
	//Constructors
	Contato() {
		this->email = "";
		this->nome = "";
		this->telefone = "";
		this->dtnasc = Data();
	}
	Contato(string email, string nome, string telefone, Data dtnasc) {
		this->email = email;
		this->nome = nome;
		this->telefone = telefone;
		this->dtnasc = dtnasc;
	}

	//Getters
	string getEmail() {
		return this->email;
	}
	string getNome() {
		return this->nome;
	}
	string getTelefone() {
		return this->telefone;
	}
	Data getDtnasc() {
		return this->dtnasc;
	}

	//Setters
	void setEmail(string email) {
		this->email = email;
	}
	void setNome(string nome) {
		this->nome = nome;
	}
	void setTelefone(string telefone) {
		this->telefone = telefone;
	}
	void setDtnasc(Data dtnasc) {
		this->dtnasc = dtnasc;
	}

	int getIdade() {
		Data data = getCurrentDate();

		int idade = data.getAno() - this->dtnasc.getAno();

		if (this->dtnasc.getMes() <= data.getMes()) {
			if (this->dtnasc.getDia() < data.getDia()) {
				idade--;
			}
		}
		return idade;
	}
};

#endif