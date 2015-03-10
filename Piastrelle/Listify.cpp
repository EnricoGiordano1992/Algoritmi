#include "Listify.h"


string Listify::listify(int N)
{
	return calculate(N, "");	
}


string Listify::calculate(int N, string s)
{
	if(N == 0)
		return s + "\n";
						
	else
		if (N == 1)
			return calculate(N-1, s + "[O]");
		else
			return calculate(N-1, s + "[O]") + calculate(N-2, s + "[OOOO]");
}
