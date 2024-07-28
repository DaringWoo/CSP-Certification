#include <iostream>
#include <iomanip> // ÓÃÓÚ setw()

using namespace std;

int main() {
    cout << left << setw(20) << "char:" << right << setw(2) << sizeof(char) << " byte(s)" << endl;
    cout << left << setw(20) << "int:" << right << setw(2) << sizeof(int) << " byte(s)" << endl;
    cout << left << setw(20) << "float:" << right << setw(2) << sizeof(float) << " byte(s)" << endl;
    cout << left << setw(20) << "double:" << right << setw(2) << sizeof(double) << " byte(s)" << endl;
    cout << left << setw(20) << "bool:" << right << setw(2) << sizeof(bool) << " byte(s)" << endl;
    cout << left << setw(20) << "short:" << right << setw(2) << sizeof(short) << " byte(s)" << endl;
    cout << left << setw(20) << "long:" << right << setw(2) << sizeof(long) << " byte(s)" << endl;
    cout << left << setw(20) << "long long:" << right << setw(2) << sizeof(long long) << " byte(s)" << endl;
    
    return 0;
}

