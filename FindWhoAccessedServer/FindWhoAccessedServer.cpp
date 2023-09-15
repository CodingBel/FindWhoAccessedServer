// There is a web server where users can access everyday. This server had an issue caused by users that accessed 
// the server in 2 specific days. 
// Lets suppose that we have at our disposal the logs of the access for both specific days as 2 vector strings
// formatted like 

// <date> <nickname>; <uninteresting_data>
// Find the lsit of nicknames that accessed the server in both days and return it as output of the fucntion

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_set>

void CleanString(std::string& myStr, const char delimiter1, const char delimiter2) {
	size_t pos = 0;
	if ((pos = myStr.find(delimiter1)) != std::string::npos)
		myStr.erase(0, pos + 1);

	if ((pos = myStr.find(delimiter2)) != std::string::npos)
		myStr.erase(pos, myStr.size());
}

std::unordered_set<std::string>who(std::vector<std::string>& day1, std::vector<std::string>day2) {
	std::unordered_set<std::string>Users{};
	std::unordered_set<std::string>usersToBlame{};

	for (auto& i : day1) {
		CleanString(i, '.', ';');
		Users.insert(i);
	}

	for (auto& i : day2) {
		CleanString(i, '.', ';');

		if (Users.find(i) != end(Users))
			usersToBlame.insert(i);
	}

	return usersToBlame;
}

int main() {

	std::vector<std::string>day1{};
	std::vector<std::string>day2{};

	// For first day
	std::string str1 = "2023-07-24T13:51:50.yoda;0998321321";
	std::string str2 = "2023-07-24T13:51:50.Luke;0998321321";
	std::string str3 = "2023-07-24T16:34:28.Obi-Wan;0980923423";
	std::string str4 = "2023-07-24T16:38:20.Anakin;0983424673";

	// For second day 
	std::string str5 = "2023-08-24T13:51:50.Luke;0998321321";
	std::string str6 = "2023-08-24T13:51:50.Luke;0998321321";
	std::string str7 = "2023-08-24T16:34:28.Ashoka;0980923423";
	std::string str8 = "2023-08-24T16:38:20.yoda;0983424673";

	// For first day
	day1.push_back(str1); day1.push_back(str2);
	day1.push_back(str3); day1.push_back(str4);

	// For second day
	day2.push_back(str5); day2.push_back(str6);
	day2.push_back(str8); day2.push_back(str7);

	std::unordered_set<std::string>UsrsToBlame = who(day1, day2);
	for (const auto& i : UsrsToBlame)
		std::cout << i << " ";

	return 0;
}


