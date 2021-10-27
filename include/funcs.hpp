#ifndef FUNCS_HPP
#define FUNCS_HPP
#include "matrix_struct.hpp"

//function that checks if a matrix is diagonal
bool is_diagonal(matrixS matrix)
{
	bool diagonal = true;
	switch (matrix.data_type)
	{
	// numbers(special number : 0)
	case 1:
	{
		for (int i = 0; i < matrix.size && diagonal; i++)
		{
			for (int j = 0; j < matrix.size; j++)
			{
				if (i != j && matrix.mat_n[i][j] != 0)
				{
					diagonal = false;
					break;
				}
			}
		}
	}
	break;
	// char(special char : o)
	case 2:
	{
		for (int i = 0; i < matrix.size && diagonal; i++)
		{
			for (int j = 0; j < matrix.size; j++)
			{
				if (i != j && matrix.mat_c[i][j] != 'o')
				{
					diagonal = false;
					break;
				}
			}
		}
	}
	break;
	//string(special string: ooo)
	case 3:
	{
		for (int i = 0; i < matrix.size && diagonal; i++)
		{
			for (int j = 0; j < matrix.size; j++)
			{
				if (i != j && matrix.mat_s[i][j] != "ooo")
				{
					diagonal = false;
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
	bool upper_triangular = true;

	switch (matrix.data_type)
	{
	case 1:
	{
		for (int i = 0; i < matrix.size && upper_triangular; i++)
		{
			for (size_t j = 0; j < matrix.size; j++)
			{
				if (i > j && matrix.mat_n[i][j] != 0)
				{
					upper_triangular = false;
					break;
				}
			}
		}
	}
	break;
	case 2:
	{
		for (int i = 0; i < matrix.size && upper_triangular; i++)
		{
			for (size_t j = 0; j < matrix.size; j++)
			{
				if (i > j && matrix.mat_c[i][j] != 'o')
				{
					upper_triangular = false;
					break;
				}
			}
		}
	}
	break;
	case 3:
	{
		for (int i = 0; i < matrix.size && upper_triangular; i++)
		{
			for (size_t j = 0; j < matrix.size; j++)
			{
				if (i > j && matrix.mat_s[i][j] != "ooo")
				{
					upper_triangular = false;
					break;
				}
			}
		}
	}
	break;
	}
	return upper_triangular;
}

//function that checks if a matrix is lower triangular
bool is_lower_triangular(matrixS matrix)
{
	bool lower_triangular = true;

	switch (matrix.data_type)
	{
	case 1:
	{
		for (int i = 0; i < matrix.size && lower_triangular; i++)
		{
			for (size_t j = 0; j < matrix.size; j++)
			{
				if (i < j && matrix.mat_n[i][j] != 0)
				{
					lower_triangular = false;
					break;
				}
			}
		}
	}
	break;
	case 2:
	{
		for (int i = 0; i < matrix.size && lower_triangular; i++)
		{
			for (size_t j = 0; j < matrix.size; j++)
			{
				if (i < j && matrix.mat_c[i][j] != 'o')
				{
					lower_triangular = false;
					break;
				}
			}
		}
	}
	break;
	case 3:
	{
		for (int i = 0; i < matrix.size && lower_triangular; i++)
		{
			for (size_t j = 0; j < matrix.size; j++)
			{
				if (i < j && matrix.mat_s[i][j] != "ooo")
				{
					lower_triangular = false;
					break;
				}
			}
		}
	}
	break;
	}
	return lower_triangular;
}

//function that checks if a matrix is lower triangular or upper triangular or both or none
int is_triangular(matrixS matrix)
{
	bool upper = is_upper_triangular(matrix);
	bool lower = is_lower_triangular(matrix);

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
	bool identity = true;
	if (is_diagonal(matrix))
	{
		switch (matrix.data_type)
		{
		case 1:
		{
			for (int i = 0; i < matrix.size; i++)
			{
				if (matrix.mat_n[i][i] != 1)
				{
					identity = false;
					break;
				}
			}
		}
		break;
		case 2:
		{
			for (int i = 0; i < matrix.size; i++)
			{
				if (matrix.mat_c[i][i] != 'i')
				{
					identity = false;
					break;
				}
			}
		}
		break;
		case 3:
		{
			for (int i = 0; i < matrix.size; i++)
			{
				if (matrix.mat_s[i][i] != "iii")
				{
					identity = false;
					break;
				}
			}
		}
		break;
		}
	}
	else
	{
		identity = false;
	}

	return identity;
}

//function that checks if a matrix is normal symmetric
bool is_normal_symmetric(matrixS matrix)
{
	bool normal_symmetric = true;

	switch (matrix.data_type)
	{
	case 1:
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
	case 2:
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
	case 3:
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

	return normal_symmetric;
}

//function that checks if two strings are reverse
bool is_reverse(std::string str1, std::string str2)
{
	bool reverse = true;
	if (str1.size() == str2.size())
	{
		int size = str1.size();
		for (int i = 0; i < size; i++)
		{
			if (str1[i] != str2[(size - 1) - i])
			{
				reverse = false;
				break;
			}
		}
	}
	else
	{
		reverse = false;
	}

	return reverse;
}

//function that checks if a matrix is skew symmetric
bool is_skew_symmetric(matrixS matrix)
{
	bool skew_symmetric = true;

	switch (matrix.data_type)
	{
	case 1:
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
	case 2:
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
	case 3:
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

	return skew_symmetric;
}

//function that checks if a matrix is normal symmetric or skew symmetric or both or none
int is_symmetric(matrixS matrix)
{
	bool normal = is_normal_symmetric(matrix);
	bool skew = is_skew_symmetric(matrix);

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
