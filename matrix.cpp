#include "matrix.h"

#include <memory>

Matrix::Matrix(size_t row, size_t col) : row_(row), col_(col)
{
	ptr_ = new double[row_ * col_];
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
	delete[] ptr_;
	ptr_ = new double[other.col_ * other.row_];
	row_ = other.row_;
	col_ = other.col_;
	std::uninitialized_copy_n(other.ptr_, other.col_ * other.row_, ptr_);
	return *this;
}

Matrix& Matrix::operator=(Matrix&& other) noexcept
{
	delete[] ptr_;
	ptr_ = other.ptr_;
	other.ptr_ = nullptr;

	row_ = other.row_;
	other.row_ = 0;

	col_ = other.col_;
	other.col_ = 0;

	return *this;
}

Matrix::~Matrix()
{
	delete[] ptr_;
}


size_t Matrix::getQuantityRow(void) const
{
	return row_;
}

size_t Matrix::getQuantityCal(void) const
{
	return col_;
}

double& Matrix::getElement(size_t index_row, size_t index_col) const
{
	return ptr_[index_row * col_ + index_col];
}

Matrix Matrix::getCut(size_t begin_index_row, size_t end_index_row, size_t begin_index_col, size_t end_index_col) const
{
	Matrix cutting(end_index_row - begin_index_row, end_index_col - begin_index_col);

	for (size_t i = 0; i < cutting.getQuantityRow(); ++i)
	{
		for (size_t j = 0; j < cutting.getQuantityCal(); ++j)
		{
			cutting.getElement(i, j) = ptr_[(i + begin_index_row) * col_ + j + begin_index_col];
		}
	}

	return cutting;
}