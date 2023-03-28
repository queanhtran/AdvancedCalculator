#include "TinyCalculator.hpp"

//define all static variables
int TinyCalculator::addition_count = 0;
int TinyCalculator::subtraction_count = 0;
int TinyCalculator::multiplication_count = 0;
int TinyCalculator::division_count = 0;
int TinyCalculator::modulo_count = 0;
int TinyCalculator::last_Operation_Memory = 0;

//definition of constructor
TinyCalculator::TinyCalculator() : result(0), calculatorRunningTotal(0) {}

//this function will conver char type to enum type
OperationType TinyCalculator::Char_to_Enum(char Input){
	OperationType User_Enum;
	//conver the char Input into upper case
	//Use switch statement to assign 
	switch(toupper(Input)) {
		case 'A'://'A' stands for ADDITION in OperationType
			User_Enum = OperationType::ADDITION;
			break;
		case 'S'://'S' stands for SUBTRACTION in OperationType
			User_Enum = OperationType::SUBTRACTION;
			break;
		case 'M'://'M' stands for MULTIPLICATION in OperationType
			User_Enum = OperationType::MULTIPLICATION;
			break;
		case 'D'://'D' stands for DIVISION in OperationType
			User_Enum = OperationType::DIVISION;
			break;
		case '%'://'%' stands for MODULO in OperationType
			User_Enum = OperationType::MODULO;	
			break;
	}
	//return the user's input in terms of enum type
	return User_Enum;
}

/*this function print out the message which asking user to enter the operation type
* then it will prompt the input
* the input will be passed to char_to_enum function to convert a char input type to enum input type
* the function return the user input as an enum type before it's done
*/
OperationType TinyCalculator::displayUserMenu(){
	OperationType User_Operation;
	char User_Char; // user's input as char type
	//print out display menu
	cout << "Select the operation type you would like to calculate by entering the first letter of the operation.\n(A)ddition\n(S)ubstraction\n(M)ultiplication\n(D)ivision\n(%)Modulo\nOperation? ";
	cin >> User_Char;// prompt input as char type from user
	User_Operation = Char_to_Enum(User_Char);//convert it to OperationType
	return User_Operation;// return enum type
}

//this function performs addition by adding left and right operands together
int TinyCalculator::addition(int LeftOperation, int RightOperation){
	int sum = LeftOperation + RightOperation;
	//it returns the sum
	return sum;
}

//this function will perform subtraction 
//if the right operand is negative,it will call the addition funtion
//otherwise, the right operand  will be  subtracted from the left operand
int TinyCalculator::subtraction(int LeftOperation, int RightOperation){
	int subtraction;
	// if right operand is negative, use addition function
	if (RightOperation < 0)
		subtraction = addition(LeftOperation, RightOperation);// call the addition function to perform addition
	else
		//otherwise the function will perform subtraction
		subtraction = LeftOperation - RightOperation;
	return subtraction;//return the result of subtraction 
}

//this function will perform multiplication
//it uses a loop to add left operand n times with n = right operand
int TinyCalculator::multiplication(int LeftOperation, int RightOperation){
	int result_multiplication = 0;
	for (int i = 0; i < RightOperation; i++){
		result_multiplication += LeftOperation; // add RightOperation times of LeftOperation
	}
	return result_multiplication;
}

//perform division by keepng subtracting the right operand from the left operand until it less than the right operand
//then it will return the number of subtractions it perform
//the result of division is the number of subtractions
int TinyCalculator::division(int LeftOperation, int RightOperation){
	int result_division = 0 ;
	while (LeftOperation >= RightOperation){
		LeftOperation -= RightOperation;
		result_division++;
	}
	return result_division;
}

//this function will perform modulo by receiving the division result from division function
//the remainder will be = left operand - (right operand * division result)
int TinyCalculator::modulo(int LeftOperation, int RightOperation){
	int division_result = TinyCalculator::division(LeftOperation, RightOperation);
	int remainder = LeftOperation - division_result*RightOperation;
	return remainder;
}

/*The process user input function will receive an enum input from user
* it calls a specific function to perform operations
* if user enters 'M' instead of an integer, a previous result will be used as a operand
* this function will later print out the result of operations
*/
void TinyCalculator::processUserInput(OperationType Input){
	string TypeOfOperation, SymbolOfOperation;
	int LeftOperation;
	int RightOperation;
	string UserInput;
	
	//using switch statement to assign a specific string to print out a message
	//the conditions in switch statements also help to keep track with number of operations performed
	//I personally choose to assign specific strings to specific operations for later outputs
	switch(Input){
		case OperationType::ADDITION:
			TypeOfOperation = "addition";
			addition_count += 1;
			SymbolOfOperation = "+";
			break;
		case OperationType::SUBTRACTION:
			TypeOfOperation = "subtraction";
			subtraction_count += 1;
			SymbolOfOperation = "-";
			break;
		case OperationType::MULTIPLICATION:
			TypeOfOperation = "multiplication";
			multiplication_count += 1;
			SymbolOfOperation = "*";
			break;
		case OperationType::DIVISION:
			TypeOfOperation = "division";
			division_count += 1;
			SymbolOfOperation = "/";
			break;
		case OperationType::MODULO:
			TypeOfOperation = "modulo";
			modulo_count += 1;
			SymbolOfOperation = "%";
			break;
	}
	
	//print out messages about the chosen operantion
	cout << "You selected " << TypeOfOperation << ".\n";
	
	//prompt left operand
	cout << "Enter your first number: ";//prompt left operand
	cin >> UserInput;
	//if "M" is entered the operand will be the result of previous operation
	if (UserInput == "M" || UserInput == "m")
		LeftOperation = last_Operation_Memory;
	else
		LeftOperation = stoi(UserInput);//convert string to int

	//prompt right operand
	cout  << "Enter your second number: ";
	cin >> UserInput;
	//if "M" is entered the operand will be the result of previous operation	
	if (UserInput == "M" || UserInput == "m")
		RightOperation = last_Operation_Memory;
	else
		RightOperation = stoi(UserInput);//convert sting to int

	
	//call private arithmetic functions to perform operations
	//pass left operand and right operand to the function called
	switch(Input){
		case OperationType::ADDITION:
			result = addition(LeftOperation, RightOperation);
			break;
		case OperationType::SUBTRACTION:
			result = subtraction(LeftOperation, RightOperation);
			break;
		case OperationType::MULTIPLICATION:
			result = multiplication(LeftOperation, RightOperation);
			break;
		case OperationType::DIVISION:
			result = division(LeftOperation, RightOperation);
			break;
		case OperationType::MODULO:
			result = modulo(LeftOperation, RightOperation);
			break;
	}
	
	calculatorRunningTotal += result;// save the result to running total
	// update the last memory saved value
	// in case of user enters M for later operations
	last_Operation_Memory = result; 
	//print out the result of performed operation
	cout << "The answer: " << LeftOperation << " " << SymbolOfOperation << " " << RightOperation << " = " << result << endl;

}


/*
 * Prompts the user to enter y/n to enter more expressions.
 *
 * @return true if 'y' is entered. Otherwise false.
 */
bool TinyCalculator::checkForPlayAgain()
{
	bool cont = true;
	char YesNo;
	cout << "Would you like to do another calculation? (y/n)" << endl;
	cin >> YesNo;
	switch(toupper(YesNo)){
		case 'Y':
			cont = true;
			break;
		case 'N':
			cont = false;
			break;
	}
	return cont;
}


/*
*This function print out the final report
*This includes: number of all type operations performed, total operations performed, running total of odd *calculator, running total of even calculator, running total of both, the average of total operations
*It receives the CalculatorArray[] as a parameter
*/
void TinyCalculator::displayReport(TinyCalculator CalculatorArray[]){
	//total operations performed
	int totalOperation = addition_count + subtraction_count + multiplication_count + division_count + modulo_count ;
	//assumed that 1st element in the array is odd calculator
	int oddRunningTotal = CalculatorArray[0].calculatorRunningTotal;
	// index [1] in the array is even calculator
	int evenRunningTotal = CalculatorArray[1].calculatorRunningTotal;
	//this is the running total from both calculators
	int cumalativeRunningTotal = CalculatorArray[1].calculatorRunningTotal + CalculatorArray[0].calculatorRunningTotal;
	int averageTotal = cumalativeRunningTotal / totalOperation;

	//print out reports about calculators
	cout << "Calculator Report\n";
	cout << "Additions: " << addition_count << endl;
	cout << "Subtractions: " << subtraction_count << endl;
	cout << "Multiplcations: " << multiplication_count << endl;
	cout << "Divisions: " << division_count << endl;
	cout << "Modulos: " << modulo_count << endl;
	cout << "Total operations: " << totalOperation << endl;
	cout << "Running total of odd calculator: " << CalculatorArray[0].calculatorRunningTotal << endl;
	cout << "Running total of even calculator: " << CalculatorArray[1].calculatorRunningTotal << endl;	
	cout << "Running Total of all operation types: " << cumalativeRunningTotal << endl;
	cout << "The average of total operations: " << averageTotal << endl;
}