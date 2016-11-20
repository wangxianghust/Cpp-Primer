#include <iostream>
#include "Chapter6.h"

int fact(int i) {
	int result = 1;
	while(i > 1) {
		result = result * i;
		-- i;
	}
	return result;
}