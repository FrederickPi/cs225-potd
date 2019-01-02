// your code here
#include "Bar.h"
#include "Foo.h"
#include <string>

using namespace potd;
using namespace std;

Bar::Bar(string name) {
	Foo * new_foo = new Foo(name);
	this->f_ = new_foo;
}

Bar::Bar(const Bar & existing) {
	string name = existing.f_->get_name();
	Foo * new_foo = new Foo(name);
	this->f_ = new_foo;
}

Bar::~Bar() {
	delete(this->f_);
}

Bar & Bar::operator=(const Bar & right) {
	delete(this->f_);
	Foo * new_foo = new Foo(right.f_->get_name());
	this->f_ = new_foo;
	return *this;
}

string Bar::get_name() {
	return this->f_->get_name();
}
