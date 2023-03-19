#include "Hashing.h"
#include "Hashing.h" // cette ligne inclut le fichier d'en-tête Hashing.h (inclusion en double, inutile)
int Hashing::murmur3_32(const char* key, int len, int seed) { // définition de la fonction murmur3_32
	static const int c1 = 0xcc9e2d51; // constante c1
	static const int c2 = 0x1b873593; // constante c2
	static const int r1 = 15; // constante r1
	static const int r2 = 13; // constante r2
	static const int m = 5; // constante m
	static const int n = 0xe6546b64; // constante n

	int hash = seed; // initialisation de la valeur du hash

	const int nblocks = len / 4; // nombre de blocs de 4 octets dans la clé
	const int* blocks = (const int*)key; // pointeur sur le début des blocs de 4 octets dans la clé
	int i;
	for (i = 0; i < nblocks; i++) { // boucle sur les blocs de 4 octets dans la clé
		int k = blocks[i]; // k est le i-ème bloc de 4 octets de la clé
		k *= c1; // multiplication de k par c1
		k = (k << r1) | (k >> (32 - r1)); // rotation à gauche de k de r1 bits
		k *= c2; // multiplication de k par c2

		hash ^= k; // XOR de hash et k
		hash = ((hash << r2) | (hash >> (32 - r2))) * m + n; // multiplication et addition de hash avec m et n
	}

	const int* tail = (const int*)(key + nblocks * 4); // pointeur sur la fin des blocs de 4 octets dans la clé
	int k1 = 0;

	switch (len & 3) { // nombre d'octets restants dans la clé (0, 1, 2 ou 3)
	case 3:
		k1 ^= tail[2] << 16;
	case 2:
		k1 ^= tail[1] << 8;
	case 1:
		k1 ^= tail[0];

		k1 *= c1;
		k1 = (k1 << r1) | (k1 >> (32 - r1));
		k1 *= c2;
		hash ^= k1; // XOR de hash et k1
	}

	hash ^= len; // XOR de hash et len
	hash ^= (hash >> 16); // XOR de hash et un décalage de 16 bits à droite de hash
	hash *= 0x85ebca6b; // multiplication de hash par une constante
	hash ^= (hash >> 13); // XOR de hash et un décalage de 13 bits à droite de hash
	hash *= 0xc2b2ae35; // multiplication de hash par une constante
	hash ^= (hash >> 16); // XOR de hash et un décalage de 16 bits à droite de hash

	return hash; // retourne la valeur finale du hash
}