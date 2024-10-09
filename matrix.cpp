#include "matrix.h"
#include <memory>

Matrix::Matrix() : v_(nullptr), col_index_(nullptr), row_index_(nullptr), row_(0), col_(0), nnz_(0) { }

Matrix::Matrix(size_t row, size_t col, size_t nnz) : row_(row), col_(col), nnz_(nnz)
{
	v_ = new double[nnz_]{ 0 };
	col_index_ = new size_t[nnz_]{ 0 };
	row_index_ = new size_t[row_ + 1]{ 0 };
}

Matrix::Matrix(const Matrix& other)
{
	*this = other;
}

Matrix::Matrix(Matrix&& other) noexcept
{
	*this = other;
}

Matrix& Matrix::operator=(const Matrix& other)
{
	row_ = other.row_;
	col_ = other.col_;
	nnz_ = other.nnz_;

	delete[] v_;
	v_ = new double[nnz_];
	std::uninitialized_copy_n(other.v_, nnz_, v_);

	delete[] col_index_;
	col_index_ = new size_t[nnz_];
	std::uninitialized_copy_n(other.col_index_, nnz_, col_index_);

	delete[] row_index_;
	row_index_ = new size_t[row_ + 1];
	std::uninitialized_copy_n(other.row_index_, row_ + 1, row_index_);

	return *this;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept
{
	row_ = other.row_;
	other.row_ = 0;

	col_ = other.col_;
	other.col_ = 0;

	nnz_ = other.nnz_;
	other.nnz_ = 0;

	delete[] v_;
	v_ = other.v_;
	other.v_ = nullptr;

	delete[] col_index_;
	col_index_ = other.col_index_;
	other.col_index_ = nullptr;

	delete[] row_index_;
	row_index_ = other.row_index_;
	other.row_index_ = nullptr;

	return *this;
}

Matrix::~Matrix()
{
	delete[] v_;
	delete[] col_index_;
	delete[] row_index_;
}


size_t Matrix::getQuantityRow(void) const
{
	return row_;
}

size_t Matrix::getQuantityCal(void) const
{
	return col_;
}

size_t Matrix::getNNZ(void) const
{
	return nnz_;
}

double Matrix::getElement(size_t index_row, size_t index_col) const
{
	for (size_t j = row_index_[index_row]; j < row_index_[index_row + 1]; ++j)
	{
		if (row_index_[j] == index_col)
		{
			return v_[j];
		}
	}
	double temp = 0.0;
	return temp;
}

Matrix Matrix::getCut(size_t begin_index_row, size_t end_index_row, size_t begin_index_col, size_t end_index_col) const
{
	Matrix cutting;

	const size_t nnz = row_index_[end_index_row] - row_index_[begin_index_row];
	cutting.row_ = end_index_row - begin_index_row;
	cutting.col_ = end_index_col - begin_index_col;

	double* temp_v = new double[nnz] { 0 };
	size_t* temp_col_index = new size_t[nnz]{ 0 };
	cutting.row_index_ = new size_t[row_ + 1]{ 0 };

	size_t counter = 0;

	//Для основной матрицы - i, j, n (i - номер строки элемента матрицы, j - номер столбца элемента матрицы, n - номер элемента матрицы)
	//Для среза матрицы - i_loc, j_loc, n_loc (i_loc - номер строки элемента среза, j_loc - номер столбца элемента среза, n_loc - номер элемента среза)
	for (size_t i_loc = 0; i_loc < cutting.row_; ++i_loc)
	{
		const size_t i = begin_index_row + i_loc;
		
		cutting.row_index_[i_loc] = counter;
		for (size_t n = row_index_[i]; n < row_index_[i + 1]; ++n)
		{
			if (begin_index_col <= col_index_[n] && col_index_[n] < end_index_col)
			{
				const size_t j_loc = col_index_[n] - begin_index_col;
				const size_t n_loc = counter;

				temp_col_index[n_loc] = j_loc;
				temp_v[n_loc] = v_[n];
				++counter;
			}
		}
	}
	cutting.row_index_[cutting.row_] = counter;

	cutting.nnz_ = counter;

	cutting.v_ = new double[cutting.nnz_]{ 0 };
	std::uninitialized_copy_n(temp_v, cutting.nnz_, cutting.v_);
	delete[] temp_v;

	cutting.col_index_ = new size_t[cutting.nnz_]{ 0 };
	std::uninitialized_copy_n(temp_col_index, cutting.nnz_, cutting.col_index_);
	delete[] temp_col_index;

	return cutting;
}