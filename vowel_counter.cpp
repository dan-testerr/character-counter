#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "Error with input args...\n";
        return 1;
    }
    
    ifstream inFile(argv[1]);
    // I spent hours trying to figure out why it kept
    // reading null unicode characters and it wouldn't 
    // change until I finally deleted "inFile.open(argv[1]);"
    // I don't know if that was just a me-problem, 
    // but thought I'd let you know.
    if (!inFile)
    {
        cout << "Error with file name..." << endl;
        return 1;
    }

    // introduction
    cout << setfill('*') << setw(60) << "\n";
    cout << setw(48) << " Welcome to my Letter Count Program " << setw(12) << "\n";
    cout << setw(61) << "\n\n";

    cout << "Analyzing file '" << argv[1] << "'...\n\n";
 
    char ch;
    int aCount = 0, bCount = 0, cCount = 0, dCount = 0, eCount = 0, iCount = 0, oCount = 0, uCount = 0;
    while (!inFile.eof()) // look at each char until the end of the file
    {
        inFile >> ch;
        switch (ch)
        {
        case 'a':
        case 'A':
            aCount++; // if a or A, increase aCount
            break;
        case 'b':
        case 'B':
            bCount++; // if b or B, increase bCount
            break;
        case 'c':
        case 'C':
            cCount++; // if c or C, increase cCount
            break;
        case 'd':
        case 'D':
            dCount++; // if d or D, increase dCount
            break;
        case 'e':
        case 'E':
            eCount++; // if e or E, increase eCount
            break;
        case 'i':
        case 'I':
            iCount++; // if i or I, increase iCount
            break;
        case 'o':
        case 'O':
            oCount++; // if o or O, increase oCount
            break;
        case 'u':
        case 'U':
            uCount++; // if u or U, increase uCount
            break;
        }
    }

    inFile.close();

    // calculate total vowels and characters
    int vowels = aCount + eCount + iCount + oCount + uCount;
    int chars = aCount + bCount + cCount + dCount + eCount + iCount + oCount + uCount;

    // displays results
    cout << setfill('.') << left;
    cout << setw(60) << "The number of A's: " << aCount << endl;
    cout << setw(60) << "The number of B's: " << bCount << endl;
    cout << setw(60) << "The number of C's: " << cCount << endl;
    cout << setw(60) << "The number of D's: " << dCount << endl;
    cout << setw(60) << "The number of E's: " << eCount << endl;
    cout << setw(60) << "The number of I's: " << iCount << endl;
    cout << setw(60) << "The number of O's: " << oCount << endl;
    cout << setw(60) << "The number of U's: " << uCount << endl;
    cout << setw(60) << "The vowel count is: " << vowels << endl;
    cout << setw(60) << "The listed character count is: " << chars << endl;

    return 0;
}