// Your code here!
#include "Thing.h"
#include <string>

using namespace potd;
using namespace std;

Thing::Thing(int size) {
	props_max_ = size;
	props_ct_ = 0;
	properties_ = new string[size];
	values_ = new string[size];
}

Thing::Thing(const Thing & right) {
	_copy(right);
}

Thing & Thing::operator=(const Thing & right) {
	if (this != &right) {
		_destroy();
		_copy(right);
	}
	return *this;
}

Thing::~Thing() {
	_destroy();
}

int Thing::set_property(string name, string value) {
	for (int i = 0; i < props_ct_; i++) {
		if (properties_[i] == name) {
			props_ct_++;
			values_[i] = value;
			return i;
		}
	}
	if (props_ct_ >= props_max_) {
		return -1;
	}
	properties_[props_ct_] = name;
	values_[props_ct_] = value;
	props_ct_++;
	return props_ct_ - 1;
}

string Thing::get_property(string name) {
	for (int i = 0; i < props_ct_; i++) {
		if (properties_[i] == name) {
			return values_[i];
		}
	}
	return "";
}

void Thing::_copy(const Thing & right) {
	props_ct_ = right.props_ct_;
	props_max_ = right.props_max_;
	properties_ = new string[props_max_];
	values_ = new string[props_max_];

	for (int i = 0; i < props_ct_; i++) {
		properties_[i] = right.properties_[i];
		values_[i] = right.values_[i];
	}
}

void Thing::_destroy() {
	delete[] properties_;
	delete[] values_;
}