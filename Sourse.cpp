#include "matrix.h"
#include "file_manager.hpp"

#include "test.hpp"


int main()
{
	//std::filesystem::path path = std::filesystem::current_path();
	//FileManager FM;

	//Matrix matrix;
	//FM.setMatrix(matrix);
	//FM.readMatrix(path / "input.txt");

	//Matrix cutting = matrix.getCut(matrix.getQuantityRow() / 2, matrix.getQuantityRow(), matrix.getQuantityCal() / 2, matrix.getQuantityCal());
	//FM.setMatrix(cutting);
	//FM.writeMatrix(path / "output.txt");


	setlocale(LC_ALL, "Russian");
	TESTS();

	return 0;
}