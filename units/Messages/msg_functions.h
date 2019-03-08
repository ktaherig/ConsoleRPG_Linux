#ifndef MSG_FUNCTIONS_H_
#define MSG_FUNCTIONS_H_

#include <string>
#include <iomanip>
#include <sstream>

namespace gui
{
	const std::string msg_menutitle(const std::string title);
	const std::string msg_menudivider(const unsigned amount, const char symbol);
	const std::string msg_menuitem(const int number, const std::string item);
	const std::string msg_error(const std::string msg);
	const std::string msg_alert(const std::string msg);
}

#endif
