#include <iostream>

using namespace std;

class Transportation{
	
	protected:
	
		float Cargo_Weight;
		float Distance_Roat;
		float Initial_fuel_load;
		float Fuel_consumption;
		float Required_fuel_trip;
	
	public:
		
		virtual void checkAvailability() = 0;
	
		friend istream &operator >> (istream &input,Transportation &obj){
			
			cout<<"	Enter the weight of the cargo: ";
			input>>obj.Cargo_Weight;
			
			cout<<"	Enter the travel distance: ";
			input>>obj.Distance_Roat;
			
			return input;
		}
		
		
};

class Ship : public Transportation{
	
	//Each 1 Ton of weight increases the fuel consumption for the vehicles as follows:
	
	//Fuel consumption for the ship is increased by 0.50.
	//Fuel consumption for the truck is increased by 1.00.
	
	float Increased_fuel_consumption_rate;
	
	public:
		
		Ship(){
				
			cout<<"	A cargo ship is on hold for current transportation"<<endl;
			
			cout<<"	Enter the amount for initial fuel: ";
			cin>>Initial_fuel_load;
			
			cout<<endl;
			
			Fuel_consumption = 60;
			
			Increased_fuel_consumption_rate = 0.50;
		}
		
		void checkAvailability(){
		
			float Total = (Cargo_Weight*(Increased_fuel_consumption_rate) + Fuel_consumption)*(Distance_Roat/100);
			
			if(Total <= Initial_fuel_load){
				
				cout<<endl;
				cout<<"	Sufficient amount of fuel in truck."<<endl;
				cout<<"	Transportation truck can reach to destination in single trip."<<endl;
			}
			
			else{
				
				Required_fuel_trip = Total - Initial_fuel_load;
				
				cout<<endl;
				cout<<"	Transportation Ship needs to refuel at the harbor\n";
				cout<<"	Need to refuel "<<Required_fuel_trip<<" L more."<<endl;
				
			}
			
		}
		
	
};

class Truck : public Transportation{
	
	//Each 1 Ton of weight increases the fuel consumption for the vehicles as follows:
	
	//Fuel consumption for the ship is increased by 0.50.
	//Fuel consumption for the truck is increased by 1.00.

	
	float Increased_fuel_consumption_rate;
	
	public:
		
		Truck(){
			
			cout<<"	A truck is on hold for current transportation"<<endl;
			
			cout<<"	Enter the amount for initial fuel: ";
			cin>>Initial_fuel_load;
			
			cout<<endl;
			
			Fuel_consumption = 30;
			
			Increased_fuel_consumption_rate = 1;
		}
		
		void checkAvailability(){
			
			float Total = (Cargo_Weight*(Increased_fuel_consumption_rate) + Fuel_consumption)*(Distance_Roat/100);
			
			if(Total <= Initial_fuel_load){
				
				cout<<endl;
				cout<<"	Sufficient amount of fuel in truck."<<endl;
				cout<<"	Transportation truck can reach to destination in single trip."<<endl;
			}
			
			else{
				
				Required_fuel_trip = Total - Initial_fuel_load;
				
				cout<<endl;
				cout<<"	Transportation Truck needs to refuel at the station\n";
				cout<<"	Need to refuel "<<Required_fuel_trip<<" L more."<<endl;
				
			}
			
		}
		
};


int main(){
	
	cout<<"		Please enter required inforamtion for the transportation of goods."<<endl;
	cout<<endl;
	
	Ship s;
	cin>>s;
	
	s.checkAvailability();
	
	cout<<endl;
	
	Truck t;
	cin>>t;
	
	t.checkAvailability();
	
	return 0;
}
