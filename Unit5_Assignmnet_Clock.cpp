/***********************************************************************
*   Rahul Sagi     4-18-2019
*   Spring 2019     COSC 1437
*   Dr. McMillan    DevC++ 5.11 
*   TCC Trinity River
*   Unit 5 Assignment Main Program
*
*   Summary:
*   Write a program to simulate the simultaneous running of a collection
*   of clocks for a period of one (1) week, where each drifts a specified
*   amount of time per second.
*
*   Skills Gained:
*   Learn how to sort vectors, create destroyer, about inheritance, classes,
*   polymorphism, and virtual methods

************************************************************************/
#include "clock_time.cpp"
#include <vector>
#include <cstring>
#define MAX_CLOCK_NAME 64 
#define RUN_TIME 604800  //seconds in one week
 
enum CLOCK_TYPE {Sundial, Atomic, Cuckoo, Grandfather, Wrist};
 
class Clock
{
    public: 
        Clock(CLOCK_TYPE const type, ClockTime const& initialTime, double const driftPerSecond, char const * const name)
        {
            type_ = Sundial; 
            driftPerSecond_ = driftPerSecond;  
            strcpy(name_,name); 
            clockTime_.setTime(initialTime); 
        }
    protected: 
        ClockTime clockTime_; 
         
    private:
        CLOCK_TYPE type_; 
        double driftPerSecond_; 
        char name_[MAX_CLOCK_NAME]; 
         
    public: 
        virtual void reset() = 0; //pure virtual function
        virtual void tick() = 0;  //pure virtual function
        virtual void displayTime() const = 0; 
        char const * const name() const {return name_; } 
        double const driftPerSecond() const { return driftPerSecond_;} 
     
}; 
 
class NaturalClock : public Clock //inheritance 
{
    public:     
        NaturalClock(CLOCK_TYPE const type, 
               ClockTime const& initialTime,
               double const driftPerSecond,
               char const * const name) : Clock(type, initialTime, driftPerSecond, name) { } //empty constructor
        virtual void reset() = 0; //pure virtual function
        virtual void tick() = 0;  //pure virtual function
        virtual void displayTime() const = 0;  
};
 
class MechanicalClock : public Clock //inheritance 
{
    public: 
        MechanicalClock(CLOCK_TYPE const type, 
               ClockTime const& initialTime,
               double const driftPerSecond,
               char const * const name) : Clock(type, initialTime, driftPerSecond, name) { } //empty constructor
        virtual void reset() = 0; //pure virtual function
        virtual void tick() = 0;  //pure virtual function
        virtual void displayTime() const = 0;  
};
 
class DigitalClock : public Clock //inheritance 
{
    public: 
        DigitalClock(CLOCK_TYPE const type, 
               ClockTime const& initialTime,
               double const driftPerSecond,
               char const * const name) : Clock(type, initialTime, driftPerSecond, name) { } //empty constructor
        virtual void reset() = 0; //pure virtual function
        virtual void tick() = 0;  //pure virtual function
        virtual void displayTime() const = 0;  
};
 
class QuantumClock : public Clock //inheritance 
{
    public: 
        QuantumClock(CLOCK_TYPE const type, 
               ClockTime const& initialTime,
               double const driftPerSecond,
               char const * const name) : Clock(type, initialTime, driftPerSecond, name) { } //empty constructor
        virtual void reset() = 0; //pure virtual function
        virtual void tick() = 0;  //pure virtual function
        virtual void displayTime() const = 0;  
};
 
class SundialClock : public NaturalClock //inheritance 
{
    public: 
        SundialClock(CLOCK_TYPE const type, 
               ClockTime const& initialTime,
               double const driftPerSecond,
               char const * const name) : NaturalClock(type, initialTime, driftPerSecond, name) { } //empty constructor
        void reset()  //vitual overload the  child can overload the functions of the parent
        {
            clockTime_.reset(); 
        }
        void tick()     
        {
            clockTime_.increment(); 
        }
        void displayTime() const
        {
            cout << "\n" << name() << " Clock\t time["; 
            clockTime_.display(); 
            cout << "] - total drift = " ;
            //calculate total drift
            cout << (clockTime_.deltaTime() * driftPerSecond());          
            cout << " seconds";
        }
};
 
class CuckooClock : public MechanicalClock //inheritance 
{
    public: 
        CuckooClock(CLOCK_TYPE const type, 
               ClockTime const& initialTime,
               double const driftPerSecond,
               char const * const name) : MechanicalClock(type, initialTime, driftPerSecond, name) { } //empty constructor
        void reset()  //vitual overload the  child can overload the functions of the parent
        {
            clockTime_.reset(); 
        }
        void tick()     
        {
            clockTime_.increment(); 
        }
        void displayTime() const
        {
            cout << "\n" << name() << " Clock\t time["; 
            clockTime_.display(); 
            cout << "] - total drift = " ;
            //calculate total drift
            cout << (clockTime_.deltaTime() * driftPerSecond());          
            cout << " seconds";
        }
};
 
class GrandfatherClock : public MechanicalClock //inheritance 
{
    public: 
        GrandfatherClock(CLOCK_TYPE const type, 
               ClockTime const& initialTime,
               double const driftPerSecond,
               char const * const name) : MechanicalClock(type, initialTime, driftPerSecond, name) { } //empty constructor
        void reset()  //vitual overload the  child can overload the functions of the parent
        {
            clockTime_.reset(); 
        }
        void tick()     
        {
            clockTime_.increment(); 
        }
        void displayTime() const
        {
            cout << "\n" << name() << " Clock\t time["; 
            clockTime_.display(); 
            cout << "] - total drift = " ;
            //calculate total drift
            cout << (clockTime_.deltaTime() * driftPerSecond());          
            cout << " seconds"; 
        }
};
 
class WristClock : public DigitalClock //inheritance 
{
    public: 
        WristClock(CLOCK_TYPE const type, 
               ClockTime const& initialTime,
               double const driftPerSecond,
               char const * const name) : DigitalClock(type, initialTime, driftPerSecond, name) { } //empty constructor
        void reset()  //vitual overload the  child can overload the functions of the parent
        {
            clockTime_.reset(); 
        }
        void tick()     
        {
            clockTime_.increment(); 
        }
        void displayTime() const
        {
            cout << "\n" << name() << " Clock\t time["; 
            clockTime_.display(); 
            cout << "] - total drift = " ;
            //calculate total drift
            cout << (clockTime_.deltaTime() * driftPerSecond());          
            cout << " seconds"; 
        }
};
 
class AtomicClock : public QuantumClock //inheritance 
{
    public: 
        AtomicClock(CLOCK_TYPE const type, 
               ClockTime const& initialTime,
               double const driftPerSecond,
               char const * const name) : QuantumClock(type, initialTime, driftPerSecond, name) { } //empty constructor
        void reset()  //vitual overload the  child can overload the functions of the parent
        {
            clockTime_.reset(); 
        }
        void tick()     
        {
            clockTime_.increment(); 
        }
        void displayTime() const
        {
            cout << "\n" << name() << " Clock\t time["; 
            clockTime_.display(); 
            cout << "] - total drift = " ;
            //calculate total drift
            cout << (clockTime_.deltaTime() * driftPerSecond());          
            cout << " seconds"; 
        }
};
 
int main()
{
    vector<Clock*> clocks_; 

    // Instantiating an object of ClockTime and resetting the values
    ClockTime ct; 
    ct.setTime(0,0,0,1); 

    // Instantiating SundialClock and adding to vector
    Clock *sundialClock = new SundialClock(Sundial, ct, 0, "Sundial");
    clocks_.push_back(sundialClock);

    // Instantiating CuckooClock and adding to vector
    Clock *cuckooClock = new CuckooClock(Cuckoo, ct, 0.000694444, "Cuckoo");
    clocks_.push_back(cuckooClock);

    // Instantiating GrandfatherClock and adding to vector
    Clock *grandFatherClock = new GrandfatherClock(Grandfather, ct, 0.000347222, "GrandFather");
    clocks_.push_back(grandFatherClock);

    // Instantiating WristClock and adding to vector
    Clock *wristClock = new WristClock(Wrist, ct, 0.000034722, "Wrist");
    clocks_.push_back(wristClock);

    // Instantiating AtomicClock and adding to vector
    Clock *atomicClock = new AtomicClock(Atomic, ct, 0, "Atomic");
    clocks_.push_back(atomicClock);

    cout << "Reported clock times after resetting: " << endl;
    cout << "==================================== " << endl;

    // Iterating through the vector and displaying initial values of all clocks
    for(vector<Clock*>::iterator it = clocks_.begin(); it != clocks_.end(); ++it) {

        (*it)->displayTime();

    } 

    cout << endl << endl;

    cout << "Running the clocks for one (1) week..." << endl;

    cout << endl;

    cout << "Reported clock times after running: " << endl;
    cout << "==================================== " << endl;

    // Iterating through the vector, incrementing the ticks over 1 week and displaying the final values of all clocks
    for(vector<Clock*>::iterator it = clocks_.begin(); it != clocks_.end(); ++it) {
        
        for(int i=0; i<RUN_TIME;i++)
        {
            (*it)->tick();
        }
        
        (*it)->displayTime(); 

    }

    cout << endl;

    // Calling destructor
    for(vector<Clock*>::iterator it = clocks_.begin(); it != clocks_.end(); ++it) {
        delete (*it);
    }

    return 0;
}
