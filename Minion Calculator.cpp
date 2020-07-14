#include <iostream>
#include <locale>
#include <iomanip>
using namespace std;

	struct comma : numpunct<char>
{
    string do_grouping() const { return "\3"; }
};

int main() {
	
	cout << "#######################\n";
	cout << "#                     #\n";
	cout << "#  Minion Calculator  #\n";
	cout << "#    Made by Vevy     #\n";
	cout << "#                     #\n";
	cout << "#######################\n\n";
	
	int fuelTypes[] = {0, 5, 10, 20, 5, 25, 25, 90, 50};
	int upgradeTypes[] = {0, 0, 5, 25};
	float itemPerSecond = 1.0;
	float minionExpander = 1.0;
	float _fuel = 1.0;
	float flyCatcher = 1.0;
	float fuel = 1.0;
	float cat = 1.0;
	float itemPerMinute;
 	float unitPricePerMinute;
	float unitPricePerHour;
	float unitPricePerDay;
	float unitPricePerWeek;
	
	
	//Time
	float timePerAction;
	cout << "Enter Time Between Actions: ";
	cin >> timePerAction;
	
	//Items
	float itemPerAction;
	cout << "-----------------" << endl;;
	cout << "Enter Items Per Action (0.5 if 1 item, 1 if 2 items, etc..): ";
	cin >> itemPerAction;
		
	//Price
	float unitPrice;
	cout << "-----------------" << endl;
	cout << "Enter Unit Price: ";
	cin >> unitPrice;
	
	
	//Fuel
	int fuelType;
	cout << "-----------------" << endl;
	cout << "Fuel Types" << endl;
	cout << "(1) Coal/Block of Coal" << endl;
	cout << "(2) E-Coal" << endl;
	cout <<	"(3) E-Charcoal" << endl;
	cout <<	"(4) E-Bread" << endl;
	cout << "(5) Solar Panel" << endl;
	cout <<	"(6) E-Lava bucket" << endl;
	cout <<	"(7) Foul Flesh" << endl;
	cout <<	"(8) Hamster Wheel" << endl;
	cout <<	"(9) Catalyst" << endl;
	cout <<	"(0) None" << endl;
	cout << "Enter Fuel: ";
	cin >> fuelType;
	
	//Upgrade 1
	int upgradeOne;
	cout << "-----------------" << endl;
	cout << "Enter 1st Upgrade" << endl;
	cout << "(1) Diamond Spreading [WIP]" << endl;
	cout << "(2) Minion Expander" << endl;
	cout << "(3) Fly Catcher" << endl;
	cout << "(4) None" << endl;
	cout << "Enter 1st Upgrade: ";
	cin >> upgradeOne;
	
	//Upgrade 2
	int upgradeTwo;
	cout << "-----------------" << endl;
	cout << "Enter 2nd Upgrade" << endl;
	cout << "(1) Diamond Spreading [WIP]" << endl;
	cout << "(2) Minion Expander" << endl;
	cout << "(3) Fly Catcher" << endl;
	cout << "(4) None" << endl;
	cout << "Enter 2nd Upgrade: "; 
	cin >> upgradeTwo;
	
	//Minion Slots
	int minionSlots;
	cout << "-----------------" << endl;
	cout << "Enter Minion Slots: ";
	cin >> minionSlots;
	
	
	
	//Fuel
	switch(fuelType){
		case 1:
		{
			//coal
			fuel = ((100 - fuelTypes[fuelType]) / 100.0) * timePerAction; //%5
			cat = itemPerAction;
		
			break;
		}
		case 2:
		{	
			//eCoal
			fuel = ((100 - fuelTypes[fuelType]) / 100.0) * timePerAction;
			cat = itemPerAction;
			
			break;
		}
		case 3:
		{	
			//eCharcoal
			fuel = ((100 - fuelTypes[fuelType]) / 100.0) * timePerAction;
			cat = itemPerAction;
			
			break;
			
		}
		case 4:
		{
			//eBread
			fuel = ((100 - fuelTypes[fuelType]) / 100.0) * timePerAction;
			cat = itemPerAction;

			break;
		}
		case 5:
		{
			//solar
			fuel = ((100 - fuelTypes[fuelType]) / 100.0) * timePerAction;
			cat = itemPerAction;
	
			break;
		}
		case 6:
		{
			//lavaBucket
			fuel = ((100 - fuelTypes[fuelType]) / 100.0) * timePerAction;
			cat = itemPerAction;
		
			break;
		}
		case 7:
		{
			//foulFlesh
			fuel = ((100 - fuelTypes[fuelType]) / 100.0) * timePerAction;
			cat = itemPerAction;
		
			break;
		}
		case 8:
		{
			//hamsterWheel
			fuel = ((100 - fuelTypes[fuelType]) / 100.0) * timePerAction;
			cat = itemPerAction;
		
			break;
		}
		case 9:
		{
			//catalyst
			cat = 3 * itemPerAction;
			
			break;
		}
		case 0:
		{
			//none
			fuel = timePerAction + fuelTypes[0];
			cat = itemPerAction;
			
			break;
		}
			default:
				cout << "Something went wrong!";
	} 
	
	switch(upgradeOne){
		case 1:
			{
				fuel = timePerAction + fuelTypes[0];
				break;
			}
		case 2:
			{	
				//minion expander
				fuel = ((100 - (fuelTypes[fuelType] + upgradeTypes[upgradeOne])) / 100.0) * timePerAction;
			
				break;
			}
		case 3:
			{
				//flyCatcher
				fuel = ((100 - (fuelTypes[fuelType] + upgradeTypes[upgradeOne])) / 100.0) * timePerAction; 
				break;
			}
		case 4:
			{
				fuel = timePerAction + fuelTypes[0];
				break;
			}
	}
	
	switch(upgradeTwo){
		case 1:
			{
				fuel = timePerAction + fuelTypes[0];
				break;
			}
		case 2:
			{	
				//minion expander
				fuel = ((100 - (fuelTypes[fuelType] + upgradeTypes[upgradeOne] + 5)) / 100.0) * timePerAction; //15%
			
				break;
			}
		case 3:
			{
				//flyCatcher
				fuel = ((100 - (fuelTypes[fuelType] + upgradeTypes[upgradeOne] + 25)) / 100.0) * timePerAction; 
		
				break;
			}
		case 4:
			{
				fuel = timePerAction + fuelTypes[0];
				break;
			}
	}

	
	system("CLS");
	
	itemPerSecond = (fuel / cat);
	itemPerMinute = 60 / itemPerSecond;
	unitPricePerMinute = (itemPerMinute * unitPrice) * minionSlots;
	unitPricePerHour = (60 * (itemPerMinute * unitPrice)) * minionSlots; 
	unitPricePerDay = (24 * (60 * (itemPerMinute * unitPrice))) * minionSlots;
	unitPricePerWeek = (7 * (24 * (60 * (itemPerMinute * unitPrice)))) * minionSlots;
	
	//Result
	cout << fixed;
	cout << setprecision(1);
	cout.imbue(locale(cout.getloc(), new comma));
	//cout << "Minute: " << unitPricePerMinute << " Coins.";
	cout << "Hour: " << unitPricePerHour << " Coins.";
	cout << "\nDay: "<< unitPricePerDay << " Coins.";
	cout << "\nWeek: "<< unitPricePerWeek << " Coins." << endl;
	
	system("PAUSE");
}