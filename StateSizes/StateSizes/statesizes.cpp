#include<iostream>
#include<string>

using std::cout;
using std::cin;
//function declaration
void single(int num, int size[], char name[50][20]);
void print(std::string states[]);

int main(void) {
	//land area of all states- Probably Delete?
	int alaska = 571951, texas = 261797, california = 155959, montana = 145552, newmexico = 121355, arizona = 113634, nevada = 109825,
		colorado = 103717, wyoming = 97100, oregon = 95996, idaho = 82747, utah = 82143, kansas = 81814, minnesota = 79610,
		nebraska = 76872, sdakota = 75884, ndakota = 68975, missouri = 68885, oklahoma = 68667, washington = 66544, georgia = 57906,
		michigan = 56803, iowa = 55869, illinois = 55583, wisconsin = 54310, florida = 53926, arkansas = 52068, alabama = 50744,
		ncarolina = 48710, newyork = 47213, mississippi = 46906, pennsylvania = 44816, louisiana = 43561, tennessee = 41217,
		ohio = 40948, kentucky = 39728, virginia = 39594, indiana = 35866, maine = 30861, scarolina = 30109, wvirginia = 24077,
		maryland = 9773, vermont = 9249, nhanpshire = 8968, massachusetts = 7840, newjersey = 7417, hawaii = 6422, connecticut = 4844,
		delaware = 1953, rhodeisland = 1044;
	//arrays of states by size and by name
	int stateSize[50] = {571951, 261797, 155959, 145552, 121355, 113634, 109825, 103717, 97100, 95996, 82747, 82143, 81814, 79610,
		76872, 75884, 68975, 68885, 68667, 66544, 57906, 56803, 55869, 55583, 54310, 53926, 52068, 50744, 48710, 47213, 46906, 44816, 43561, 41217,
		40948, 39728, 39594, 35866, 30861, 30109, 24077, 9773, 9249, 8968, 7840, 7417, 6422, 4844, 1953, 1044};

	char stateName[50][20] = {"Alaska", "Texas", "California", "Montana", "New Mexico", "Arizona", "Nevada", "Colorado", "Wyoming", "Oregon", "Idaho",
		"Utah", "Kansas", "Minnesota", "Nebraska", "South Dakota", "North Dakota", "Missouri", "Oklahoma", "Washington", "Georgia", "Michigan", "Iowa", 
		"Illinois", "Wisconsin", "Florida", "Arkansas", "Alabama", "North Carolina", "New York", "Mississippi", "Pennsylvania", "Louisiana", "Tennessee", 
		"Ohio", "Kentucky", "Virginia", "Indiana", "Maine", "South Carolina", "West Virginia", "Maryland", "Vermont", "New Hanpshire", "Massachusetts", 
		"New Jersey", "Hawaii", "Connecticut", "Delaware", "Rhode Island"};

	int usrInp, usrChoice;
	//greedy algorithm where states can be in multiple (3 texases and one newjersey)
	cout << "What is the area of your space (in mi)? ";
	cin >> usrInp;
	//make another where each state is unique (texas, florida, connecticut)
	single(usrInp, stateSize, stateName);
	//state how many sq miles are left over
	//create an introduction
}

void print(std::string states[]) {
	int length = 0, i;
	for (i = 0; i < 50; i++) {
		if (states[i] != "NULL")
			length++;
	}
	if (length == 0)
		cout << "Your area is smaller than the smallest US state.";
	else if (length == 1)
		cout << "The area is the size of " << states[0] << ".";
	else if (length == 2)
		cout << "The area is the size of " << states[0] << "and " << states[1] << ".";
	else if (length > 2) {
		cout << "The area is the size of ";
		for (i = 0; i < length - 1; i++)
			cout << states[i] << ", ";
		cout << "and " << states[length - 1] << ".";
	}
}

void single(int num, int size[], char name[50][20]) {
	int total = num;
	int i = 0, k;
	std::string list[50];
	for (k = 0; k < 50; k++){
		list[k] = "NULL";
	}
	k = 0;
	while (i < 50) {
		if (size[i] <= total) {
			list[k] = name[i];
			total = total - size[i];
			k++;
		}
		i++;
	}
	print(list);
	cout << "\n(With " << total << "mi left over)";
}