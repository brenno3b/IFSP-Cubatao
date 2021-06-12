#pragma once
#include <iostream>
#include <assert.h>
#include <iomanip>

#include "Ingredient.h"

using namespace std;

class Pizza
{
	private:
		string name;
		Ingredient ingredients[6];
		float price;
	public:
		//Constructors
		Pizza() {
			this->name = "";
			this->price = 0;
		}
		Pizza(string name, initializer_list<Ingredient> ingredients, float price) {
			this->name = name;
			assert(ingredients.size() <= size_t(this->ingredients));
			copy(ingredients.begin(), ingredients.end(), this->ingredients);
			this->price = price;
		}
		
		//Getters
		string getName() {
			return this->name;
		}
		Ingredient getIngredients(int index) {
			return this->ingredients[index];
		}
		float getPrice() {
			return this->price;
		}

		//Return all properties and it's values
		void showPizza() {
			cout << "name: " << this->name << endl;
			cout << "ingredients: ";
			for(int i = 0; i < 6; i++) {
				cout << this->ingredients[i].getName() << " ";
			}
			cout << endl;
			cout << "price: " << fixed << setprecision(2) << this->price << endl;
		}
};