#include "matrix.h"
#include "file_manager.hpp"


int main()
{
	std::filesystem::path path = std::filesystem::current_path();
	Matrix matrix = reader(path / "input.txt");

	Matrix cutting = matrix.getCut(matrix.getQuantityRow() / 2, matrix.getQuantityRow(), matrix.getQuantityCal() / 2, matrix.getQuantityCal());
	writer(path / "output.txt", cutting);

	return 0;
}