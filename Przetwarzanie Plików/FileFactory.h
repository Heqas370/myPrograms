#include <string>
#include "IFile.h"
#include "BinaryFile.h"
#include "CsvFile.h"

	 class FileFactory
	{
	public:
		static IFile* Open(const std::string, const std::string);
	};


