#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Ingredient
{
	private:
		string name;
		int quantity;
		float price;
	public:
		//Constructors
		Ingredient() {
			this->name = "";
			this->quantity = 0;
			this->price = 0;
		}
		Ingredient(string name, int quantity, float price) {
			this->name = name;
			this->quantity = quantity;
			this->price = price;
		}
		
		//Getters
		string getName() {
			return this->name;
		}
		int getQuantity() {
			return this->quantity;
		}
		float getPrice() {
			return this->price;
		}

		//Return all properties and it's values
		void showIngredient(){
			cout << "name: " << this->name << endl;
			cout << "quantity: " << this->quantity << endl;
			cout << "price: " << fixed << setprecision(2) << this->price << endl;
		}
};