#include <vector>
#include "potd.h"
using namespace std;

vector<int> evaluate() {
    vector<int> ret(7);
    ret[0] = 0; // change to 0 or 1
    ret[1] = 0; // change to 0 or 1  // This returns 0 if negative number called
    ret[2] = 1; // change to 0 or 1
    ret[3] = 1; // change to 0 or 1
    ret[4] = 1; // change to 0 or 1 // true
    ret[5] = 0; // change to 0 or 1
    ret[6] = 1; // change to 0 or 1
    return ret;
}