
#include "pch.h"
#include <iostream>
#include<fstream>
#include<map>
#include<sstream>
#include<algorithm>
#include<iomanip>


std::map<int, std::pair<int, int>> function(std::ifstream &obj) {
	std::string str;
	std::map<int, std::pair<int, int>> dataM;
	std::getline(obj, str);
	while (std::getline(obj, str)) {
		auto it= std::remove(str.begin(), str.end(), ':');
		str.erase(it);
		std::pair<int, std::pair<int, int>> dataP;
		int year, qnt, prc;
		std::string yearS, qntS, prcS;
		std::stringstream ss(str);
		ss >> yearS >> qntS >> prcS;
		year = std::stoi(yearS);
		qnt = std::stoi(qntS);
		prc = std::stoi(prcS);
		std::pair<int, int> p = std::make_pair(qnt, prc);
		dataP = std::make_pair(year, p);
		dataM.insert(dataP);
	}
	return dataM;
}

// Qnt- quantity of rainy days;
//Prc- price for liter
int main()
{
	std::ifstream dataW("Data.txt");
	int range, firstY, secondY, third;
	dataW >> firstY >> secondY;
	range = secondY - firstY;
	std::map<int, std::pair<int, int>> mapp;

	mapp = function(dataW);	
	double amountOfQnt = 0, amountOfPrc = 0, amountOfQntSq = 0, amountPrcQnt = 0;
	long double resultA, resultB;
	for (auto& it : mapp) {
		amountPrcQnt += it.second.first * it.second.second;
		amountOfQnt += it.second.first; 
		amountOfQntSq += it.second.first* it.second.first;
		amountOfPrc += it.second.second;
		}
	resultA = (((range+1)*amountPrcQnt) - amountOfPrc*amountOfQnt) / (((range+1)*amountOfQntSq) - (amountOfQnt* amountOfQnt));
	resultB = (amountOfPrc - resultA * amountOfQnt) / (range+1);
	std::cout<< std::setprecision(9) << resultA << std::setprecision(11)<<    " " << resultB;
		return resultA, resultB;
}

