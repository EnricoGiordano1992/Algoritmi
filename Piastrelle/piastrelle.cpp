
#include <iostream>
#include <cstring>
#include <string>
#include <assert.h>
#include <fstream>

using namespace std;
typedef basic_string<char> string;


int read_file(string NomeFile)
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

void write_file(string NomeFile, string Contenuto)
{
	
	ofstream myfile (NomeFile.c_str());
	if (myfile.is_open())
	{
    	myfile << Contenuto;

    	myfile.close();
  	}
  	else cout << "File non apribile";
}


string calculate(int N, string s)
{
	if(N == 0)
		return s + "\n";
						
	else
		if (N == 1)
			return calculate(N-1, s + "[O]");
		else
			return calculate(N-1, s + "[O]") + calculate(N-2, s + "[OOOO]");
}

string listify(int N)
{
	return calculate(N, "");	
}






int main (void)
{
	int N = read_file("input.txt");
	assert( N >= 1 && N <= 25 );

	string s = listify(N);

	write_file("output.txt", s);

	return 0;

}