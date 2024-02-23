#include <iostream>
#include <map>
#include <string>
#include <memory>


class Planenew 
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
        Planenew(const std::string& from, const std::string& to) : pos(0.0), vel(0.0), distance(0.0), at_SCE(true) {
            // Initialize flights ( Question 2)
            flights["SCE"]["PHL"] = 160;
            flights["SCE"]["ORD"] = 640;
            flights["SCE"]["EWR"] = 220;

            origin = from;
            destination = to;
            distance = flights[from][to]; // Distance between origin and destination airports
            std::cout << "Plane Created with this tail number " << this << std::endl; // Print memory address of the created plane
        }

        Planenew(const std::string& tailNum) : tailNumber(tailNum), at_SCE(true) {} // New

        // Destructor
        ~Planenew() 
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

class Pilotnew 
{
    private:
        std::string namenew;
        
    public:
    // Constructor
        Pilotnew(std::string namenew)
        {
            this->namenew = namenew;
            std::cout << "Pilot " << namenew << " with certificate  number " << this << " is at the gate, and ready to board the plane." << std::endl;
        }

        // Deconstructor
        ~Pilotnew()
        {
            std::cout << "Pilot " << namenew << " is out of the plane." << std::endl;
        }

        // Asking for name:
        std::string getName() const
        {
        return namenew;
        }

        std::shared_ptr<Planenew> myPlanenew;
};

void swap(std::shared_ptr<Pilotnew> &pilotnew, std::shared_ptr<Pilotnew> &copilotnew )
{
    std::swap(pilotnew->myPlanenew, copilotnew->myPlanenew);
    std::swap(pilotnew, copilotnew);
};
