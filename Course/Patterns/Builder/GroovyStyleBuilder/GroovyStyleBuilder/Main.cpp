// GrrovyStyleBuilder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

struct Tag
{
	string name, text;
	vector<Tag> children;
	vector<pair<string, string>> attributes; // key value pairs

	friend std::ostream& operator<<(std::ostream& os, const Tag& tag)
	{
		os << "<" << tag.name;

		for (const auto& att : tag.attributes)
			os << " " << att.first << "=\"" << att.second << "\"";

		if (tag.children.size() == 0 && tag.text.length() == 0)
		{
			os << "/>" << std::endl;
		}
		else
		{
			os << ">" << std::endl;

			if (tag.text.length())
				os << tag.text << std::endl;

			for (const auto& child : tag.children)
				os << child;

			os << "</" << tag.name << ">" << std::endl;
		}

		return os;
	}
protected:
	Tag(const string &name, const string &text) : name(name), text(text){}
	Tag(const string &name, const vector<Tag> & children) : name(name), children(children) {}

};

struct P : public Tag
{
	P(const string &text) : Tag("p", text) {}
	P(initializer_list<Tag> children) : Tag("p", children){	}
};

struct IMG : public Tag
{
	explicit IMG(const string & url) : Tag("img", "")
	{
		attributes.emplace_back(make_pair("src", url));
	}
};

int main()
{
	cout << 
		P{
			IMG { 
				"http://www.something.com/image.jpg"
			},
			P{"hello"},
			P{"BYE"}
			
		} << endl;

	getchar();
	return 0;
}

