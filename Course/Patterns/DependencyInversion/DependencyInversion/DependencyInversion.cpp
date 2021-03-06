// DependencyInversion SOLID principle

#include "pch.h"
#include <iostream>

/* high level modules should not depend on the low level modules.
Both should depend on abstractions

 Abstractions should not depend on details.  Details should depend
 on abstractions.
*/
#include "pch.h"

enum class Relationship
{
	parent, 
	child, 
	sibling
};

struct Person
{
	string name;
};


struct RelationshipBrowser
{
	virtual vector<Person> FindAllChildrenOf(const string & name) = 0;
};

// relationships is a low level module. Dont want to pass it in directly
struct Relationships: RelationshipBrowser 
{
	vector<tuple<Person, Relationship, Person>> relations;

	void AddParentAndChild(const Person & parent, const Person & child) 
	{
		relations.push_back({ parent, Relationship::parent, child });
		relations.push_back({ child, Relationship::child, parent });
	}

	virtual vector<Person> FindAllChildrenOf(const string & name) override
	{
		vector<Person> result;

		for (const auto&[first, rel, second] : relations)
		{
			if (first.name == name && rel == Relationship::parent)
			{
				result.push_back(second);
			}
		}

		return result;
	}

};

struct Research // high level module
{
	// example of a high level module depending on the low leve module

	//Research(Relationships & relationships)
	//{
	//	auto & relations = relationships.relations;
	//	for (const auto& [first, rel, second] : relations)
	//	{
	//		if (first.name == "John" && rel == Relationship::parent)
	//		{
	//			cout << "John has a child called " << second.name << endl;
	//		}
	//	}
	//}

	Research(RelationshipBrowser & browser)
	{
		for (const auto & child : browser.FindAllChildrenOf("John"))
		{
			cout << "John has a child called " << child.name << endl;
		}
	}
};

int main()
{
	Person parent{ "John" };
	Person child1{ "Chris" }, child2{ "Matt" };

	Relationships relationships;
	relationships.AddParentAndChild(parent, child1);
	relationships.AddParentAndChild(parent, child2);

	Research research(relationships);

	getchar();
	return 0;
}

