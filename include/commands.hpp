#ifndef COMMANDS_HPP
#define COMMANDS_HPP
#include <iostream>
using namespace std;

void show_commands()
{
	cout << "--------------------------------------" << endl;
	cout << "These are the available commands: " << endl;
	cout << " | add matrix" << endl;
	cout << " | ‫‪is_diagonal‬‬" << endl;
	cout << " | ‫‪is_upper_triangular‬‬" << endl;
	cout << " | ‫‪is_lower_triangular‬‬" << endl;
	cout << " | ‫‪is_triangular‬‬" << endl;
	cout << " | ‫‪is_identity‬‬" << endl;
	cout << " | ‫‪is_normal_symmetric‬‬" << endl;
	cout << " | ‫‪is_skew_symmetric‬‬" << endl;
	cout << " | ‫‪‫‪is_symmetric‬‬‬‬" << endl;
	cout << " | inverse" << endl;
	cout << " | ‫‪show‬‬" << endl;
	cout << " | ‫‪delete‬‬" << endl;
	cout << " | ‫‪change‬‬" << endl;
	cout << "--------------------------------------" << endl;
}

void menu()
{
	cout << "Welcome To This Program!!! " << endl;
	string command_line = " ";

	while (command_line != "exit")
	{
		cout << "Enter your command or \"help\" (or exit to end the program)..." << endl;
		cin >> command_line;
		if (command_line == "help")
		{
			show_commands();
		}
		else if(command_line == "add")
		{
			cin >> command_line;
			if (command_line == "matrix")
			{
				cout << "hellooooo" << endl;
			}
			else
			{
				cout << "Invalid command !!" << endl;
			}
		}
	}

	cout << "Program Ended..." << endl;
}

#endif // COMMANDS_HPP
