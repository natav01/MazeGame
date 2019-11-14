#include "game-map-utils.h"
#include <iostream>
#include "random-utils.h"

void drawMaze (const std::array<std::array<char, mazeColumns>, mazeRows> &mase) {

	for (int row =0; row<mazeRows; row++) {
		for (int column = 0; column < mazeColumns; column++) {
			char ch = mase[row][column];
			std::cout<<ch;
		}
		std::cout<<endl;
	}
}

bool scanForChar(const std::array<std::array<char, mazeColumns>, mazeRows> &maze,
                 const char charToFind,
                 int &rCharRow,
                 int &rCharColumn)
{
    for (int row = 0; row < mazeRows; row++)
    {
        for (int column = 0; column < mazeColumns; column++)
        {
            if (maze[row][column] == charToFind)
            {
                rCharRow = row;
                rCharColumn = column;
                return true;
            }
        }
    }

    return false;
}

void placeCharRandomly(std::array<std::array<char, mazeColumns>, mazeRows> &rMaze,
                       char charToPlace,
                       int charCount)
{
    for(int i = 0; i < charCount; i++)
    {
        int randomRow = 0;
        int randomColumn = 0;

        do
        {
            randomRow = generateRandomNumber(0, mazeRows - 1);
            randomColumn = generateRandomNumber(0, mazeColumns - 1);
        }
        while (rMaze[randomRow][randomColumn] != emptySymbol);

        rMaze[randomRow][randomColumn] = charToPlace;
    }
}
