#include <iostream>

template<typename TypeA>
void AssertEqual(TypeA a, TypeA b) {
	if (a == b) {
		std::cout << "[Test]: passed\n";
	}
	else {
		std::cout << "[Test]: failed\n";
	}
}