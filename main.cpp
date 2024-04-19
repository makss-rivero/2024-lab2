#include <iostream>
#include <string>
using namespace std;


int characterCounter(const char* chars, char character);
int characterCounter(const string& s, char character);

int main() {
    int studentCode = 84883;
    int totalTaskCount = 25;
    int taskNumber = studentCode % totalTaskCount;
    cout << "Student code: " << studentCode << " & Task number: " << taskNumber << endl;

    int arrLength;
    cout << "Enter arrayOfCharacters length: ";
    cin >> arrLength;
    cin.ignore();

    char** arrayOfCharacters = new char*[arrLength];
    string* arrayOfStrings = new string[arrLength];


    for (int i = 0; i < arrLength; i++) {
        cout << "Enter string: " << i + 1 << " => ";
        string input;
        getline(cin, input);

        arrayOfCharacters[i] = new char[input.length() + 1];
        strcpy(arrayOfCharacters[i], input.c_str());
        arrayOfStrings[i] = input;
    }

    char searchCharacter;
    cout << "Enter character to count: ";
    cin >> searchCharacter;
    cin.ignore();




    for (int i = 0; i < arrLength; i++) {
        cout << "character: " << searchCharacter
             << " appears " << characterCounter(arrayOfCharacters[i], searchCharacter)
             << " times in c-string "<< i + 1
             << " & "
             << characterCounter(arrayOfStrings[i], searchCharacter) << " times in string " << i + 1 << endl;
    }

    for (int i = 0; i < arrLength; i++) {
        delete[] arrayOfCharacters[i];
    }
    delete[] arrayOfCharacters;
    delete[] arrayOfStrings;

    return 0;
}


int characterCounter(const char* chars, const char character) {
    int characterCount = 0;
    for (int i = 0; chars[i] != '\0'; i++) {
        if (chars[i] == character) {
            characterCount++;
        }
    }
    return characterCount;
}

int characterCounter(const string& string, const char character) {
    int characterCount = 0;
    for (char ch : string) {
        if (ch == character) {
            characterCount++;
        }
    }
    return characterCount;
}











