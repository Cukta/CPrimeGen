#include <stdio.h>
#include <stdlib.h>

#define VECTOR_INITIAL_CAPACITY 1000
#define VECTOR_OVERFLOW_SIZE 2,147,483,647

typedef struct
{
	int capacity;
	int size;
	int* data;
} Vector;

void vector_init(Vector* vector);
void vector_append(Vector* vector, int value);
int vector_get(Vector* vector, int index);
void vector_double_capacity_if_full(Vector* vector);

void vector_init(Vector* vector){
	vector->size = 0;
	vector->capacity = VECTOR_INITIAL_CAPACITY;
	vector->data = malloc(sizeof(int)* vector->capacity);
	if (vector->data == NULL){
		printf("ERROR: Couldn't allocate memory.\n");
		exit(1);
	}
}

void vector_append(Vector* vector, int value){
	vector_double_capacity_if_full(vector);
	vector->data[vector->size++] = value;
}

int vector_get(Vector* vector, int index){
	if (index >= vector->size || index < 0){
		printf("Index %d out of range for vector of size %d.\n", index, vector->size);
		exit(1);
	}
	return vector->data[index];
}

void vector_double_capacity_if_full(Vector *vector) {
	int* tmp;
	if (vector->size >= vector->capacity) {
		vector->capacity *= 2;
		if (vector->capacity > VECTOR_OVERFLOW_SIZE || vector->capacity < 0){
			printf("ERROR: Vector capacity overflow.\n");
			free(vector->data);
			exit(1);
		}
		tmp = realloc(vector->data, sizeof(int)* vector->capacity);
		if (tmp == NULL){
			printf("ERROR: Couldn't reallocate memory.\n");
			free(vector->data);
			exit(1);
		}
		vector->data = tmp;
	}
}

void vector_free(Vector *vector) {
	free(vector->data);
}
