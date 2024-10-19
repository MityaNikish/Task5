#include "matrix.h"
#include <memory>

namespace 
{
	template <typename T>
	std::enable_if_t<std::is_arithmetic<T>::value, void>
	insert(T* array, size_t size, size_t index, T value)
	{
		T* new_array = new T[size + 1];
		std::uninitialized_copy_n(array, index, new_array);

		new_array[index] = value;
		for (size_t i = index; i < size; ++i)
		{
			new_array[i + 1] = array[i];
		}
		delete[] array;
		array = new_array;
	}
}


Matrix::Matrix() : v_(nullptr), col_index_(nullptr), row_index_(nullptr), row_(0), col_(0), nnz_(0) { }

Matrix::~Matrix()
{
	delete[] v_;
	delete[] col_index_;
	delete[] row_index_;
}


Matrix::Matrix(size_t row, size_t col, size_t nnz) : row_(row), col_(col), nnz_(nnz)
{
	v_ = new double[nnz_];
	col_index_ = new size_t[nnz_];
	row_index_ = new size_t[row_ + 1];
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


const Matrix Matrix::operator+(const Matrix& other) const
{
	if (row_ != other.row_ || col_ != other.col_)
	{
		throw "Размерности не совпадают";
	}

	Matrix result(*this);

	for (size_t i = 0; i < other.row_; ++i)
	{
		for (size_t n = other.row_index_[i]; n < other.row_index_[i + 1]; ++n)
		{
			const size_t j = other.col_index_[n];
			result.setElement(i, j, result.getElement(i, j) + other.v_[n]);
		}
	}

	return result;
}

void Matrix::operator+=(const Matrix& other)
{
	*this = *this + other;
}


const Matrix Matrix::operator-() const
{
	Matrix result(*this);

	for (size_t n = 0; n < nnz_; ++n)
	{
		v_[n] = -v_[n];
	}

	return result;
}


const Matrix Matrix::operator-(const Matrix& other) const
{
	return Matrix(*this + -other);
}

void Matrix::operator-=(const Matrix& other)
{
	*this = *this - other;
}


const Matrix Matrix::operator*(const double value) const
{
	Matrix result;

	for (size_t n = 0; n < result.nnz_; ++n)
	{
		result.v_[n] *= value;
	}

	return result;
}

void Matrix::operator*=(const double value)
{
	*this = *this * value;
}


double Matrix::operator[](size_t multi_index) const
{
	if (multi_index >= row_ * col_)
	{
		throw "Обращение к не существующему элементу";
	}

	for (size_t i = 0; i < row_; ++i)
	{
		for (size_t n = row_index_[i]; n < row_index_[i + 1]; ++n)
		{
			if (i * row_ + col_index_[n] == multi_index)
			{
				return v_[n];
			}

			if (i * row_ + col_index_[n] > multi_index)
			{
				return double {0.0};
			}
		}
	}
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


double Matrix::getElement(size_t index_row, size_t index_col) const
{
	if (index_row > row_ || index_col > col_)
	{
		throw "Обращение к не существующему элементу";
	}

	for (size_t j = row_index_[index_row]; j < row_index_[index_row + 1]; ++j)
	{
		if (row_index_[j] == index_col)
		{
			return v_[j];
		}
	}

	return double {0.0};
}

void Matrix::setElement(size_t index_row, size_t index_col, double value)
{
	if (index_row > row_ || index_col > col_)
	{
		throw "Обращение к не существующему элементу";
	}

	for (size_t n = row_index_[index_row]; n < row_index_[index_row + 1]; ++n)
	{
		if (col_index_[n] == index_col)
		{
			v_[n] = value;
			return;
		}

		if (col_index_[n] > index_col)
		{
			addElement(index_row, index_col);
			v_[n] = value;
			return;
		}
	}
}

void Matrix::addElement(size_t index_row, size_t index_col)
{
	if (index_row > row_ || index_col > col_)
	{
		throw "Обращение к не существующему элементу";
	}

	for (size_t n = row_index_[index_row]; n < row_index_[index_row + 1]; ++n)
	{
		if (col_index_[n] < index_col)
			continue;

		if (col_index_[n] == index_col)
		{
			return;
		}

		insert(v_, nnz_, n, 0.0);
		insert(col_index_, nnz_, n, index_col);
		break;
	}

	for (size_t i = index_row; i < row_; ++i)
	{
		++row_index_[i + 1];
	}
}