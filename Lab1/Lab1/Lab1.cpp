#include "pch.h"
#include <iostream>
using namespace std;

int main() {
    cout << "a=";
    int a; cin >> a;
    cout << "x=";
    int x; cin >> x;
    cout << "c=";
    int c; cin >> c;
    int result;
    int right = a * a * a / 3 - c * (x + 3);

    __asm
    {
        mov eax, a
        imul a
        imul a
        cdq
        mov ebx, 3
        idiv ebx
        mov ebx, eax
        mov eax, x
        add eax, 3
        imul c
        sub ebx, eax
        mov result, ebx
    }
    if (result == right) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    cout << "My answer = " << result << endl;
    cout << "Right answer = " << right << endl;

    return 0;
}
