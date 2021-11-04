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

void free_matrix(matrixS &matrix)
{
	switch (matrix.data_type)
	{
	case 1:
	{
		for (int i = 0; i < matrix.row; i++)
		{
			delete[] matrix.mat_n[i];
		}
		delete[] matrix.mat_n;
		break;
	}
	case 2:
	{
		for (int i = 0; i < matrix.row; i++)
		{
			delete[] matrix.mat_c[i];
		}
		delete[] matrix.mat_c;
	}
	case 3:
	{
		for (int i = 0; i < matrix.row; i++)
		{
			delete[] matrix.mat_s[i];
		}
		delete[] matrix.mat_s;
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
		cout << temp_matrix.name << "[0][0]: ";
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
					cout << temp_matrix.name << '[' << i << "][" << j << "]: ";
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
					cout << temp_matrix.name << '[' << i << "][" << j << "]: ";
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
					cout << temp_matrix.name << '[' << i << "][" << j << "]: ";
					cin >> temp_matrix.mat_s[i][j];
				}
			}
		}
	}
	else if (temp_string[0] == '[')
	{
		temp_matrix.col = temp_matrix.size = temp_matrix.row;
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
					element = "";

					for (++char_no; temp_string[char_no] != ',' && temp_string[char_no] != ']'; char_no++)
					{
						element += temp_string[char_no];
					}
					temp_matrix.mat_n[i][j] = stof(element);
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
					element = "";

					for (++char_no; temp_string[char_no] != ',' && temp_string[char_no] != ']'; char_no++)
					{
						element += temp_string[char_no];
					}
					temp_matrix.mat_c[i][j] = element[0];
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
					element = "";

					for (++char_no; temp_string[char_no] != ',' && temp_string[char_no] != ']'; char_no++)
					{
						element += temp_string[char_no];
					}
					temp_matrix.mat_s[i][j] = element;
				}
			}
		}
		if (temp_string[char_no] != ']')
		{
			cout << "Invalid number of elements" << endl;
		}
	}
	else if (is_number(temp_string))
	{
		temp_matrix.col = stoi(temp_string);
		if (temp_matrix.col <= 0)
		{
			cout << "the number of rows/columns should be a positive number!!!" << endl;
			return;
		}
		temp_string = split_command(commandsLine);
		if (temp_string == "")
		{
			cout << temp_matrix.name << "[0][0]: ";
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
						cout << temp_matrix.name << '[' << i << "][" << j << "]: ";
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
						cout << temp_matrix.name << '[' << i << "][" << j << "]: ";
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
						cout << temp_matrix.name << '[' << i << "][" << j << "]: ";
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
						element = "";

						for (++char_no; temp_string[char_no] != ',' && temp_string[char_no] != ']'; char_no++)
						{
							element += temp_string[char_no];
						}
						temp_matrix.mat_n[i][j] = stof(element);
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
						element = "";

						for (++char_no; temp_string[char_no] != ',' && temp_string[char_no] != ']'; char_no++)
						{
							element += temp_string[char_no];
						}
						temp_matrix.mat_c[i][j] = element[0];
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
						element = "";

						for (++char_no; temp_string[char_no] != ',' && temp_string[char_no] != ']'; char_no++)
						{
							element += temp_string[char_no];
						}
						temp_matrix.mat_s[i][j] = element;
					}
				}
			}
			if (temp_string[char_no] != ']')
			{
				cout << "Invalid number of elements" << endl;
			}
		}
		else
		{
			cout << "Invalid input!!!" << endl;
		}
	}
	else
	{
		cout << "Invalid input!!!" << endl;
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

void inverse(string &commandLine, vector<matrixS> &matrixV)
{
	string first_name = split_command(commandLine);
	if (first_name == "")
	{
		cout << "Invalid name for matrix" << endl;
		return;
	}

	bool found = false;
	for (int k = 0; k < matrixV.size(); k++)
	{
		if (matrixV[k].name == first_name)
		{
			if (matrixV[k].size == 0)
			{
				cout << "matrix should be square!!!" << endl;
				return;
			}
			found = true;
			matrixS temp_matrix(matrixV[k]);
			new_matrix(temp_matrix);

			switch (matrixV[k].data_type)
			{
			case 1:
			{
				for (int i = 0; i < matrixV[k].size; i++)
				{
					for (int j = 0; j < matrixV[k].size; j++)
					{
						temp_matrix.mat_n[i][j] = matrixV[k].mat_n[j][i];
					}
				}
			}
			break;
			case 2:
			{
				for (int i = 0; i < matrixV[k].size; i++)
				{
					for (int j = 0; j < matrixV[k].size; j++)
					{
						temp_matrix.mat_c[i][j] = matrixV[k].mat_c[j][i];
					}
				}
			}
			break;
			case 3:
			{
				for (int i = 0; i < matrixV[k].size; i++)
				{
					for (int j = 0; j < matrixV[k].size; j++)
					{
						temp_matrix.mat_s[i][j] = matrixV[k].mat_s[j][i];
					}
				}
			}
			break;
			}

			string second_name = split_command(commandLine);
			if (second_name != "")
			{
				temp_matrix.name = second_name;
				matrixV.push_back(temp_matrix);
			}
			else
			{
				free_matrix(matrixV[k]);
				matrixV[k] = temp_matrix;
			}
			break;
		}
	}

	if (!found)
	{
		cout << "matrix with name(" << first_name << ") dosen\'t exist!!!" << endl;
	}
}

void delete_matrix(string &commandLine, vector<matrixS> &matrixV)
{
	bool found = false;
	string name = split_command(commandLine);

	for (int i = 0; i < matrixV.size(); i++)
	{
		if (matrixV[i].name == name)
		{
			found = true;
			free_matrix(matrixV[i]);
			matrixV.erase(matrixV.begin() + i);
			cout << "matrix \"" << name << "\" deleted " << endl;

			break;
		}
	}

	if (!found)
	{
		cout << "matrix with name(" << name << ") doesn\'t exist!!!" << endl;
	}
}

void change_matrix(string &commandLine, vector<matrixS> &matrixV)
{
	string name = split_command(commandLine);
	bool found = false;

	for (int i = 0; i < matrixV.size(); i++)
	{
		if (name == matrixV[i].name)
		{
			string temp = split_command(commandLine);
			if (!is_number(temp))
			{
				cout << "invalid input!!!" << endl;
				return;
			}
			int row = stoi(temp);

			temp = split_command(commandLine);
			if (!is_number(temp))
			{
				cout << "invalid input!!!" << endl;
				return;
			}
			int col = stoi(temp);

			if (row >= matrixV[i].row || col >= matrixV[i].col || row < 0 || col < 0)
			{
				cout << "invalid input for row/col !!!" << endl;
				return;
			}
			temp = split_command(commandLine);
			if (temp == "")
			{
				cout << "invalid input to change!!!" << endl;
				return;
			}
			switch (matrixV[i].data_type)
			{
			case 1:
			{
				if (is_number(temp))
				{
					matrixV[i].mat_n[row][col] = stof(temp);
				}
				else
				{
					cout << "the data type dosent match!!!" << endl;
					return;
				}
			}
			break;
			case 2:
			{
				if (isalpha(temp[0]) && temp.size() == 1)
				{
					matrixV[i].mat_c[row][col] = temp[0];
				}
				else
				{
					cout << "the data type dosent match!!!" << endl;
					return;
				}
			}
			break;
			case 3:
			{
				if (!is_number(temp))
				{
					matrixV[i].mat_s[row][col] = temp;
				}
				else
				{
					cout << "the data type dosent match!!!" << endl;
					return;
				}
			}
			}

			found = true;
			break;
		}
	}

	if (!found)
	{
		cout << "matrix with name(" << name << ") dosen\'t exist!!!" << endl;
	}
}

int is_available(const string &name, const vector<matrixS> &matrixV)
{
	for (int i = 0; i < matrixV.size(); i++)
	{
		if (matrixV[i].name == name)
		{
			return i;
		}
	}
	return -1;
}

void menu(vector<matrixS> &matrixV)
{
	string command_line = " ";
	int index;									   //string that keeps the command line
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
		else if (command == "inverse")
		{
			inverse(command_line, matrixV);
		}
		else if (command == "delete")
		{
			delete_matrix(command_line, matrixV);
		}
		else if (command == "change")
		{
			change_matrix(command_line, matrixV);
		}
		else if (command == "is_diagonal")
		{
			if (index = is_available(split_command(command_line), matrixV) == -1)
			{
				cout << "matrix with this name doesn\'t exist" << endl;
			}
			else
			{
				if (is_diagonal(matrixV[index]))
				{
					cout << "the matrix \"" << matrixV[index].name << "\" is diagonal" << endl;
				}
				else
				{
					cout << "the matrix \"" << matrixV[index].name << "\" is NOT diagonal!!" << endl;
				}
			}
		}
		else if (command == "is_upper_triangular")
		{
			if (index = is_available(split_command(command_line), matrixV) == -1)
			{
				cout << "matrix with this name doesn\'t exist" << endl;
			}
			else
			{
				if (is_upper_triangular(matrixV[index]))
				{
					cout << "the matrix \"" << matrixV[index].name << "\" is upper triangular" << endl;
				}
				else
				{
					cout << "the matrix \"" << matrixV[index].name << "\" is NOT upper triangular!!" << endl;
				}
			}
		}
		else if (command == "is_lower_triangular")
		{
			if (index = is_available(split_command(command_line), matrixV) == -1)
			{
				cout << "matrix with this name doesn\'t exist" << endl;
			}
			else
			{
				if (is_lower_triangular(matrixV[index]))
				{
					cout << "the matrix \"" << matrixV[index].name << "\" is lower triangular" << endl;
				}
				else
				{
					cout << "the matrix \"" << matrixV[index].name << "\" is NOT lower triangular!!" << endl;
				}
			}
		}
		else if (command == "is_triangular")
		{
			if (index = is_available(split_command(command_line), matrixV) == -1)
			{
				cout << "matrix with this name doesn\'t exist" << endl;
			}
			else
			{
				switch (is_triangular(matrixV[index]))
				{
				case 0:
					cout << "the matrix \"" << matrixV[index].name << "\" is neither lower nor upper triangular" << endl;
					break;
				case 1:
					cout << "the matrix \"" << matrixV[index].name << "\" is just upper triangular" << endl;
					break;
				case 2:
					cout << "the matrix \"" << matrixV[index].name << "\" is just lower triangular" << endl;
					break;
				case 3:
					cout << "the matrix \"" << matrixV[index].name << "\" is both upper and lower triangular" << endl;
					break;
				}
			}
		}
		else if (command == "is_identity")
		{
			if (index = is_available(split_command(command_line), matrixV) == -1)
			{
				cout << "matrix with this name doesn\'t exist" << endl;
			}
			else
			{
				if (is_identity(matrixV[index]))
				{
					cout << "the matrix \"" << matrixV[index].name << "\" is identity" << endl;
				}
				else
				{
					cout << "the matrix \"" << matrixV[index].name << "\" is NOT identity!!" << endl;
				}
			}
		}
		else if (command == "is_normal_symmetric")
		{
			if (index = is_available(split_command(command_line), matrixV) == -1)
			{
				cout << "matrix with this name doesn\'t exist" << endl;
			}
			else
			{
				if (is_normal_symmetric(matrixV[index]))
				{
					cout << "the matrix \"" << matrixV[index].name << "\" is normal symmetric" << endl;
				}
				else
				{
					cout << "the matrix \"" << matrixV[index].name << "\" is NOT normal symmetric!!" << endl;
				}
			}
		}
		else if (command == "is_skew_symmetric")
		{
			if (index = is_available(split_command(command_line), matrixV) == -1)
			{
				cout << "matrix with this name doesn\'t exist" << endl;
			}
			else
			{
				if (is_skew_symmetric(matrixV[index]))
				{
					cout << "the matrix \"" << matrixV[index].name << "\" is skew symmetric" << endl;
				}
				else
				{
					cout << "the matrix \"" << matrixV[index].name << "\" is NOT skew symmetric!!" << endl;
				}
			}
		}
		else if (command == "is_symmetric")
		{
			if (index = is_available(split_command(command_line), matrixV) == -1)
			{
				cout << "matrix with this name doesn\'t exist" << endl;
			}
			else
			{
				switch (is_symmetric(matrixV[index]))
				{
				case 0:
					cout << "the matrix \"" << matrixV[index].name << "\" is neither normal nor skew symmetric" << endl;
					break;
				case 1:
					cout << "the matrix \"" << matrixV[index].name << "\" is just normal symmetric" << endl;
					break;
				case 2:
					cout << "the matrix \"" << matrixV[index].name << "\" is just skew symmetric" << endl;
					break;
				case 3:
					cout << "the matrix \"" << matrixV[index].name << "\" is both normal and skew symmetric" << endl;
					break;
				}
			}
		}
	}

	cout << "Program Ended..." << endl;
}

#endif // COMMANDS_HPP
