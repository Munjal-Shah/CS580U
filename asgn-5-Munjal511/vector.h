#ifndef VECTOR_H
#define VECTOR_H

typedef struct data{
    int value;
}Data;

typedef struct vector{
    Data * data;
    int current_size;
    int max_size;
	
	void (*insert)(struct vector *, int, Data);
	Data * (*read)(struct vector *, int);
	void (*remove)(struct vector * array, int index);
	void (*delete)(struct vector * array);

}Vector;

Vector * newVector();
void insertVector(Vector * v, int i, Data d);
Data * readVector(Vector *array, int index);
void removeVector(Vector * array, int index);
void deleteVector(Vector * array);

#endif