#include "FileManager.h"

#include <iostream>

FileManager::FileManager(std::FILE* f) : file{f}
{}

FileManager::~FileManager()
{
	if (file)
		fclose(file);
	file = nullptr;
	if constexpr (_DEBUG)
		std::cout << "closing file\n";
}

FileManager::operator std::FILE* ()
{
	return file;
}
