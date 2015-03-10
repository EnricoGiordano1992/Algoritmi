#include "Write.h"

void Write::write_file(string NomeFile, string Contenuto)
{
	
	ofstream myfile (NomeFile.c_str());
	if (myfile.is_open())
	{
    	myfile << Contenuto;

    	myfile.close();
  	}
  	else cout << "File non apribile";
}
