#pragma once
#include "matrix.h"
#include <filesystem>

class Matrix;

class FileManager
{
	Matrix* matrix_ = nullptr;

public:
	FileManager() = default;
	FileManager(const FileManager&) = delete;
	FileManager& operator=(const FileManager&) = delete;
	FileManager(FileManager&&) = delete;
	FileManager& operator=(FileManager&&) = delete;
	~FileManager() = default;

	//Привязывается к объекту снаружи по указателю
	void setMatrix(Matrix& matrix);
	//Читает файл, конструирует объект переданный снаружи и после отвязывается
	void readMatrix(std::filesystem::path file_path);
	//Записывает в файл данные объекта переданного снаружи и после отвязывается
	void writeMatrix(std::filesystem::path file_path);
};