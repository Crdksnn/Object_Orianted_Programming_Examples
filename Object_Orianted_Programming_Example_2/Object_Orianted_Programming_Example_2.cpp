#include <iostream>

using namespace std;

class Flight{
	
	private:
		
		string FlightName;
		int LaunchHour;
		int LaunchMin;
		int LandHour;
		int LandMin;
		int Duration;
		string State;
		
	public:
			
		Flight(){
			
			cout<<"Enter the name of the flight: ";
			cin>>FlightName;
			cout<<"Enter the departure time of the plane: ";
			cin>>LaunchHour>>LaunchMin;
			cout<<"Enter the duration of the flight in minutes: ";
			cin>>Duration;
			State = "IDLE";
			cout<<endl;
			cout<<endl;
			
			calculateLanding();
		}
		
		int getLaunchHour(){
			
			return LaunchHour;
		}
		
		int getLaunchMin(){
			
			return LaunchMin;
		}
	
		int getLandHour(){
			
			return LandHour;
		}
		
		int getLandMin(){
			
			return LandMin;
		}
	
		string getState(){
			
			return State;
		}
		
		string getName(){
			
			return FlightName;
		}
		
		void setState(string State){
			
			this->State = State;
		}
		
		void calculateLanding(){
			
			int count = 0;
			int Temp_Duration = Duration;
			
			while(60<=Temp_Duration){
				
				Temp_Duration = Temp_Duration - 60;
				count++;
			}
			
			LandMin = LaunchMin + Temp_Duration;
			
			if(60<=LandMin){
				LandMin = LandMin % 60;
				count++;
			}
			
			LandHour = LaunchHour + count;
			
		}
};

class FligthSchedule{
	
	public:
	
	Flight flights[3];	
	
	//method(type) type
	void sorting(string key){
		
		if(key == "launch"){
			
			int j;
		
		for(int i=0;i<3;i++){
			
			j = i+1;
			
			for(;j<3;j++){
				
				if(flights[j].getLaunchHour()<flights[i].getLaunchHour()){
					
					Flight temp = flights[i];
					flights[i] = flights[j];
					flights[j] = temp;
				}
				
				if(flights[i].getLaunchHour()==flights[j].getLaunchHour()){
					
					if(flights[j].getLaunchMin()<flights[i].getLaunchMin()){
						
						Flight temp = flights[j];
						flights[j] = flights[i];
						flights[i] = temp;
					}
					
				}
				
			}
			
			for(int i=0;i<3;i++){
			
			if(flights[i].getLaunchHour()==flights[i+1].getLaunchHour()){
				if(flights[i].getLaunchMin()==flights[i+1].getLaunchMin()){
					
					flights[i+2].setState("DELAYED");
				}
			}
			
		}
			
		}
			
		}
		
		if(key == "land"){
			
			int j;
		
		for(int i=0;i<3;i++){
			
			j = i+1;
			
			for(;j<3;j++){
				
				if(flights[j].getLandHour()<flights[i].getLandHour()){
					
					Flight temp = flights[i];
					flights[i] = flights[j];
					flights[j] = temp;
				}
				
				if(flights[i].getLandHour()==flights[j].getLandHour()){
					
					if(flights[j].getLandMin()<flights[i].getLandMin()){
						
						Flight temp = flights[j];
						flights[j] = flights[i];
						flights[i] = temp;
					}
					
				}
				
			}
			
		}
		
		for(int i=0;i<3;i++){
			
			if(flights[i].getLandHour()==flights[i+1].getLandHour()){
				if(flights[i].getLandMin()==flights[i+1].getLandMin()){
					
					flights[i+2].setState("DELAYED");
				}
			}
			
		}
		
		}
		
	}
	
};

class LaunchController{
	
	private:
		
		int launchHour1;
		int launchHour2;
		int launchMin1;
		int launchMin2;
		
	public:
		
		void launchSchedule(FligthSchedule* flights){
			
			flights->sorting("launch");
			
			cout<<"Launch Order"<<endl;
			for(int i=0;i<3;i++){
				
				cout<<flights->flights[i].getName()<<" Launch at "<<flights->flights[i].getLaunchHour()<<" : "<<flights->flights[i].getLaunchMin()<<" Flight State: "<<flights->flights[i].getState()<<endl;
			}
			
		}
};

class LandingController{
	
	private:
		
		int landHour1;
		int landHour2;
		int landMin1;
		int landMin2;
	
	public:
		
		void landingSchedule(FligthSchedule* flights){
			
			flights->sorting("land");
			
			cout<<endl;
			cout<<"Land Order"<<endl;
			for(int i=0;i<3;i++){
				
				cout<<flights->flights[i].getName()<<" Launch at "<<flights->flights[i].getLandHour()<<" : "<<flights->flights[i].getLandMin()<<" Flight State: "<<flights->flights[i].getState()<<endl;
				
			}
			
		}
	
};

class FlightController: public LandingController,public LaunchController{
	
	protected:
		
		FligthSchedule flight_schedule;
		
	public:
		
		FligthSchedule* flights;
		
		FlightController(){
			
		flights = &flight_schedule;
		
		launchSchedule(flights);
		landingSchedule(flights);
		}
			
};

int main(){
	
	FlightController f;
	
	return 0;
}
