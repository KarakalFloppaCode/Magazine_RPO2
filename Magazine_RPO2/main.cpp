#include <io.h> // _setmode, _fileno
#include <fcntl.h> // _O_U16TEXT
#include "autorization.hpp"

/*
		std::cout		std::wcout
		char			wchar_t
		std::cin		std::wcin
		std::string		std::wstring
		std::getline	std::getline
		"Text"			L"Text"
		'\n'			L'\n'
		std::endl		std::endl
	*/

int main()
{

	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stdout), _O_U16TEXT);	
	
	Start();

	return 0;
}



/*
	




*/