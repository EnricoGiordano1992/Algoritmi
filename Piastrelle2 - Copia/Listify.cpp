#include "Listify.h"


string Listify::listify(int N)
{
	return calculate(N, "", "");	
}


string Listify::calculate(int N, string s_up, string s_down)
{
	string number = ""+to_string(N % 5);
	if(N == 0)
		return s_up + "\n" + s_down + "\n\n";
						
	else
		if (N == 1)
			return calculate_min_1_down(N, s_up + " " + number, s_down) + calculate_min_1_up(N, s_up, s_down + " " + number) + calculate(N-1, s_up + " " + number, s_down + " " + number);
		else
			return calculate_min_1_down(N, s_up + " " + number, s_down) + calculate_min_1_down(N, s_up + " " + number + " " + number + " ", s_down ) + calculate(N-1, s_up + " " + number, s_down + " " + number);
}





string Listify::calculate_min_1_down(int N, string s_up, string s_down)
{
	string number = ""+to_string(N % 5);

	if(N == 1)
		return calculate(N-1, s_up, s_down + " " + number);
	else
		return calculate(N-1, s_up, s_down + " " + number) + calculate_min_1_up(N-1, s_up, s_down + " " + number + " " + number);
}

string Listify::calculate_min_2_down(int N, string s_up, string s_down)
{
	string number = ""+to_string(N % 5);

	return calculate_min_1_down(N-1, s_up, s_down + " " + number) + calculate(N-2, s_up, s_down + " " + number + " " + number);
}


string Listify::calculate_min_1_up(int N, string s_up, string s_down)
{
	string number = ""+to_string(N % 5);

	if(N == 1)
		return calculate(N-1, s_up + " " + number, s_down);
	else
	 	return calculate(N-1, s_up + " " + number, s_down) + calculate_min_1_down(N-1, s_up + " " + number + " " + number, s_down);
}

string Listify::calculate_min_2_up(int N, string s_up, string s_down)
{
	string number = ""+to_string(N % 5);

	return calculate_min_1_up(N-1, s_up + " " + number, s_down) + calculate(N-2, s_up + " " + number + " " + number, s_down);
}
