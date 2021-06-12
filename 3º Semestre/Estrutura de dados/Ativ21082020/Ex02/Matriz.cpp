#include <iostream>
#include <locale.h>

using namespace std;

/*
Popula as matrizes, args:
@param1: Array de ponteiros matriz 1.
@param2: Array de ponteiros matriz 2.
*/
void popularMatrizes(int *_mat1[], int *_mat2[]) {
	for(int i=0; i<3; ++i)
	{
		_mat1[i] = new int[3];		
		for(int j=0; j<3; ++j)
	    {
	    	cout << "Digite um número: ";
	    	cin >> _mat1[i][j];
	    }
	}
	
	cout << "\n";
	
	for(int i=0; i<3; ++i)
	{
		_mat2[i] = new int[3];		
		for(int j=0; j<3; ++j)
	    {
	    	cout << "Digite um número: ";
	    	cin >> _mat2[i][j];
	    }
	}
	cout << "\n";
}

/*
Mostra e verifica a igualdade das matrizes, args:
@param1: Array de ponteiros matriz 1.
@param2: Array de ponteiros matriz 2.
@param3: Booleano para verificar se as matrizes são iguais.
*/
void mostrarMatrizes(int *_mat1[], int *_mat2[], bool &_igual) {
	for(int i=0; i<3; ++i)
	{
	    for(int j=0; j<3; ++j)
	    {
            cout << _mat1[i][j] << " | ";
            
            if(_mat1[i][j] != _mat2[i][j]) {
				_igual = false;
			}
		}
		cout << "\n"; 
	}
	
	cout << "\n";
	
	for(int i=0; i<3; ++i)
	{
	    for(int j=0; j<3; ++j)
	    {
            cout << _mat2[i][j] << " | ";
		}
		cout << endl; 
	}
	
	cout << "\n";
	
	if(_igual == false) {
		cout << "As matrizes são diferentes !";
	}
	else {
		cout << "As matrizes são iguais !";
	}	
}

int main(){
	//Seta os caracteres com acentos.
	setlocale(LC_ALL,"");
	
	int **mat1, **mat2;
	bool igual = true;
	mat1 = new int*[5];
	mat2 = new int*[5];
	
	popularMatrizes(mat1, mat2);
	mostrarMatrizes(mat1, mat2, igual);
}