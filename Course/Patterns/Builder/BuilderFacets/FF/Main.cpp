/* several builders building the same obkect -- the idea being that the object is so complicated that you 
need separate APIs to create the object
*/

#include "pch.h"

#include "Person.h"
#include "PersonBuilder.h"
#include "PersonJobBuilder.h"
#include "PersonAddressBuilder.h"

int main()
{
	Person p = Person::create()
		.lives()
			.at("123 Magic Rd")
			.withPostCode("07405")
			.in("Jersey City")
		.works()
			.at("IBM")
			.as_a("Contractor")
			.earning(10);

	cout << p << endl;
	getchar();
	return 0;
}

