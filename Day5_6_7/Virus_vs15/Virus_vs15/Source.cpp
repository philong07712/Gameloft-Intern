#include <stdio.h>
#include <cstdlib>
# include "vld.h"
#include <iostream>
using namespace std;
#include "Patient.h"
int main()
{
	Patient p;
	char t = '0';
	while (p.GetState() == 1)
	{
		cout << "Take Medicine (0 = NO, 1 = YES): \n";
		cin >> t;
		if (t == '1')
		{
			int min = 1;
			int max = 1;
			int medicine_resistance = min + (rand() % (int)(max - min + 1));
			cout << "Resit taken: " << medicine_resistance << endl;
			p.TakeMedicine(medicine_resistance);
		}
	}
	return 0;
}