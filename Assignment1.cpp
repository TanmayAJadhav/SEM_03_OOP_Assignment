#include <iostream>
using namespace std;

class Complex
{
    float real, img;

public:
    Complex()
    {
        real = 0.0;
        img = 0.0;
    }

    Complex operator+(Complex c)
    {
        Complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }

    Complex operator-(Complex c1)
    {
        Complex temp;
        temp.real = real - c1.real;
        temp.img = img - c1.img;
        return temp;
    }

    Complex operator*(Complex c)
    {
        Complex temp;
        temp.real = (real * c.real) - (img * c.img);
        temp.img = (real * c.img) + (img * c.real);
        return temp;
    }

    friend ostream &operator<<(ostream &	out, Complex &c_)
    {
        out << "Complex number is: " << c_.real << "+ " << c_.img << "i" << endl;
        return out;
    }

    friend istream &operator>>(istream &in, Complex &c_)
    {
        cout << "Real part: " << endl;
        in >> c_.real;
        cout << "Imaginary part: " << endl;
        in >> c_.img;
        return in;
    }
};

int main()
{
    Complex c1, c2, c3;

    while (true)
    {
        cout << "Enter the operation you want to perform: \n 1)Addition \n 2)Subtraction \n 3)Multiplication \n 4)Exit! " << endl;
        int choice;
        cin >> choice;

        if (choice == 4)
        {
            break;
        }

        cout << "Enter the real and imaginary part of the first complex number: " << endl;
        cin >> c1;
        cout << "Enter the real and imaginary parts of the second complex number: " << endl;
        cin >> c2;

        switch (choice)
        {
        case 1:
            c3 = c1 + c2;
            cout << "The addition is: " << c3 << endl;
            break;

        case 2:
            c3 = c1 - c2;
            cout << "The sub is: " << c3 << endl;
            break;

        case 3:
            c3 = c1 * c2;
            cout << "The multiplication is: " << c3 << endl;
            break;

        default:
            cout << "Enter a valid option!" << endl;
            break;
        }
    }
    return 0;
}
