#pragma once
#include <fstream>
#include <vector>
#include "Point.h"
#include"FileError.h"
class IFile
{
protected:
	std::fstream file;
	std::string filePath;
	unsigned long length;
	std::fstream::openmode openMode;
public:
	IFile(const std::string, const std::string);
	virtual ~IFile();
	virtual FileError Write( std::vector<Point>&)=0;
	virtual FileError Read(std::vector<Point>&)=0;
	virtual FileError Read(Point&, const unsigned long)=0;
};

