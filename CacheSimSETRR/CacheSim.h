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
#define CACHE_SIZE 2048
#define INDEX_SIZE 64
#define BLOCK_SIZE 32
#define TAGLEN 21
#define INDEXLEN 6
#define OFFSETLEN 5
#define SET 2
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