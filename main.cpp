#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

int convertToPigLatin(char arr[50]);
bool isVowel(char ch);

int main() {

    char user_input[50];
    char answer = ' ';
    
    do {
        cout << "Enter a word to convert it to pig latin" << endl;
        cin.getline(user_input, 50); //get user input
        
        cout << "Your entered word is " << user_input << endl;
        
        convertToPigLatin(user_input); //translate user's input into piglatin
        
        cout << "Would you like to convert another word? (Y/N)" << endl;
        cin >> answer;
        
        cin.ignore(); //clear past user input
        cin.clear();
    } while (answer == 'Y' || answer == 'y');
    
    cout << "Goodbye" << endl;
    return 0;
}

bool isVowel (char ch) {
    switch (tolower(ch)) { //if the first character of the given input is a vowel
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}

int convertToPigLatin(char arr[50]) {
    char new_arr[50] = {0}; //make sure new_arr is terminated

    size_t arr_length = strlen(arr); //holds length of input
    
    for (int i = 0; i < arr_length; i++) { //make sure all characters in input are lower case for easier processing
        new_arr[i] = tolower(arr[i]);
    }
    
    char last_char = new_arr[0]; //save the first character in case it needs to be appended
    
    if (atoi(arr) || arr[0] == '\0') { //if the input begins with a number or null character print an error
        cout << "Cannot translate input" << endl;
        return -1;
    } else if (arr_length <= 2) { // if the input is 2 or less characters
        cout << new_arr << endl; //print the input as is
        cout << "Boring! Try somthing more than 2 characters long" << endl;
        return 0;
    } else if ((strstr(new_arr, "and") && arr_length == 3) || (arr_length == 3 && strstr(new_arr, "but")) || (arr_length == 3 && strstr(new_arr, "for")) || (arr_length == 3 && strstr(new_arr, "nor")) || (arr_length == 3 && strstr(new_arr, "yet")) || (arr_length == 3 && strstr(new_arr, "the"))) { //if the input is more than 2 characters long
        cout << new_arr << endl; //print the input as is
        cout << "No conjucntions try again!" << endl;
        return 0;
    } else { //if the given input is three characters and is not a conjunction, being translation
        if (isVowel(arr[0])) { //check if input's first character is a vowel
            cout << "Your word in piglatin is "<< new_arr << "ay" << endl; //print that string with 'ay' at the end (i.e. egg'ay')
            return 0;
        } else { //else if the given input starts with a consonant
            for (int r = 1; r < arr_length; r++) { //shift each character up an index
                new_arr[r-1] = new_arr[r];
            }
            new_arr[arr_length - 1] = last_char; //replace the last character with the first character of the input
            cout << "Your word in piglatin is " << new_arr << "ay" << endl;
            return 0;
        }
    }
    return 0;
}
