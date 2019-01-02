#include <iostream>
#include "potd.cpp"

using namespace std;

int main() {
    unordered_map<string, int> mapA({
                                    {"common", 13}, 
                                    {"fly", 2},
                                    {"unique_a", 13}
                                    });
    unordered_map<string, int> mapB({
                                    {"common", 17}, 
                                    {"fly", 3},
                                    {"unique_b", 17}
                                    });

    unordered_map<string, int> common = common_elems(mapA, mapB);

    cout << mapA["common"] << endl;
    cout << mapB["common"] << endl;
    cout << mapB["fly"] << endl;
    cout << common["fly"] << endl;
    cout << common["common"] << endl;
    cout << common["unique_b"] << endl;
}
