//
//  test001.cpp
//  ExperimentalDev00
//  Code safely makes sure the user inputs a string
//  that can be converted into a double data type value
//
//  Created by FastTrackCoder on 6/10/22.
//

#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <iomanip>
using namespace std;

int main()
{
    string input;
    double num_input;
    bool num_flag = false;
    bool second_decimal_flag = false;
    
    cout << "This program will turn a string into a double:\n\n";
    cout << "Enter a number: ";
    cin >> input;
    cin.ignore(20,'\n');
    cin.clear();
    cout << "Good at first input:" << endl; // For troubleshooting
    // This portion of the code deals with the string not being a number
    do
    {
        cout << "Starting a for loop: " << endl;
        
        for(int i = 0; i < input.length(); i++)
        {
            if(!isdigit(input[i]))  // If not a number, check if it has a decimal point
            {
                cout << "Processing a digit in index[" << i << "]: " << endl;
                
                // If the char is not a decimal point, - or + sign or if the input has 2 decimal points
                // completely ask for a new input number.
                if((input[i] != '.' && input[i] != '+' && input[i] != '-') ||
                        (input[i] == '.' && second_decimal_flag == true))
                {
                    num_flag = false;
                    second_decimal_flag = false;
                    // Ask the user for an actual number
                    cout << "\nThe string you put in was not a number, \nplease " <<
                    "input an actual number: ";
                    cin >> input;
                    cin.ignore(20, '\n');
                    cin.clear();
                    break;
                }
                else if(input[i] == '.')    // Checks for decimal and plants a flag
                    second_decimal_flag = true;
                // If it has a + or - after the first index, cancel the input completely
                else if((input[i] == '+' || input[i] == '-') && i != 0)
                {
                    num_flag = false;
                    second_decimal_flag = false;
                    // Ask the user for an actual number
                    cout << "\nThe string you put in was not a number, \nplease " <<
                    "input an actual number: ";
                    cin >> input;
                    cin.ignore(20, '\n');
                    cin.clear();
                    break;
                }
                
            }
            
            num_flag = true;
        }
    } while(num_flag == false);
    
    // Finally convert string to double and then do some math on it
    // to show
    num_input = stod(input);
    
//    cout << fixed << showpoint;
    cout << "Double: " << num_input << endl;
    cout << num_input << " + 1 = " << (num_input + 1.0) << endl;
    cout << num_input << " / 2.0 = " << (num_input / 2.0) << endl;
    
    return 0;
}
