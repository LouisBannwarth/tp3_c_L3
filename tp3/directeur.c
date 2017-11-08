#include <stdlib.h> 
#include <stdio.h> 

#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/shm.h>
#include "musee.h"
void creer(int capacite,int file){
	
	
	void* monMusee;
	int memid;
	key_t key=ftok("./directeur.c",159);
	memid=shmget(key,sizeof(monMusee),0700| IPC_CREAT);
	if (memid == -1) { 
		perror("shmget"); 
	}
	((struct musee*)monMusee) ->capacite= capacite;
	((struct musee*)monMusee) ->file = file;
	((struct musee*)monMusee) ->ouvert = 0;
}

void supprime(){
	key_t key=ftok("./directeur.c",159);
	int memid=shmget(key,sizeof(struct musee),0700);
	int error=shmctl(memid,IPC_RMID,NULL);
	if(error==-1){
		perror("erreur suppression");
	}
}
int main(int argc,char* argv[]){
	creer(atoi(argv[2]),atoi(argv[3]));
	supprime();
}




