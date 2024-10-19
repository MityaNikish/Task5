#include "matrix.h"
#include "file_manager.hpp"
#include <iostream>

void test_sum_matrix()
{
	try
	{
		Matrix a(3, 2);
		a.getElement(0, 0) = 1;
		a.getElement(0, 1) = 2;
		a.getElement(1, 0) = 3;
		a.getElement(1, 1) = 4;
		a.getElement(2, 0) = 5;
		a.getElement(2, 1) = 6;

		Matrix b(3, 2);
		b.getElement(0, 0) = 6;
		b.getElement(0, 1) = 5;
		b.getElement(1, 0) = 4;
		b.getElement(1, 1) = 3;
		b.getElement(2, 0) = 2;
		b.getElement(2, 1) = 1;

		Matrix target(3, 2);
		target.getElement(0, 0) = 7;
		target.getElement(0, 1) = 7;
		target.getElement(1, 0) = 7;
		target.getElement(1, 1) = 7;
		target.getElement(2, 0) = 7;
		target.getElement(2, 1) = 7;

		std::cout << "Тест operator+(): ";
		Matrix result = a + b;

		if (target == result)
		{
			std::cout << "Тест выполнен." << std::endl;
		}
		else
		{
			std::cout << "Тест НЕ выполнен." << std::endl;
		}
	}
	catch (const char* error_message)
	{
		std::cout << error_message;
	}
}

void test_sum_eq_matrix()
{
	try
	{
		Matrix a(3, 2);
		a.getElement(0, 0) = 1;
		a.getElement(0, 1) = 2;
		a.getElement(1, 0) = 3;
		a.getElement(1, 1) = 4;
		a.getElement(2, 0) = 5;
		a.getElement(2, 1) = 6;

		Matrix b(3, 2);
		b.getElement(0, 0) = 6;
		b.getElement(0, 1) = 5;
		b.getElement(1, 0) = 4;
		b.getElement(1, 1) = 3;
		b.getElement(2, 0) = 2;
		b.getElement(2, 1) = 1;

		Matrix target(3, 2);
		target.getElement(0, 0) = 7;
		target.getElement(0, 1) = 7;
		target.getElement(1, 0) = 7;
		target.getElement(1, 1) = 7;
		target.getElement(2, 0) = 7;
		target.getElement(2, 1) = 7;

		std::cout << "Тест operator+=(): ";
		a += b;

		if (target == a)
		{
			std::cout << "Тест выполнен." << std::endl;
		}
		else
		{
			std::cout << "Тест НЕ выполнен." << std::endl;
		}
	}
	catch (const char* error_message)
	{
		std::cout << error_message;
	}
}

void test_diff_matrix()
{
	try
	{
		Matrix a(3, 2);
		a.getElement(0, 0) = 1;
		a.getElement(0, 1) = 2;
		a.getElement(1, 0) = 3;
		a.getElement(1, 1) = 4;
		a.getElement(2, 0) = 5;
		a.getElement(2, 1) = 6;

		Matrix b(3, 2);
		b.getElement(0, 0) = 6;
		b.getElement(0, 1) = 5;
		b.getElement(1, 0) = 4;
		b.getElement(1, 1) = 3;
		b.getElement(2, 0) = 2;
		b.getElement(2, 1) = 1;

		Matrix target(3, 2);
		target.getElement(0, 0) = -5;
		target.getElement(0, 1) = -3;
		target.getElement(1, 0) = -1;
		target.getElement(1, 1) = 1;
		target.getElement(2, 0) = 3;
		target.getElement(2, 1) = 5;

		std::cout << "Тест operator-(): ";

		Matrix result = a - b;

		if (target == result)
		{
			std::cout << "Тест выполнен." << std::endl;
		}
		else
		{
			std::cout << "Тест НЕ выполнен." << std::endl;
		}
	}
	catch (const char* error_message)
	{
		std::cout << error_message;
	}
}

void test_diff_eq_matrix()
{
	try
	{
		Matrix a(3, 2);
		a.getElement(0, 0) = 1;
		a.getElement(0, 1) = 2;
		a.getElement(1, 0) = 3;
		a.getElement(1, 1) = 4;
		a.getElement(2, 0) = 5;
		a.getElement(2, 1) = 6;

		Matrix b(3, 2);
		b.getElement(0, 0) = 6;
		b.getElement(0, 1) = 5;
		b.getElement(1, 0) = 4;
		b.getElement(1, 1) = 3;
		b.getElement(2, 0) = 2;
		b.getElement(2, 1) = 1;

		Matrix target(3, 2);
		target.getElement(0, 0) = -5;
		target.getElement(0, 1) = -3;
		target.getElement(1, 0) = -1;
		target.getElement(1, 1) = 1;
		target.getElement(2, 0) = 3;
		target.getElement(2, 1) = 5;

		std::cout << "Тест operator-=(): ";

		a -= b;

		if (target == a)
		{
			std::cout << "Тест выполнен." << std::endl;
		}
		else
		{
			std::cout << "Тест НЕ выполнен." << std::endl;
		}
	}
	catch (const char* error_message)
	{
		std::cout << error_message;
	}
}

void test_mult_scalar_matrix()
{
	try
	{
		Matrix a(3, 2);
		a.getElement(0, 0) = 1;
		a.getElement(0, 1) = 2;
		a.getElement(1, 0) = 3;
		a.getElement(1, 1) = 4;
		a.getElement(2, 0) = 5;
		a.getElement(2, 1) = 6;

		Matrix target(3, 2);
		target.getElement(0, 0) = 2;
		target.getElement(0, 1) = 4;
		target.getElement(1, 0) = 6;
		target.getElement(1, 1) = 8;
		target.getElement(2, 0) = 10;
		target.getElement(2, 1) = 12;

		std::cout << "Тест operator*(arg): ";

		Matrix result = a * 2;

		if (target == result)
		{
			std::cout << "Тест выполнен." << std::endl;
		}
		else
		{
			std::cout << "Тест НЕ выполнен." << std::endl;
		}
	}
	catch (const char* error_message)
	{
		std::cout << error_message;
	}
}

void test_mult_eq_scalar_matrix()
{
	try
	{
		Matrix a(3, 2);
		a.getElement(0, 0) = 1;
		a.getElement(0, 1) = 2;
		a.getElement(1, 0) = 3;
		a.getElement(1, 1) = 4;
		a.getElement(2, 0) = 5;
		a.getElement(2, 1) = 6;


		Matrix target(3, 2);
		target.getElement(0, 0) = -5;
		target.getElement(0, 1) = -3;
		target.getElement(1, 0) = -1;
		target.getElement(1, 1) = 1;
		target.getElement(2, 0) = 3;
		target.getElement(2, 1) = 5;
		std::cout << "Тест operator*=(arg): ";

		a *= 2;

		if (target == a)
		{
			std::cout << "Тест выполнен." << std::endl;
		}
		else
		{
			std::cout << "Тест НЕ выполнен." << std::endl;
		}
	}
	catch (const char* error_message)
	{
		std::cout << error_message;
	}
}

void test_mult_matrix()
{
	try
	{
		Matrix a(2, 3);
		a.getElement(0, 0) = 1;
		a.getElement(0, 1) = 2;
		a.getElement(0, 2) = 3;
		a.getElement(1, 0) = 4;
		a.getElement(1, 1) = 5;
		a.getElement(1, 2) = 6;

		Matrix b(3, 2);
		b.getElement(0, 0) = 1;
		b.getElement(0, 1) = 2;
		b.getElement(1, 0) = 3;
		b.getElement(1, 1) = 4;
		b.getElement(2, 0) = 5;
		b.getElement(2, 1) = 6;

		Matrix target(2, 2);
		target.getElement(0, 0) = 22;
		target.getElement(0, 1) = 28;
		target.getElement(1, 0) = 49;
		target.getElement(1, 1) = 64;

		std::cout << "Тест operator*(matrix): ";

		Matrix result = a * b;

		if (target == result)
		{
			std::cout << "Тест выполнен." << std::endl;
		}
		else
		{
			std::cout << "Тест НЕ выполнен." << std::endl;
		}
	}
	catch (const char* error_message)
	{
		std::cout << error_message;
	}
}

int main()
{
	//std::filesystem::path path = std::filesystem::current_path();
	//Matrix matrix = reader(path / "input.txt");

	//Matrix cutting = matrix.getCut(matrix.getQuantityRow() / 2, matrix.getQuantityRow(), matrix.getQuantityCal() / 2, matrix.getQuantityCal());
	//writer(path / "output.txt", cutting);


	//Тесты
	setlocale(LC_ALL, "Russian");

	test_sum_matrix();
	test_sum_eq_matrix();

	test_diff_matrix();
	test_diff_eq_matrix();

	test_mult_scalar_matrix();
	test_mult_eq_scalar_matrix();

	test_mult_matrix();

	return 0;
}