/*
	SOLID OpenClosed principle -- code should be open to extension, but closed to modification
*/

#include "pch.h"

#include "BetterFilter.h"
#include "ColorSpecification.h"
#include "SizeSpecification.h"
#include "Product.h"

/* this approach demonstrates that additional filters can be written based on the Specification approach 
and the code thats already tested does not need to be re-opened
*/
int main()
{
	Product apple{ "Apple", Color::green, Size::small };
	Product tree{ "Tree", Color::green, Size::large };
	Product house{ "House", Color::blue, Size::large };
	vector<Product *> items{ &apple, &tree, &house };

	BetterFilter bf;
	ColorSpecification greenSpec(Color::green);
	// the filter code is going to call isSatisfied() on the greenSpec for every item in the vector passed in
	for (const auto &item : bf.filter(items, greenSpec))
		cout << item->name << " is green" << endl;

	SizeSpecification largeSpec(Size::large);
	AndSpecification<Product> greenAndLarge(greenSpec, largeSpec);
	for (const auto &item : bf.filter(items, greenAndLarge))
		cout << item->name << " is green and large" << endl;

	getchar();
	return 0;
}

