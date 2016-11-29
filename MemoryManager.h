//
// Created by mathieu on 11/22/16.
//

#ifndef LOG710_LAB3_MEMORYMANAGER_H
#define LOG710_LAB3_MEMORYMANAGER_H

#include <stdlib.h>


size_t MAX_MEM;
int ALLOC_STRATEGY;

/** Initialise les structures de données du gestionnaire.
Initialise un premier bloc de la taille maximale de la mémoire*/
void initmem();

/** Cette fonction alloue un nouveau bloc de mémoire.*/
int* alloumem(size_t size);

/** Cette fonction libère un bloc de mémoire similaire à free().*/
void liberemem(int* pBloc);

/** Cette fonction retourne le nombre de blocs de mémoire libres*/
int nbloclibres();

/** Cette fonction retourne le nombre de blocs alloués présentement*/
int nblocalloues();

/** Combien de mémoire libre (non allouée) au total. */
size_t memlibre();

/** Taille du plus grand bloc libre.*/
size_t mem_pgrand_libre();

/** Combien de petits blocs (plus petit que maxTaillePetit) non alloués
y a-t-il présentement en mémoire? */
int mem_small_free(size_t maxTaillePetit);

/**Est-ce qu’un octet (byte) particulier est alloué*/
int mem_est_alloue(int* pOctet);


#endif //LOG710_LAB3_MEMORY_H



#endif //LOG710_LAB3_MEMORYMANAGER_H
