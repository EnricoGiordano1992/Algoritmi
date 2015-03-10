#include "Listify.h"


#define DEFINE_MY_STRING	string number = ""+to_string((counter % 5)+1)

string Listify::listify(int N)
{
	return calculate(N, "", "", 0);	
}


string Listify::calculate(int N, string s_up, string s_down, int counter)
{
	DEFINE_MY_STRING;

	if(N == 0)
		return s_up + "\n" + s_down + "\n\n";
						
	else
		if (N == 1)
			return calculate_min_1_down(N, s_up + " " + number, s_down, counter+1) + calculate(N-1, s_up + " " + number, s_down + " " + number, counter+1);
		else
			return calculate_min_1_down(N, s_up + " " + number, s_down, counter+1) + calculate_min_1_up(N, s_up, s_down  + " " + number, counter+1 ) 
				+ calculate(N-1, s_up + " " + number, s_down + " " + number, counter+1)
				+ calculate_min_2_down(N, s_up + " " + number + " " + number, s_down, counter+1) + calculate_min_2_up(N, s_up, s_down + " " + number + " " + number + " ", counter+1 );
}





string Listify::calculate_min_1_down(int N, string s_up, string s_down, int counter)
{
	DEFINE_MY_STRING;

	if(N == 1)
		return calculate(N-1, s_up, s_down + " " + number, counter+1);
	else
		return calculate(N-1, s_up, s_down + " " + number, counter+1) + calculate_min_1_up(N-1, s_up, s_down + " " + number + " " + number, counter+1);
}

string Listify::calculate_min_2_down(int N, string s_up, string s_down, int counter)
{
	DEFINE_MY_STRING;

	return calculate_min_1_down(N-1, s_up, s_down + " " + number, counter+1) + calculate(N-2, s_up, s_down + " " + number + " " + number, counter+1);
}


string Listify::calculate_min_1_up(int N, string s_up, string s_down, int counter)
{
	DEFINE_MY_STRING;

	if(N == 1)
		return calculate(N-1, s_up + " " + number, s_down, counter+1);
	else
	 	return calculate(N-1, s_up + " " + number, s_down, counter+1) + calculate_min_1_down(N-1, s_up + " " + number + " " + number, s_down, counter+1);
}

string Listify::calculate_min_2_up(int N, string s_up, string s_down, int counter)
{
	DEFINE_MY_STRING;

	return calculate_min_1_up(N-1, s_up + " " + number, s_down, counter+1) + calculate(N-2, s_up + " " + number + " " + number, s_down, counter+1);
}
