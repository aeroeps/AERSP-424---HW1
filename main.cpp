# include <iostream>
#include <map>
#include <string>
# include <cmath>

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

    /*
    std::cout << "Enter the airplanes empty weight (Pounds): ";
    std:: cin >> emptyWeight;

    std::cout << "Enter airplane empty weight moment (pounds-inches): ";
    std::cin >> emptyWeightMoment;

    // Frount Seat Data
    std::cout << "Enter the number of frount seat occupants: ";
    std::cin >> numberFrontSeatOcc;

    std::cout << "Enter the weight of each of the frount seat occupents (pounds)" << std::endl;
    int FSeatWeight[numberFrontSeatOcc]; // this will set up the array for number of frount seat passengers
    for (int i =1; i<numberFrontSeatOcc+1; i++)
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
    for (int i =1; i<numberRearSeatOcc+1; i++)
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

    */

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
    numberofGalofFuel = 30.000;
    fuelWeightPerGallon = 6;
    fuelMomentArm = 75;
    bagWeight = 10;
    bagMomentArm = 140;

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

        std::string origin;
        std::string destination;
        std::map<std::string, std::map<std::string, int >  > flights;

    public:
        // Constructor
        Plane(const std::string& from, const std::string& to) : pos(0.0), vel(0.0), distance(0.0), at_SCE(true) {
            // Initialize flights (taken from Question 2)
            flights[from][to] = 160;
            flights[from]["ORD"] = 640;
            flights[from]["EWR"] = 220;

            flights[to][from] = 160; // Reverse mapping for PHL
            flights["ORD"][from] = 640; // Reverse mapping for ORD
            flights["EWR"][from] = 220; // Reverse mapping for EWR

            origin = from;
            destination = to;
            distance = flights[from][to]; // Distance between origin and destination airports
            std::cout << "Plane Created at " << this << std::endl; // Print memory address of the created plane
        }

        // Destructor
        ~Plane() 
        {
            std::cout << "Plane Destroyed" << std::endl;
        }

        // Getter and setter functions
        double getPos() const { return pos; }
        void setPos(double newPos) { pos = newPos; }

        double getVel() const { return vel; }
        void setVel(double newVel) { vel = newVel; }

        double getDistance() const { return distance; }

        bool getAtSCE() const { return at_SCE; }

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

            // Flow Chart
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

int main() 
{
    std::cout << "########################################### Question 1 ###########################################" << std::endl;
    double totalWeight = 0, cgLocation = 0;
    Question1(totalWeight, cgLocation);


    // Questions 5: 
    std::cout << "########################################### Question 5 ###########################################" << std::endl;
    Plane plane("SCE", "ORD");
    // Picking a random velocity between 400 and 500 mph
    plane.setVel(425);
    double dt = 50;
    dt = dt/ 3600;
    int maxNumIterations = 1200;
    
    double time = 0.0; // This is so that we can print out the time
    // Printing out the data of the flight in it's timesteps:
    for (int iter = 0; iter <= maxNumIterations; ++iter) 
    {
        plane.operate(dt);
        std::cout << "Time: " << dt*3600*iter << " seconds, Position: " << plane.getPos() << " miles." << std::endl;
    }

    return 0;
}