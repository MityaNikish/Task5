#pragma once
#include "matrix.h"
#include <filesystem>

Matrix reader(std::filesystem::path parh);

void writer(std::filesystem::path parh, const Matrix& matrix);