#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED


bool Testlib::__assert_print_to_stderr = true;
bool Testlib::__assert_print_if_ok     = false;
bool Testlib::__assert_throw_exception = true;
bool Testlib::__test_print_to_stderr   = true;
bool Testlib::__test_throw_exception   = false;

void Test1();

void TestAll();

void Test1() {
	{
        LongNum long1;
        ASSERT_MSG(long1 == 0, "long number is equal to 0");
        ASSERT_MSG(long1.getSize() == 0, "size of value massive = 0");
    }
    {
		unsigned long long my_ull = 1234567890;
		//std:: string my_string = "1234567890", long_string;
        LongNum long1(my_ull);
        /*std:: ostream os;
        ss << long1;
        ss >> long_string;
		ASSERT_MSG(long_string == my_string, "long number is equal to 1234567890");*/
		//ASSERT_MSG((string)long_string == my_string, "long number is equal to 1234567890");
		ASSERT_MSG(long1.getSign() == LongNum:: Sign::POSITIVE, "sign = POSITIVE");
    }
    {
        long long my_ll = -1234567890;
		LongNum long1(my_ll);
		ASSERT_MSG(long1.getSign() == LongNum:: Sign::NEGATIVE, "sign = NEGATIVE");
    }
    {
		int my_int = 0;
        LongNum long1(my_int);		
 		ASSERT_MSG(long1.getSign() == LongNum:: Sign::ZERO, "sign = ZERO");
	}
    {
		int N = 11;
        char* my_char = (char*)malloc(N * sizeof(char));
		my_char[0] = '-';
		for (int i = 1; i < N; ++i) {
			my_char[i] = '9' - (i - 1);
		}
		LongNum long1(my_char);
		ASSERT_MSG(long1.getSign() == LongNum:: Sign::NEGATIVE, "sign = NEGATIVE");
		free(my_char);
    }
    {
		std:: string my_string = "00000000000001234567890";
		LongNum long1(my_string);
		ASSERT_MSG(long1.getSign() == LongNum:: Sign::POSITIVE, "sign = POSITIVE");
    }
    {
        std:: string my_string = "-1234567890";
		LongNum long1(my_string);
		ASSERT_MSG(long1.getSign() == LongNum:: Sign::NEGATIVE, "sign = NEGATIVE");
    }
}

void Test2() {
	{
		LongNum long1("001234567980"), long2;
		long2 = long1;
		ASSERT_MSG(long2.getSign() == LongNum:: Sign::POSITIVE, "sign = POSITIVE");
	}
	
}


void Test3() {
	{
		LongNum long1("001234567890"), long2(1234567890);
		ASSERT_MSG((long1 == long2), "001234567890 is equal to 1234567890");
	}
	{
		LongNum long1, long2(0);
		ASSERT_MSG((long1 == long2) && (long2 == long1), "0 is equal to 0");
	}
	{
		LongNum long1, long2(5);
		ASSERT_MSG(!(long1 == long2) && !(long2 == long1), "0 is not equal to 5");
	}
	{
		LongNum long1("-1234567890"), long2(1234567890);
		ASSERT_MSG(!(long1 == long2) && !(long2 == long1), "1234567890 is not equal to -1234567890");
	}
	{
		LongNum long1("-1234567890"), long2(1234567890);
		ASSERT_MSG((long1 != long2) && (long2 != long1), "1234567890 is not equal to -1234567890");
	}
	{
		LongNum long1("-1234567890");
		int my_int = 1234567890;
		ASSERT_MSG((long1 != my_int) && (my_int != long1), "1234567890 is not equal to -1234567890");
	}	
}

void Test4() {
	{
		LongNum long1("001234567890"), long2(1234567891);
		ASSERT_MSG((long1 < long2), "001234567890 is equal to 1234567890");
	}
	{
		LongNum long1("0"), long2(1234567890);
		ASSERT_MSG((long1 < long2), "0 < 1234567890");
	}
	{
		LongNum long1("0"), long2(-1234567890);
		ASSERT_MSG(!(long1 < long2), "0 !< 1234567890");
	}
	{
		LongNum long1("1234567890"), long2(0);
		ASSERT_MSG(!(long1 < long2), "1234567890 !< 0");
	}
	{
		LongNum long1("0"), long2(0);
		ASSERT_MSG(!(long1 < long2), "0 !< 0");
	}
	{
		LongNum long1("-1234567890"), long2(1234567890);
		ASSERT_MSG((long1 < long2), "-1234567890 < 1234567890");
	}
	{
		LongNum long1("-1234567890"), long2;
		ASSERT_MSG((long1 < long2), "-1234567890 < 0");
	}
	{
		LongNum long1("0"), long2;
		ASSERT_MSG((long1 <= long2), "0 <= 0");
	}	
	{
		LongNum long1("0"), long2(1234567890);
		ASSERT_MSG(!(long1 > long2), "0 is not greater then 1234567890");
	}
	{
		LongNum long1("001234567890"), long2(-1234567891);
		ASSERT_MSG((long1 >= long2), "001234567890 >= -1234567890");
	}
}

void Test5() {
	{
		LongNum long1("001234567890");
		ASSERT_MSG((+long1).getSign() == LongNum:: Sign::POSITIVE, "sign = POSITIVE");		
	}
	{
		LongNum long1("0");
		ASSERT_MSG((+long1).getSign() == LongNum:: Sign::ZERO, "sign = ZERO");		
	}
	{
		LongNum long1;
		ASSERT_MSG((+long1).getSign() == LongNum:: Sign::ZERO, "sign = ZERO");		
	}
	{
		LongNum long1("-0");
		ASSERT_MSG((+long1).getSign() == LongNum:: Sign::ZERO, "sign = ZERO");		
	}
	{
		LongNum long1(-1234567890);
		ASSERT_MSG((+long1).getSign() == LongNum:: Sign::NEGATIVE, "sign = NEGATIVE");		
	}
	{
		LongNum long1(-1234567890), long2(1234567890);
		ASSERT_MSG(((long1 + long2) == LongNum(0)) && ((long2 + long1) == LongNum(0)), "-1234567890 + 1234567890 = 0");
		ASSERT_MSG(long1 == LongNum(-1234567890) && long2 == LongNum(1234567890), "Agruments did not change");		
	}
	{
		LongNum long1(-1234567890), long2(0);
		ASSERT_MSG(((long1 + long2) == LongNum(-1234567890)) && ((long2 + long1) == LongNum(-1234567890)), "-1234567890 + 0 = -1234567890");
		ASSERT_MSG(long1 == LongNum(-1234567890) && long2 == LongNum(0), "Agruments did not change");		
	}
	{
		long long l1 = -1111111111, l2 = -2222222222;
		LongNum long1(l1), long2(l2);
		ASSERT_MSG(((long1 + long2) == LongNum(l1 + l2)) && ((long2 + long1) == LongNum(l1 + l2)), "-1111111111 + -2222222222 = -3333333333");
		ASSERT_MSG(long1 == LongNum(l1) && long2 == LongNum(l2), "Agruments did not change");		
	}
	{
		long long l1 = 1111111111, l2 = 2222222222;
		LongNum long1(l1), long2(l2);
		ASSERT_MSG(((long1 + long2) == LongNum(l1 + l2)) && ((long2 + long1) == LongNum(l1 + l2)), "-1111111111 + -2222222222 = -3333333333");
		ASSERT_MSG(long1 == LongNum(l1) && long2 == LongNum(l2), "Agruments did not change");		
	}	
	{
		long long l1 = -12345678905, l2 = 97845632108;
		LongNum long1(l1), long2(l2);
		ASSERT_MSG(((long1 + long2) == LongNum(l1 + l2)) && ((long2 + long1) == LongNum(l1 + l2)), "-1111111111 + -2222222222 = -3333333333");
		ASSERT_MSG(long1 == LongNum(l1) && long2 == LongNum(l2), "Agruments did not change");		
	}	
	{
		long long l1 = 0;
		int l2 = 0;
		LongNum long1(l1), long2(l2);
		ASSERT_MSG(((long1 + long2) == LongNum(l1 + l2)) && ((long2 + long1) == LongNum(l1 + l2)), "-1111111111 + -2222222222 = -3333333333");
		ASSERT_MSG(long1 == LongNum(l1) && long2 == LongNum(l2), "Agruments did not change");		
	}
	{
		long long l1 = 1111111111, l2 = 2222222222;
		LongNum long1(l1), long2(l2);
		ASSERT_MSG((long1 += long2) == LongNum(l1 + l2), "-1111111111 += -2222222222 = -3333333333");
		ASSERT_MSG(long1 == LongNum(l1 + l2) && long2 == LongNum(l2), "Agrument1 change and argument 2 did not change");		
	}
	{
		LongNum long1(1234567890);
		ASSERT_MSG((++long1) == LongNum(1234567891), "prefix ++ test");
		ASSERT_MSG(long1 == LongNum(1234567891), "prefix ++ test");	
	}
	{
		LongNum long1(1234567890);
		ASSERT_MSG((long1++) == LongNum(1234567890), "postfix ++ test");
		ASSERT_MSG(long1 == LongNum(1234567891), "postfix ++ test");	
	}	
}


void Test6() {
	{
		LongNum long1("001234567890");
		ASSERT_MSG((-long1).getSign() == LongNum:: Sign::NEGATIVE, "sign = NEGATIVE");		
	}
	{
		LongNum long1("0");
		ASSERT_MSG((-long1).getSign() == LongNum:: Sign::ZERO, "sign = ZERO");		
	}
	{
		LongNum long1;
		ASSERT_MSG((-long1).getSign() == LongNum:: Sign::ZERO, "sign = ZERO");		
	}
	{
		LongNum long1("-0");
		ASSERT_MSG((-long1).getSign() == LongNum:: Sign::ZERO, "sign = ZERO");		
	}
	{
		LongNum long1(-1234567890);
		ASSERT_MSG((-long1).getSign() == LongNum:: Sign::POSITIVE, "sign = POSITIVE");		
	}
	{
		LongNum long1(-1234567890), long2(1234567890);
		long long l = -1234567890;
		l *= 2;
		ASSERT_MSG(((long1 - long2) == LongNum(l)) && ((long2 - long1) == LongNum(-l)), "-1234567890 - 1234567890");
		ASSERT_MSG(long1 == LongNum(-1234567890) && long2 == LongNum(1234567890), "Agruments did not change");		
	}
	{
		LongNum long1(-1234567890), long2(0);
		ASSERT_MSG(((long1 - long2) == LongNum(-1234567890)) && ((long2 - long1) == LongNum(1234567890)), "-1234567890 - 0 = -1234567890");
		ASSERT_MSG(long1 == LongNum(-1234567890) && long2 == LongNum(0), "Agruments did not change");		
	}
	{
		long long l1 = -1111111111, l2 = -2222222222;
		LongNum long1(l1), long2(l2);
		ASSERT_MSG(((long1 - long2) == LongNum(l1 - l2)) && ((long2 - long1) == LongNum(l2 - l1)), "-1111111111 - -2222222222 = 1111111111");
		ASSERT_MSG(long1 == LongNum(l1) && long2 == LongNum(l2), "Agruments did not change");		
	}
	{
		long long l1 = 1111111111, l2 = 2222222222;
		LongNum long1(l1), long2(l2);
		ASSERT_MSG(((long1 - long2) == LongNum(l1 - l2)) && ((long2 - long1) == LongNum(l2 - l1)), "1111111111 - 2222222222 = -1111111111");
		ASSERT_MSG(long1 == LongNum(l1) && long2 == LongNum(l2), "Agruments did not change");		
	}	
	{
		long long l1 = -12345678905, l2 = 97845632108;
		LongNum long1(l1), long2(l2);
		ASSERT_MSG(((long1 - long2) == LongNum(l1 - l2)) && ((long2 - long1) == LongNum(l2 - l1)), "-12345678905 -97845632108");
		ASSERT_MSG(long1 == LongNum(l1) && long2 == LongNum(l2), "Agruments did not change");		
	}	
	{
		long long l1 = 0;
		int l2 = 0;
		LongNum long1(l1), long2(l2);
		ASSERT_MSG(((long1 - long2) == LongNum(l1 - l2)) && ((long2 - long1) == LongNum(l2 - l1)), "0-0=0");
		ASSERT_MSG(long1 == LongNum(l1) && long2 == LongNum(l2), "Agruments did not change");		
	}
	{
		long long l1 = 1111111111, l2 = 2222222222;
		LongNum long1(l1), long2(l2);
		ASSERT_MSG((long1 -= long2) == LongNum(l1 - l2), "1111111111 -= 2222222222 = -1111111111");
		ASSERT_MSG(long1 == LongNum(l1 - l2) && long2 == LongNum(l2), "Agrument1 changed and argument 2 did not change");		
	}
	{
		LongNum long1(1234567890);
		ASSERT_MSG((--long1) == LongNum(1234567889), "prefix ++ test");
		ASSERT_MSG(long1 == LongNum(1234567889), "prefix ++ test");	
	}
	{
		LongNum long1(1234567890);
		ASSERT_MSG((long1--) == LongNum(1234567890), "postfix ++ test");
		ASSERT_MSG(long1 == LongNum(1234567889), "postfix ++ test");	
	}	
}

void Test7() {
	{
		LongNum long1(-1234567890), long2(1234567890);
		long long l = -1234567890;
		l *= (-l);
		ASSERT_MSG(((long1 * long2) == LongNum(l)) && ((long2 * long1) == LongNum(l)), "-1234567890 * 1234567890");
		ASSERT_MSG(long1 == LongNum(-1234567890) && long2 == LongNum(1234567890), "Agruments did not change");		
	}
	{
		LongNum long1(-1234567890), long2(0);
		ASSERT_MSG(((long1 * long2) == LongNum(0)) && ((long2 * long1) == LongNum(0)), "-1234567890 * 0");
		ASSERT_MSG(long1 == LongNum(-1234567890) && long2 == LongNum(0), "Agruments did not change");		
	}
	{
		long long l1 = -1111111111, l2 = -2222222222;
		LongNum long1(l1), long2(l2);
		ASSERT_MSG(((long1 * long2) == LongNum(l1 * l2)) && ((long2 * long1) == LongNum(l2 * l1)), "-1111111111 * -2222222222");
		ASSERT_MSG(long1 == LongNum(l1) && long2 == LongNum(l2), "Agruments did not change");		
	}
	{
		long long l1 = 1111111111, l2 = 2222222222;
		LongNum long1(l1), long2(l2);
		ASSERT_MSG(((long1 * long2) == LongNum(l1 * l2)) && ((long2 * long1) == LongNum(l2 * l1)), "1111111111 * 2222222222");
		ASSERT_MSG(long1 == LongNum(l1) && long2 == LongNum(l2), "Agruments did not change");		
	}	
	{
		long long l1 = -12345678905, l2 = 978;
		LongNum long1(l1), long2(l2);
		ASSERT_MSG(((long1 * long2) == LongNum(l1 * l2)) && ((long2 * long1) == LongNum(l2 * l1)), "-12345678905 * 97845632108");
		ASSERT_MSG(long1 == LongNum(l1) && long2 == LongNum(l2), "Agruments did not change");		
	}	
	{
		long long l1 = 0;
		int l2 = 0;
		LongNum long1(l1), long2(l2);
		ASSERT_MSG(((long1 * long2) == LongNum(l1 * l2)) && ((long2 * long1) == LongNum(l2 - l1)), "0-0=0");
		ASSERT_MSG(long1 == LongNum(l1) && long2 == LongNum(l2), "Agruments did not change");		
	}
	{
		long long l1 = 1111111111, l2 = 2222222222;
		LongNum long1(l1), long2(l2);
		ASSERT_MSG((long1 *= long2) == LongNum(l1 * l2), "1111111111 *= 2222222222");
		ASSERT_MSG(long1 == LongNum(l1 * l2) && long2 == LongNum(l2), "Agrument1 changed and argument 2 did not change");		
	}
}

void Test8() {
	{
		LongNum long1(-1234567890), long2(1234567890);
		long long l = -1234567890;
		l /= (-l);
		ASSERT_MSG(((long1 / long2) == LongNum(l)) && ((long2 / long1) == LongNum(l)), "-1234567890 / 1234567890");
		ASSERT_MSG(long1 == LongNum(-1234567890) && long2 == LongNum(1234567890), "Agruments did not change");		
	}
	{
		LongNum long1(-1234567890), long2(0);
		try{
			long1/long2;
		}
		catch(...) {
		//And how to do it humanly?
			ASSERT_MSG(1, "-1234567890 / 0");
		}	
		ASSERT_MSG((long2 / long1) == LongNum(0), "0 / -1234567890");
		ASSERT_MSG(long1 == LongNum(-1234567890) && long2 == LongNum(0), "Agruments did not change");		
	}
	{
		long long l1 = -1111111111, l2 = -2222222222;
		LongNum long1(l1), long2(l2);
		ASSERT_MSG(((long1 / long2) == LongNum(l1 / l2)) && ((long2 / long1) == LongNum(l2 / l1)), "-1111111111 / -2222222222");
		ASSERT_MSG(long1 == LongNum(l1) && long2 == LongNum(l2), "Agruments did not change");		
	}
	{
		long long l1 = 1111111111, l2 = 2222222222;
		LongNum long1(l1), long2(l2);
		ASSERT_MSG(((long1 / long2) == LongNum(l1 / l2)) && ((long2 / long1) == LongNum(l2 / l1)), "1111111111 / 2222222222");
		ASSERT_MSG(long1 == LongNum(l1) && long2 == LongNum(l2), "Agruments did not change");		
	}	
	{
		long long l1 = -12345678905, l2 = 978;
		LongNum long1(l1), long2(l2);
		ASSERT_MSG(((long1 / long2) == LongNum(l1 / l2)) && ((long2 / long1) == LongNum(l2 / l1)), "-12345678905 / 97845632108");
		ASSERT_MSG(long1 == LongNum(l1) && long2 == LongNum(l2), "Agruments did not change");		
	}	
	{
		long long l1 = 0;
		int l2 = 0;
		LongNum long1(l1), long2(l2);
		try{
			long1/long2;
		}
		catch(...) {
		//And how to do it humanly?
			ASSERT_MSG(1, "0 / 0");
		}
		try{
			long2/long1;
		}
		catch(...) {
		//And how to do it humanly?
			ASSERT_MSG(1, "0 / 0");
		}
		ASSERT_MSG(long1 == LongNum(l1) && long2 == LongNum(l2), "Agruments did not change");		
	}
	{
		long long l1 = 1111111111, l2 = 2222222222;
		LongNum long1(l1), long2(l2);
		ASSERT_MSG((long1 /= long2) == LongNum(l1 / l2), "1111111111 /= 2222222222");
		ASSERT_MSG(long1 == LongNum(l1 / l2) && long2 == LongNum(l2), "Agrument1 changed and argument 2 did not change");		
	}
}

void Test9() {
	{
		long long l1 = -1111111111, l2 = -2222222222;
		LongNum long1(l1), long2(l2);
		ASSERT_MSG((long1 % long2) == LongNum(l1 % l2), "-1111111111 % -2222222222");
		ASSERT_MSG(long1 == LongNum(l1) && long2 == LongNum(l2), "Agruments did not change");		
	}
	{
		long long l1 = 1111111111, l2 = -2222222222;
		LongNum long1(l1), long2(l2);
		ASSERT_MSG((long2 % long1) == LongNum(l2 % l1), "-1111111111 % -2222222222");
		ASSERT_MSG(long1 == LongNum(l1) && long2 == LongNum(l2), "Agruments did not change");		
	}
	{
		long long l1 = -1111111111, l2 = 2222222222;
		LongNum long1(l1), long2(l2);
		ASSERT_MSG((long2 % l1) == LongNum(l2 % l1), "-1111111111 % -2222222222");
		ASSERT_MSG(long1 == LongNum(l1) && long2 == LongNum(l2), "Agruments did not change");		
	}
}




/*void Test2() {
    {
        ASSERT_MSG(Fraction < int > (7,3) == Fraction < int > (7,3), "7/3 is equal to 7/3");
        ASSERT_MSG(Fraction < int > (0,100) == Fraction < int > (0,1), "0/100 is equal to 0/1");
        ASSERT_MSG(Fraction < int > (6,3) == 2, "6/3 is equal to 2/1");
        ASSERT_MSG(Fraction < int > (7,3) != Fraction < int > (8,3), "7/3 is not equal to 8/3");
        ASSERT_MSG(Fraction < int > (-6,3) == Fraction < int > (2,-1), "-6/3 is equal to 2/-1");
    }
}

void Test3(){
    {
        ASSERT_MSG(Fraction < int > (7,3) > Fraction < int > (5,3), "7,3 is more than 5/3");
        ASSERT_MSG(Fraction < int > (-5,2) > -3 , "-5/2 is more than -3");
        ASSERT_MSG(5 > Fraction < int > (0,100) , "4 is more than 0/100");
        ASSERT_MSG(Fraction < int > (6,3) >= 2 , "6/3 is more or equal to 2");
        ASSERT_MSG(Fraction < int > (6,3) >= Fraction < int > (12,6) , "6/3 is more or equal to 12/6");
        ASSERT_MSG(Fraction < int > (7,3) >= 2 , "7/3 is more or equal to 2");
        ASSERT_MSG(Fraction < int > (6,3) >= Fraction < int > (11,6) , "6/3 is more or equal to 11/6");
        ASSERT_MSG(2 >= Fraction < int > (5,3), "2 is more or equal to 5/3");
        ASSERT_MSG(-2 >= Fraction < int > (6,-3), "-2 is more or equal to -6/3");
        ASSERT_MSG(Fraction < int > (4,3) < Fraction < int > (5,2) , "4/3 is less than 5/2");
        ASSERT_MSG(Fraction < int > (-6,5) < -1 , "-6/5 is less than -1");
        ASSERT_MSG(-2 < Fraction < int > (-4,3) , "-2 is less than -4/3");
        ASSERT_MSG(Fraction < int > (5,2) <= Fraction < int > (8,3) , "5/2 is less or equal to 8/3");
        ASSERT_MSG(Fraction < int > (5,2) <= Fraction < int > (10,4) , "5/2 is less or equal to 10/4");
        ASSERT_MSG(Fraction < int > (-5,2) <= -2 , "-5/2 is less or equal to -2");
        ASSERT_MSG(Fraction < int > (-4,2) <= -2 , "-4/2 is less or equal to -2");
        ASSERT_MSG(2 <= Fraction < int > (7,3) , "2 is less or equal to 7/3");
        ASSERT_MSG(-2 <= Fraction < int > (-6,3) , "-2 is less or equal to -6/3");
    }
}

void Test4(){
    {
        Fraction < int > frac1(4,3), frac2 (2,3) , frac3 (1,2) , frac4 (-4,3);
        ASSERT_MSG( (frac1 + frac2) == 2, "4/3 + 2/3 is equal to 2");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG(frac2 == Fraction < int > (2,3) , "The second term did not change");
        ASSERT_MSG( (frac1 + frac3) == Fraction < int > (11,6), "4/3 + 1/2 is equal to 11/6");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG(frac3 == Fraction < int > (1,2) , "The second term did not change");
        ASSERT_MSG( (frac1 + frac4) == 0, "4/3 + -4/3 is equal to 0");
        ASSERT_MSG( (frac1 + 3) == Fraction < int > (13,3), "4/3 + 3 is equal to 13/3");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG( (2 + frac3) == Fraction < int > (5,2), "1/2 + 2 is equal to 5/2");
        ASSERT_MSG(frac3 == Fraction < int > (1,2) , "The second term did not change");
        ASSERT_MSG( (+frac2) == Fraction < int > (2,3) , "+2/3 is equal to 2/3");
        ASSERT_MSG( (frac1 += frac2) == 2 , "4/3 += 2/3 is equal to 2");
        ASSERT_MSG(frac1 == 2 ,"I changed");
        ASSERT_MSG(frac2 == Fraction < int > (2,3), " I didn't changed");
        ASSERT_MSG( (frac2 += 1) == Fraction < int > (5,3) , "2/3 += 1 is equal to 5/3 ");
        ASSERT_MSG(frac2 == Fraction < int > (5,3), "I changed");
        ASSERT_MSG((++frac4) == Fraction < int > (-1,3) , "++(-4/3) is equal to -1/3");
        ASSERT_MSG(frac4 == Fraction < int > (-1,3), "I changed");
        ASSERT_MSG((frac4++) == Fraction < int > (-1,3) , "(-1/3)++ is equal to -1/3");
        ASSERT_MSG(frac4 == Fraction < int > (2,3), "I changed");
    }
}

void Test5(){
    {
        Fraction < int > frac1(4,3), frac2 (1,3) , frac3 (1,2) , frac4 (-4,3);
        ASSERT_MSG( (frac1 - frac2) == 1, "4/3 - 2/3 is equal to 1");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG(frac2 == Fraction < int > (1,3) , "The second term did not change");
        ASSERT_MSG( (frac1 - frac3) == Fraction < int > (5,6), "4/3 - 1/2 is equal to 5/6");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG(frac3 == Fraction < int > (1,2) , "The second term did not change");
        ASSERT_MSG( (frac1 - frac4) == Fraction < int > (8,3), "4/3 - -4/3 is equal to 8/3");
        ASSERT_MSG( (frac1 - 3) == Fraction < int > (-5,3), "4/3 - 3 is equal to -5/3");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG( (2 - frac3) == Fraction < int > (3,2), "2 - 1/2 is equal to 3,2");
        ASSERT_MSG(frac3 == Fraction < int > (1,2) , "The second term did not change");
        ASSERT_MSG( (-frac2) == Fraction < int > (-1,3) , "-(1/3) is equal to -1/3");
        ASSERT_MSG(frac2 == Fraction < int > (-1,3), "I changed");
        ASSERT_MSG( (frac1 -= frac2) == Fraction < int > (5,3) , "4/3 -= -1/3 is equal to 5/3 ");
        ASSERT_MSG(frac1 == Fraction < int > (5,3),"I changed");
        ASSERT_MSG(frac2 == Fraction < int > (-1,3), " I didn't changed");
        ASSERT_MSG( (frac3 -= 1) == Fraction < int > (-1,2) , "1/2 -= 1 is equal to -1/2 ");
        ASSERT_MSG(frac3 == Fraction < int > (-1,2), "I changed");
        ASSERT_MSG((--frac4) == Fraction < int > (-7,3) , "--(-4/3) is equal to -7/3");
        ASSERT_MSG(frac4 == Fraction < int > (-7,3), "I changed");
        ASSERT_MSG((frac4--) == Fraction < int > (-7,3) , "(-7/3)++ is equal to -7/3");
        ASSERT_MSG(frac4 == Fraction < int > (-10,3), "I changed");
    }
}

void Test6(){
    {
        Fraction < int > frac1(4,3), frac2 (3,4) , frac3 (0,2) , frac4 (2,-3);
        ASSERT_MSG( (frac1 * frac2) == 1, "4/3 * 3/4 is equal to 1");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG(frac2 == Fraction < int > (3,4) , "The second term did not change");
        ASSERT_MSG( (frac1 * frac3) == Fraction < int > (0), "4/3 * 0/2 is equal to 0");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG(frac3 == Fraction < int > (0,2) , "The second term did not change");
        ASSERT_MSG( (frac1 * frac4) == Fraction < int > (-8,9), "4/3 * -2/3 is equal to -8/9");
        ASSERT_MSG( (frac1 * 3) == 4, "4/3 * 3 is equal to 4");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG( (2 * frac2) == Fraction < int > (3,2), "2 * 3/4 is equal to 3/2");
        ASSERT_MSG(frac2 == Fraction < int > (3,4) , "The second term did not change");
        ASSERT_MSG( (frac1 *= frac2) == 1 , "4/3 *= 3/4 is equal to 1");
        ASSERT_MSG(frac1 == 1 ,"I changed");
        ASSERT_MSG(frac2 == Fraction < int > (3,4), " I didn't changed");
        ASSERT_MSG( (frac2 *= 3) == Fraction < int > (9,4) , "3/4 *= 3 is equal to 9/4 ");
        ASSERT_MSG(frac2 == Fraction < int > (9,4), "I changed");
        frac4.square();
        ASSERT_MSG( frac4 == Fraction < int > (4,9) , "(-2/3)^2 is equal to 4/9");
        frac4.sqrt();
        ASSERT_MSG( frac4 == Fraction < int > (2,3) , "sqrt(4/9) is equal to 2/3");
    }
}

void Test7(){
    {
        Fraction < int > frac1(4,3), frac2 (4,3) , frac3 (1,2) , frac4 (-2,3);
        ASSERT_MSG( (frac1 / frac2) == 1, "4/3 / 4/3 is equal to 1");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG(frac2 == Fraction < int > (4,3) , "The second term did not change");
        ASSERT_MSG( (frac1 / frac3) == Fraction < int > (8,3), "4/3 / 1/2 is equal to 8/3");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG(frac3 == Fraction < int > (1,2) , "The second term did not change");
        ASSERT_MSG( (frac1 / frac4) == -2, "4/3 / -2/3 is equal to -2");
        ASSERT_MSG( (frac1 / 4) == Fraction < int > (1,3), "4/3 / 4 is equal to 1/3");
        ASSERT_MSG(frac1 == Fraction < int > (4,3) , "The first term did not change");
        ASSERT_MSG( (2 / frac2) == Fraction < int > (3,2), "2 / 4/3 is equal to 3/2");
        ASSERT_MSG(frac2 == Fraction < int > (4,3) , "The second term did not change");
        ASSERT_MSG( (frac1 /= frac2) == 1 , "4/3 /= 4/3 is equal to 1");
        ASSERT_MSG(frac1 == 1 ,"I changed");
        ASSERT_MSG(frac2 == Fraction < int > (4,3), " I didn't changed");
        ASSERT_MSG( (frac2 /= 3) == Fraction < int > (4,9) , "3/4 /= 3 is equal to 4/9 ");
        ASSERT_MSG(frac2 == Fraction < int > (4,9), "I changed");
    }
}

void Test8 ()
{
    {
        Fraction < int > frac1(5,3),frac2;
        ASSERT_MSG((frac2 = frac1) == Fraction < int > (5,3) , " 5/3 is equal to 5/3");
        ASSERT_MSG( frac1 == Fraction < int > (5,3) ," I don't changed");
        ASSERT_MSG((frac2 = 3) == 3 , " 3 is equal to 3");
    }
}*/

void TestAll() {
    Testlib::Test test;
    RUN_TEST_MSG(test, Test1, "Construction check");
	RUN_TEST_MSG(test, Test2, "Copy check");
	RUN_TEST_MSG(test, Test3, "Equality check");
	RUN_TEST_MSG(test, Test4, "Comparison check");
	RUN_TEST_MSG(test, Test5, "Summirizing check");
	RUN_TEST_MSG(test, Test6, "Difference check");
	RUN_TEST_MSG(test, Test7, "Multiply test");
	RUN_TEST_MSG(test, Test8, "Division test");
	RUN_TEST_MSG(test, Test9, "Remainder test");


   /* RUN_TEST_MSG(test, Test2, "Equality check");
    RUN_TEST_MSG(test, Test3, "Compared test");
    RUN_TEST_MSG(test, Test4, "Summary test");
    RUN_TEST_MSG(test, Test5, "Difference test");
    RUN_TEST_MSG(test, Test6, "Multiply test");
    RUN_TEST_MSG(test, Test7, "Division test");
    RUN_TEST_MSG(test, Test8, "Check of equal");*/
}

#endif // TEST_H_INCLUDED
