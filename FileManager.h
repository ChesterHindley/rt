#pragma once
#include <cstdio>
class FileManager
{
	std::FILE* file;
public:
	FileManager(std::FILE* f);
	~FileManager();


	// not safe but dont care for this project
	// ref counting would be needed
	operator std::FILE*();
};

