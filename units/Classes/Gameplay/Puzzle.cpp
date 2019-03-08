#include "../../Headers/Gameplay/Puzzle.h"

Puzzle::Puzzle(std::string fileName)
{
	this->correctAnswer = 0;

	std::ifstream inFile(fileName.c_str());

	int nrOfAns = 0;
	std::string answer = "";
	int correctAns = 0;

	if (inFile.is_open())
	{
		std::getline(inFile, this->question);
		inFile >> nrOfAns;
		inFile.ignore();

		for (size_t i = 0; i < nrOfAns; i++)
		{
			std::getline(inFile, answer);
			this->answers.push_back(answer);
		}

		inFile >> correctAns;
		this->correctAnswer = correctAns;
		inFile.ignore();
	}
	else
		throw("Could not open puzzle!");

	inFile.close();
}

Puzzle::~Puzzle()
{

}

std::string Puzzle::getAsString()
{
	std::string answers = "";
	std::stringstream ss;

	for (size_t i = 0; i < this->answers.size(); i++)
	{
		ss << i << ": " << this->answers[i] << "\n";
	}

	ss << this->question << "\n" << "\n"
		<< answers << "\n";

    return ss.str();
}
