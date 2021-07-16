#include <iostream>
#include "String.h"

using namespace std;

void test() {
    String s1("hello");
    String s2(s1);
    String s3 = s1;
}

int main() {
    test();
    return 0;
}
