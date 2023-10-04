#include <iostream>
#include <complex>
using namespace std;

int main(int argc, char *argv[])
{
    complex<int> z1, z2;
    z1 = complex<int>(5,3);
    z2 = complex<int>(-4,2);

    cout << z1 + z2 << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}