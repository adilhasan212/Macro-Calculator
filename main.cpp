#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include "MaleClass.h"
#include "FemaleClass.h"

using namespace std;

int main() {
	cout << "MACRO CALCULATOR" << endl << "----------------" << endl << "(Enter 0 to restart)" << endl << endl << endl;
	MaleClass maleGoal;
	FemaleClass femaleGoal;
	int age;
	double caloriesNeeded = 1, activityLevel = 0, weight, height, heightFeet, heightInches;
	char units, sex, method, activity;
	bool program = true;
	// In case of wrong input, program can restart
	while (program) {
		// Get all needed information
		cout << "What units would you like to use?" << endl << "A) Imperial" << setw(30) << "B) SI" << endl << endl;
		cin >> units;
		if (units != 'a' && units != 'A' && units != 'b' && units != 'B') {
			cout << endl << "Enter A or B" << endl << endl;
			continue;
		}
		cout << endl << "Are you male or female?" << endl << "A) Male" << setw(30) << "B) Female" << endl << endl;
		cin >> sex; cout << endl;
		if (sex != 'a' && sex != 'A' && sex != 'b' && sex != 'B') {
			cout << "Enter A or B" << endl << endl;
			continue;
		}
		cout << "How old are you?" << endl << endl; cin >> age; cout << endl;
		if (age < 4 || age > 150) {
			cout << "Enter a valid age" << endl << endl;
			continue;
		}
		cout << "Would you like to cut, bulk, or maintain?" << endl << "A) Cut" << setw(30) << "B) Bulk"
			<< setw(30) << "C) Maintain" << endl << endl;
		cin >> method; cout << endl << endl; 
		if (method != 'a' && method != 'A' && method != 'b' && method != 'B' && method != 'c' && method != 'C') {
			cout << "Enter A, B, or C" << endl << endl;
			continue;
		}
		cout << "How active are you?" << endl <<
			"A) Not Active" << setw(26) << "B) Light Activity" << setw(26) << "C) Moderate Activity" << setw(26)
			<< "D) Active" << setw(26) << "E) Very Active" << endl << endl;
		cin >> activity; cout << endl;
		if (activity != 'a' && activity != 'A' && activity != 'b' && activity != 'B' && activity != 'c' && activity != 'C' && activity != 'd' && activity != 'D' && activity != 'e' && activity != 'E') {
			cout << "Enter A, B, C, D or E" << endl << endl;
			continue;
		}

		// Get the multiplier, more activity = more calories needed
		if (activity == 'a' || activity == 'A') {
			activityLevel = 1.15;
		}
		else if (activity == 'b' || activity == 'B') {
			activityLevel = 1.3;
		}
		else if (activity == 'c' || activity == 'C') {
			activityLevel = 1.4;
		}
		else if (activity == 'd' || activity == 'D') {
			activityLevel = 1.6;
		}
		else if (activity == 'e' || activity == 'E') {
			activityLevel = 1.75;
		}

		// Male
		// Imperial
		if ((sex == 'a' || sex == 'A') && (units == 'a' || units == 'A')) {
			cout << "How tall are you?" << endl << endl; 
			cout << "Feet: "; cin >> heightFeet; cout << "Inches: "; cin >> heightInches; cout << endl << endl;
			if (heightFeet < 0 || heightFeet > 11 || heightInches < 0 || heightInches > 130) {
				cout << "Enter a valid height" << endl << endl;
				continue;
			}
			cout << "How much do you weigh? (lbs)" << endl << endl; cin >> weight;
			if (weight < 0 || weight > 1800) {
				cout << "Enter a valid weight" << endl << endl;
				continue;
			}
			caloriesNeeded = maleGoal.maleCalorieGoal(units, method, heightFeet, heightInches, weight, age, activityLevel);
			if (caloriesNeeded == 0) {
				cout << "INVALID INPUT" << endl << endl;
				continue;
			}
			cout << endl << endl;  cout << endl << 
				"-------------------------------------------------------------------------"
				<< endl << "Your daily intake should be " << round(caloriesNeeded) << " calories and " << 
				round(weight * 0.8) << " - " << round(weight) << " grams of protein." << endl; cout <<
				"-------------------------------------------------------------------------" << endl << endl;
			program = false;
		}
		// Male
		// SI
		else if ((sex == 'a' || sex == 'A') && units == 'b' || units == 'B') {
			cout << "How tall are you? (cm)" << endl << endl; cin >> height; cout << endl << endl;
			if (height < 0 || height > 300) {
				cout << "Enter a valid height" << endl << endl;
				continue;
			}
			cout << "How much do you weigh? (kgs)" << endl << endl; cin >> weight;
			if (weight < 0 || weight > 750) {
				cout << "Enter a valid weight" << endl << endl;
				continue;
			}
			caloriesNeeded = maleGoal.maleCalorieGoal(units, method, height, weight, age, activityLevel);
			if (caloriesNeeded == 0) {
				cout << "INVALID INPUT" << endl;
				continue;
			}
			cout << endl << endl;  cout << endl <<
				"-------------------------------------------------------------------------"
				<< endl << "Your daily intake should be " << round(caloriesNeeded) << " calories and " <<
				round((weight * 2.2) * 0.8) << " - " << round(weight * 2.2)  << " grams of protein." << endl; cout <<
				"-------------------------------------------------------------------------" << endl << endl;
			program = false;
		}
		// Female
		// Imperial
		else if ((sex == 'b' || sex == 'B') && (units == 'a' || units == 'A')) {
			cout << "How tall are you?" << endl << endl; 
			cout << "Feet: "; cin >> heightFeet; cout << "Inches: "; cin >> heightInches; cout << endl << endl;
			if (heightFeet < 0 || heightFeet > 11 || heightInches < 0 || heightInches > 130) {
				cout << "Enter a valid height" << endl << endl;
				continue;
			}
			cout << "How much do you weigh? (lbs)" << endl << endl; cin >> weight;
			if (weight < 0 || weight > 1800) {
				cout << "Enter a valid weight" << endl << endl;
				continue;
			}
			caloriesNeeded = femaleGoal.femaleCalorieGoal(units, method, heightFeet, heightInches, weight, age, activityLevel);
			if (caloriesNeeded == 0) {
				cout << "INVALID INPUT" << endl << endl;
				continue;
			}
			cout << endl << endl;  cout << endl <<
				"-------------------------------------------------------------------------"
				<< endl << "Your daily intake should be " << round(caloriesNeeded) << " calories and " <<
				round(weight * 0.8) << " - " << round(weight) << " grams of protein." << endl; cout <<
				"-------------------------------------------------------------------------" << endl << endl;
			program = false;
		}
		// Female
		// SI
		else if ((sex == 'b' || sex == 'B') && units == 'b' || units == 'B') {
			cout << "How tall are you? (cm)" << endl << endl; cin >> height; cout << endl << endl;
			if (height < 0 || height > 300) {
				cout << "Enter a valid height" << endl << endl;
				continue;
			}
			cout << "How much do you weigh? (kgs)" << endl << endl; cin >> weight;
			if (weight < 0 || weight > 750) {
				cout << "Enter a valid weight" << endl << endl;
				continue;
			}
			caloriesNeeded = femaleGoal.femaleCalorieGoal(units, method, height, weight, age, activityLevel);
			if (caloriesNeeded == 0) {
				cout << "INVALID INPUT" << endl;
				continue;
			}
			cout << endl << endl;  cout << endl <<
				"-------------------------------------------------------------------------"
				<< endl << "Your daily intake should be " << round(caloriesNeeded) << " calories and " <<
				round((weight * 2.2) * 0.8) << " - " << round(weight * 2.2) << " grams of protein." << endl; cout <<
				"-------------------------------------------------------------------------" << endl << endl;
			program = false;
		}

	}


	return 0;
}