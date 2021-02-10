
#pragma once
#include<fstream>
#include"Point.h"
#include"FileError.h"
#include<sstream>
#include"IFile.h"
using namespace std;
class CsvFile : public IFile{
private:
	void WriteLine(Point);
	vector<string> Split(std::string, char);
public:
	CsvFile(const std::string, const std::string);
	~CsvFile();
	 virtual FileError Write( std::vector<Point>&);
	 virtual FileError Read(std::vector<Point>&);
	 virtual FileError Read(Point&, const unsigned long);

};