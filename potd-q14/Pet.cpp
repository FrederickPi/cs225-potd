// Pet.cpp
#include "Pet.h"

string Pet::getFood() {return food_;}
string Pet::getName() {return name_;}
string Pet::getOwnerName() {return owner_name_;}
void Pet::setFood(string nu_food) {food_ = nu_food;}
void Pet::setName(string nu_name) {name_ = nu_name;}
void Pet::setOwnerName(string nu_owner_name) {owner_name_ = nu_owner_name;}
string Pet::print() {
	return "My name is " + name_;
}
Pet::Pet() {
	setType("cat");
	food_ = "fish";
	name_ = "Fluffy";
	owner_name_ = "Cinda";
}
Pet::Pet(string nu_type, string nu_food, string nu_name, string nu_owner_name) {
	setType(nu_type);
	food_ = nu_food;
	name_ = nu_name;
	owner_name_ = nu_owner_name;
}