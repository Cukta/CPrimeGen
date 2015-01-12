#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

#define TRUE 1
#define FALSE 0

void main(){
	Vector primes;
	int num_primes;
	int current_prime;
	int i;

	vector_init(&primes);

	
	printf("How many primes do you want to generate?: \t");
	scanf_s("%d", &num_primes);

	
	for (i = 0; i < num_primes; ++i){
		int is_prime = TRUE;
		if (i == 0)
			current_prime = 2;
		else if (i == 1){
			current_prime = 3;
		}
		else{
			int j;
			current_prime += 2;
			for (j = 0; j < primes.size; ++j){
				if (current_prime % primes.data[j] == 0){
					is_prime = FALSE;
					break;
				}
				if (current_prime < primes.data[j] * primes.data[j])
					break;
			}
		}
		if (is_prime)
			vector_append(&primes, current_prime);
	}

	for (i = 0; i < primes.size; ++i){
		printf("%d\n", primes.data[i]);
	}

	vector_free(&primes);

	system("PAUSE");
}
