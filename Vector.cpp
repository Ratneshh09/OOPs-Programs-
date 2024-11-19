#include <iostream>
#include <vector>
using namespace std;

template <typename T>  
class Vector {
private:
    vector<T> elements; 
public:    
    Vector(int size, T initial_value) {
        elements.resize(size, initial_value);
    }  
    void modifyElement(int index, T new_value) {
        if (index >= 0 && index < elements.size()) {
            elements[index] = new_value;
        } else {
            cout << "Index out of bounds!" << endl;
        }
    }    
    void multiplyByScalar(T scalar) {
        for (int i = 0; i < elements.size(); i++) {
            elements[i] *= scalar;
        }
    }   
    void display() const {
        cout << "(";
        for (int i = 0; i < elements.size(); i++) {
            cout << elements[i];
            if (i != elements.size() - 1) {
                cout << ", ";
            }
        }
        cout << ")" << endl;
    }
};
int main() {
  
    Vector<int> vec(5, 0);
    cout << "Initial vector: ";
    vec.display();

    vec.modifyElement(2, 10);
    cout << "After modifying element at index 2: ";
    vec.display();

    vec.multiplyByScalar(2);
    cout << "After multiplying by scalar 2: ";
    vec.display();

    Vector<double> vec2(3, 1.5);
    cout << "Initial vector (double): ";
    vec2.display();

    vec2.modifyElement(0, 2.5);
    cout << "After modifying element at index 0: ";
    vec2.display();

    vec2.multiplyByScalar(3.0);
    cout << "After multiplying by scalar 3.0: ";
    vec2.display();

    return 0;
}
