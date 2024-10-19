#include "file_manager.hpp"
#include "fstream"
#include "sstream"
#include <string>

void FileManager::setMatrix(Matrix& matrix)
{
	matrix_ = &matrix;
}

void FileManager::readMatrix(std::filesystem::path file_path)
{
	size_t quantity_row = 0, quantity_col = 0, nnz;

	std::ifstream fin(file_path);
	{
		std::string str;
		std::getline(fin, str);
		std::stringstream sstr(str);

		sstr >> quantity_row;
		sstr >> quantity_col;
		sstr >> nnz;
	}

	Matrix matrix(quantity_row, quantity_col, nnz);

	size_t counter = 0;
	size_t actual_i = 0;
	for (size_t n = 0; n < nnz; ++n)
	{
		std::string str;
		std::getline(fin, str);
		std::stringstream sstr(str);
	
		size_t i, j;
		double value;

		sstr >> i;
		sstr >> j;
		sstr >> value;

		matrix.v_[n] = value;
		matrix.col_index_[n] = j;

		if (actual_i != i)
		{
			for (size_t s = actual_i; s < i; ++s) matrix.row_index_[s + 1] = counter;
			actual_i = i;
		}
		matrix.row_index_[i + 1] = ++counter;
	}

	*matrix_ = std::move(matrix);
	matrix_ = nullptr;
}

void FileManager::writeMatrix(std::filesystem::path file_path)
{
	std::ofstream fout(file_path, std::ios::trunc);

	fout << matrix_->row_;
	fout << " ";
	fout << matrix_->col_;
	fout << " ";
	fout << matrix_->nnz_;
	fout << "\n";

	for (size_t i = 0; i < matrix_->row_; ++i)
	{
		for (size_t n = matrix_->row_index_[i]; n < matrix_->row_index_[i + 1]; ++n)
		{
			fout << i << " " << matrix_->col_index_[n] << " " << matrix_->v_[n] << "\n";
		}
	}
	matrix_ = nullptr;
}