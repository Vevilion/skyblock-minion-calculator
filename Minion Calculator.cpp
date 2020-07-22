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
	
	int fuelTypes[] = {0, 5, 10, 20, 5, 25, 25, 90, 50, 0};
	int upgradeTypes[] = {0, 0, 5, 25, 0};
	int diamondChance[] = {10, 10};
	float itemPerSecond = 1.0;
	float minionExpander = 1.0;
	float _fuel = 1.0;
	float flyCatcher = 1.0;
	float fuel = 1.0;
	float cat = 1.0;
	float spreading = 1.0;
	float itemPerHour;
	float itemPerDay;
	float itemPerWeek;
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
	cout << "Enter Items Per Action (0.5 if 1 item): ";
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
	cout << "1st Minion Upgrade" << endl;
	cout << "(1) Diamond Spreading [WIP]" << endl;
	cout << "(2) Minion Expander" << endl;
	cout << "(3) Fly Catcher" << endl;
	cout << "(4) None" << endl;
	cout << "Enter 1st Upgrade: ";
	cin >> upgradeOne;
	
	//Upgrade 2
	int upgradeTwo;
	cout << "-----------------" << endl;
	cout << "2nd Minion Upgrade" << endl;
	cout << "(1) Diamond Spreading [WIP]" << endl;
	cout << "(2) Minion Expander" << endl;
	cout << "(3) Fly Catcher" << endl;
	cout << "(4) None" << endl;
	cout << "Enter 2nd Upgrade: "; 
	cin >> upgradeTwo;
	
	//Bonus
	float bonus;
	cout << "-----------------" << endl;
	cout << "Enter any other bonuses. (Type 0 if none): ";
	cin >> bonus; 
	
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
			fuel = timePerAction * (1 - ((fuelTypes[fuelType] / 100.0) / (1 + (fuelTypes[fuelType] / 100.0))));
			//fuel = ((100 - fuelTypes[fuelType]) / 100.0) * timePerAction; //%5
			cat = itemPerAction;
		
			break;
		}
		case 2:
		{	
			//eCoal
			fuel = timePerAction * (1 - ((fuelTypes[fuelType] / 100.0) / (1 + (fuelTypes[fuelType] / 100.0))));
			cat = itemPerAction;
			
			break;
		}
		case 3:
		{	
			//eCharcoal
			fuel = timePerAction * (1 - ((fuelTypes[fuelType] / 100.0) / (1 + (fuelTypes[fuelType] / 100.0))));
			cat = itemPerAction;
			
			break;
			
		}
		case 4:
		{
			//eBread
			fuel = timePerAction * (1 - ((fuelTypes[fuelType] / 100.0) / (1 + (fuelTypes[fuelType] / 100.0))));
			cat = itemPerAction;

			break;
		}
		case 5:
		{
			//solar
			fuel = timePerAction * (1 - ((fuelTypes[fuelType] / 100.0) / (1 + (fuelTypes[fuelType] / 100.0))));
			cat = itemPerAction;
	
			break;
		}
		case 6:
		{
			//lavaBucket
			fuel = timePerAction * (1 - ((fuelTypes[fuelType] / 100.0) / (1 + (fuelTypes[fuelType] / 100.0))));
			cat = itemPerAction;
	
			break;
		}
		case 7:
		{
			//foulFlesh
			fuel = timePerAction * (1 - ((fuelTypes[fuelType] / 100.0) / (1 + (fuelTypes[fuelType] / 100.0))));
			cat = itemPerAction;
		
			break;
		}
		case 8:
		{
			//hamsterWheel
			fuel = timePerAction * (1 - ((fuelTypes[fuelType] / 100.0) / (1 + (fuelTypes[fuelType] / 100.0))));
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
				//WIP
				fuel = timePerAction + fuelTypes[fuelType];
				break;
			}
		case 2:
			{	
				//minion expander
				fuel = timePerAction * (1 - (((fuelTypes[fuelType] + upgradeTypes[upgradeOne]) / 100.0) / (1 + ((fuelTypes[fuelType] + upgradeTypes[upgradeOne]) / 100.0))));
				break;
			}
		case 3:
			{
				//flyCatcher
				fuel = timePerAction * (1 - (((fuelTypes[fuelType] + upgradeTypes[upgradeOne]) / 100.0) / (1 + ((fuelTypes[fuelType] + upgradeTypes[upgradeOne]) / 100.0)))); 
				break;
			}
		case 4:
			{
				fuel = timePerAction * (1 - ((fuelTypes[fuelType] / 100.0) / (1 + (fuelTypes[fuelType] / 100.0))));
				break;
			}
	}
	
	switch(upgradeTwo){
		case 1:
			{
				//WIP
				fuel = timePerAction + fuelTypes[fuelType];
				break;
			}
		case 2:
			{	
				//minion expander
				fuel = timePerAction * (1 - (((fuelTypes[fuelType] + upgradeTypes[upgradeOne] + upgradeTypes[upgradeTwo]) / 100.0) / (1 + ((fuelTypes[fuelType] + upgradeTypes[upgradeOne]) / 100.0))));
			
				break;
			}
		case 3:
			{
				//flyCatcher
				fuel = timePerAction * (1 - (((fuelTypes[fuelType] + upgradeTypes[upgradeOne] + upgradeTypes[upgradeTwo]) / 100.0) / (1 + ((fuelTypes[fuelType] + upgradeTypes[upgradeOne] + upgradeTypes[upgradeTwo]) / 100.0)))); 
		
				break;
			}
		case 4:
			{
				fuel = timePerAction * (1 - (((fuelTypes[fuelType] + upgradeTypes[upgradeOne]) / 100.0) / (1 + ((fuelTypes[fuelType] + upgradeTypes[upgradeOne]) / 100.0))));
				break;
			}
	}
	
	if(bonus > 0){
		fuel = timePerAction * (1 - (((fuelTypes[fuelType] + upgradeTypes[upgradeOne] + upgradeTypes[upgradeTwo] + bonus) / 100.0) / (1 + ((fuelTypes[fuelType] + upgradeTypes[upgradeOne] + upgradeTypes[upgradeTwo] + bonus) / 100.0)))); 
	} else {
		fuel = timePerAction * (1 - (((fuelTypes[fuelType] + upgradeTypes[upgradeOne] + upgradeTypes[upgradeTwo]) / 100.0) / (1 + ((fuelTypes[fuelType] + upgradeTypes[upgradeOne]) / 100.0))));
	}

	
	system("CLS");
	
	itemPerSecond = (fuel / cat);
	itemPerMinute = 60 / itemPerSecond;
	unitPricePerMinute = (itemPerMinute * unitPrice) * minionSlots;
	unitPricePerHour = (60 * (itemPerMinute * unitPrice)) * minionSlots; 
	unitPricePerDay = (24 * (60 * (itemPerMinute * unitPrice))) * minionSlots;
	unitPricePerWeek = (7 * (24 * (60 * (itemPerMinute * unitPrice)))) * minionSlots;
	
	itemPerHour = (itemPerMinute * minionSlots) * 60;
	itemPerDay = itemPerHour * 24;
	itemPerWeek = itemPerDay * 7;
	
	//Result
	cout << fixed;
	cout << setprecision(1);
	cout.imbue(locale(cout.getloc(), new comma));
	//cout << "Minute: " << unitPricePerMinute << " Coins.";
	cout << "Coins per:" << endl;
	cout << "Hour: " << unitPricePerHour << endl;
	cout << "Day: "<< unitPricePerDay << endl;
	cout << "Week: "<< unitPricePerWeek << endl;
	
	cout << "-----------------" << endl;
	cout << "Items per:" << endl;
	cout << "Hour: " << itemPerHour << endl;
	cout << "Day: " << itemPerDay << endl;
	cout << "Week: " << itemPerWeek << endl;
	cout << "\n";
	
	system("PAUSE");
}
