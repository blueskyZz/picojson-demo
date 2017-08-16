#include "picojson.h"
#include <iostream>
#include <string>
using namespace std;

//{
//	"questionId":1,
//	"answerSummary" :
//	{
//		"attendStudents":100,
//		"optionStats" : [
//		{
//			"num":20,
//			"option" : 0
//		},
//		{
//			"num":60,
//			"option" : 1
//		},
//		]
//	}
//}

std::string ToJson() {

	//picojson::value 同时只能代表一种类型，要么是double等原始类型，或者是数组array，或者object
	//object可以保存键值对，是个map
	//object键值对的值可以是任意类型的value

	picojson::value json;
	//这里json保存键值对，所以是个object
	json.set<picojson::object>(picojson::object());
	json.get<picojson::object>()["questionId"] = picojson::value(double(1));

	//这里answerSummary也是一个键值对，所以也是object
	json.get<picojson::object>()["answerSummary"].set<picojson::object>(picojson::object());

	json.get<picojson::object>()["answerSummary"].get<picojson::object>()["attendStudents"] = picojson::value(double(200));
	//这里optionStats是一个数组，所以是个array
	json.get<picojson::object>()["answerSummary"].get<picojson::object>()["optionStats"].set<picojson::array>(picojson::array());

	picojson::value option_stat;
	//这里option_stat也是一个键值对，所以也是object
	option_stat.set<picojson::object>(picojson::object());
	option_stat.get<picojson::object>()["option"] = picojson::value(double(0));
	option_stat.get<picojson::object>()["num"] = picojson::value(double(20));
	//array的实现是个vector，所以使用push_back
	json.get<picojson::object>()["answerSummary"].get<picojson::object>()["optionStats"].get<picojson::array>().push_back(option_stat);

	option_stat.get<picojson::object>()["option"] = picojson::value(double(1));
	option_stat.get<picojson::object>()["num"] = picojson::value(double(60));
	//array的实现是个vector，所以使用push_back
	json.get<picojson::object>()["answerSummary"].get<picojson::object>()["optionStats"].get<picojson::array>().push_back(option_stat);

	return json.serialize();
};

int main() {
	std::string a = ToJson();
	return 0;
}
