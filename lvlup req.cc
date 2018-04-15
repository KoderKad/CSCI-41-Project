#include <cmath>
#include <iostream>
using namespace std;
int main(void)
{	
	int levels = 100;
	int xp_for_first_level = 1000;
	int xp_for_last_level = 1000000;

	double B = log((double)xp_for_last_level / xp_for_first_level) / (levels - 1);
	double A = (double)xp_for_first_level / (exp(B) - 1.0);

	for (int i = 1; i <= levels; i++)
	{
		int old_xp = round(A * exp(B * (i - 1)));
		int new_xp = round(A * exp(B * i));
		cout << i << " " << (new_xp - old_xp) <<endl;
	}
}

//Dylan, check out this code i found online to see if this can help
