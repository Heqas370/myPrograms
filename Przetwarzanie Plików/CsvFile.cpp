#include "CsvFile.h"

void CsvFile::WriteLine(Point v)
{
	file << v.x <<";"<< v.y<<";" << v.z << endl;
}

vector<string> CsvFile::Split(std::string str , char delim)
{
	vector<string> result;
	stringstream ss(str);
	string item;
	while (getline(ss, item, delim)) {
		result.push_back(item);
	}
	return result;

}

CsvFile::CsvFile(const std::string filePath, const std::string mode) : IFile(filePath,mode)
{
}

CsvFile::~CsvFile()
{
	file.close();
}

FileError CsvFile::Write( std::vector<Point>& v)
{
	if (filePath.find("csv") == std::string::npos) {
		FileError error = FileError::FILE_INVALID;
		}
	file.seekp(0, std::fstream::end);
	unsigned long teraz = file.tellp();
	unsigned long po_wpisaniu;
	FileError error = FileError::ACCESS_DENIED;
	if (openMode & std::fstream::out) {
		size_t rozmiar = 0;
		for (int i = 0; i < v.size(); i++)
		{
			WriteLine(v[i]);
		}
	}
	po_wpisaniu = file.tellp();
	CsvFile::length = po_wpisaniu - teraz;
	error = FileError::SUCCESS;

	return error;
}





FileError CsvFile::Read(Point& v, const unsigned long idx)
{
	if (filePath.find("csv") == string::npos)
		FileError error = FileError::FILE_INVALID;
	else if (openMode & fstream::in) {
		file.seekg(0, fstream::beg);
		string punkt;
		vector<string> tab1;
		while (getline(file, punkt)) {
				Split(punkt, ';');
				stringstream ss1, ss2, ss3;
				ss1 << tab1[0];
				ss1 >> v.x;
				ss2 << tab1[1];
				ss2 >> v.y;
				ss3 << tab1[2];
				ss3 >> v.z;
				FileError error = FileError::SUCCESS;
		};
	}
	FileError error = FileError::OUT_OF_BOUNDS;
	return error;
	
	
}
FileError CsvFile::Read(std::vector<Point>& v) {
	string line;
	vector<string> pomoc;
	if (filePath.find("csv") == string::npos)
		FileError error = FileError::FILE_INVALID;
	if (openMode & fstream::in) {
		vector<string> tab1, tab2;
		string line;
		file.seekg(0, fstream::beg);
		while (getline(file, line)) {
			tab1.push_back(line);
		}
		for (int i = 0; i < tab1.size(); i++) {
			int a = 0;
			Split(tab1[i], ';');
			vector<string> pomoc;
			tab2.push_back(pomoc[a]);
			tab2.push_back(pomoc[(long long int)a + 1]);
			tab2.push_back(pomoc[(long long int)a + 2]);
		}
		for (int i = 0; i < tab2.size(); i += 3) {
			stringstream ss1, ss2, ss3;
			Point p;
			ss1 << tab2[i];
			ss1 >> p.x;
			ss2 << tab2[i + 1];
			ss2 >> p.y;
			ss3 << tab2[i + 2];
			ss3 >> p.z;
			v.push_back(p);
		}
		FileError error = FileError::SUCCESS;
		return error;
	}
}

	