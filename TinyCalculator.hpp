#ifndef TINYCALCULATOR_HPP
#define TINYCALCULATOR_HPP

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//enum type operations
enum OperationType {ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION, MODULO};

//helper function
bool checkForPlayagain();

class TinyCalculator{ 
public: 
	TinyCalculator();//default 
	static OperationType displayUserMenu(); // print out message and prompt the chosen operation
	void processUserInput(OperationType Input); //perform an operation based on the passed enum type input, make a call to spefic function to perform operation. 
	static void displayReport(TinyCalculator CalculatorArray[]);// print out report before ending
	bool checkForPlayAgain();// prompt 'Y' or 'N' from user to check if they want to do another operation
	static OperationType Char_to_Enum(char Input);// convert char type input to enum type by switch statement

private: 
	//these functions will perform operations upon requests 
	//they receive left and right operands as parameters
	int addition(int LeftOperation, int RightOperation);
	int subtraction(int LeftOperation, int RightOperation);
	int multiplication(int LeftOperation, int RightOperation);
	int division(int LeftOperation, int RightOperation);
	int modulo(int LeftOperation, int RightOperation);

	//result stands for operations' results
	int result;
	// calculatorRunningTotal is the  sum of all results peer
	int calculatorRunningTotal;

	//these static variables will be used for report
	//use static type to keep track with the counting
	static int addition_count;
	static int subtraction_count;
	static int multiplication_count;
	static int division_count;
	static int modulo_count;
	static int last_Operation_Memory;
};

#endif
