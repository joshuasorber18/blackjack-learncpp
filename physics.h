//
// Created by Josh Sorber on 4/27/18.
//

#ifndef UNTITLED_PHYSICS_H
#define UNTITLED_PHYSICS_H
using namespace std;
namespace physics {
    const double gravity (9.8);
    double calculateHeight(double v, double s, double h) {
        double secSquared = (s*s);
        //return (-(1/2)*gravity*secSquared)+(v*seconds)+(height);
        return (((-gravity)/2)*(secSquared))+(h);
    }
    double getTime() {
        while(true) {
            cout << "Please enter a time in seconds to find the height at: ";
            double time;
            cin >> time;
            if(time) {
                return time;
            } else if(time == 0) {
                cout << "Error: Invalid Time\n";
                cin.clear();
            }
        }
    }
    double getInitialHeight() {
        while(true) {
            cout << "Please enter an initial height for the projectile: ";
            double height;
            cin >> height;
            if(height) {
                return height;
            } else if(height == 0) {
                cout << "Error: Invalid Height\n";
                cin.clear();
            }
        }
    }
}

#endif //UNTITLED_PHYSICS_H
