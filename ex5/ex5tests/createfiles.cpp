/*
 * createfiles.cpp
 *
 *  Created on: Jun 15, 2015
 *      Author: roigreenberg
 */
#include <iostream>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <string>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

using namespace std;





int main(int argc, char* argv[])
{
	string s;
	if(argc <= 1)
	{
		for (int j = 1; j<=10000; j*=10)
		{
			s = "ftest" + to_string(j);
			cout << s <<endl;
			ofstream of (s);
			for ( int i = 0; i< 100*j; i++)
			{
				of << i << "-";
				of << "123456789abcdefghijklmnopqrstuvwxyz\n";
			}
			of << "**********";
			of.close();
		}
	s = "ftestshouldntbesent";
	ofstream of (s);
	cout << s <<endl;
	of << "1234";
	of.close();
	}
	else
	{
		s = "ftestbig";
		cout << s <<endl;
		ofstream of (s);
		for ( int i = 0; i < 10000000; i++)
		{
			of << i << "-";
			of << "123456789abcdefghijklmnopqrstuvwxyz\n";
		}
		of << "**********";
		of.close();
	}
	return 0;
}
