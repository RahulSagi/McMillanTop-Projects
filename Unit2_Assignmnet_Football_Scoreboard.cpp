/***********************************************************************
*   Rahul Sagi     3-26-2019
*   Spring 2019     COSC 1437
*   Dr. McMillan    DevC++ 5.11 
*   TCC Trinity River
*   Unit 2 Assignment Main Program
*
*   Summary:
*   Write a program to creat a dynamic scoreboard between two football teams throughout
*   the duration of a football game
*
*   Skills Gained:
*   Learn how to create classes, how private and public accessors work, the setter and getter
*   functions, and pass values by reference

************************************************************************/

#include<iostream>
#include<string>
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


class Team {

    private:
        string name = "";
        string coachName = "";
        string homeCity = "";
        bool homeStatus = true;
        int score = 0;
        int timeoutCount = 3;
        bool possession = false;

    public:
        void setName(string);
        string getName();
        void setCoachName(string);
        string getCoachName();
        void setHomeCity(string);
        string getHomeCity();
        void setHomeStatus(bool);
        bool getHomeStatus();
        void setScore(int);
        int getScore();
        void setTimeoutCount(int);
        int getTimeoutCount();
        void setPossession(bool);
        bool getPossession();
        void printTeamDetails();
        void addToScore(int);
       
};

// Sets Team Name
void Team::setName(string n)
{
    name = n;
}

// Returns Name
string Team::getName()
{
    return name;
}

// sets the Coach's Name
void Team::setCoachName(string cn)
{
    coachName = cn;
}

// Gets the coach's name
string Team::getCoachName() 
{
    return coachName;
}

// sets the Home City
void Team::setHomeCity(string hc)
{
    homeCity = hc;
}

// Gets the Home City
string Team::getHomeCity() 
{
    return homeCity;
}

// Determines which team is the home team
void Team::setHomeStatus(bool y)
{
    homeStatus = y;
}

// gets the home team
bool Team::getHomeStatus()
{
    return homeStatus;
}

// Sets the score
void Team::setScore(int num) 
{
    score = num;
}

// Gets the score
int Team::getScore() 
{
    return score;
}

// sets the Timeouts
void Team::setTimeoutCount(int tc) 
{
    timeoutCount = tc;
}

// Gets the Timeouts
int Team::getTimeoutCount() 
{
    return timeoutCount;
}

// Set the team that the possession
void Team::setPossession(bool yyy)
{
    possession = yyy;
}

//Get the team that has possession
bool Team::getPossession()
{
    return possession;
}

//Print thr Team Details
void Team::printTeamDetails() {
    cout << "Team Name: " << getName() << endl;
    cout << "Team Score: " << getScore() << endl;
    cout << "Timeouts Left: " << getTimeoutCount() << endl;
    cout << "Home Team: " << getHomeStatus() << endl;
    cout << "Posession: " << getPossession() << endl;
}

// Add Score
void Team::addToScore(int points) {
    score = score + points;
}

class Scoreboard
{
    private:
        int quarter = 1;
        double timeLeft = 15;
        Team homeTeam;
        Team visitorTeam;
    public:
        void setQuarter(int);
        int getQuarter();
        void setTimeLeft(double);
        double getTimeLeft();
        void printScoreboard();
        void setHomeTeam(Team);
        Team & getHomeTeam();
        void setVisitorTeam(Team);
        Team & getVisitorTeam();
};

// Set the Quarter
void Scoreboard::setQuarter(int q)
{
    if(quarter != q) {
        timeLeft = 15;
    }

    quarter = q;
}

// Get the Quarter
int Scoreboard::getQuarter()
{
    return quarter;
}

// set the amount of time left in the game
void Scoreboard::setTimeLeft(double tl)
{
    timeLeft = tl;
}

// Get the amount of time left in the game
double Scoreboard::getTimeLeft()
{
    return timeLeft;
}

// set the Home Team
void Scoreboard::setHomeTeam(Team h)
{
    homeTeam = h;
}

// Get the home team
Team & Scoreboard::getHomeTeam() 
{
    return homeTeam;
}

// Set the Visitor Team
void Scoreboard::setVisitorTeam(Team v)
{
    visitorTeam = v;
}

// Get the Visitor Team
Team & Scoreboard::getVisitorTeam()
{
    return visitorTeam;
}

// Scoreboard that displays in the output
void Scoreboard::printScoreboard() {
    cout << "***************************************" << endl;
    cout << MAGENTA;
    cout << "Quarter: " << getQuarter() << endl;
    cout << "Time Left: " << getTimeLeft() << endl;
    cout << RESET;
    cout << endl;

    cout << BLUE;
    homeTeam.printTeamDetails();
    cout << RESET;

    cout << endl;

    cout << RED;
    visitorTeam.printTeamDetails();
    cout << RESET;
    cout << "***************************************" << endl;
}

void showFirstMenu(Scoreboard &scoreBoard); // Input values for Home Team's and Visitor's Team's Coach, Name and City
void showSecondMenu(); // Input Values Corresponding to the Menu Item
void handleOption(string, Scoreboard &scoreBoard); // Handle the values entered by user in showSecondMenu()
void goScore(Scoreboard &scoreBoard); // Edit the Scores of both teams
void goPossession(Scoreboard &scoreBoard); // Determine which Team has possessiom
void goTimeoutsLeft(Scoreboard &scoreBoard); // Edit the number of timeouts left
bool isScoreValid(int); // Validate Score
bool isQuarterValid(Scoreboard &, int); // Validate Quarter
bool isTimeoutsValid(Team &, int); // Validate Timeouts
bool isTimeLeftValid(Scoreboard &, double); // Validate Time Left
bool isPossValid(string); // Validate Possession


 int main() {

     Scoreboard scoreBoard;

    showFirstMenu(scoreBoard);

    string option = "";
    do
    {
        showSecondMenu();//show menu
        cout << "\nPlease select an option: ";
        // getline(cin,option); //accept input from the user whole line
        cin >> option;
        handleOption(option, scoreBoard); //pass the option that the user entered into our function

    } while(option != "e" && option != "E");
    
    return 0;
 }     

 void showFirstMenu(Scoreboard &scoreBoard) 
 {

    string hTeamName = "";
    string hCoachName = "";
    string hTeamCity = "";
    string vTeamName = "";
    string vCoachName = "";
    string vTeamCity = "";

    // Accept home team details
    cout << RED;
    cout << "Home Team Name. ";
    hTeamName = validateString(hTeamName);
    cout << "Home Team's Coach's Last Name. ";
    hCoachName = validateString(hCoachName);
    cout << "Home Team's City. ";
    hTeamCity = validateString(hTeamCity);
    cout << RESET;
    
    // Set Home team details into scoreBoard object
    scoreBoard.getHomeTeam().setName(hTeamName);
    scoreBoard.getHomeTeam().setCoachName(hCoachName);
    scoreBoard.getHomeTeam().setHomeCity(hTeamCity);
    scoreBoard.getHomeTeam().setHomeStatus(true);
    scoreBoard.getHomeTeam().setPossession(false);

    cout << endl;

    // Set Visitor Team Details
    cout << BLUE;
    cout << "Visitor Team Name. ";
    vTeamName = validateString(vTeamName);
    cout << "Visitor Team's Coach's Last Name. ";
    vCoachName = validateString(vCoachName);
    cout << "Visitor Team's City. ";
    vTeamCity = validateString(vTeamCity);
    cout << RESET;

    // Set Visitor Team details into scoreBoard object
    cout << endl;
    scoreBoard.getVisitorTeam().setName(vTeamName);
    scoreBoard.getVisitorTeam().setCoachName(vCoachName);
    scoreBoard.getVisitorTeam().setHomeCity(vTeamCity);
    scoreBoard.getVisitorTeam().setHomeStatus(false);
    scoreBoard.getVisitorTeam().setPossession(true);

    cout << endl;

    scoreBoard.printScoreboard();

    cout << endl;

 }  

// Input Values Corresponding to the Menu Item
void showSecondMenu() 
{
    cout << "Enter the letter corresponding to the menu item:" << endl;
    cout << "A. Score: " <<  endl;
    cout << "B. Posession: " << endl;
    cout << "F. Timeouts Left: " << endl;
    cout << "E: Exit" << endl;
    cout << "X: Clear the screen" << endl;
}

// Handle the values entered by user in showSecondMenu()
void handleOption(string userOption, Scoreboard &scoreBoard)
{

    if(userOption == "a")
    {
        goScore(scoreBoard);   

    } else if(userOption == "b") {

        goPossession(scoreBoard);
    
    } else if(userOption == "f") {

        goTimeoutsLeft(scoreBoard);
    
    } else if(userOption == "e"){
    
        cout << "\nGoodbye" << endl;

    } else if(userOption == "x") {

        system("clear"); //add the #include<cstdlib>

    } else //default clause  
    {
        cout << "\nError: Something went wrong." << endl;
    }

    cout << endl << endl;

}

// Edit the Scores of both teams
void goScore(Scoreboard &scoreBoard) {

    int score = 0;
    bool valid = true;

    // Accept score and validate input
    do {
        cout << "Points Earned. ";
        score = validateInt(score);

        if(scoreBoard.getHomeTeam().getPossession() == true) {
            valid = isScoreValid(score);
        } else {
            valid = isScoreValid(score);
        }
    } while(valid == false);

    // Accept quarter and validate input
    int quarter = 0;
    do {
        
        cout << "Quarter. ";
        quarter = validateInt(quarter);
        valid = isQuarterValid(scoreBoard, quarter);

    } while(valid == false);

    scoreBoard.setQuarter(quarter);

    double timeLeft = 0;

    // Accept time left and validate input
    do {
        
        cout << "Time left in the quater. ";
        timeLeft = validateDouble(timeLeft);
        valid = isTimeLeftValid(scoreBoard, timeLeft);

    } while(valid == false);

    // Check possession to add score to either home or visitor team object
    if (scoreBoard.getHomeTeam().getPossession() == true) {
        scoreBoard.getHomeTeam().addToScore(score);
    } else {
        scoreBoard.getVisitorTeam().addToScore(score);
    }

    scoreBoard.setTimeLeft(timeLeft);

    cout << endl;

    scoreBoard.printScoreboard();

    cout << endl;
}

// Determine which Team has possessiom
void goPossession(Scoreboard &scoreBoard)
{
    string poss;
    bool valid = true;

    // Accept possession and validate input
    do {
        cout << "Who has possession? Enter H for home, and V for visitor. ";
        poss = validateString(poss);

        valid = isPossValid(poss);

    } while(valid == false);

    int quarter = 0;

    // Accept quarter and validate input
    do {
        
        cout << "Quarter. ";
        quarter = validateInt(quarter);
        valid = isQuarterValid(scoreBoard, quarter);

    } while(valid == false);

    scoreBoard.setQuarter(quarter);

    double timeLeft = 0;

    // Accept time left and validate input
    do {
        
        cout << "Time left in the quarter. ";
        timeLeft = validateDouble(timeLeft);
        valid = isTimeLeftValid(scoreBoard, timeLeft);

    } while(valid == false);

    // Check possession to give possession to either home or visitor team object
    if(poss == "h" || poss == "H")
    {
        scoreBoard.getHomeTeam().setPossession(true);
        scoreBoard.getVisitorTeam().setPossession(false);

    } else if(poss == "v" || poss == "V") {

       scoreBoard.getHomeTeam().setPossession(false);
       scoreBoard.getVisitorTeam().setPossession(true); 
    } 

    scoreBoard.setTimeLeft(timeLeft);

    cout << endl;

    scoreBoard.printScoreboard();

    cout << endl;

}

// Edit the number of timeouts left
void goTimeoutsLeft(Scoreboard &scoreBoard)
{
    int timeouts = 0;
    bool valid = true;

    // Accept timeouts and validate input
    do {
        cout << "Timeouts Left. ";
        timeouts = validateInt(timeouts);

        if(scoreBoard.getHomeTeam().getPossession() == true) {
            valid = isTimeoutsValid(scoreBoard.getHomeTeam(), timeouts);
        } else {
            valid = isTimeoutsValid(scoreBoard.getVisitorTeam(), timeouts);
        }
    } while(valid == false);

    int quarter = 0;

    // Accept quarter and validate input
    do {
        
        cout << "Quarter. ";
        quarter = validateInt(quarter);
        valid = isQuarterValid(scoreBoard, quarter);

    } while(valid == false);

    scoreBoard.setQuarter(quarter);

    double timeLeft = 0;

    // Accept time left and validate input
    do {
        
        cout << "Time left in the quater. ";
        timeLeft = validateDouble(timeLeft);
        valid = isTimeLeftValid(scoreBoard, timeLeft);

    } while(valid == false);

    // Check possession to set timeout count to either home or visitor team object
    if (scoreBoard.getHomeTeam().getPossession() == true) {
        scoreBoard.getHomeTeam().setTimeoutCount(timeouts);
    } else {
        scoreBoard.getVisitorTeam().setTimeoutCount(timeouts);
    }

    scoreBoard.setTimeLeft(timeLeft);

    cout << endl;

    scoreBoard.printScoreboard();

    cout << endl;
}

// Validate Quarter
bool isQuarterValid(Scoreboard &scoreBoard, int quarter) {
    if(quarter > 4 || quarter < scoreBoard.getQuarter()) {
        cout << "Invalid input. Quarter cannot be greater than 4 or less than current quarter: " << scoreBoard.getQuarter() << endl;
        return false;
    } else {
        return true;
    }
}

// Validate Timeouts
bool isTimeoutsValid(Team &team, int timeoutsLeft) {
    if(timeoutsLeft < 0 || timeoutsLeft > team.getTimeoutCount()) {
        cout << "Invalid input. Timeouts left cannot be less than zero or greater than current timeouts left: " << team.getTimeoutCount() << endl;
        return false;
    } else {
        return true;
    }
}

// Validate Time Left
bool isTimeLeftValid(Scoreboard &scoreBoard, double timeLeft) {
    if(timeLeft < 0 || timeLeft > scoreBoard.getTimeLeft()) {
        cout << "Invalid input. Time Left can not be less than zero or greater than current time left: " << scoreBoard.getTimeLeft() << endl;
        return false;
    } else {
        return true;
    }
}

// Validate Score
bool isScoreValid(int score) {
    if (score == 3 || score == 7) {
        return true;
    } else {
        cout << "Invalid input. Score has to be 3 or 7. " << endl;
        return false;
    }
}

// Validate Possession
bool isPossValid(string poss) {
    if (poss == "H" || poss == "V" || poss == "h" || poss == "v") {
        return true;
    } else {
        cout << "Invalid input. Select h or v " << endl;
        return false;
    }
}
