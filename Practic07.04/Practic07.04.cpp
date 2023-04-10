#include <iostream>
#include <string>
using namespace std;

/*
Написать ф-ю вычисления значения по заданной строке символов, являющихся
записью этого числа в десятичной системе исчисления

Необходимо предусмотреть случай из выхода за границы диапазона
определнного типом INT
*/

void f1() {
	int znak;
	string str;
	try {
		cin >> str; // "56+46"
		if ((znak = str.find_first_of("+-/*", 1)) == string::npos)
			throw "Нет знака арифм. действия\n";
		int a = stoi(str.substr(0, znak));
		string c = str.substr(znak+1);
		int b = stoi(str.substr(znak+1));
		switch (str[znak])
		{
		case '+':
			if (a > INT_MAX - b) throw "+";
			cout << a + b << endl;
			break;
		case '-':
			if (a < INT_MIN + b) throw "-";
			cout << a - b << endl;
			break;
		case '*':
			if (a < 0 || b < 0) 
				if (a < INT_MIN / b) throw "*";			
			else
				if (a > INT_MAX / b) throw "*";
			cout << a * b << endl;
			break;
		case'/':
			if (b == 0) throw "devide by zero";
			cout << a / b << endl;
			break;
		default:
			break;
		}

	}
	catch (const char* s) {
		cout << "Error! " << s;
	}
	catch (const out_of_range& e) {
		cout << "Error! " << e.what();
	}
}


int main()
{
	setlocale(LC_ALL, "");
	f1();
}
