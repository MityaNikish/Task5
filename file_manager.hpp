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

	//������������� � ������� ������� �� ���������
	void setMatrix(Matrix& matrix);
	//������ ����, ������������ ������ ���������� ������� � ����� ������������
	void readMatrix(std::filesystem::path file_path);
	//���������� � ���� ������ ������� ����������� ������� � ����� ������������
	void writeMatrix(std::filesystem::path file_path);
};