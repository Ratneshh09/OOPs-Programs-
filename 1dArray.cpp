#include <iostream>
#include <stdexcept>  

class CppArray {
private:
    int* arr;      
    int size;      

public:
    
    CppArray(int s) : size(s) {
        if (size <= 0) {
            throw std::invalid_argument("Array size must be positive");
        }
        arr = new int[size];
    }
    ~CppArray() {
        delete[] arr;
    }
    CppArray(const CppArray& other) : size(other.size) {
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
    }
    CppArray& operator=(const CppArray& other) {
        if (this == &other) {
            return *this;  
        }
        delete[] arr;
        size = other.size;
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }

        return *this;
    }
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }
    const int& operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }
    int getSize() const {
        return size;
    }
    void read() {
        for (int i = 0; i < size; ++i) {
            std::cout << "Enter element " << i << ": ";
            std::cin >> arr[i];
        }
    }
    void print() const {
        std::cout << "Array contents: ";
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    try {
        
        CppArray arr1(5);
        arr1.read();
        arr1.print();
        CppArray arr2(3);
        arr2 = arr1;  
        arr2.print();
        std::cout << "Element at index 2 in arr1: " << arr1[2] << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
