#include "Utils.h"

class Listify {
	
	public:
		static string listify(int N);
		
	private:
		static string calculate(int N, string s_up, string s_down);
		
		static string calculate_min_1_up(int N, string s_up, string s_down);
		static string calculate_min_2_up(int N, string s_up, string s_down);
		static string calculate_min_1_down(int N, string s_up, string s_down);
		static string calculate_min_2_down(int N, string s_up, string s_down);
		

};
