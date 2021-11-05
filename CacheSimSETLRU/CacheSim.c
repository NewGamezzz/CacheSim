/**
 * CacheSim.c 
 * This program is designed for class exercise only.
 * It is provided as is. There is no warranty or support of any kind.
 *
 * Krerk Piromsopa, Ph.D.
 * Department of Computer Engineering
 * Chulalongkorn University
 * Bangkok, Thailand.
 * 
 * History
 * 2013 - Initial design
 * 2015 - Refactor/Clean code
**/
#include <stdio.h>
#include <string.h>
#include "CacheSim.h"

long MISS;
long HIT;
struct Cache cache[SET][INDEX_SIZE];
int init() {
	MISS=0;
	HIT=0;
	int i, j;
	for(i=0; i<SET; i++){
	    for(j=0;j<INDEX_SIZE;j++){
	        cache[i][j].valid=0;
	        cache[i][j].tag=0;
	        cache[i][j].dirty=0;
	        cache[i][j].time=0;
	    }
	}
}
int calAddr(unsigned long addr,unsigned long *tag,unsigned long *idx,unsigned long *offset) {
	unsigned long tmp;
	int i;
	*tag=addr>>(OFFSETLEN+INDEXLEN);
	tmp=0;
	for(i=0;i<INDEXLEN;i++) {
		tmp<<=1;
		tmp|=0x01;
	}
	*idx=addr>>OFFSETLEN & tmp;
	tmp=0;
	for(i=0;i<OFFSETLEN;i++) {
		tmp<<=1;
		tmp|=0x01;
	}
	*offset=addr & tmp;
}
int access(unsigned long addr){
    unsigned long offset;
	unsigned long tag;
	unsigned long idx;
	bool h=0;
    int i;
    int s=0;
    unsigned long max_time = 0;
    unsigned long min_time;
	int valid=0;
	calAddr(addr,&tag,&idx,&offset);
	min_time = cache[0][idx].time;

	for(int i=0; i<SET; i++){
		if(cache[i][idx].tag==tag && cache[i][idx].valid){
			h=1;
			s=i;
		}
	}

	for(int i=0; i<SET; i++){
        if(max_time < cache[i][idx].time){
        	max_time = cache[i][idx].time;
        }
    }

	if(h==1){
        HIT++;
        cache[s][idx].time = max_time+1;
	}
	else{
        MISS++;
		for(int i=0; i<SET; i++){
	        if(min_time > cache[i][idx].time){
	        	min_time = cache[i][idx].time;
	        	s = i;
	        }
		}
        cache[s][idx].valid=1;
        cache[s][idx].tag = tag;
        cache[s][idx].time = max_time+1;
	}

}
int main(int argc,char *argv[]){
    printf("CacheSim v.2015\n");
    printf("This program is designed for class exercise only.\n");
    printf("By Krerk Piromsopa, Ph.D.\n");
    FILE *input;
    char buff[1025];
    unsigned long myaddr;
    if (argc<2) {
		fprintf(stderr,"Usage:\n\t%s address_file\n",argv[0]);
		exit(-1);
	}
    input=fopen(argv[1],"r");
    //read file
    while (fgets(& buff[0],1024,input)) {
		sscanf(buff,"0x%x",&myaddr);
        access(myaddr);
    }
    printf("HIT:%7d MISS: %7d\n",HIT,MISS);
    printf("TOTAL:%7d\n", HIT+MISS);

}
