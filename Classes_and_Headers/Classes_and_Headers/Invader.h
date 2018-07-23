#pragma once
#include<string>

class invader
{
public:
	int amount; //how many lines this type takes up
	int lineNum;
	std::string type;
	int score;
	int perLine = 11;
};