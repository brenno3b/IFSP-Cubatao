#include <iostream>
#include <locale.h>

using namespace std;

/*
Popula o array passando como args:
@param1: O array v[].
@param2: Passando por refer�ncia a vari�vel aux.
*/
void popularArray(int p[], int &_aux) {
	for(int i = 0; i < 10; i++) {
		cout << "Digite um n�mero: ";
		cin >> p[i];
		_aux = p[i] + _aux;
	}
}

/*
Calcula e retorna a quantidade de valores acima da m�dia, args:
@param1: O array v[].
@param2: Passando o valor m�dia.
*/
int calcQuant(int p[], int _media) {
	int quant = 0;
	
	for(int i = 0; i < 10; i++) {
		if(p[i] > _media) {
			quant++;
		}
	}
	cout << "\n";
	return quant;
}

int main() {
	//Seta os caracteres com acentos.
	setlocale(LC_ALL,"");
	
	int *v, aux = 0, media = 0;
	v = new int[10];
	
	popularArray(v, aux);
	
 	//Calcula a m�dia
	media = aux / 10;
	
	cout << "A quantidade de valores acima da m�dia � de: " << calcQuant(v, media) << endl;
	cout << "M�dia � igual a: " << media << endl;
}