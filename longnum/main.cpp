#include <iostream>

#include "longnum.h"
#include <cstdlib>

#define N 11
#define DEFAULT_EXAMPLE -50
#define DEFAULT_UNSIGNED_EXAMPLE 4
#define EX_STRING "-46"

using namespace std;

int main () {
	LongNum long_empty;
	cerr << "long_empty = " << long_empty << endl;
	
	unsigned long long my_ull = DEFAULT_UNSIGNED_EXAMPLE;
	LongNum long_ull(my_ull);
	cerr << "long_ull = " << long_ull << endl;
	
	long long my_ll = DEFAULT_EXAMPLE;
	LongNum long_ll(my_ll);
	cerr << "long_ll = " << long_ll << endl;
	
	int my_int = DEFAULT_EXAMPLE;
	LongNum long_int(my_int);
	cerr << "long_int = " << long_int << endl;
	
	char* my_char = (char*)malloc(N * sizeof(char));
	my_char[0] = '-';
	for (int i = 1; i < N; ++i) {
		my_char[i] = '9' - (i - 1);
	}
	LongNum long_char(my_char);
	cerr << "long_char = " << long_char << endl;
	
	string my_string = EX_STRING;
	LongNum long_string(my_string);
	cerr << "long_string = " << long_string << endl;
	
	cerr << endl;
	
	cerr << "long_int == long_ll is " << (long_int == long_ll) << endl;
	cerr << "long_int == unsigned long long is " << (long_int == my_ull) << endl;
	cerr << "unsigned long long == long_string is " << (my_ull == long_string) << endl;
	
	cerr << endl;
	
	cerr << "long_empty != long_ull is " << (long_empty != long_ull) << endl;
	cerr << "long_int != unsigned long long is " << (long_int != my_ull) << endl;
	cerr << "unsigned long long != long_string is " << (my_ull != long_string) << endl;
	
	cerr << endl;
	
	cerr << "long_ll < long_string is " << (long_ll < long_string) << endl;
	cerr << "long_int < unsigned long long is " << (long_int < my_ull) << endl;
	cerr << "unsigned long long < long_string is " << (my_ull < long_string) << endl;
	
	cerr << endl;
	
	cerr << "long_ull <= long_string is " << (long_ull <= long_string) << endl;
	cerr << "long_int <= unsigned long long is " << (long_int <= my_ull) << endl;
	cerr << "unsigned long long <= long_string is " << (my_ull <= long_string) << endl;
	
	cerr << endl;
	
	cerr << "long_ull > long_string is " << (long_ull > long_string) << endl;
	cerr << "long_int > unsigned long long is " << (long_int > my_ull) << endl;
	cerr << "unsigned long long > long_string is " << (my_ull > long_string) << endl;
	
	cerr << endl;
	
	cerr << "long_ull >= long_string is " << (long_ull >= long_string) << endl;
	cerr << "long_int >= unsigned long long is " << (long_int >= my_ull) << endl;
	cerr << "unsigned long long >= long_string is " << (my_ull >= long_string) << endl;
	
	cerr << endl;
	
	cerr << "long_ll + long_string is " << long_ll + long_string << endl;
	cerr << "long_int + unsigned long long is " << (long_int + my_ull) << endl;
	cerr << "unsigned long long + long_string is " << (my_ull + long_string) << endl;
	
	cerr << endl;
	
	cerr << "long_ll - long_string is " << long_ll - long_string << endl;
	cerr << "long_int - unsigned long long is " << (long_int - my_ull) << endl;
	cerr << "unsigned long long - long_string is " << (my_ull - long_string) << endl;
	
	cerr << endl;
	
	cerr << "long_ll prefix ++ is " << ++long_ll << endl;
	cerr << "long_int postfix ++ is " << long_int++ << endl;

	cerr << endl;
	
	long_ll += long_string;
	cerr << "long_ll += long string is " << long_ll << endl;
	long_int += my_string;
	cerr << "long_int += my_string is " << long_int << endl;

	cerr << endl;
	
	cerr << "long_ll prefix -- is " << --long_ll << endl;
	cerr << "long_int postfix -- is " << long_int-- << endl;

	cerr << endl;
	
	long_ll -= long_string;
	cerr << "long_ll -= long string is " << long_ll << endl;
	long_int -= my_string;
	cerr <<"long_int -= my_string is " << long_int << endl;
	
	cerr << endl;
	
	cerr << "long_ll * long_string is " << (long_ll * long_string) << endl;
	cerr << "long_int * unsigned long long is " << (long_int * my_ull) << endl;
	cerr << "unsigned long long * long_string is " << (my_ull * long_string) << endl;
	
	cerr << endl;
	
	cerr << "long_ll / long_string is " << (long_ll / long_string) << endl;
	//cerr << "long_int / unsigned long long is " << (long_int / my_ull) << endl;
	//cerr << "unsigned long long / long_string is " << (my_ull / long_string) << endl;
	
	cerr << endl;
	
	
	
	free(my_char);
	return 0;
}
