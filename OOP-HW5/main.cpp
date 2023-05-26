#include "Fraction.h"
#include <iostream>
#include <sstream>

using namespace std;
void runTests(const Fraction& a, const Fraction& b) {
    Fraction c;
    cout << "Fractions: " << a << " and " << b << endl;
    cout << "---------------begin-------------------" << endl;
    c = a + b;
    cout << "The sum is: " << c << endl;
    c = a - b;
    cout << "The diff is: " << c << endl;
    c = a * b;
    cout << "The product is: " << c << endl;
    c = a / b;
    cout << "The division is: " << c << endl;
    cout << "The result of Frations1 < Frations2 is: " << (a < b) << endl;
    cout << "The result of Frations1 <= Frations2 is: " << (a <= b) << endl;
    cout << "The result of Frations1 > Frations2 is: " << (a > b) << endl;
    cout << "The result of Frations1 >= Frations2 is: " << (a >= b) << endl;
    cout << "The result of Frations1 != Frations2 is: " << (a != b) << endl;
    cout << "The result of Frations1 == Frations2 is: " << (a == b) << endl;
    cout << "----------------end------------------" << endl;
}
void testTypecast(const Fraction& a) {
    cout << "Typecast: " << a << " as a double: " << static_cast<double>(a) << endl;
}
void testToString(const Fraction& a) {
    cout << "To string: " << a << " as a string: " << a.to_string() << endl;
}
void testDecimalConversion(const string& decimal) {
    Fraction a(stod(decimal));
    cout << "Converted decimal: " << decimal << " to fraction: " << a << endl;
}
int main(int argc, char* argv[]) {
    if (argc == 5) {
        try {
            Fraction a(stoi(argv[1]), stoi(argv[2]));
            Fraction b(stoi(argv[3]), stoi(argv[4]));
            runTests(a, b);
        } catch (const invalid_argument& e) {
            cerr << "Invalid input: " << e.what() << endl;
        } catch (const std::exception& e) {
            cerr << "Error: " << e.what() << endl;
        } catch (...) {
            cerr << "Unknown error occurred" << endl;
        }
    } else if (argc == 3) {
        try {
            Fraction a(stoi(argv[1]), stoi(argv[2]));
            testTypecast(a);
            testToString(a);
            cout << "Enter a fraction in the format numerator/denominator: ";
            cin >> a;
            cout << "You entered: " << a << endl;
        } catch (const invalid_argument& e) {
            cerr << "Invalid input: " << e.what() << endl;
        } catch (const std::exception& e) {
            cerr << "Error: " << e.what() << endl;
        } catch (...) {
            cerr << "Unknown error occurred" << endl;
        }
    } else if (argc == 2) {
        try {
            string decimal(argv[1]);
            testDecimalConversion(decimal);
        } catch (const invalid_argument& e) {
            cerr << "Invalid input: " << e.what() << endl;
        } catch (const std::exception& e) {
            cerr << "Error: " << e.what() << endl;
        } catch (...) {
            cerr << "Unknown error occurred" << endl;
        }
    } else {
        cerr << "Invalid number of arguments" << endl;
    }
    return 0;
}