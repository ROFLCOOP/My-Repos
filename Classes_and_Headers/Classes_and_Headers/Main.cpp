#include <iostream>
#include "Invader.h"

void movement()
{

}

void fill(std::string pos[10][22], std::string type, int line, int amount, int perLine)
{
	for (int y = line; y < line + amount; y++)
	{
		for (int x = 0; x < perLine; x++)
		{
			pos[y][x] = type;
			std::cout << pos[y][x] << " ";
		}
		std::cout << std::endl;
	}
}

int main()
{
	invader squid;
	squid.amount = 1;
	squid.lineNum = 0;
	squid.type = "S";
	squid.score = 100;

	invader crab;
	crab.amount = 2;
	crab.lineNum = squid.lineNum + squid.amount;
	crab.type = "C";
	crab.score = 10;

	invader octopus;
	octopus.amount = 2;
	octopus.lineNum = crab.lineNum + crab.amount;
	octopus.type = "O";
	octopus.score = 1;

	std::string position[10][22];
	
	fill(position, squid.type, squid.lineNum, squid.amount, squid.perLine);

	fill(position, crab.type, crab.lineNum, crab.amount, crab.perLine);

	fill(position, octopus.type, octopus.lineNum, octopus.amount, octopus.perLine);



	

	system("pause");

	return 0;
}