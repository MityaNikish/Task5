#pragma once

#include "matrix.h"
#include <iostream>


//Сумма двух пустых матриц
void TEST_sum_matrix_1(void)
{
	try
	{
		Matrix a(3, 2);

		Matrix b(3, 2);

		Matrix target(3, 2);

		std::cout << "Test operator+(): ";
		Matrix result = a + b;

		if (target == result)
		{
			std::cout << "[PASSED]" << std::endl;
		}
		else
		{
			std::cout << "[FAILED]" << std::endl;
		}
	}
	catch (const char* error_message)
	{
		std::cout << error_message;
	}
}

//Сумма пустой и полной матриц
void TEST_sum_matrix_2(void)
{
	try
	{
		Matrix a(3, 2);

		Matrix b(3, 2);
		b.setElement(0, 0, 6);
		b.setElement(0, 1, 5);
		b.setElement(1, 0, 4);
		b.setElement(1, 1, 3);
		b.setElement(2, 0, 2);
		b.setElement(2, 1, 1);

		Matrix target(3, 2);
		target.setElement(0, 0, 6);
		target.setElement(0, 1, 5);
		target.setElement(1, 0, 4);
		target.setElement(1, 1, 3);
		target.setElement(2, 0, 2);
		target.setElement(2, 1, 1);

		std::cout << "Test operator+(): ";
		Matrix result = a + b;

		if (target == result)
		{
			std::cout << "[PASSED]" << std::endl;
		}
		else
		{
			std::cout << "[FAILED]" << std::endl;
		}
	}
	catch (const char* error_message)
	{
		std::cout << error_message;
	}
}

//Сумма полной и пустой матриц
void TEST_sum_matrix_3(void)
{
	try
	{
		Matrix a(3, 2);
		a.setElement(0, 0, 1);
		a.setElement(0, 1, 2);
		a.setElement(1, 0, 3);
		a.setElement(1, 1, 4);
		a.setElement(2, 0, 5);
		a.setElement(2, 1, 6);

		Matrix b(3, 2);

		Matrix target(3, 2);
		target.setElement(0, 0, 1);
		target.setElement(0, 1, 2);
		target.setElement(1, 0, 3);
		target.setElement(1, 1, 4);
		target.setElement(2, 0, 5);
		target.setElement(2, 1, 6);


		std::cout << "Test operator+(): ";
		Matrix result = a + b;

		if (target == result)
		{
			std::cout << "[PASSED]" << std::endl;
		}
		else
		{
			std::cout << "[FAILED]" << std::endl;
		}
	}
	catch (const char* error_message)
	{
		std::cout << error_message;
	}
}

//Сумма двух полных матриц
void TEST_sum_matrix_4(void)
{
	try
	{
		Matrix a(3, 2);
		a.setElement(0, 0, 1);
		a.setElement(0, 1, 2);
		a.setElement(1, 0, 3);
		a.setElement(1, 1, 4);
		a.setElement(2, 0, 5);
		a.setElement(2, 1, 6);

		Matrix b(3, 2);
		b.setElement(0, 0, 6);
		b.setElement(0, 1, 5);
		b.setElement(1, 0, 4);
		b.setElement(1, 1, 3);
		b.setElement(2, 0, 2);
		b.setElement(2, 1, 1);

		Matrix target(3, 2);
		target.setElement(0, 0, 7);
		target.setElement(0, 1, 7);
		target.setElement(1, 0, 7);
		target.setElement(1, 1, 7);
		target.setElement(2, 0, 7);
		target.setElement(2, 1, 7);

		std::cout << "Test operator+(): ";
		Matrix result = a + b;

		if (target == result)
		{
			std::cout << "[PASSED]" << std::endl;
		}
		else
		{
			std::cout << "[FAILED]" << std::endl;
		}
	}
	catch (const char* error_message)
	{
		std::cout << error_message;
	}
}

//Сумма двух разряженных матриц (с повторяющимися позициями элементами)
void TEST_sum_matrix_5(void)
{
	try
	{
		Matrix a(3, 2);
		a.setElement(0, 0, 1);
		a.setElement(1, 0, 3);
		a.setElement(2, 0, 5);

		Matrix b(3, 2);
		b.setElement(0, 0, 6);
		b.setElement(1, 0, 4);
		b.setElement(2, 0, 2);

		Matrix target(3, 2);
		target.setElement(0, 0, 7);
		target.setElement(1, 0, 7);
		target.setElement(2, 0, 7);

		std::cout << "Test operator+(): ";
		Matrix result = a + b;

		if (target == result)
		{
			std::cout << "[PASSED]" << std::endl;
		}
		else
		{
			std::cout << "[FAILED]" << std::endl;
		}
	}
	catch (const char* error_message)
	{
		std::cout << error_message;
	}
}

//Сумма двух разряженных матриц (с не повторяющимися позициями элементов)
void TEST_sum_matrix_6(void)
{
	try
	{
		Matrix a(3, 2);
		a.setElement(0, 0, 1);
		a.setElement(1, 0, 3);
		a.setElement(2, 0, 5);


		Matrix b(3, 2);
		b.setElement(0, 1, 2);
		b.setElement(1, 1, 4);
		b.setElement(2, 1, 6);

		Matrix target(3, 2);
		target.setElement(0, 0, 1);
		target.setElement(0, 1, 2);
		target.setElement(1, 0, 3);
		target.setElement(1, 1, 4);
		target.setElement(2, 0, 5);
		target.setElement(2, 1, 6);


		std::cout << "Test operator+(): ";
		Matrix result = a + b;

		if (target == result)
		{
			std::cout << "[PASSED]" << std::endl;
		}
		else
		{
			std::cout << "[FAILED]" << std::endl;
		}
	}
	catch (const char* error_message)
	{
		std::cout << error_message;
	}
}



//Разность двух пустых матриц
void TEST_diff_matrix_1(void)
{
	try
	{
		Matrix a(3, 2);

		Matrix b(3, 2);

		Matrix target(3, 2);

		std::cout << "Test operator-(): ";
		Matrix result = a - b;

		if (target == result)
		{
			std::cout << "[PASSED]" << std::endl;
		}
		else
		{
			std::cout << "[FAILED]" << std::endl;
		}
	}
	catch (const char* error_message)
	{
		std::cout << error_message;
	}
}

//Разность двух разряженных матриц (с повторяющимися позициями элементами)
void TEST_diff_matrix_2(void)
{
	try
	{
		Matrix a(3, 2);
		a.setElement(0, 0, 1);
		a.setElement(1, 0, 3);
		a.setElement(2, 0, 5);

		Matrix b(3, 2);
		b.setElement(0, 0, 6);
		b.setElement(1, 0, 4);
		b.setElement(2, 0, 2);

		Matrix target(3, 2);
		target.setElement(0, 0, -5);
		target.setElement(1, 0, -1);
		target.setElement(2, 0, 3);

		std::cout << "Test operator-(): ";
		Matrix result = a - b;

		if (target == result)
		{
			std::cout << "[PASSED]" << std::endl;
		}
		else
		{
			std::cout << "[FAILED]" << std::endl;
		}
	}
	catch (const char* error_message)
	{
		std::cout << error_message;
	}
}

//Разность двух разряженных матриц (с не повторяющимися позициями элементов)
void TEST_diff_matrix_3(void)
{
	try
	{
		Matrix a(3, 2);
		a.setElement(0, 0, 1);
		a.setElement(1, 0, 3);
		a.setElement(2, 0, 5);


		Matrix b(3, 2);
		b.setElement(0, 1, 2);
		b.setElement(1, 1, 4);
		b.setElement(2, 1, 6);

		Matrix target(3, 2);
		target.setElement(0, 0, 1);
		target.setElement(0, 1, -2);
		target.setElement(1, 0, 3);
		target.setElement(1, 1, -4);
		target.setElement(2, 0, 5);
		target.setElement(2, 1, -6);


		std::cout << "Test operator-(): ";
		Matrix result = a - b;

		if (target == result)
		{
			std::cout << "[PASSED]" << std::endl;
		}
		else
		{
			std::cout << "[FAILED]" << std::endl;
		}
	}
	catch (const char* error_message)
	{
		std::cout << error_message;
	}
}



//Произведение пустой матрицы и числа
void TEST_mult_with_double_matrix_1(void)
{
	try
	{
		Matrix a(3, 2);

		Matrix target(3, 2);

		std::cout << "Test operator*(double): ";
		Matrix result = a * 5;

		if (target == result)
		{
			std::cout << "[PASSED]" << std::endl;
		}
		else
		{
			std::cout << "[FAILED]" << std::endl;
		}
	}
	catch (const char* error_message)
	{
		std::cout << error_message;
	}
}

//Произведение разряженной матрицы и числа
void TEST_mult_with_double_matrix_2(void)
{
	try
	{
		Matrix a(3, 2);
		a.setElement(0, 0, 1);
		a.setElement(1, 0, 3);
		a.setElement(2, 0, 5);


		Matrix target(3, 2);
		target.setElement(0, 0, 3);
		target.setElement(1, 0, 9);
		target.setElement(2, 0, 15);

		std::cout << "Test operator*(double): ";
		Matrix result = a * 3;

		if (target == result)
		{
			std::cout << "[PASSED]" << std::endl;
		}
		else
		{
			std::cout << "[FAILED]" << std::endl;
		}
	}
	catch (const char* error_message)
	{
		std::cout << error_message;
	}
}

//Произведение полной матрицы и числа
void TEST_mult_with_double_matrix_3(void)
{
	try
	{
		Matrix a(3, 2);
		a.setElement(0, 0, 1);
		a.setElement(0, 1, 2);
		a.setElement(1, 0, 3);
		a.setElement(1, 1, 4);
		a.setElement(2, 0, 5);
		a.setElement(2, 1, 6);

		Matrix target(3, 2);
		target.setElement(0, 0, 3);
		target.setElement(0, 1, 6);
		target.setElement(1, 0, 9);
		target.setElement(1, 1,12);
		target.setElement(2, 0, 15);
		target.setElement(2, 1, 18);

		std::cout << "Test operator*(double): ";
		Matrix result = a * 3;

		if (target == result)
		{
			std::cout << "[PASSED]" << std::endl;
		}
		else
		{
			std::cout << "[FAILED]" << std::endl;
		}
	}
	catch (const char* error_message)
	{
		std::cout << error_message;
	}
}



//Произведение пустых матриц
void TEST_mult_with_matrix_matrix_1(void)
{
	try
	{
		Matrix a(3, 2);

		Matrix b(2, 3);

		Matrix target(3, 3);

		std::cout << "Test operator*(Matrix): ";
		Matrix result = a * b;

		if (target == result)
		{
			std::cout << "[PASSED]" << std::endl;
		}
		else
		{
			std::cout << "[FAILED]" << std::endl;
		}
	}
	catch (const char* error_message)
	{
		std::cout << error_message;
	}
}

//Произведение полных матриц
void TEST_mult_with_matrix_matrix_2(void)
{
	try
	{
		Matrix a(2, 3);
		a.setElement(0, 0, 1);
		a.setElement(0, 1, 2);
		a.setElement(0, 2, 3);
		a.setElement(1, 0, 4);
		a.setElement(1, 1, 5);
		a.setElement(1, 2, 6);

		Matrix b(3, 2);
		b.setElement(0, 0, 1);
		b.setElement(0, 1, 2);
		b.setElement(1, 0, 3);
		b.setElement(1, 1, 4);
		b.setElement(2, 0, 5);
		b.setElement(2, 1, 6);

		Matrix target(2, 2);
		target.setElement(0, 0, 22);
		target.setElement(0, 1, 28);
		target.setElement(1, 0, 49);
		target.setElement(1, 1, 64);

		std::cout << "Test operator*(Matrix): ";
		Matrix result = a * b;

		if (target == result)
		{
			std::cout << "[PASSED]" << std::endl;
		}
		else
		{
			std::cout << "[FAILED]" << std::endl;
		}
	}
	catch (const char* error_message)
	{
		std::cout << error_message;
	}
}

//Произведение разряженных матриц
void TEST_mult_with_matrix_matrix_3(void)
{
	try
	{
		Matrix a(2, 3);
		a.setElement(0, 0, 1);
		a.setElement(0, 2, 3);
		a.setElement(1, 0, 4);

		Matrix b(3, 2);
		b.setElement(0, 0, 1);
		b.setElement(1, 1, 4);
		b.setElement(2, 0, 5);

		Matrix target(2, 2);
		target.setElement(0, 0, 16);
		target.setElement(1, 0, 4);

		std::cout << "Test operator*(Matrix): ";
		Matrix result = a * b;

		if (target == result)
		{
			std::cout << "[PASSED]" << std::endl;
		}
		else
		{
			std::cout << "[FAILED]" << std::endl;
		}
	}
	catch (const char* error_message)
	{
		std::cout << error_message;
	}
}



//Все тесты
void TESTS(void)
{
	//Блок тестов на сумму
	TEST_sum_matrix_1();
	TEST_sum_matrix_2();
	TEST_sum_matrix_3();
	TEST_sum_matrix_4();
	TEST_sum_matrix_5();
	TEST_sum_matrix_6();
	//

	std::cout << "\n\n";

	//Блок тестов на разность
	TEST_diff_matrix_1();
	TEST_diff_matrix_2();
	TEST_diff_matrix_3();
	//

	std::cout << "\n\n";

	//Блок тестов на произведение матрицы и числа
	TEST_mult_with_double_matrix_1();
	TEST_mult_with_double_matrix_2();
	TEST_mult_with_double_matrix_3();
	//

	std::cout << "\n\n";

	//Блок тестов на произведение матриц
	TEST_mult_with_matrix_matrix_1();
	TEST_mult_with_matrix_matrix_2();
	TEST_mult_with_matrix_matrix_3();
	//
}