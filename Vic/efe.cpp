#include <iostream>
using namespace std;

class Pareja
{
public:
    double a, b;

    // constructor parametrizado
    Pareja(const double a, const double b)
    {
        this->a = a;
        this->b = b;
    }
};

// Sobrecarga del operador +
Pareja &operator+(const Pareja &p1, const Pareja &p2)
{
    return *(new Pareja(p1.a + p2.a, p1.b + p2.b));
}


// Sobrecarga del operador << para la clase Pareja
ostream &operator<<(ostream &o, const Pareja &p)
{
    o << "(" << p.a << ", " << p.b << " )";
    return o;
}

int main()
{
    Pareja A(50, 75);
    Pareja B(150, 175);
    Pareja C = A + B;

    cout << "A = " << A << "\n";
    cout << "B = " << B << "\n";
    cout << "C = " << C << "\n";

    return 0;
}