#pragma once
#include "file_manager.hpp"

class FileManager;

class Matrix
{
	//Массив не нулевых значений
	double* v_;
	//Массив индексов столбцов
	size_t* col_index_;
	//Массив экстентов строк
	size_t* row_index_;

	//Количество строк
	size_t row_;
	//Количество столбцов
	size_t col_;
	//Количество не нулевых элементов
	size_t nnz_;

public:
	Matrix();
	~Matrix();

	Matrix(const Matrix& other);
	Matrix(Matrix&& other) noexcept;

	Matrix& operator=(const Matrix& other);
	Matrix& operator=(Matrix&& other) noexcept;

	const Matrix operator+(const Matrix& other) const;
	void operator+=(const Matrix& other);

	const Matrix operator-() const;

	const Matrix operator-(const Matrix& other) const;
	void operator-=(const Matrix& other);

	const Matrix operator*(const double value) const;
	void operator*=(const double value);

	double operator[](size_t multi_index) const;

	size_t getQuantityRow(void) const;
	size_t getQuantityCal(void) const;
	size_t getNNZ(void) const;
	Matrix getCut(size_t begin_index_row, size_t end_index_row, size_t begin_index_col, size_t end_index_col) const;

	double getElement(size_t index_row, size_t index_col) const;
	void setElement(size_t index_row, size_t index_col, double value);
	void addElement(size_t index_row, size_t index_col);

	friend FileManager;

private:
	Matrix(size_t row, size_t col, size_t nnz);
};