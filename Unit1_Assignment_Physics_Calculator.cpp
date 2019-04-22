/***********************************************************************
*   Rahul Sagi     3-19-2019
*   Spring 2019     COSC 1437
*   Dr. McMillan    DevC++ 5.11 
*   TCC Trinity River
*   Unit 1 Assignment Main Program
*
*   Summary:
*   Write a program that calculates different physics formulas such as 
*   Force, Weight, Acceleration, Velocity, Motion, and Momentum. Ask the 
*   user which of these formulas he wants to calculate, while also allowing 
*   him the option to exit the loop or clear the screen.
*
*   Skills Gained:
*   Learn how to validate input, calculate mathematical formulas across multiple functions,
*   showcase a menu, and display different colors on the output.

************************************************************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>      // std::setprecision
#include "Input_Validation_Extended.h"
using namespace std;

//Define Color on Mac
//the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

// Function declarations
void showMenu();
void handleOption(string userOption);
void showMenuAndGetOption();
void goVelocity();
void goAcceleration();
void goMotion();
void goNewton();
void goWeight();
void goMomentum();

int main()
{
    string option = "";
    do
    {
        showMenu();//show menu
        cout << "\nPlease select an option: ";
        getline(cin,option); //accept input from the user whole line
        handleOption(option); //pass the option that the user entered into our function

    } while(option != "e" && option != "E");

    return 0;

    // showMenuAndGetOption();
    return 0;

}

void showMenu() {

    cout << "Enter the number corresponding to the menu item:" << endl;
    cout << "A. Velocity" <<  endl;
    cout << "B. Acceleration" << endl;
    cout << "C. Motion" << endl;
    cout << "D. Force" << endl;
    cout << "F. Weight" << endl;
    cout << "G. Momentum" << endl;
    cout << "E: Exit" << endl;
    cout << "X: Clear the screen" << endl;

}

void handleOption(string userOption)
{

    if(userOption == "a")
    {
        goVelocity();   

    } else if(userOption == "b") {

        goAcceleration();
    
    } else if(userOption == "c") {

        goMotion();
    
    } else if(userOption == "d") {

        goNewton();
    
    } else if(userOption == "f") {

        goWeight();
    
    } else if(userOption == "g") {

        goMomentum();
    
    } else if(userOption == "e"){
    
        cout << "\nGoodbye" << endl;

    } else if(userOption == "x") {

        system("clear"); //add the #include<cstdlib>

    } else //default clause  
    {
        cout << RED << "\nError: Something went wrong." << RESET << endl;
    }

    cout << endl << endl;

}

void goVelocity() {

    double ds;
    double dt;

    cout << "ds in kilometers. ";
    ds = validateDouble(ds);
    cout << "dt in hours. ";
    dt = validateDouble(dt);

    double velocity = (ds/dt);
    cout << fixed << setprecision(4);
    cout << endl << "==========" << endl << endl;

    cout << GREEN << "Velocity is " << velocity << " km/hour." << RESET << endl;

    cout << endl << "==========" << endl;

}

void goAcceleration() {

    double dv;
    double dt;

    cout << "dv in meters/hour. ";
    dv = validateDouble(dv);
    cout << "dt in seconds. ";
    dt = validateDouble(dt);

    double accel = (dv/dt);
    cout << fixed << setprecision(4);
    cout << endl << "==========" << endl << endl;

    cout << GREEN << "Acceleration is " << accel << " m/s." << RESET << endl;

    cout << endl << "==========" << endl;

}

void goMotion() {

    double v0;
    double a;
    double t;
    double s0;

    cout << "v0 in km/hour: "; 
    v0 = validateDouble(v0);
    cout << "a in m/sec: "; 
    a = validateDouble(a);
    cout << "t in sec: ";
    t = validateDouble(t);
    cout << "s0 in meters: ";
    s0 = validateDouble(s0);

    double ma = (v0 + (a * t));
    double ms = (s0 + (v0 * t) + (0.5 * a * t * t));
    double mv2 = ((ma * ma) + (2 * a * (ms - s0)));
    double mv = (0.5 * (ma + v0));

    cout << fixed << setprecision(4);
    cout << endl << "==========" << endl << endl;

    cout << GREEN;

    cout << "Ma is " << ma << " km/hour" << endl;
    cout << "Ms is " << ms << " km" << endl;
    cout << "Mv2 is " << mv2 << " km/hour" << endl;
    cout << "Mv is " << mv << " km/hour" << endl;

    cout << RESET;

    cout << endl << "==========" << endl;

}

void goNewton() {

    double m;
    double a;

    cout << "m in kg. ";
    m = validateDouble(m);
    cout << "a in m/s^2. ";
    a = validateDouble(a);

    double force = (m * a);
    cout << fixed << setprecision(4);
    cout << endl << "==========" << endl << endl;

    cout << GREEN << "Force is " << force << " kg m/s^2." << RESET << endl;

    cout << endl << "==========" << endl;

}

void goWeight() {

    double m;
    double g;

    cout << "m in kg. ";
    m = validateDouble(m);
    cout << "g in grams. ";
    g = validateDouble(g);

    double weight = (m * g);
    cout << fixed << setprecision(4);
    cout << endl << "==========" << endl << endl;


    cout << GREEN << "Weight is " << weight << " lbs." << RESET << endl;

    cout << endl << "==========" << endl;

}

void goMomentum() {

    double m;
    double v;

    cout << "Enter the value for m in kg: ";
    m = validateDouble(m);
    cout << "Enter the value for v in m/s: ";
    v = validateDouble(v);

    double momentum = (m * v);
    cout << fixed << setprecision(4);
    cout << endl << "==========" << endl << endl;
    
    cout << GREEN << "Momentum is " << momentum << " kg m/s." << RESET << endl;

    cout << endl << "==========" << endl;

}
