#include "std_lib_facilities.h"
#include "Matrix.h"

int main() {
	try {
		cout << "Operations on quadratic Matrices.\n\n"
			<< "Enter q for quit\n"
			<< "\t+ for adding two Matrices\n"
			<< "\t- for subtracting two Matrices\n"
			<< "\t* for multiplying two Matrices\n"
			<< "\t/ for dividing two Matrices\n"
			<< "\tI for the inverse of a Matrix\n"
			<< "\tG for the gauss of a Matrix\n"
			<< "\tt for the transpose of a Matrix\n";

		char operation = 0;
		cin >> operation;

		int size = 0;
		cout << "Enter the size of the Matrix: ";
		cin >> size;

		switch (operation) {
		case '+':
		{
			Matrix a{ size, 'A' };
			Matrix b{ size, 'B' };
			cout << '\n' << a << b << a + b;
			break;
		}
		case '-':
		{
			Matrix a{ size, 'A' };
			Matrix b{ size, 'B' };
			cout << '\n' << a << b << a - b;
			break;
		}
		case '*':
		{
			Matrix a{ size, 'A' };
			Matrix b{ size, 'B' };
			cout << '\n' << a << b << a * b;
			break;
		}
		case '/':
		{
			Matrix a{ size, 'A' };
			Matrix b{ size, 'B' };
			cout << '\n' << a << b;
			b.Invers();
			cout << a * b;
			break;
		}
		case 'I':
		{
			Matrix i{ size,'A' };
			cout << i;
			i.Invers();
			cout << i;
			break;
		}
		case 'G':
		{
			Matrix k{ size,'A' };
			cout << k;
			k.Gauss();
			cout << k;
			break;
		}
		case 't':
		{
			Matrix l{ size,'A' };
			cout << l;
			l.transpose();
			cout << l;
			break;
		}
		}
	}

	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >> c && c != ';');
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin >> c && c != ';');
		return 2;
	}
}
