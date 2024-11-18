//
// Created by Sydney Maxwell Clements on 9/15/24.
//

#include <iomanip>
#include "Month.h"
#include "Date.h"
#include "Login.h"
#include <iostream>
#include <algorithm>

using namespace std;
int get_int_from_user(const string& integerType, int numLimit) {
    // This variable will change when the user inputs a valid input
    bool loop_can_end = false;
    // This variable will be the user's input
    string user_input;
    // This int will be used to make the string input into an int output
    int constructed_return = 0;
    // This is a bool that tells me if the user's input was a negative number
    bool num_is_negative = false;
    // Loops until user_input_valid == true waiting for a valid input
    while(!loop_can_end){
        // Ask the user for input
        cout << "Please enter a valid " << integerType << " input :" ;
        // Collect input
        getline(cin, user_input);
        if(user_input.length()==0){
            cout << "No input. Enter a  "<< integerType <<": ";
        }
        else{
            // Before the following loop we assume that the user input is valid and try to disprove that
            loop_can_end = true;
            // This boolean represents the fact that the character we are looking at is the first character, hence it can be a negative num
            bool first_char = true;
            /* This loop runs through every character of the user input
             * CL is current_letter but shortened
             * It then checks every CL to see if it is any un allowed character
             * The loop starts by assuming its valid, and checks if it isn't at any point
             * if any character is invalid it lets the function know to keep going
             */
            for (char current_letter : user_input) {
                if ((int)current_letter == 45 && first_char) {
                    // We found a not allowed char (not a number)
                    num_is_negative = true;
                } else if (!(48 <= current_letter && current_letter <= 57)) {
                    // We found a not allowed char (not a number)
                    loop_can_end = false;
                } else {
                    // this will "move" the constructed integer over 1 place so the new number can slot in
                    constructed_return *= 10;
                    // The ascii for the integers is between 48-57, so if we remove 48 from the ascii value then the char values equal the integer values and we can just add
                    constructed_return += (((int) current_letter)-48);
                }
                first_char = false;
            }
            if(num_is_negative){
                constructed_return*=-1;
            }
            if(constructed_return > numLimit){
                loop_can_end = false;
                cout << "Number is too big must be less than " << numLimit << endl;
            }
            if (constructed_return <= 0) {
                loop_can_end = false;
                cout << "Number is too small must be greater than 0" << endl;
            }
            if(!loop_can_end){
                constructed_return = 0;
                num_is_negative = false;
            }
        }
    }
    return constructed_return;
}

string get_sentence_from_user(string sentenceType) {
    // This variable will change when the user inputs a valid input
    bool loop_can_end = false;
    // This variable will be the user's input
    string user_input;
    // Loops until user_input_valid == true waiting for a valid input
    while(!loop_can_end){
        // Ask the user for input
        cout << "Please enter a valid "<< sentenceType <<" input: ";
        // Collect input
        getline(cin, user_input);
        if(user_input.length()==0){
            cout << "No input. Enter a "<< sentenceType <<": ";
        } else {
            // Before the following loop we assume that the user input is valid and try to disprove that
            loop_can_end = true;
            /* This loop runs through every character of the user input
             * CL is current_letter but shortened
             * It then checks every CL to see if it is any un allowed character
             * The loop starts by assuming its valid, and checks if it isn't at any point
             * if any character is invalid it lets the function know to keep going
             */
            for (char current_letter : user_input) {
                if (current_letter != 10) {
                    // This is a valid character so nothing needs to be done
                }
                else{
                    loop_can_end = false;
                }
            }
        }

    }
    return user_input;
}

string get_choice_from_user() {
    // This variable will change when the user inputs a valid input
    bool loop_can_end = false;
    // This variable will be the user's input
    string user_input;
    // Loops until user_input_valid == true waiting for a valid input
    while(!loop_can_end) {
        // Ask the user for input
        cout << "Please choose either 'log in' or 'sign up'" << endl;
        // Collect input
        getline(cin, user_input);
        //convert input to lowercase so we can accept any case combination of log in or sign up
        transform(user_input.begin(), user_input.end(), user_input.begin(), ::tolower);
        if (user_input.length() == 0) {
            cout << "No input. Please enter 'log in' or 'sign up': " << endl;
        } else {
            // Before the following loop we assume that the user input is valid and try to disprove that
            loop_can_end = true;
            if (user_input == "log in" || user_input == "sign up") {
                //this is a valid character, nothing needs to be done
            } else {
                cout << "Invalid Input." << endl;
                loop_can_end = false;
            }
        }
    }
    return user_input;
}

string get_name_pass_from_user(string input_type) {
    cout << "Please enter a " << input_type << "of length 8-20 characters with no spaces: " << endl;
    string input;
    getline(cin, input);
    size_t found = input.find(" ");
//loop until white space
    while (found != string::npos) {
        int strSize = input.length();
        int count = 0;
//loop through the input and count the whitespace
        for (int i = 0; i < strSize; i++) {
            if (input[i] == ' ') {
                count += 1;
            }
        }
//if all of it is whitespace print no input
        if (strSize == count) {
            cout << "No input. Enter a single word: " << endl;
        } else {
            cout << "Invalid" << input_type << "Please enter a " << input_type << " of length 8-20 characters with no spaces:" << endl;
        }
        getline(cin, input);
        found = input.find(" ");
    }
    return input;
}

int main() {
    //get login info from user
    cout << "Welcome to my date counter!" << endl;
    cout << "If you already have an account, type 'log in', otherwise type 'sign up'" << endl;
    string choice = get_choice_from_user();
    string username = get_name_pass_from_user("username");
    string password = get_name_pass_from_user("password");

    Login login = Login(choice, username, password);
    login.user_pass_file();

    int dayNumber = get_int_from_user("Day Number",32);
    string monthName = get_sentence_from_user("Month Name");
    int yearNumber = get_int_from_user("Year Number",2500);

    Date today = Date(dayNumber,monthName, yearNumber);
    today.displayDate();
    bool loop_complete = false;
    while(!loop_complete){
        cout << "What would you like to do?" << endl;
        cout << "Enter \"Set Date\", \"Add Day\", \"Add Month\", \"Add Year\", or \"Quit\"" << endl;
        string user_input = get_sentence_from_user("Command");
        if(user_input == "Set Date"){
            today = Date(get_int_from_user("Day Number",32),get_sentence_from_user("Month Name"), get_int_from_user("Year Number",2500));
            today.displayDate();
        } else if (user_input == "Add Day"){
            today.incrementDay();
            today.displayDate();
        } else if (user_input == "Add Month"){
            today.incrementMonth();
            today.displayDate();
        } else if (user_input == "Add Year"){
            today.incrementYear();
            today.displayDate();
        } else if (user_input == "Quit"){
            loop_complete = true;
            cout << "Thank you for using my date counter" << endl;
        }

    }
}

