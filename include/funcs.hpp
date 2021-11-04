#ifndef FUNCS_HPP
#define FUNCS_HPP
#include <iostream>
#include "matrix_struct.hpp" //include header that has matrix defenition
using namespace std;

//function that checks if a matrix is diagonal
bool is_diagonal(matrixS matrix)
{
	//check that matrix is square
	if (matrix.size == 0)
	{
		cout << "the matrix should be square matrix!!!" << endl;
		return false;
	}

	bool diagonal = true;	  // bool data type that keeps the resault (default is true)
	switch (matrix.data_type) //checks if a matrix is diagonal based on data type
	{
	case 1: // numbers(special number : 0)
	{
		for (int i = 0; i < matrix.size && diagonal; i++)
		{
			for (int j = 0; j < matrix.size; j++)
			{
				if (i != j && matrix.mat_n[i][j] != 0)
				{
					diagonal = false; //set diagonal to false is find a none-zero element (not on the main diameter)
					break;
				}
			}
		}
	}
	break;
	case 2: // char(special char : o)
	{
		for (int i = 0; i < matrix.size && diagonal; i++)
		{
			for (int j = 0; j < matrix.size; j++)
			{
				if (i != j && matrix.mat_c[i][j] != 'o')
				{
					diagonal = false; //set diagonal to false is find a none-'o' element (not on the main diameter)
					break;
				}
			}
		}
	}
	break;
	case 3: //string(special string: ooo)
	{
		for (int i = 0; i < matrix.size && diagonal; i++)
		{
			for (int j = 0; j < matrix.size; j++)
			{
				if (i != j && matrix.mat_s[i][j] != "ooo")
				{
					diagonal = false; //set diagonal to false is find a none-"ooo" element (not on the main diameter)
					break;
				}
			}
		}
	}
	break;
	}
	return diagonal; //return the resault
}

//function that checks if a matrix is upper triangular
bool is_upper_triangular(matrixS matrix)
{
	//check that matrix is square
	if (matrix.size == 0)
	{
		cout << "the matrix should be square matrix!!!" << endl;
		return false;
	}

	bool upper_triangular = true; // bool data type that keeps the resault (default is true)
	switch (matrix.data_type)	  //checks if a matrix is upper triangular based on data type
	{
	case 1: // numbers(special number : 0)
	{
		for (int i = 0; i < matrix.size && upper_triangular; i++)
		{
			for (size_t j = 0; j < matrix.size; j++)
			{
				if (i > j && matrix.mat_n[i][j] != 0)
				{
					upper_triangular = false; //set upper triangular to false if find a none-zero element under the main diameter
					break;
				}
			}
		}
	}
	break;
	case 2: // char(special char : o)
	{
		for (int i = 0; i < matrix.size && upper_triangular; i++)
		{
			for (size_t j = 0; j < matrix.size; j++)
			{
				if (i > j && matrix.mat_c[i][j] != 'o')
				{
					upper_triangular = false; //set upper triangular to false if find a none-'o' element under the main diameter
					break;
				}
			}
		}
	}
	break;
	case 3: //string(special string: ooo)
	{
		for (int i = 0; i < matrix.size && upper_triangular; i++)
		{
			for (size_t j = 0; j < matrix.size; j++)
			{
				if (i > j && matrix.mat_s[i][j] != "ooo")
				{
					upper_triangular = false; //set upper triangular to false if find a none-"ooo" element under the main diameter
					break;
				}
			}
		}
	}
	break;
	}
	return upper_triangular; //return the resault
}

//function that checks if a matrix is lower triangular
bool is_lower_triangular(matrixS matrix)
{
	//check that matrix is square
	if (matrix.size == 0)
	{
		cout << "the matrix should be square matrix!!!" << endl;
		return false;
	}

	bool lower_triangular = true; // bool data type that keeps the resault (default is true)
	switch (matrix.data_type)	  //checks if a matrix is lower triangular based on data type
	{
	case 1: // numbers(special number : 0)
	{
		for (int i = 0; i < matrix.size && lower_triangular; i++)
		{
			for (size_t j = 0; j < matrix.size; j++)
			{
				if (i < j && matrix.mat_n[i][j] != 0)
				{
					lower_triangular = false; //set lower triangular to false if find a none-zero element under the main diameter
					break;
				}
			}
		}
	}
	break;
	case 2: // char(special char : o)
	{
		for (int i = 0; i < matrix.size && lower_triangular; i++)
		{
			for (size_t j = 0; j < matrix.size; j++)
			{
				if (i < j && matrix.mat_c[i][j] != 'o')
				{
					lower_triangular = false; //set lower triangular to false if find a none-'o' element under the main diameter
					break;
				}
			}
		}
	}
	break;
	case 3: //string(special string: ooo)
	{
		for (int i = 0; i < matrix.size && lower_triangular; i++)
		{
			for (size_t j = 0; j < matrix.size; j++)
			{
				if (i < j && matrix.mat_s[i][j] != "ooo")
				{
					lower_triangular = false; //set lower triangular to false if find a none-"ooo" element under the main diameter
					break;
				}
			}
		}
	}
	break;
	}
	return lower_triangular; //return the resault
}

//function that checks if a matrix is lower triangular or upper triangular or both or none
int is_triangular(matrixS matrix)
{
	//check that matrix is square
	if (matrix.size == 0)
	{
		cout << "the matrix should be square matrix!!!" << endl;
		return 0;
	}

	bool upper = is_upper_triangular(matrix); // check if matrix is upper triangular
	bool lower = is_lower_triangular(matrix); // check if matrix is lower triangular

	if (!upper && !lower)
	{
		return 0; // neither lower nor upper
	}
	else if (upper && !lower)
	{
		return 1; // just upper
	}
	else if (!upper && lower)
	{
		return 2; // just lower
	}
	else
	{
		return 3; // both upper and lower
	}
}

//function that checks if a matrix is identity
bool is_identity(matrixS matrix)
{
	//check that matrix is square
	if (matrix.size == 0)
	{
		cout << "the matrix should be square matrix!!!" << endl;
		return false;
	}

	bool identity = true;	 // bool data type that keeps the resault (default is true)
	if (is_diagonal(matrix)) // check if matrix is diagonal
	{
		switch (matrix.data_type) //checks if a matrix is identity based on data type
		{
		case 1: // numbers (special number :1)
		{
			for (int i = 0; i < matrix.size; i++)
			{
				if (matrix.mat_n[i][i] != 1)
				{
					identity = false; //set identity to false if find a none-1 on main diameter
					break;
				}
			}
		}
		break;
		case 2: // characters (special character : 'i')
		{
			for (int i = 0; i < matrix.size; i++)
			{
				if (matrix.mat_c[i][i] != 'i')
				{
					identity = false; //set identity to false if find a none-'i' on main diameter
					break;
				}
			}
		}
		break;
		case 3: // strings (special string "iii")
		{
			for (int i = 0; i < matrix.size; i++)
			{
				if (matrix.mat_s[i][i] != "iii")
				{
					identity = false; //set identity to false if find a none-"iii" on main diameter
					break;
				}
			}
		}
		break;
		}
	}
	else
	{
		identity = false; // set identity to false if matrix is not diagonal
	}

	return identity; //return the resault
}

//function that checks if a matrix is normal symmetric
bool is_normal_symmetric(matrixS matrix)
{
	//check that matrix is square
	if (matrix.size == 0)
	{
		cout << "the matrix should be square matrix!!!" << endl;
		return false;
	}

	bool normal_symmetric = true; // bool data type that keeps the resault (default is true)
	switch (matrix.data_type)	  //checks if a matrix is normal symmetric based on data type
	{
	case 1: //numbers
	{
		for (int i = 0; i < matrix.size; i++)
		{
			for (int j = 0; j < matrix.size; j++)
			{
				if (matrix.mat_n[i][j] != matrix.mat_n[j][i])
				{
					normal_symmetric = false;
					break;
				}
			}
		}
	}
	break;
	case 2: //characters
	{
		for (int i = 0; i < matrix.size; i++)
		{
			for (int j = 0; j < matrix.size; j++)
			{
				if (matrix.mat_c[i][j] != matrix.mat_c[j][i])
				{
					normal_symmetric = false;
					break;
				}
			}
		}
	}
	break;
	case 3: //string
	{
		for (int i = 0; i < matrix.size; i++)
		{
			for (int j = 0; j < matrix.size; j++)
			{
				if (matrix.mat_s[i][j] != matrix.mat_s[j][i])
				{
					normal_symmetric = false;
					break;
				}
			}
		}
	}
	break;
	}

	return normal_symmetric; //return the resault
}

//function that checks if two strings are reverse
bool is_reverse(std::string str1, std::string str2)
{
	bool reverse = true; // bool data type that keeps the resault (default is true)
	if (str1.size() == str2.size())
	{
		int size = str1.size();
		for (int i = 0; i < size; i++)
		{
			if (str1[i] != str2[(size - 1) - i])
			{
				reverse = false; //set revrse to false if the strings aren't reverse of each other
				break;
			}
		}
	}
	else
	{
		reverse = false; //set reverse to false if the two strings dont have equal sizes
	}

	return reverse; //return the resault
}

//function that checks if a matrix is skew symmetric
bool is_skew_symmetric(matrixS matrix)
{
	//check that matrix is square
	if (matrix.size == 0)
	{
		cout << "the matrix should be square matrix!!!" << endl;
		return false;
	}

	bool skew_symmetric = true; // bool data type that keeps the resault (default is true)
	switch (matrix.data_type)	//checks if a matrix is skew symmetric based on data type
	{
	case 1: //numbers
	{
		for (int i = 0; i < matrix.size; i++)
		{
			for (int j = 0; j < matrix.size; j++)
			{
				if (i != j && (matrix.mat_n[i][j] != (-1 * matrix.mat_n[j][i])))
				{
					skew_symmetric = false;
					break;
				}
			}
		}
	}
	break;
	case 2: //characters
	{
		for (int i = 0; i < matrix.size; i++)
		{
			for (int j = 0; j < matrix.size; j++)
			{
				if (i != j)
				{
					if (islower(matrix.mat_c[i][j]))
					{
						if (toupper(matrix.mat_c[i][j]) != matrix.mat_c[j][i])
						{
							skew_symmetric = false;
							break;
						}
					}
					else
					{
						if (tolower(matrix.mat_c[i][j]) != matrix.mat_c[j][i])
						{
							skew_symmetric = false;
							break;
						}
					}
				}
			}
		}
	}
	break;
	case 3: //strings
	{
		for (int i = 0; i < matrix.size; i++)
		{
			for (int j = 0; j < matrix.size; j++)
			{
				if (i != j && !is_reverse(matrix.mat_s[i][j], matrix.mat_s[j][i]))
				{
					skew_symmetric = false;
					break;
				}
			}
		}
	}
	break;
	}

	return skew_symmetric; //return the resault
}

//function that checks if a matrix is normal symmetric or skew symmetric or both or none
int is_symmetric(matrixS matrix)
{
	//check that matrix is square
	if (matrix.size == 0)
	{
		cout << "the matrix should be square matrix!!!" << endl;
		return 0;
	}

	bool normal = is_normal_symmetric(matrix); //check if matrix is normal symmetric
	bool skew = is_skew_symmetric(matrix);	   //check if matrix is skew symmetric

	if (!normal && !skew)
	{
		return 0; // neither normal nor skew
	}
	else if (normal && !skew)
	{
		return 1; // just normal
	}
	else if (!normal && skew)
	{
		return 2; // just skew
	}
	else
	{
		return 3; // both normal and skew
	}
}
#endif // FUNCS_HPP
