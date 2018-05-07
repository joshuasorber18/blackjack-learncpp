//
// Created by Josh Sorber on 4/25/18.
//

#ifndef UNTITLED_INPUTOPERATIONS_H
#define UNTITLED_INPUTOPERATIONS_H
using namespace std;
namespace inputOp {
    int getSomeNumber() {

        while(true) {
            int someNumber;
            cout << "Please enter a number 1-9: ";
            cin >> someNumber;

            if (cin.fail() || someNumber > 9 || someNumber < 0)
            {
                cin.clear();
                cin.ignore(32767, '\n');
            } else {
                cin.clear();
                cin.ignore(32767, '\n');
                return someNumber;
            }

        }

    }

    string getName(int index) {
        string enteredName;
        do {
            cout << "Enter Name #" << index << ": ";
            getline(cin, enteredName);
            cin.clear();
        } while(enteredName.length() == 0);

        return enteredName;
    }
}


#endif //UNTITLED_INPUTOPERATIONS_H
