#include <iostream>
#include <string>
using namespace std;

int main() {
    // Task 1: Concatenate Strings
    string firstName = "John";
    string lastName = "Doe";
    
    // Combine the 'firstName' and 'lastName' to create a full name.
    string fullname = firstName + ' ' + lastName;
    // Print the full name to the console.
    cout << fullname;
    // Hint: Use string concatenation.


    // Task 2: Uppercase and Lowercase
    string text = "This is a sample text.";

    // Convert 'text' to uppercase and store it in a new variable.
    string uptext;
    for (int i = 0; i < text.length(); i++) {
        uptext += toupper(text[i]);
    }
    // Convert 'text' to lowercase and store it in another new variable.
    string lowtext;
    for (int i = 0; i < text.length(); i++) {
        lowtext += tolower(text[i]);
    }
    // Print both the uppercase and lowercase versions.
    cout << uptext << ' ' << lowtext;

    // Task 3: Substring
    string sentence = "The quick brown fox jumps over the lazy dog.";
    // Extract the word "brown" from 'sentence' and store it in a new variable.
    string sub = sentence.substr(10,5);
    // Print the extracted word.
    cout << sub;


    // Task 4: Replace
    string originalString = "C++ is a popular programming language.";
    
    // Replace "C++" with "CPlusPlus" in 'originalString'.
    originalString.erase(0,3);
    originalString.insert(0, "CPlusPlus");
    // Print the modified string.
    cout << originalString;

    // Task 5: String Length
    string someText = "This is a random piece of text.";
    
    // Calculate and print the length (number of characters) of 'someText'.
    cout << someText.length();
    cin >> text;
    return 0;
}
