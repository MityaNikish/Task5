#include "file_manager.hpp"
#include "fstream"
#include "sstream"
#include <string>

Matrix reader(std::filesystem::path parh)
{
	size_t quantity_row = 0, quantity_col = 0;
	std::ifstream fin(parh);
	fin >> quantity_row;
	fin >> quantity_col;
	Matrix matrix(quantity_row, quantity_col);

	for (size_t i = 0; i < quantity_row; ++i)
	{
		std::string str;
		std::getline(fin, str);
		std::stringstream sstr(str);

		for (size_t j = 0; j < quantity_col; ++j)
		{
			double elem;
			sstr >> elem;
			matrix.getElement(i, j) = elem;
		}
	}
	return matrix;
}

void writer(std::filesystem::path parh, const Matrix& matrix)
{
	std::ofstream fout(parh, std::ios::trunc);

	fout << matrix.getQuantityRow();
	fout << " ";
	fout << matrix.getQuantityCal();

	for (size_t i = 0; i < matrix.getQuantityRow(); ++i)
	{
		fout << "\n";
		for (size_t j = 0; j < matrix.getQuantityCal(); ++j)
		{
			fout << matrix.getElement(i, j) << " ";
		}
	}
}