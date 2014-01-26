// EPOS-- OStream Utility Test Program

#include <utility/ostream.h>

__USING_SYS;

int main()
{
    OStream cout;

    cout << "OStream test\n";
    cout << "This is a char:\t\t\t" << 'A' << "\n";
    cout << "This is a negative char:\t" << '\377' << "\n";
    cout << "This is an unsigned char:\t" << 'A' << "\n";
    cout << "This is an int:\t\t\t" << 1 << "\n";
    cout << "This is a negative int:\t\t" << -1 << "\n";
    cout << "This is an unsigned int:\t" << 1 << "\n";
    cout << "This is a short:\t\t" << 1 << "\n";
    cout << "This is a negative short:\t" << -1 << "\n";
    cout << "This is an unsigned short:\t" << 1 << "\n";
    cout << "This is a long:\t\t\t" << 100000 << "\n";
    cout << "This is a negative long:\t" << -100000 << "\n";
    cout << "This is an unsigned long:\t" << 100000 << "\n";
    cout << "This is a string:\t\t" << "string" << "\n";
    cout << "This is a pointer:\t\t" << &cout << "\n";

    return 0;
}
