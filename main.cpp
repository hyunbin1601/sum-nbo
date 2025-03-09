#include <stdio.h>
#include <stdint.h>
#include "sum_nbo.h"

int main(int argc, char* argv[]){
	uint32_t* s = sum_nbo(argc, argv);

	if (!s) {
		return 1;
	}

	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)", s[0], s[0], s[1], s[1], s[2], s[2]);
}
