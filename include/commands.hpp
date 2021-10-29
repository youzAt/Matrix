#ifndef COMMANDS_HPP
#define COMMANDS_HPP
#include <iostream>
#include<vector>
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

string split_command(string &commandLine)
{
	string command = "";
	static string temp;
	if (temp != commandLine)
	{
		for (int i = 0; i < commandLine.size(); i++)
		{
			if (commandLine[i] == ' ')
			{
				commandLine = commandLine.substr(i + 1);
				break;
			}
			else
			{
				command = command + commandLine[i];
			}
		}
		temp = command;
		return command;
	}
	commandLine = "";
	command = "";
	return command;
}

void add_matrix(string & commandsLine)
{

}

void menu(vector<matrixS> & matrixV)
{
	string command_line = " ";					   //string that keeps the command line
	cout << "Welcome To This Program!!! " << endl; //welcome message

	while (command_line != "exit") //loop for getting command line or end the program with "exit" command
	{
		// ask to enter the command and get the command line from input
		cout << "Enter your command or \"help\" (or exit to end the program)..." << endl;
		getline(cin, command_line);

		if (command_line == "help") //show all available commands with "help" command
		{
			show_commands();
		}
		else if (split_command(command_line) == "add")
		{
			if (split_command(command_line) == "matrix")
			{
				cout << "yessss" << endl;
			}
			else
			{
				cout << "Unavalable command!!!" << endl;
			}
		}
	}

	cout << "Program Ended..." << endl;
}

#endif // COMMANDS_HPP
