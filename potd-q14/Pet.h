// Pet.h
#include "Animal.h"

class Pet : public Animal {
	public:
		string getFood();
		string getName();
		string getOwnerName();
		void setFood(string nu_food);
		void setName(string nu_name);
		void setOwnerName(string nu_owner_name);
		string print();
		Pet();
		Pet(string nu_type, string nu_food, string nu_name, string nu_owner_name);
	private:
		string name_;
		string owner_name_;
};