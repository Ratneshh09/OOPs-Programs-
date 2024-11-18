#include <iostream>
using namespace std;

class Complex {
private:
    float real;  
    float imag;  

public:
    
    Complex() : real(0), imag(0) {}

    
    Complex(float r, float i) : real(r), imag(i) {}

    
    Complex operator+(const Complex& c) const {
        return Complex(real + c.real, imag + c.imag);
    }

   
    Complex operator*(const Complex& c) const {
        float r = real * c.real - imag * c.imag;  
        float i = real * c.imag + imag * c.real;  
        return Complex(r, i);
    }

    
    friend istream& operator>>(istream& input, Complex& c) {
        cout << "Enter real part: ";
        input >> c.real;
        cout << "Enter imaginary part: ";
        input >> c.imag;
        return input;
    }

    
    friend ostream& operator<<(ostream& output, const Complex& c) {
        if (c.imag >= 0)
            output << c.real << " + " << c.imag << "i";
        else
            output << c.real << " - " << -c.imag << "i";  
        return output;
    }
};

int main() {
    Complex c1, c2, c3, c4;

    
    cout << "Enter the first complex number:\n";
    cin >> c1;

   
    cout << "Enter the second complex number:\n";
    cin >> c2;

    
    c3 = c1 + c2;

    
    c4 = c1 * c2;

    
    cout << "\nThe first complex number is: " << c1 << endl;
    cout << "The second complex number is: " << c2 << endl;
    cout << "The sum is: " << c3 << endl;
    cout << "The product is: " << c4 << endl;

    return 0;
}

