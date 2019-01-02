// your code here
#pragma once

#include "Foo.h"
#include <string>

using namespace std;

namespace potd {
	class Bar {
		public:
			Bar(string);
			Bar(const Bar &);
			~Bar();
			Bar & operator=(const Bar &);
			string get_name();
		private:
			Foo * f_;
	};
}