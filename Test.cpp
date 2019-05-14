#include <iostream>
using namespace std;
#include "badkan.hpp"
#include "chain.hpp"
#include "powerset.hpp"
#include "product.hpp"
#include "range.hpp"
#include "zip.hpp"

using namespace itertools;

int main() {

	badkan::TestCase testcase;
	int grade = 0;
	int signal = setjmp(badkan::longjmp_buffer);
	int Temp = 0;
	if (signal == 0) {
	/////////////////////////My_Test///////////////////////////
	/////////////////////////range_Test////////////////////////
		testcase.setname("range test");
		 Temp = 0;
		for (int i: range(0,12)) {
			testcase.CHECK_EQUAL(i, Temp);
			Temp++;
		}

		Temp = 4;
		for (int i: range(4,7)) {
			testcase.CHECK_EQUAL(i, Temp);
			Temp++;
		}

        //////////////////// range_Test - Check "-" ////////////////////////
		Temp = -7;
		for (int i: range(-7,0)) {
			testcase.CHECK_EQUAL(i, Temp);
			Temp++;
		}

		Temp = 10;
		for (int i: range(10,12)) {
			testcase.CHECK_EQUAL(i, Temp);
			Temp++;
		}

		Temp = 2;
		for (int i: range(2,2)) {
			testcase.CHECK_EQUAL(i, Temp);
			Temp++;
		}
    //////////////////// range_Test - Check Char ////////////////////////
		char Temp_C = 'a';
		for (int i: range('a','j')) {
			testcase.CHECK_EQUAL(i, Temp_C);
			Temp_C++;
		}

		Temp_C = 'd';
		for (int i: range('d','d')) {
			testcase.CHECK_EQUAL(i, Temp_C);
			Temp_C++;
		}

		Temp_C = 'u';
		for (int i: range('u','l')) {
			testcase.CHECK_EQUAL(i, Temp_C);
			Temp_C++;
		}

    ///////////////////////////Chain_Test////////////////////////////////////
		testcase.setname("Chain test");
		Temp = 0;
		int Chck_1[] = {1,2,3,4,5,6,7,8,9,10};
		for(int i: chain(range(1,6), range(5,11))) {
			testcase.CHECK_EQUAL(i, Chck_1[Temp]);
			Temp++;				
		}

		Temp = 0;
		int Chck_2[] = {0,1,2,3,4,5,5,6,7};
		for(int i: chain(range(0,6), range(5,8))) {
			testcase.CHECK_EQUAL(i, Chck_2[Temp]);
			Temp++;				
		}

		Temp = 0;
		char Chck_3[] = {'a','b','c','d','e','f'};
		for(int i: chain(range('a','d'), range('d','g'))) {
			testcase.CHECK_EQUAL(i, Chck_3[Temp]);
			Temp++;				
		}
		
		Temp = 0;
		char Chck_4[] = {'a','b','c','A','B','C','D'};
		for(int i: chain(range('a','d'), range('A','E'))) {
			testcase.CHECK_EQUAL(i, Chck_4[Temp]);
			Temp++;				
		}
			Temp = 0;
		char Chck_5[] = {'A','B','C','D','E','F','G'};
		
		for(int i: chain(range('A','D'), range('D','H')))
		{
			testcase.CHECK_EQUAL(i, Chck_5[Temp]);
			Temp++;				
		}

	
    //////////////////////////////////Test_Product//////////////////////////
        testcase.setname(" TEST PRODUCT");
	    int Temp=0;
		string Chck_6[]={"0,e","0,d","1,e","1,d","2,e","2,d"};
        for (auto pair: product(range(0,3), string("ed")))
        {
		testcase.CHECK_OUTPUT(pair,Chck_6[Temp]);
		Temp++;
        }
	    Temp=0;
		string Chck_7[]={"0,3","0,4","1,3","1,4","2,3","2,4"};
        for (auto pair: product(range(0,3), range(3,5)))
        {
		testcase.CHECK_OUTPUT(pair,Chck_7[Temp]);
		Temp++;
        }
	    Temp=0;
		string Chck_8[]={"1,a","1,b","2,a","2,b","3,a","3,b","4,a","4,b"};
        for (auto pair: product(range(1,5), range('a','c')))
        {
		testcase.CHECK_OUTPUT(pair,Chck_8[Temp]);
		Temp++;
        }
	    Temp=0;
		string Chck_9[]={"6,c","6,d","7,c","7,d","8,c","8,d"};
        for (auto pair: product(range(6,9), range('c','e')))
        {
		testcase.CHECK_OUTPUT(pair,Chck_9[Temp]);
		Temp++;
        }

     ///////////////////////////// Test Zip	/////////////////////////////////
		testcase.setname("Test Zip ");
        Temp=0;
        string Chck_10[]={"1,d","2,e","3,r","4,i"};
        for (auto pair: zip(range(1,5), string("deri"))) {
		testcase.CHECK_OUTPUT(pair,Chck_10[Temp]);
		Temp++;
        }

        Temp=0;
		string Chck_11[]={"1,c","2,p","3,p"};
        for (auto pair: zip(range(1,4), string("cpp"))) {
		testcase.CHECK_OUTPUT(pair,Chck_11[Temp]);
		Temp++;
        }

        Temp=0;
		string Chck_12[]={"0,0","1,1","2,2","3,3","4,4"};
        for (auto pair: zip(range(0,5), range(0,5))) {
		testcase.CHECK_OUTPUT(pair,Chck_12[Temp]);
		Temp++;
        }

        Temp=0;
		string Chck_13[]={"0,a","1,b","2,c","3,d"};
        for (auto pair: zip(range(0,4), range('a','e'))) {
		testcase.CHECK_OUTPUT(pair,Chck_13[Temp]);
		Temp++;
        }

        Temp=0;
		string Chck_14[]={"A,a","B,b","C,c","D,d"};
        for (auto pair: zip(range('A','E'), range('a','e'))) {
		testcase.CHECK_OUTPUT(pair,Chck_14[Temp]);
		Temp++;
}

	////////////////////////////////// Test_PowerSet /////////////////////////////////
	    testcase.setname(" Test PowerSet");
	    Temp=0;
		string Chck_15[]={"{}","{5}","{6}","{5,6}","{7}","{5,7}","{6,7}","{5,6,7}"};
        for (auto pair: powerset(range(5,8))){
		testcase.CHECK_OUTPUT(pair,Chck_15[Temp]);
		Temp++;
}

	    Temp=0;
		string Chck_16[]={"{}","{a}","{b}","{a,b}","{1}","{a,1}","{b,1}","{a,b,1}","{2}","{a,2}","{b,2}","{a,b,2}","{1,2}","{a,1,2}","{b,1,2}","{a,b,1,2}"};
        for (auto subset: powerset(chain(range('a','c'),range('1','3')))) {
		testcase.CHECK_OUTPUT(subset,Chck_16[Temp]);
		Temp++;
}

	Temp=0;
	string Chck_17[]={"{}","{c}","{p}","{c,p}","{p}","{c,p}","{p,p}","{c,p,p}"};
    for (auto subset: powerset(string("cpp"))) {
	  testcase.CHECK_OUTPUT(subset,Chck_17[Temp]);
 	   Temp++;
}

////////////////////////////////// end_MyTest ////////////////////////////////////////

    grade = testcase.grade();
	}
	else
	{
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}
