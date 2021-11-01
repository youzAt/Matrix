#ifndef COMMANDS_HPP
#define COMMANDS_HPP
#include <iostream>
#include "matrix_struct.hpp"
#include <vector>
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

bool is_number(const string &str)
{
	for (const auto &item : str)
	{
		if (isdigit(item) == 0)
		{
			return false;
		}
	}
	return true;
}

void new_matrix(matrixS &matrix)
{
	switch (matrix.data_type)
	{
	case 1:
	{
		matrix.mat_n = new float *[matrix.row];
		for (int i = 0; i < matrix.row; i++)
		{
			matrix.mat_n[i] = new float[matrix.col];
		}
		break;
	}
	case 2:
	{
		matrix.mat_c = new char *[matrix.row];
		for (int i = 0; i < matrix.row; i++)
		{
			matrix.mat_c[i] = new char[matrix.col];
		}
	}
	case 3:
	{
		matrix.mat_s = new string *[matrix.row];
		for (int i = 0; i < matrix.row; i++)
		{
			matrix.mat_s[i] = new string[matrix.col];
		}
	}
	}
}

void add_matrix(string &commandsLine, vector<matrixS> &matrixV)
{
	matrixS temp_matrix;
	string temp_string;
	string element = "";
	temp_string = split_command(commandsLine);
	if (temp_string == "")
	{
		cout << "Too few arguments!!!" << endl;
		return;
	}
	for (const auto &item : matrixV)
	{
		if (item.name == temp_string)
		{
			cout << "This matrix name is already exist!!!" << endl;
			return;
		}
	}
	temp_matrix.name = temp_string;

	temp_string = split_command(commandsLine);
	if (!is_number(temp_string) || temp_string == "")
	{
		cout << "Invalid/No arguments for matrix rows/columns!!!" << endl;
		return;
	}
	temp_matrix.row = stoi(temp_string);
	if (temp_matrix.row <= 0)
	{
		cout << "the number of rows/columns should be a positive number!!!" << endl;
		return;
	}

	temp_string = split_command(commandsLine);
	if (temp_string == "")
	{
		temp_matrix.col = temp_matrix.size = temp_matrix.row;
		cout << temp_matrix.name << "[1][1]: ";
		cin >> element;
		if (element == "")
		{
			cout << "Invalid input!!!" << endl;
			return;
		}
		if (isdigit(element[0]))
		{
			temp_matrix.data_type = 1;
			new_matrix(temp_matrix);
			temp_matrix.mat_n[0][0] = stof(element);
			for (int i = 0; i < temp_matrix.row; i++)
			{
				for (int j = 0; j < temp_matrix.col; j++)
				{
					if (i == 0 && j == 0)
					{
						continue;
					}
					cout << temp_matrix.name << '[' << i + 1 << "][" << j + 1 << "]: ";
					cin >> temp_matrix.mat_n[i][j];
				}
			}
		}
		else if (isalpha(element[0]) && element.size() == 1)
		{
			temp_matrix.data_type = 2;
			new_matrix(temp_matrix);
			temp_matrix.mat_c[0][0] = element[0];
			for (int i = 0; i < temp_matrix.row; i++)
			{
				for (int j = 0; j < temp_matrix.col; j++)
				{
					if (i == 0 && j == 0)
					{
						continue;
					}
					cout << temp_matrix.name << '[' << i + 1 << "][" << j + 1 << "]: ";
					cin >> temp_matrix.mat_c[i][j];
				}
			}
		}
		else
		{
			temp_matrix.data_type = 3;
			new_matrix(temp_matrix);
			temp_matrix.mat_s[0][0] = element;
			for (int i = 0; i < temp_matrix.row; i++)
			{
				for (int j = 0; j < temp_matrix.col; j++)
				{
					if (i == 0 && j == 0)
					{
						continue;
					}
					cout << temp_matrix.name << '[' << i + 1 << "][" << j + 1 << "]: ";
					cin >> temp_matrix.mat_s[i][j];
				}
			}
		}
	}
	else if (temp_string[0] == '[')
	{
		int char_no;
		for (char_no = 1; temp_string[char_no] != ','; char_no++)
		{
			element += temp_string[char_no];
		}

		if (isdigit(element[0]))
		{
			temp_matrix.data_type = 1;
			new_matrix(temp_matrix);
			temp_matrix.mat_n[0][0] = stof(element);
			for (int i = 0; i < temp_matrix.row; i++)
			{
				for (int j = 0; j < temp_matrix.col; j++)
				{
					if (i == 0 && j == 0)
					{
						continue;
					}
				}
			}
		}
		else if (isalpha(element[0]) && element.size() == 1)
		{
			temp_matrix.data_type = 2;
			new_matrix(temp_matrix);
			temp_matrix.mat_c[0][0] = element[0];
			for (int i = 0; i < temp_matrix.row; i++)
			{
				for (int j = 0; j < temp_matrix.col; j++)
				{
					if (i == 0 && j == 0)
					{
						continue;
					}
				}
			}
		}
		else
		{
			temp_matrix.data_type = 3;
			new_matrix(temp_matrix);
			temp_matrix.mat_s[0][0] = element;
			for (int i = 0; i < temp_matrix.row; i++)
			{
				for (int j = 0; j < temp_matrix.col; j++)
				{
					if (i == 0 && j == 0)
					{
						continue;
					}
				}
			}
		}
	}

	matrixV.push_back(temp_matrix);
}

void show_matrix(string commandLine, vector<matrixS> matrixV)
{
	bool found = false;
	for (auto const &item : matrixV)
	{
		if (item.name == commandLine)
		{
			found = true;
			for (int i = 0; i < item.row; i++)
			{
				for (int j = 0; j < item.col; j++)
				{
					if (item.data_type == 1)
					{
						cout << item.mat_n[i][j] << '\t';
					}
					else if (item.data_type == 2)
					{
						cout << item.mat_c[i][j] << '\t';
					}
					else
					{
						cout << item.mat_s[i][j] << '\t';
					}
				}
				cout << endl;
			}
			break;
		}
	}

	if (!found)
	{
		cout << "matrix with this name(" << commandLine << ") dosen\'t exist!!" << endl;
	}
}

void menu(vector<matrixS> &matrixV)
{
	string command_line = " ";					   //string that keeps the command line
	cout << "Welcome To This Program!!! " << endl; //welcome message

	while (command_line != "exit") //loop for getting command line or end the program with "exit" command
	{
		// ask to enter the command and get the command line from input
		cout << "Enter your command or \"help\" (or \"exit\" to end the program)..." << endl;
		getline(cin, command_line);
		string command = "";

		if (command_line == "help") //show all available commands with "help" command
		{
			show_commands();
		}
		else if ((command = split_command(command_line)) == "add")
		{
			if (split_command(command_line) == "matrix")
			{
				add_matrix(command_line, matrixV);
			}
			else
			{
				cout << "Invalid command!!!" << endl;
			}
		}
		else if (command == "show")
		{
			show_matrix(command_line, matrixV);
		}
	}

	cout << "Program Ended..." << endl;
}

#endif // COMMANDS_HPP
