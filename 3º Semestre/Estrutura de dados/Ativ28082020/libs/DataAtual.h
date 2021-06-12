#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <ctime>

#include "../classes/Data.h"

using namespace std;

#ifndef DATAATUAL.H
#define DATAATUAL.H

//Método que pega a data atual e retorna o construtor da classe data.
extern Data getCurrentDate() {
	time_t date = time(0);
	tm* ltm = localtime(&date);

	int anoAtual = ltm->tm_year + 1900;
	int mesAtual = ltm->tm_mon + 1;
	int diaAtual = ltm->tm_mday;

	return Data(diaAtual, mesAtual, anoAtual);
}

#endif