#pragma once

#include <iostream>

using namespace std;

namespace Input {

    short Getshort ( short From, short To, string Message = "") {

    short Number;
    do {

        cout << Message << endl;
        cin >> Number;
    } while (Number < From || Number > To);
    return Number;
    }

    int GetInt ( int From, int To, string Message = "") {

    int Number;
    do {

        cout << Message << endl;
        cin >> Number;
    } while (Number < From || Number > To);
    return Number;
    }

    float GetFloat ( float From, float To, string Message = "" ) {
        
    float Number;
    do {

        cout << Message << endl;
        cin >> Number;
    } while (Number < From || Number > To);
    return Number;
    }

    long GetLong ( long From, long To, string Message = "" ) {
        
    long Number;
    do {

        cout << Message << endl;
        cin >> Number;
    } while (Number < From || Number > To);
    return Number;
    }

    double GetDouble ( double From, double To, string Message = "" ) {
        
    double Number;
    do {

        cout << Message << endl;
        cin >> Number;
    } while (Number < From || Number > To);
    return Number;
    }

    bool GetBool ( string Message = "" ) {
        
    bool Boolean = false;
    do {

        cout << Message << endl;
        cin >> Boolean;
    } while (Boolean < 0 || Boolean > 1);
    return Boolean;
    }


    string GetString (string Message = "" ) {
        
    string text = "\0";
    cout << Message << endl;
    getline(cin, text); 

    return text;
    }

    char GetChar ( string Message = "" ) {
    
    char text = '\0';
    cout << Message << endl;
    cin >> text;
    }

    
}
