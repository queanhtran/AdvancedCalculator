#include "TinyCalculator.hpp"

int main() {
	bool more = true; 
	int count = 1; // keep track with the counting
	TinyCalculator CalculatorArray[2]; //initializes an array with 2 lements
	TinyCalculator oddCalculator;
	TinyCalculator evenCalculator;

		//the do function will perform a calculator at first 
		// it calls to displayUserMenu asking user to choosee a type of operation
		//later it call processUserInput function to perform operations as well as prompt operands from user
		//after that, it call to the checkforPlayAgain function
		// if user enter 'Y' or 'y', the program will keep running
		// when count is odd (1, 3, 5...) the odd calculator will take turn to perform 
		//otherwise, it's the even calculator's turn
		do{
	    OperationType opType;
		if (count % 2 == 0){
			//print out display menu for operations' options
			opType = TinyCalculator::displayUserMenu();
			//process operation and print out the result
	    	evenCalculator.processUserInput(opType);
			//check if the user wants to enter more expression
	    	more = evenCalculator.checkForPlayAgain();	
		}
		else{
			//print out display menu for operations' options
			opType = TinyCalculator::displayUserMenu();
			//process operation and print out the result
			oddCalculator.processUserInput(opType);
			//check if the user wants to enter more expression
	    	more = oddCalculator.checkForPlayAgain();
		}
		count += 1; // increments the count after every time it perform an operation
	}while(more); // performing operations while user answer 'y'

	//assign [0] element in the array to oddCalculator
	//assign [1] element in the array to evenCalculator
	CalculatorArray[0] = oddCalculator;
	CalculatorArray[1] = evenCalculator;
	
	//display the report of calculators
	TinyCalculator::displayReport(CalculatorArray);

	return 0; // done with the program
}

