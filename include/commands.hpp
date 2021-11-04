#ifndef COMMANDS_HPP
#define COMMANDS_HPP
#include <iostream>
#include "matrix_struct.hpp"
#include <vector>
using namespace std;

//function thas prints all the available commands
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

//function that split command line and seprats it by " " and return the first part
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
				commandLine = commandLine.substr(i + 1); // set rest of the commandline to itself
				break;
			}
			else
			{
				command = command + commandLine[i];
			}
		}
		temp = command;
		return command; //return the first part of command line
	}
	commandLine = "";
	command = "";
	return command; //return " " if the commandline is empty
}

//function that checks if a string contains only numbers character
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

//function that gets a matrix and allocate memory for matrix elements based on data type and row/col
void new_matrix(matrixS &matrix)
{
	switch (matrix.data_type)
	{
	case 1: //numbers
	{
		matrix.mat_n = new float *[matrix.row];
		for (int i = 0; i < matrix.row; i++)
		{
			matrix.mat_n[i] = new float[matrix.col];
		}
		break;
	}
	case 2: //characters
	{
		matrix.mat_c = new char *[matrix.row];
		for (int i = 0; i < matrix.row; i++)
		{
			matrix.mat_c[i] = new char[matrix.col];
		}
	}
	case 3: //strings
	{
		matrix.mat_s = new string *[matrix.row];
		for (int i = 0; i < matrix.row; i++)
		{
			matrix.mat_s[i] = new string[matrix.col];
		}
	}
	}
}

//function that gets a matrix and free the allocated memory for matrix
void free_matrix(matrixS &matrix)
{
	switch (matrix.data_type)
	{
	case 1: //numbers
	{
		for (int i = 0; i < matrix.row; i++)
		{
			delete[] matrix.mat_n[i];
		}
		delete[] matrix.mat_n;
		break;
	}
	case 2: //characters
	{
		for (int i = 0; i < matrix.row; i++)
		{
			delete[] matrix.mat_c[i];
		}
		delete[] matrix.mat_c;
	}
	case 3: //string
	{
		for (int i = 0; i < matrix.row; i++)
		{
			delete[] matrix.mat_s[i];
		}
		delete[] matrix.mat_s;
	}
	}
}

// function that recieve information and add a matrix to the main vector
void add_matrix(string &commandsLine, vector<matrixS> &matrixV)
{
	matrixS temp_matrix; //a temporary matrix to keep matrix information
	string temp_string;	 // a temporary string to revieve information
	string element = ""; //string for matrix element

	temp_string = split_command(commandsLine); // get the name of matrix
	if (temp_string == "")					   // validation the name
	{
		cout << "Too few arguments!!!" << endl;
		return;
	}

	for (const auto &item : matrixV) //check if its repetitious
	{
		if (item.name == temp_string)
		{
			cout << "This matrix name is already exist!!!" << endl;
			return;
		}
	}
	temp_matrix.name = temp_string; //set the name of matrix

	temp_string = split_command(commandsLine);		  //get the row number of matrix
	if (!is_number(temp_string) || temp_string == "") //validation the input for row number
	{
		cout << "Invalid/No arguments for matrix rows/columns!!!" << endl;
		return;
	}
	temp_matrix.row = stoi(temp_string); //set the row number

	if (temp_matrix.row <= 0) //validation the row number
	{
		cout << "the number of rows/columns should be a positive number!!!" << endl;
		return;
	}

	temp_string = split_command(commandsLine); // get the third part of information
	if (temp_string == "")					   // should recive square matrix element by element
	{
		temp_matrix.col = temp_matrix.size = temp_matrix.row; //set size and col
		cout << temp_matrix.name << "[0][0]: ";
		cin >> element;
		if (element == "") // validation the input
		{
			cout << "Invalid input!!!" << endl;
			return;
		}
		if (isdigit(element[0])) // check if data type is number and get the elements
		{
			temp_matrix.data_type = 1; //set data type to number
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
		else if (isalpha(element[0]) && element.size() == 1)// check if data type is character and get the elements
		{
			temp_matrix.data_type = 2; // set data type to character
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
		else //data type is string and get the elements
		{
			temp_matrix.data_type = 3; // set data type to string
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
	else if (temp_string[0] == '[') //should recive square matrix element in command line
	{
		temp_matrix.col = temp_matrix.size = temp_matrix.row; //set col and size
		int char_no;
		for (char_no = 1; temp_string[char_no] != ','; char_no++)
		{
			element += temp_string[char_no];
		}

		if (isdigit(element[0])) // check if data type is number and get the elements
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
		else if (isalpha(element[0]) && element.size() == 1)// check if data type is character and get the elements
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
		else //data type is string and get the elements
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
		if (temp_string[char_no] != ']') //validation the number of elements
		{
			cout << "Invalid number of elements" << endl;
		}
	}
	else if (is_number(temp_string)) //should recive a matrix by row and col
	{
		temp_matrix.col = stoi(temp_string); //validation col number
		if (temp_matrix.col <= 0)
		{
			cout << "the number of rows/columns should be a positive number!!!" << endl;
			return;
		}

		temp_string = split_command(commandsLine);
		if (temp_string == "") // should recive matrix element by element
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
		else if (temp_string[0] == '[') //should recive a matrix by row and col
		{

			int char_no;
			for (char_no = 1; temp_string[char_no] != ','; char_no++)
			{
				element += temp_string[char_no];
			}

			if (isdigit(element[0])) // data type is number
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
			else if (isalpha(element[0]) && element.size() == 1) //data type is character
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
			else //data type is string
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
			if (temp_string[char_no] != ']') //validation the number of elements
			{
				cout << "Invalid number of elements" << endl;
			}
		}
		else //validation the input
		{
			cout << "Invalid input!!!" << endl;
		}
	}
	else //validation the input
	{
		cout << "Invalid input!!!" << endl;
	}

	matrixV.push_back(temp_matrix); // add temp_matrix to the main vector
}

// function that gets a matrix name and prints the matrix if the name is valid
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

	if (!found) // validation the name of matrix
	{
		cout << "matrix with this name(" << commandLine << ") dosen\'t exist!!" << endl;
	}
}

// funtion that inverses a matrix
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

//function that delete a matrix from main vector
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

// function that change an element of a matrix
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

// function that cheks if a matrix is availabe
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

//function that will recive command line and calls the proper function
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
			index = is_available(split_command(command_line), matrixV);
			if (index == -1)
			{
				cout << "matrix with this name doesn\'t exist" << endl;
			}
			else
			{
				cout << index << endl;
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
			index = is_available(split_command(command_line), matrixV);
			if (index == -1)
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
			index = is_available(split_command(command_line), matrixV);
			if (index == -1)
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
			index = is_available(split_command(command_line), matrixV);
			if (index == -1)
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
			index = is_available(split_command(command_line), matrixV);
			if (index == -1)
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
			index = is_available(split_command(command_line), matrixV);
			if (index == -1)
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
			index = is_available(split_command(command_line), matrixV);
			if (index == -1)
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
			index = is_available(split_command(command_line), matrixV);
			if (index == -1)
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
		else
		{
			cout << "invalid command!!!" << endl;
		}
	}

	cout << "Program Ended..." << endl;
}

#endif // COMMANDS_HPP
