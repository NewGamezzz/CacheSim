/**
 * CacheSim.h
 * This program is designed for class exercise only.
 * It is provided as is. There is no warranty or support of any kind.
 *
 * Krerk Piromsopa, Ph.D.
 * Department of Computer Engineering
 * Chulalongkorn University
 * Bangkok, Thailand.
**/
#ifndef CACHESIM_H_INCLUDED
#define CACHESIM_H_INCLUDED

/* Please adjust parameters here */
#define CACHE_SIZE 262144
#define INDEX_SIZE 8192
#define BLOCK_SIZE 32
#define TAGLEN 14
#define INDEXLEN 13
#define OFFSETLEN 5
#define SET 4
typedef unsigned char Byte;
typedef unsigned char bool;
typedef struct Cache{
    bool valid;
    bool dirty;
    unsigned long tag;
    unsigned long time;
    Byte data[BLOCK_SIZE];
};

#endif // CACHESIM_H_INCLUDED