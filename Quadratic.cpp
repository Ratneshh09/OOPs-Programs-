#include <iostream>
#include <cmath>  
using namespace std;

class Quadratic {
private:
    float a, b, c;  

public:
    
    Quadratic() : a(0), b(0), c(0) {}

    
    Quadratic(float a, float b, float c) : a(a), b(b), c(c) {}

   
    Quadratic operator+(const Quadratic& other) {
        return Quadratic(a + other.a, b + other.b, c + other.c);
    }

    
    friend ostream& operator<<(ostream& out, const Quadratic& q) {
        out << q.a << "x^2 + " << q.b << "x + " << q.c;
        return out;
    }

    
    friend istream& operator>>(istream& in, Quadratic& q) {
        cout << "Enter coefficient a (for x^2): ";
        in >> q.a;
        cout << "Enter coefficient b (for x): ";
        in >> q.b;
        cout << "Enter coefficient c (constant term): ";
        in >> q.c;
        return in;
    }

    
    float eval(float x) {
        return a * x * x + b * x + c;
    }

    
    void findRoots() {
        float discriminant = b * b - 4 * a * c;  // Discriminant: b^2 - 4ac
        if (discriminant > 0) {
            float root1 = (-b + sqrt(discriminant)) / (2 * a);
            float root2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "The roots are real and different: " << root1 << " and " << root2 << endl;
        } else if (discriminant == 0) {
            float root = -b / (2 * a);  
            cout << "The root is real and equal: " << root << endl;
        } else {
            
            float realPart = -b / (2 * a);
            float imaginaryPart = sqrt(-discriminant) / (2 * a);
            cout << "The roots are complex: " << realPart << " + " << imaginaryPart << "i and "
                 << realPart << " - " << imaginaryPart << "i" << endl;
        }
    }
};

int main() {
    Quadratic q1, q2, q3;

    
    cout << "Enter the first quadratic polynomial:" << endl;
    cin >> q1;
    cout << "Enter the second quadratic polynomial:" << endl;
    cin >> q2;

    
    cout << "\nThe first polynomial is: " << q1 << endl;
    cout << "The second polynomial is: " << q2 << endl;

   
    q3 = q1 + q2;
    cout << "\nThe sum of the polynomials is: " << q3 << endl;

 
    float x = 2;
    cout << "The value of the first polynomial at x = " << x << " is: " << q1.eval(x) << endl;

    
    cout << "\nFinding roots of the first polynomial (ax^2 + bx + c = 0):" << endl;
    q1.findRoots();

    return 0;
}

