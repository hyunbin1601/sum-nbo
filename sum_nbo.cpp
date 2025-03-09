#include <stdint.h>
#include <stdio.h>

uint32_t my_ntohl(uint32_t n) {
	uint32_t x;
	x = ((n & 0x000000FF) << 24) | ((n & 0x0000FF00) << 8)  | ((n & 0x00FF0000) >> 8)  | ((n & 0xFF000000) >> 24);
	
	return x;
}

uint32_t* sum_nbo(int argc, char* argv[]) {

	static uint32_t result[3];
	
	FILE* file1 = fopen(argv[1], "rb");
	if (!file1) {
		fprintf(stderr, "파일이 제대로 열리지 않았습니다\n");
		return NULL;
	}
	
	FILE* file2 = fopen(argv[2], "rb");
	if (!file2) {
		fprintf(stderr, "파일이 제대로 열리지 않았습니다\n");
		fclose(file1);
		return NULL;
	}
	
	uint32_t num1 = 0;
	uint32_t num2 = 0;
	
	if (fread(&num1, sizeof(uint32_t), 1, file1) < 1) {
		fprintf(stderr, "파일의 크기가 작아서 제대로 읽지 못했습니다\n");
		fclose(file1);
		fclose(file2);
		return NULL;
	}
	
	if (fread(&num2, sizeof(uint32_t), 1, file2) < 1) {
		fprintf(stderr, "파일의 크기가 작아서 제대로 읽지 못했습니다\n");
		fclose(file1);
		fclose(file2);
		return NULL;
	}
	
	fclose(file1);
	fclose(file2);
	
	num1 = my_ntohl(num1);
	num2 = my_ntohl(num2);
	
	uint32_t sum = num1 + num2;
	
	result[0] = num1;
	result[1] = num2;
	result[2] = sum;
	
	return result;
	
}
