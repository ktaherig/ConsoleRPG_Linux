#ifndef STATE_H_
#define STATE_H_

#include "../STL_Include.h"
#include "../Messages/msg_functions.h"

using namespace std;

class State
{
private:
	bool quit;

public:
	State();
	virtual ~State();

	//Accessors
	const bool& getQuit() const;

	//Modifiers
	void setQuit(const bool quit);

	//Functions
	virtual int getChoice() const;
	virtual void update() = 0; //Pure virtual function

};

#endif
