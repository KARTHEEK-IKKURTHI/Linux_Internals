



#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

int get_semaphore(void);
int release_semaphore(void);
int sem_id;
union semun{
	int	val;	/*Value for SETVAL*/
	struct semid_ds *buf;	//Buffer for IPC_STAT,IPC_SET;
	unsigned short *array;	//Array for GETALL,SETALL;
	struct seminfo *_buf;
	
	
	
int main(){
	int i,j;
	sem_id=semget((key_t)1234,1,0666|IPC-CREAT);
	
	
	
	
	
for(i=0;i<=10;i++){
	get_semaphore();
	printf("\n SEM2: %d :got the Semaphore\n",getpid());
	for(j=0;j<=3:j++){
		sleep(1);
		printf("\a");
	}
	
	printf("\n SEM2: %d : Released the semaphore \n",getpid());
	
	release_semaphore();
	sleep(2);
	
}

if(semctl(sem_id,0,IPC_RMID,sem_union)<0){
	printf("Unable delete semaphore\n");
	}
else{
	printf("Semaphore Deleted");
	}
int get_semaphore(void){
	sem_op.sem_num=0;
	
	
	sem_op.sem_op=-1;
	
	sem_op.sem_flg=SEM_UNDO;
	
	if(semop(sem_id,&sem_op,1)<0){
		printf("Failed to get the Semaphore \n");
		return -1;
		
		}
		
	return 0;
	
}
int release_semaphore(void){
	sem_op.sem_num=0;
	sem_op.sem_op=1;
	sem_op.sem_flg=SEM_UNDO;
	if
