//
// Created by mathieu on 11/22/16.
//

#include <stdlib.h>

#ifndef LOG710_LAB3_MEMORY_H
#define LOG710_LAB3_MEMORY_H

typedef struct bloc_struct
{
    int size;
    int position;
    int allocated;
    int* previousPtr;
    int* nextPtr;
    int* memoryPtr;
} Bloc;

typedef struct map_bloc_mem_struct
{
    int* memoryLocation;
    Bloc* bloc;
} map_bloc_mem;

Bloc* firstBloc;
Bloc* currentBloc;
int blocNb;
size_t remainingSpace;
int freeBlocNb;
int allocatedBlocNb;

/*Permet le mapping entre le memoryPtr du bloc donné au processus
et le Ptr sur le bloc associé à celui-ci*/
void mapBloc(int*, Bloc*);

#endif //LOG710_LAB3_MEMORY_H

