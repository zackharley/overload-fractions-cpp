/*
 * A testing class for CISC/CMPE320 assignment 2.
 * You must satisfy all tests in this file, but may add some of your own.
 */
#include <iostream>
using namespace std;

#include "fraction_13zh24.h"

int main() {

	// Test constructors and << operator overloading
	Fraction test1;
	cout << "Should be \"0/1\": " << test1 << endl;
	Fraction test2(4);
	cout << "Should be \"4/1\": " << test2 << endl;
	Fraction test3(20, 30);
	cout << "Should be \"2/3\": " << test3 << endl;
	Fraction test4(210, -60);
	cout << "Should be \"-7/2\": " << test4 << endl;

	// Test exception for when denominator is zero
	try {
		Fraction test5(4, 0);
		cout << "Should not get here: " << test5 << endl;
	} catch (FractionException &e) {
		cout << "Exception message should indicate illegal denominator: " << e.what() << endl;
	}

	// Test accessors
	cout << "Numerator should be -7: " << test4.numerator() << endl;
	cout << "Denominator should be 2: " << test4.denominator() << endl;

	// Test binary arithmetic operators
	Fraction test6(9, 8);
	Fraction test7(1, 6);
	Fraction test8 = test6 + test7;
	cout << "Should be \"31/24\": " << test8 << endl;
	Fraction test9 = test6 - test7;
	cout << "Should be \"23/24\": " << test9 << endl;
	Fraction test10 = test6 - 1;
	cout << "Should be \"1/8\": " << test10 << endl;
	Fraction test11 = 2 - test7;
	cout << "Should be \"11/6\": " << test11 << endl;
	Fraction test12 = test6 * test7;
	cout << "Should be \"3/16\": " << test12 << endl;
	Fraction test13 = test6 / test7;
	cout << "Should be \"27/4\": " << test13 << endl;

	// Test unary negation
	cout << "Should be \"-1/6\": " << -test7 << endl;

	// Test pre and post-increment operators
	Fraction test14 = 2 + test3++;
	cout << "Should be \"8/3\": " << test14 << endl;
	cout << "Should be \"5/3\": " << test3 << endl;
	Fraction test15 = 2 + ++test3;
	cout << "Should be \"14/3\": " << test15 << endl;
	cout << "Should be \"8/3\": " << test3 << endl;

	// Test += operator
	Fraction test16(3, 8);
	test16 += test3;
	cout << "Should be \"73/24\": " << test16 << endl;

	// Test comparisons
	cout << "\nShould see six comparison test results:" << endl;
	Fraction test17(9, 8);
	if (test6 == test17)
		cout << "Equality test passed." << endl;
	if (test6 != test7)
		cout << "Inequality test passed." << endl;
	if (test6 > test7 && test6 >= test7)
		cout << "Greater than test passed." << endl;
	if (test7 < test6 && test7 <= test6)
		cout << "Less than test passed." << endl;
	if (test6 > 1)
		cout << "Mixed type comparison passed." << endl;
	if (1 < test6)
		cout << "Second mixed type comparison passed." << endl;

	// // Test input, exception and +=:
	Fraction sum(0);
	Fraction fin;
	cout << "\nSumming fractions. Enter fractions as \"1/2\" or just enter a single integer." << endl;
	cout << "Enter zero to end the summation:" << endl;
	do {
		cout << "Enter a fraction to add to sum: ";
		try {
			cin >> fin;
			sum += fin;
		} catch (FractionException &e) {
			cout << e.what() << endl;
		}
	} while (fin != 0);
	cout << "Sum is: " << sum << endl;

	// My tests
	Fraction myTest1(4, 2);
	if(2 == myTest1) 
		cout << endl << "My equality 1" << endl;
	if(myTest1 == 2)
		cout << "My equality 2" << endl;
	Fraction myTest2(4, 3);
	if(myTest2 != 4)
		cout << "My inequality 1" << endl;
	if(4 != myTest2) 
		cout << "My inequality 2" << endl;
	Fraction myTest3(8, 3);
	if(myTest3 > 2) 
		cout << "My greater than 1" << endl;
	if(3 > myTest3)
		cout << "My greater than 2" << endl;
	if(2 >= myTest1)
		cout << "My greater than or equal 1" << endl;
	if(myTest1 >= 2)
		cout << "my greater than or equal 2" << endl;
	Fraction myTest4(11, 3);
	if(3 < myTest4)
		cout << "My less than 1" << endl;
	if(myTest4 < 4)
		cout << "my less than 2" << endl;
	if(2 <= myTest1)
		cout << "My less than or equal 1" << endl;
	if(myTest1 <= 2)
		cout << "my less than or equal 2" << endl;
	Fraction myTest5(4, 3);
	Fraction myTest6 = myTest5 + 2;
	cout << "Should be \"10/3\": " << myTest6 << endl;
	Fraction myTest7 = 3 + myTest5;
	cout << "Should be \"13/3\": " << myTest7 << endl;
	Fraction myTest8(10, 4);
	Fraction myTest9 = myTest8 * 2;
	cout << "Should be \"5/1\": " << myTest9 << endl;
	Fraction myTest10 = 4 * myTest8;
	cout << "Should be \"10/1\": " << myTest10 << endl;
	Fraction myTest11(3, 4);
	Fraction myTest12 = myTest11 / 2;
	cout << "Should be \"3/8\": " << myTest12 << endl;
	Fraction myTest13 = 8 / myTest11;
	cout << "Should be \"32/3\": " << myTest13 << endl;
	Fraction myTest14(3, 10);
	myTest14 += 3;
	cout << "Should be \"33/10\": " << myTest14 << endl;

	return 0;

} // end main