#include"RNG.h"
#include"CsvFile.h"
#include"BinaryFile.h"
#include"Point.h"
#include<fstream>
#include<iostream>
#include"FileFactory.h"
using namespace std;

int main() {
	RNG losowanie;
	Point p;
	std::vector<Point> p_zapis, p_odczyt;
	for  (int i = 0; i < 1000;  i++)
	{
		p.x = losowanie.rand(-1000, 1000);
		p.y = losowanie.rand(-1000, 1000);
		p.z = losowanie.rand(-1000, 1000);
		p_zapis.push_back(p);
	}
	IFile* csv, * bin;
	csv = FileFactory::Open("pliczek.csv", "w");
	csv->Write(p_zapis);
	bin = FileFactory::Open("inny_pliczek.bin", "w");
	bin->Write(p_zapis);
	

}
	
	