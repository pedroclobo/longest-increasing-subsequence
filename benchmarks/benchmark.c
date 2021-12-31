#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define SIZES_LEN 8
#define OUTPUT1 "1.txt"
#define OUTPUT2 "2.txt"

void write_to_file(size_t size, char prob) {
	char command[100];
	memset(command, 0, sizeof(command));
	char number[20];
	sprintf(number, "%lu", size);

	if (prob == 1) {
		strcat(command,"./random_k 1 0 0.5 ");
		strcat(command, number);
		strcat(command, " ");
		strcat(command, "> arr.in");
	} else if (prob == 2) {
		strcat(command,"./random_k 2 0 0.5 ");
		strcat(command, number);
		strcat(command, " ");
		strcat(command, number);
		strcat(command, " ");
		strcat(command, "> arr.in");
	}

	system(command);
}

int average(int *arr, size_t size) {
	int average = 0;

	for (size_t i = 0; i < size; i++) {
		average += arr[i];
	}

	return average / size;
}

int main() {
	FILE *out_1 = fopen(OUTPUT1, "w");
	FILE *out_2 = fopen(OUTPUT2, "w");

	for (size_t size = 1; size < 100000; size += 1000) {
		int times[5];

		for (int j = 0; j < 5; j++) {
			write_to_file(size, 1);

			time_t begin = time(NULL);

			system("../src/proj < arr.in");

	    	time_t end = time(NULL);

			times[j] = end - begin;
		}

		fprintf(out_1, "%lu %d\n", size, average(times, 5));
	}

	for (size_t size = 1; size < 100000; size += 1000) {
		int times[5];

		for (int j = 0; j < 5; j++) {
			write_to_file(size, 2);

			time_t begin = time(NULL);

			system("../src/proj < arr.in");

	    	time_t end = time(NULL);

			times[j] = end - begin;
		}

		fprintf(out_2, "%lu %d\n", size, average(times, 5));
	}

	fclose(out_1);
	fclose(out_2);
}
