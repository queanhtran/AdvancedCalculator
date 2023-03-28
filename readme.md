*******************************************************
*  **Name      :**  Ngoc Que Anh Tran      
*  **Student ID:**  110-355-603             
*  **Class     :**  CSCI 2312 Section 01           
*  **HW#       :**  5           
*  **Due Date  :**  NOV 12, 2022
*******************************************************

# Read Me  
##  Description of the program
* This program is an advanced option of calculator, it includes an odd and an even calculator
* they will take turn to perform operations
* the program will prompt left and right operands every time a new operation is performed
* the program will keep running until the user choose to exit it
* before ending the program will print out a report of all operations performed

## Algorithm
* set up a class with neccessary  functions  and variables
* declare variables and functioins in the hpp file 
* define variables in Implementation.cpp file, I choose to initialize them = 0
* define constructor with result = 0, and calculatorrunningtoal = 0
* define the displayUserMenu to print out messages and prompt the chosen operation type
* pass the user input to as a parameter to the process user input function
* this function will perform operation anf print out result
* then make a call to checkforplayagain function to ask if user want to do more operations
* the odd and even calculators will take turn to perform operations
* the variable count will be used to keep track with it
* if the count is odd, it's odd calculator's turn, otherwise the even calculator will be assigned

##  Source files
## header.hpp 
**Header file**
1. define the header.hpp
2. include all libraries needed (math, string, iostream)
3. declare an enum array operation type 
4. declare a class, its variables and funtions
5. all variable members are set to privated and functions are public
6. static variables are all kinds of operations count, last operation memory which stores the result of previous operation in case of user enter 'M' instead of an integer for the operand.
7. end of ifdefine

  
## Implementation.cpp
**Implementation program**
  1. this is where all the functions are defined except main function
  2. define all static variables and initialize to 0
  3. use a constructor to initialize result = 0 and calculatorRunningTotal = 0
  4. display user menu function will print out message about the operations and prompt user input
  5. this input will be converted to enum type by calling char_to_enum function
  6. display user menu will return with the useer input in enum type
  7. the process user input will take the enum type input above as a parameter
  8. it later make a call to certain function to perform operations based on the chosen operation type
  9. this funcction also prompt left and right operands
  10. there is a special option, if user enter M/m, the result of previous operation will be used for the operand 
  11. once it is done with calculating, the function will print out the result
  12. the result each time will be added to the calculatorRunningTotal variable
  13. the last_operation_memory variable will be used to saved memory of result
  14. it will be updated after every operation
  15. the displayReport function will receive a TinyCalculator array [2] as a parameter
  16. this function print out report of all type operations performed, the total operations, running total of each calculator, running total of both and the average of total operations
  17. the boolean function check for play again will prompt user's choice between Y/N to continue or exit the program.


## main.cpp
   **Main program**
  1. this is where all functions are called
  2. a count variable is used to keep track with the use of even and odd calculators
  3. as the count is odd, the odd calculator will take turn, otherwise it's on the even calculator call
  4. the specifc calculator will make calls to display menu function first then pass the user's input to processUserInput functiion
  5. later it will call the check for play again boolean function to prompt user's choice of continue or end the program
  6. if user chooses to end the program, the display reporrt function will be called to print out the report
  7. then the program is ended
     
## output.txt
* this file stores a copy of output

##  Circumstances of programs

   * The program runs successfully.  
   * The program was developed and tested on replit.

##  How to build and run the program

1. You should see a directory named homework with the files:
        * main.cpp
   		* Implemention.cpp
   		* header.hpp
        * Readme
   		* output.txt
   since I work on replt, there is no need for makefile
   
3. Build the program.  

    Change to the directory that contains the file by:  
    > % cd [PA5] 

    Compile the program by:  
    > % make

4. Run the program by:  
   > % ./[main]

5. Delete the obj files, executables, and core dump by  
   > %./make clean

*******
# Test 1
* Select the operation type you would like to calculate by entering the first letter of the operation.
* (A)ddition
* (S)ubstraction
* (M)ultiplication
* (D)ivision
* (%)Modulo
* Operation? a
* You selected addition.
* Enter your first number: 111
* Enter your second number: 222 
* The answer: 111 + 222 = 333
* Would you like to do another calculation? (y/n)
* y

# Test 2
* Select the operation type you would like to calculate by entering the first letter of the operation.
* (A)ddition
* (S)ubstraction
* (M)ultiplication
* (D)ivision
* (%)Modulo
* Operation? s
* You selected subtraction.
* Enter your first number: 9999
* Enter your second number: 8888
* The answer: 9999 - 8888 = 1111
* Would you like to do another calculation? (y/n)
* y
  
# Test 3
* Select the operation type you would like to calculate by entering the first letter of the operation.
* (A)ddition
* (S)ubstraction
* (M)ultiplication
* (D)ivision
* (%)Modulo
* Operation? d
* You selected division.
* Enter your first number: 83
* Enter your second number: 83
* The answer: 83 / 83 = 1
* Would you like to do another calculation? (y/n)
* y
# Test 4
* Select the operation type you would like to calculate by entering the first letter of the operation.
* (A)ddition
* (S)ubstraction
* (M)ultiplication
* (D)ivision
* (%)Modulo
* Operation? %
* You selected modulo.
* Enter your first number: 84
* Enter your second number: 83
* The answer: 84 % 83 = 1
* Would you like to do another calculation? (y/n)
* y
  
# Test 5
* Select the operation type you would like to calculate by entering the first letter of the operation.
* (A)ddition
* (S)ubstraction
* (M)ultiplication
* (D)ivision
* (%)Modulo
* Operation? d
* You selected division.
* Enter your first number: 83
* Enter your second number: 84
* The answer: 83 / 84 = 0
* Would you like to do another calculation? (y/n)
* y
  
# Test 6 
* Select the operation type you would like to calculate by entering the first letter of the operation.
* (A)ddition
* (S)ubstraction
* (M)ultiplication
* (D)ivision
* (%)Modulo
* Operation? s
* You selected subtraction.
* Enter your first number: M
* Enter your second number: 0
* The answer: 0 - 0 = 0
* Would you like to do another calculation? (y/n)
* y
  
# Test 7
* Select the operation type you would like to calculate by entering the first letter of the operation.
* (A)ddition
* (S)ubstraction
* (M)ultiplication
* (D)ivision
* (%)Modulo
* Operation? a  
* You selected addition.
* Enter your first number: 5000
* Enter your second number: 5001
* The answer: 5000 + 5001 = 10001
* Would you like to do another calculation? (y/n)
* y
  
# Test 8
* Select the operation type you would like to calculate by entering the first letter of the operation.
* (A)ddition
* (S)ubstraction
* (M)ultiplication
* (D)ivision
* (%)Modulo
* Operation? m
* You selected multiplication.
* Enter your first number: 7
* Enter your second number: 2
* The answer: 7 * 2 = 14
* Would you like to do another calculation? (y/n)
* n
  
# Calculator Report
* Additions: 2
* Subtractions: 2
* Multiplcations: 1
* Divisions: 2
* Modulos: 1
* Total operations: 8
* Running total of odd calculator: 10335
* Running total of even calculator: 1126
* Running Total of all operation types: 11461
* The average of total operations: 1432
 