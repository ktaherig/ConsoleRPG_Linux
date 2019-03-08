#ifndef PUZZLE_H_
#define PUZZLE_H_

#include "../../STL_Include.h"

class Puzzle
{
private:
	std::string question;
	std::vector<std::string> answers;
	int correctAnswer;

public:
	Puzzle(std::string fileName);
	virtual ~Puzzle();
	std::string getAsString();

	inline const int& getCorrectAns()const { return this->correctAnswer; }
};

#endif /* ifndef PUZZLE_H_ */
