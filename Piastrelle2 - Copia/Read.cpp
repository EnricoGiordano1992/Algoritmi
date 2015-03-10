#include "Read.h"

int Read::read_file(string NomeFile)
{
	int N;
	string line;
	ifstream myfile;
	
	myfile.open(NomeFile.c_str());
	
    if (myfile.is_open())
    {
      while ( getline (myfile,line ))
        N = atoi(line.c_str());

      myfile.close();
    }
    	
    return N;
}
