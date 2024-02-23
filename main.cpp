#include <iostream>
#include <map>
#include <string>
#include "Question_8.h"


void Question1(double totalWeight, double cgLocation)
{
    // Intializing varibles to stroe the data from the Airplane. 
    double emptyWeight, emptyWeightMoment;
    double FSeatMomArm, RSeatMomArm;
    double fuelWeightPerGallon, fuelMomentArm;
    double bagWeight, bagMomentArm;
    int numberFrontSeatOcc, numberRearSeatOcc;
    double numberofGalofFuel;
    
    
    double totalMoment;

    // Max Values of Data
    const double MaxGrossWeight = 2950;
    const double MaxCGLimit = 84.7;
    const double MinCGLimit = 82.1;

    
    std::cout << "Enter the airplanes empty weight (Pounds): ";
    std:: cin >> emptyWeight;

    std::cout << "Enter airplane empty weight moment (pounds-inches): ";
    std::cin >> emptyWeightMoment;

    // Frount Seat Data
    std::cout << "Enter the number of frount seat occupants: ";
    std::cin >> numberFrontSeatOcc;

    std::cout << "Enter the weight of each of the frount seat occupents (pounds)" << std::endl;
    int FSeatWeight[numberFrontSeatOcc]; // this will set up the array for number of frount seat passengers
    for (int i =0; i<numberFrontSeatOcc; i++)
    {
        std:: cout << "Frount seat occupant " << i << " weight: ";
        std::cin >> FSeatWeight[i];
    }

    std::cout << "Enter frount seat moment arm (inches): ";
    std::cin >> FSeatMomArm;

    // Rear Seat Data
    std::cout << "Enter the number of rear seat occupants: ";
    std::cin >> numberRearSeatOcc;

    std::cout << "Enter the weight of each of the rear seat occupents (pounds)" << std::endl;
    int RSeatWeight[numberRearSeatOcc]; // this will set up the array for number of frount seat passengers
    for (int i =0; i<numberRearSeatOcc; i++)
    {
        std:: cout << "Rear seat occupant " << i << " weight: ";
        std::cin >> RSeatWeight[i];
    }

    std::cout << "Enter rear seat moment arm (inches): ";
    std::cin >> RSeatMomArm;

    std::cout << "Enter number of gallons of usable fuel (gallons): ";
    std::cin >> numberofGalofFuel;

    std::cout << "Enter usable fuel weight per gallon (pound): ";
    std::cin >> fuelWeightPerGallon;

    std::cout << "Enter fuel tank momnet arm (inches): ";
    std::cin >> fuelMomentArm;

    std::cout << "Enter baggs wight( pounds): ";
    std::cin >> bagWeight;

    std::cout << "Enter baggs moment arm(inches): ";
    std::cin >> bagMomentArm;

    
    /*
    emptyWeight = 2050;
    emptyWeightMoment = 155400;
    numberFrontSeatOcc = 2;
    int FSeatWeight[2];
    FSeatWeight[0] = 180;
    FSeatWeight[1] = 150;
    FSeatMomArm = 85;
    numberRearSeatOcc = 2;
    int RSeatWeight[2];
    RSeatWeight[0] = 160;
    RSeatWeight[1] = 170;
    RSeatMomArm = 121;
    numberofGalofFuel = 44.000;
    fuelWeightPerGallon = 6;
    fuelMomentArm = 75;
    bagWeight = 10;
    bagMomentArm = 140;
    */

    // Calculations - Total Weight
    totalWeight = emptyWeight + (numberofGalofFuel * fuelWeightPerGallon) + bagWeight;
    for (int i = 0; i < numberFrontSeatOcc; ++i)
    {
        totalWeight += FSeatWeight[i];
    }
    for (int i = 0; i < numberRearSeatOcc; ++i)
    {
        totalWeight += RSeatWeight[i];
    }
    // Calculations - Total Moment
    totalMoment = emptyWeightMoment + (numberofGalofFuel * fuelWeightPerGallon * fuelMomentArm) + (bagWeight * bagMomentArm);
    for (int i = 0; i < numberFrontSeatOcc; ++i)
    {
        totalMoment += (FSeatWeight[i] * FSeatMomArm);
    }
    for (int i = 0; i < numberRearSeatOcc; ++i)
    {
        totalMoment += (RSeatWeight[i] * RSeatMomArm);
    }
    

    // Calculations - Locations of Center of Gravity
    cgLocation = totalMoment / totalWeight;
 
    std::cout << "\nTotal Weight: " << totalWeight << " pounds\n";
    std::cout << "Center of Gravity (C.G.) Location: " << cgLocation << " inches\n";
   
   bool designLimmits = false;
    if (totalWeight < MaxGrossWeight && cgLocation < MaxCGLimit && cgLocation > MinCGLimit)
    {
        std::cout << "The airplane is within design limits" << std::endl;
        designLimmits = true;
    }

    int orginalNumberOfGalOfFuel = numberofGalofFuel;
    
    // Check if the airplane is within design limits
    while (totalWeight > MaxGrossWeight || cgLocation > MaxCGLimit || cgLocation < MinCGLimit)
    {
        if (totalWeight > MaxGrossWeight)
        {
            numberofGalofFuel -= 0.01;
        }
        else if (cgLocation < MaxCGLimit)
        {
            numberofGalofFuel -= 0.01;
        }
        else if (cgLocation > MinCGLimit)
        {
            numberofGalofFuel += 0.01;
        }
        
        // Recalculate total weight and CG
        totalWeight = 0;
        totalMoment = 0;
        totalWeight = emptyWeight + (numberofGalofFuel * fuelWeightPerGallon) + bagWeight;
        totalMoment = emptyWeightMoment + (numberofGalofFuel * fuelWeightPerGallon * fuelMomentArm) + (bagWeight * bagMomentArm);
        for (int i = 0; i < numberFrontSeatOcc; ++i)
        {
            totalWeight += FSeatWeight[i];
        }
        for (int i = 0; i < numberRearSeatOcc; ++i)
        {
            totalWeight += RSeatWeight[i];
        }
        for (int i = 0; i < numberFrontSeatOcc; ++i)
        {
            totalMoment += (FSeatWeight[i] * FSeatMomArm);
        }
        for (int i = 0; i < numberRearSeatOcc; ++i)
        {
            totalMoment += (RSeatWeight[i] * RSeatMomArm);
        }
        

        cgLocation = totalMoment / totalWeight;
        
        
    }
    if (designLimmits == false)
    {
        std::cout << "The airplane is not within design limits" << std::endl;
        // Output results
        double addFuelNeeded = numberofGalofFuel - orginalNumberOfGalOfFuel; // Assuming initial fuel is 44 gallons
        if (addFuelNeeded > 0)
        {
            std::cout << "Additional fuel needed (gallons): " << abs(addFuelNeeded) << '\n';
        }

        if (addFuelNeeded < 0)
        {
            std::cout << "Fuel needed to be lost (gallons): " << abs(addFuelNeeded) << '\n';
        }
        std::cout << "New total weight: " << totalWeight << " pounds\n";
        std::cout << "New C.G. location: " << cgLocation << " inches\n";
    }
    
}

class Plane 
{
    private:
        double pos;
        double vel;
        double distance;
        bool at_SCE;

        std::string tailNumber;
        std::string origin;
        std::string destination;
        std::map<std::string, std::map<std::string, int >  > flights;

    public:
        // Constructor
        Plane(const std::string& from, const std::string& to) : pos(0.0), vel(0.0), distance(0.0), at_SCE(true) {
            // Initialize flights ( Question 2)
            flights["SCE"]["PHL"] = 160;
            flights["SCE"]["ORD"] = 640;
            flights["SCE"]["EWR"] = 220;

            origin = from;
            destination = to;
            distance = flights[from][to]; // Distance between origin and destination airports
            std::cout << "Plane Created with this tail number " << this << std::endl; // Print memory address of the created plane
        }

        Plane(const std::string& tailNum) : tailNumber(tailNum), at_SCE(true) {} // New

        // Destructor
        ~Plane() 
        {
            //std::cout << "Plane Destroyed" << std::endl;
        }

        // Getter and setter functions
        double getPos() const { return pos; }
        void setPos(double newPos) { pos = newPos; }

        double getVel() const { return vel; }
        void setVel(double newVel) { vel = newVel; }

        double getDistance() const { return distance; }

        bool getAtSCE() const { return at_SCE; }

        void setAtSCE(bool atSce) { at_SCE = atSce; }

        std::string getTailNumber() const { return tailNumber; }

        std::string getOrigin() const { return origin; }

        std::string getDestination() const { return destination; }

        // Operate function
        void operate(double dt) 
        {
            // Ensure time-related variables are non-negative
            if (dt < 0)
            {
                dt = 0;
            }

            // Flow Chart logic
            if (pos < distance)
            {
                pos += vel * dt;
                at_SCE = 0;
            }
            else
            {
                if (destination == "SCE")
                {
                    at_SCE = 1;
                    pos =0.0;
                    std::string temp1 = origin;
                    origin = destination;
                    destination = temp1;
                }
                else 
                {
                    std::string temp2 = origin;
                    origin = destination;
                    destination = temp2;
                }
                pos = 0.0;
            }
        }
};

class Pilot 
{
    private:
        std::string name;
        
    public:
    // Constructor
        Pilot(std::string name)
        {
            this->name = name;
            std::cout << "Pilot " << name << " with certificate  number " << this << " is at the gate, and ready to board the plane." << std::endl;
        }

        // Deconstructor
        ~Pilot()
        {
            std::cout << "Pilot " << name << " is out of the plane." << std::endl;
        }

        // Asking for name:
        std::string getName() const
        {
        return name;
        }

        Plane* myPlane;
};

void swap(Pilot*& pilot, Pilot*& copilot)
{
    std::swap(pilot->myPlane, copilot->myPlane);
    std::swap(pilot, copilot);
};

int main() 
{
    std::cout << "########################################### Question 1 ###########################################" << std::endl;
    double totalWeight = 0, cgLocation = 0;
    Question1(totalWeight, cgLocation);

    for (int i = 0; i < 3; ++i) 
    {
        std::cout << std::endl; // Space 
    }

    // Questions 5: 
    std::cout << "########################################### Question 2 - 5 ###########################################" << std::endl;
    Plane plane("SCE", "ORD");
    plane.setPos(0.0);
    
    plane.setVel(410); // Picking a random velocity between 400 and 500 mph
    double dt = 30; // Picking a random number of time steps between 10 and 100 mph
    dt = dt/ 3600; 
    int maxNumIterations = 1800; // Picking a random of iterations that we will run between 1000 and 2000 mph
    
    // Printing out the data of the flight in it's timesteps:
    for (int iter = 0; iter <= maxNumIterations; ++iter) 
    {    
        std::cout << "Time: " << dt * 3600 * iter << " seconds, Position: " << plane.getPos() << " miles.\n";
        plane.operate(dt);        
    }

    for (int i = 0; i < 3; ++i) 
    {
        std::cout << std::endl; // Space
    }

    // Problem 7 - Old Pointers
    std::cout << "########################################### Question 5 - 7 ###########################################" << std::endl;
    
    Pilot* pilot = new Pilot("Alpha");
    Pilot* copilot = new Pilot("Bata");
    Plane plane1("SCE", "ORD");


    // Simulation loop
    for (int iter = 0; iter <= maxNumIterations; ++iter) 
    {
        plane.operate(dt);
        
        
        if (iter == 0)
        {
            std::cout << "The plane " << &plane << " is at SCE" << std::endl;
            std::cout << "Pilot " << pilot->getName() << " with certificate number " << pilot << " is in controle of the plane: "<< &plane << std::endl;
            std::cout << "Pilot " << copilot->getName() << " with certificate number " << copilot << " is in controle of the plane: "<< &plane << std::endl;
            std::cout << std::endl;
        }

        if (plane.getAtSCE())
        {
            std::cout << "The plane " << &plane << " is at SCE" << std::endl;
            std::swap(pilot, copilot);
            std::cout << "Pilot " << pilot->getName() << " with certificate number " << pilot << " is in controle of the plane: "<< &plane << std::endl;
            std::cout << "Pilot " << copilot->getName() << " with certificate number " << copilot << " is in controle of the plane: "<< &plane << std::endl;
            std::cout << std::endl;
        }   

        
    }

    std::cout << "Plane Destroyed" << std::endl;
    delete pilot;
    delete copilot;
    
    
    // Print out line spacing
    for (int i = 0; i < 3; ++i) 
    {
        std::cout << std::endl; // Space
    }

    // Question 8 - New Pointers
    std::cout << "########################################### Question 8 ###########################################" << std::endl;
    
    std::shared_ptr<Pilotnew> pilotnew = std:: make_shared<Pilotnew>("AlphaNew");
    std::shared_ptr<Pilotnew> copilotnew = std:: make_shared<Pilotnew>("BataNew");

    std::shared_ptr<Planenew> planenew = std::make_shared<Planenew>("SCE", "ORD");


    // Simulation loop
    for (int iter = 0; iter <= maxNumIterations; ++iter) 
    {
        plane.operate(dt);
        
        
        if (iter == 0)
        {
            std::cout << "The plane " << planenew.get() << " is at SCE" << std::endl;
            std::cout << "Pilot " << pilotnew->getName() << " with certificate number " << pilotnew.get() << " is in controle of the plane: "<< planenew.get() << std::endl;
            std::cout << "Pilot " << copilotnew->getName() << " with certificate number " << copilotnew.get() << " is in controle of the plane: "<< planenew.get() << std::endl;
            std::cout << std::endl;
        }

        if (plane.getAtSCE())
        {
            std::cout << "The plane " << planenew.get() << " is at SCE" << std::endl;
            std::swap(pilotnew, copilotnew);
            std::cout << "Pilot " << pilotnew->getName() << " with certificate number " << pilotnew.get() << " is in controle of the plane: "<< planenew.get() << std::endl;
            std::cout << "Pilot " << copilotnew->getName() << " with certificate number " << copilotnew.get() << " is in controle of the plane: "<< planenew.get() << std::endl;
            std::cout << std::endl;
        }   
    }
    
    return 0;
}