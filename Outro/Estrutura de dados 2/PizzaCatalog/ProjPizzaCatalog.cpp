#include <iostream>
#include <locale.h>
#include "Pizza.h"
#include "Ingredient.h"

using namespace std;

//Popula o array de ingredients
void populateIngredients(Ingredient ingredients[]) {
	ingredients[0] = Ingredient("Queijo", 20, 7.50);
	ingredients[1] = Ingredient("Calabresa", 3, 10);
	ingredients[2] = Ingredient("Frango", 8, 11.50);
	ingredients[3] = Ingredient("Catupiry", 15, 4.35);	
	ingredients[4] = Ingredient("Azeitona", 50, 1.50);
	ingredients[5] = Ingredient("Ovos", 50, 2.15);
	ingredients[6] = Ingredient("Molho de tomate", 12, 3.50);
	ingredients[7] = Ingredient("Bacon", 9, 9.23);
	ingredients[8] = Ingredient("Presunto", 15, 8.75);
	ingredients[9] = Ingredient("Cebola", 12, 6);
	ingredients[10] = Ingredient("Ervilha", 15, 4);
	ingredients[11] = Ingredient("Tomate", 10, 4.95);
	ingredients[12] = Ingredient("Manjericão", 8, 11);
	ingredients[13] = Ingredient("Brigadeiro", 3, 15);
}

//Popula o array de pizzas
void populatePizzas(Pizza pizzas[], Ingredient ingredients[]) {
    pizzas[0] = Pizza("Mussarela", {ingredients[0], ingredients[6]}, 25.00);
    pizzas[1] = Pizza("Calabresa", {ingredients[1]}, 28.00);
	pizzas[2] = Pizza("Portuguesa", {ingredients[5], ingredients[4], ingredients[9], ingredients[10], ingredients[0], ingredients[8]}, 36.00);
    pizzas[3] = Pizza("Marguerita", {ingredients[6], ingredients[0], ingredients[11], ingredients[12]}, 32.00);
    pizzas[4] = Pizza("Frango com catupiry", {ingredients[2], ingredients[3]}, 28.00);
    pizzas[5] = Pizza("Brigadeiro", {ingredients[13]}, 27.50);
}

//Mostra todas as pizzas do cardápio
void showPizzas(Pizza pizzas[], int countOfPizzas){
	
	cout << "-------- Seja bem-vindo a BlueLight's Pizzaria --------" << endl << endl;
	
	for(int i = 0; i < countOfPizzas; i++) {
		cout << "Nome: " << pizzas[i].getName() << endl << endl;
		cout << "Ingredientes: " << endl;
		for(int j = 0; j < 6; j++) {
			if(pizzas[i].getIngredients(j).getName() != ""){
				cout << "- " << pizzas[i].getIngredients(j).getName() << endl;
			}
		}
		cout << endl;
		cout << "Preço: R$" << fixed << setprecision(2) << pizzas[i].getPrice() << endl;
		cout << "-------------------------------" << endl;
	}
}

int main()
{
	//Permite acentos e cedilha
	setlocale(LC_ALL, "");
	
	//Quantidade de pizzas disponíveis
	const int countOfPizzas = 6;
	//Quantidade de ingredientes disponíveis
	const int countOfIngredients = 14;
	
	//Inicialização das classes
	Pizza pizzas[countOfPizzas];
	Ingredient ingredients[countOfIngredients];
	
	populateIngredients(ingredients);
	populatePizzas(pizzas, ingredients);
    
    showPizzas(pizzas, countOfPizzas);
    
    //pizzas[*Insert index here*].showPizza();
    //ingredients[*Insert index here*].showIngredient();
    
    return 0;
}