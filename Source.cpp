#include<iostream>
#include<conio.h>
#include<windows.h> 
#include <iomanip>
#define size 20
using namespace std;
void Convert(int, int);
void menu();

class stack
{
	int array[size];
	int top;
public:
	stack();
	void push(int);
	int pop();
	bool isfull();
	bool isempty();
};
stack::stack()
{
	top = -1;
}
void stack::push(int number)
{
	if (!isfull())
	{
		array[++top] = number;
	}
	else
	{
		cout << "Overflow";
	}
}
int stack::pop()
{
	if (!isempty())
	{
		return array[top--];
	}
	else
	{
		cout << "Underflow";
	}
}
bool stack::isfull()
{
	return top == size - 1;
}
bool stack::isempty()
{
	return top == -1;
}
void Convert(int number, int base)
{
	stack stack1;
	if (base == 2)
	{
		system("Color 2");
		while (number > 0)
		{
			stack1.push(number % 2);
			number = number / 2;
		}
		cout << setw(43) << "Binary Value : ";
		while (!stack1.isempty())
		{
			cout << stack1.pop() << " ";
		}
		cout << endl;
		system("pause");
		system("cls");
	}
	else if (base == 8)
	{
		system("Color 1");
		while (number > 0)
		{
			stack1.push(number % 8);
			number = number / 8;
		}
		cout << setw(42) << "Octal Value : ";
		while (!stack1.isempty())
		{
			cout << stack1.pop() << " ";
		}
		cout << endl;
		system("pause");
		system("cls");
	}
	else if (base == 16)
	{
		int remainder;
		system("Color 5");
		while (number > 0)
		{
			remainder = number % 16;
			if (remainder < 10)
			{
				stack1.push(remainder + 48);
			}
			else
			{
				stack1.push(remainder + 55);
			}
			number = number / 16;
		}
		cout << setw(40) << "Hex Value : ";
		while (!stack1.isempty())
		{
			cout << char(stack1.pop()) << " ";
		}
		cout << endl;
		system("pause");
		system("cls");
	}
	else
	{
		system("Color B");
		cout << setw(55) << "Error: Enter A Valid Base!!" << endl;
		system("pause");
		system("cls");
	}
}
void menu()
{
	char choice;
	system("Color A");
	cout << "\n\n\n" << setw(50) << "==============" << endl;
	cout << setw(50) << "| Conversion |" << endl;
	cout << setw(50) << "==============" << endl;
	system("pause");
	system("cls");
	do
	{
		system("Color 3");
		cout << "";
		int number, base;
		cout << "\n\n\n" << setw(50) << "Enter Decimal Value : ";
		cin >> number;
		cout << setw(57) << "Enter Base Number (2,8,16) : ";
		cin >> base;
		Convert(number, base);
		cout << "\n\n\n" << setw(60) << "Do you want to Proceed More (Y|N) : ";
		cin >> choice;
		system("cls");
	} while (choice == 'y' || choice == 'Y');
}
int main()
{
	menu();
	_getch();
	return 0;
}