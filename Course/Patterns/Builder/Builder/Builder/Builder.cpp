#include "pch.h"

struct HtmlElement
{
	string name, text;
	vector<HtmlElement> elements; // inner elements

	const size_t indentSize = 2;

	HtmlElement() {}
	HtmlElement(const string & name, const string & text) : name(name), text(text)
	{  
	} 

	string str(int indent = 0) const 
	{
		ostringstream oss;
		string i(indentSize*indent, ' ');

		oss << i << "<" << name << ">" << endl;

		if (text.size() > 0)
			oss << string(indentSize * (indent + 1), ' ') << text << endl;

		for (const auto &e : elements)
			oss << e.str(indent + 1);

		oss << i << "</" << name << ">" << endl;
		return oss.str();
	}
};

/* a specialized component with API that allows you to build up an object over multiple steps */
struct HtmlBuilder
{
	HtmlElement root;

	HtmlBuilder(string name)
	{
		root.name = name;
	}
	void AddChild(string childName, string childText)
	{
		HtmlElement e{ childName, childText };
		root.elements.emplace_back(e);
	}
	string str() const { return root.str(); }
};

int main()
{
	HtmlBuilder builder{ "ul" };
	builder.AddChild("li", "hello");
	builder.AddChild("li", "world");
	cout << builder.str() << endl;

	getchar();
	return 0;
}

	