#define MAJORV 1
#define MINORV 0
#define SUFFIXV ""

#include <iostream>
#include <cinttypes>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <algorithm>

using namespace std; 

int main(int argc, char *argv[]){


	int primes[27] = {7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113};

/*
	printf("\n\n  32 bit\n");

	for(int i = 0; i < 27; ++i){

		printf("__constant uint p%d[%d] = { ",primes[i], primes[i]);

		for( int j = 0; j < primes[i]; ++j ){

			uint32_t bitmask = 0;

			int start;

			if(j == 0){
				start = 0;
			}
			else{
				start = primes[i] - j;
			}

			for(int k = start; k < 64; k += primes[i] ){

				if(k % 2 == 0){
					bitmask |= 1 << (k/2);
				}

			}

			if(j == primes[i]-1){
				printf("%u };\n\n", bitmask);
			}
			else{
				printf("%u, ", bitmask);
			}


		}

	}
*/
	printf("\n\n  64 bit\n");

	for(int i = 0; i < 27; ++i){

		printf("const uint64_t p%d[%d] = { ",primes[i], primes[i]);

		for( int j = 0; j < primes[i]; ++j ){

			uint64_t bitmask = 0;

			int start;

			if(j == 0){
				start = 0;
			}
			else{
				start = primes[i] - j;
			}

			for(int k = start; k < 128; k += primes[i] ){
				
				if(k % 2 == 0){
					bitmask |= 1ULL << (k/2);
				}

			}

			if(j == primes[i]-1){
				printf("0x%" PRIx64 " };\n\n", bitmask);
			}
			else{
				printf("0x%" PRIx64 ", ", bitmask);
			}
		}

	}

	return 0;
}
