#include <iostream>
#include <limits>

using namespace std;

int main() {
    double num1, num2;        
    char op;                  
    char doAnother = 'y';     
    while (doAnother == 'y' || doAnother == 'Y') {
        cout << "Enter first number, operator, second number: ";
        cin >> num1 >> op >> num2;
        switch(op) {
            case '+':
                cout << "Answer = " << num1 + num2 << endl;
                break;
            case '-':
                cout << "Answer = " << num1 - num2 << endl;
                break;
            case '*':
                cout << "Answer = " << num1 * num2 << endl;
                break;
            case '/':
                
                if (num2 != 0) {
                    cout << "Answer = " << num1 / num2 << endl;
                } else {
                    cout << "Error: Division by zero!" << endl;
                }
                break;
            default:
                cout << "Error: Invalid operator!" << endl;
        }
        cout << "Do another (y/n)? ";
        cin >> doAnother;
        
        while (doAnother != 'y' && doAnother != 'Y' && doAnother != 'n' && doAnother != 'N') {
            cout << "Invalid input. Please enter 'y' or 'n': ";
            cin >> doAnother;
        }
    }
    cout << "Goodbye!" << endl;
    return 0;
}
