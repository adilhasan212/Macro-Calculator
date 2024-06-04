#pragma once
#include <iomanip>
#include <iostream>

using namespace std;

class FemaleClass {
private:
	double heightFeet,
		heightInches,
		weight,
		caloriesNeeded;
public:
	// Imperial Units
	double femaleCalorieGoal(char units, char method, double heightFeet, double heightInches, double weight, int age, double activityLevel) {
		double height;
		if (units == 'a' || units == 'A') {
			height = heightFeet * 12 + heightInches;
			caloriesNeeded = 9.99 * weight + 6.25 * height - 4.92 * age -161;
			caloriesNeeded *= activityLevel;
		}
		else {
			return 0;
		}

		if (method == 'a' || method == 'A') {
			caloriesNeeded -= 500;
		}
		else if (method == 'b' || method == 'B') {
			caloriesNeeded += 250;
		}
		else if (method == 'c' || method == 'C') {
			// Do nothing
		}
		else {
			return 0;
		}
		return caloriesNeeded;
	}

	// SI Units
	double femaleCalorieGoal(char units, char method, double height, double weight, int age, double activityLevel) {

		if (units == 'b' || units == 'B') {
			height = height * 0.393701;
			weight = weight * 2.20462;
			caloriesNeeded = 9.99 * weight + 6.25 * height - 4.92 * age -161;
			caloriesNeeded *= activityLevel;
		}
		else {
			return 0;

		}

		if (method == 'a' || method == 'A') {
			caloriesNeeded -= 500;
		}
		else if (method == 'b' || method == 'B') {
			caloriesNeeded += 250;
		}
		else if (method == 'c' || method == 'C') {
			// Do nothing
		}
		else {
			return 0;
		}
		return caloriesNeeded;
	}

};

