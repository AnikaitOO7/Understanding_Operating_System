	//FCFS if the arrival time same

#include<stdio.h>
#include<stdlib.h>

int p;

int com_time();
int turn_time();
int wait_time();
int resp_time();
int fcfs_table();
void line(int x);

int main(){
	int ch, i;

	printf("Enter the no. of Process : ");
	scanf("%d",&p);

	int burst[p]; 
	printf("\n\nEnter the Burst Time for each Process :\n" );
	for(i = 0; i < p; i++){
		scanf("%d",&burst[i]);
    }
    line(35);
    printf("\n\tProcess\t\t\tBurst Time\n");
    line(35);
    for(i=0; i < p ;++i)
    {
        printf("\n\t  P%d \t\t\t    %d\n", i+1, burst[i]);
    }
    line(35);
    
	printf("\n\n\t\t\t**MENU FOR FIRST COME FIRST SERVE**\n\n");
	while(1){
		printf("\n\nEnter 1 for Completion Time.");
		printf("\nEnter 2 for Turn around Time.");
		printf("\nEnter 3 for Waiting Time.");
		printf("\nEnter 4 for Responce Time.");
		printf("\nEnter 5 for FCFS Table.");
		printf("\nEnter 6 to exit.");
		printf("\n\nEnter the choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1 :	com_time(burst);
						break;
			case 2 :	turn_time(burst);
						break;
			case 3 :	wait_time(burst);
						break;
			case 4 :	resp_time(burst);
						break;	
			case 5 :	fcfs_table(burst);
						exit(0);	
			case 6 :	exit(0);							
			default:	printf("\n\n\t**WARNING!!! Enter the right choice given in menu to insert**\n\n");		 	
		}
    }
    return 0;
}

int com_time(int burst[], int i){
	int com[p];
	int temp = 0;

	for (i = 0; i < p ; i++){
		temp =  temp + burst[i];
		com[i] = temp;

	}

	/*
	Another formula

	for(i=2;i<p;i++){
    		com[i] = com[i-1] + com[i-2];
    	}*/

	line(63);

	printf(" \n\tProcess\t\t\tBurst Time\t\tCompletion Time\n");
	
	line(63);
    
    for(i=0; i < p ;++i)
    {
        printf("\n\t  P%d \t\t\t    %d \t\t\t       %d\n", i+1, burst[i], com[i]);
    }

    line(63);
    return 0;
}

int turn_time(int burst[], int i){
	int com[p];
	int temp = 0;

	for (i = 0; i < p ; i++){
		temp =  temp + burst[i];
		com[i] = temp;

	}

	line(64);

	printf(" \n\tProcess\t\t\tBurst Time\t\tTurn Around Time\n");
	
	line(64);
    
    for(i=0; i < p ;++i)
    {
        printf("\n\t  P%d \t\t\t    %d \t\t\t       %d\n", i+1, burst[i], com[i]);
    }

    line(64);
    return 0;
}

int wait_time(int burst[], int i){
	int com[p];
	int temp = 0;

	for (i = 0; i < p ; i++){
		com[0] = 0;
		temp =  temp + burst[i];
		com[i+1] = temp;
	}

	line(64);

	printf(" \n\tProcess\t\t\tBurst Time\t\tWaiting Time\n");
	
	line(64);
    
    for(i=0; i < p ;++i)
    {
        printf("\n\t  P%d \t\t\t    %d \t\t\t       %d\n", i+1, burst[i], com[i]);
    }

    line(64);

    int val = 0;
    for(i=0;i<p;i++){
    	val = val + com[i];
    }

    float sum = com[i];
    float var = (float) val / (float) p;

    printf("\n\n\tTotal Time = %.2f", sum);
    printf("\n\n\tAverage Waiting Time = %.2f\n", var);
    return 0;
}

int resp_time(int burst[], int i){
	int com[p];
	int temp = 0;

	for (i = 0; i < p ; i++){
		com[0] = 0;
		temp =  temp + burst[i];
		com[i+1] = temp;
	}

	line(64);

	printf(" \n\tProcess\t\t\tBurst Time\t\tResponce Time\n");
	
	line(64);
    
    for(i=0; i < p ;++i)
    {
        printf("\n\t  P%d \t\t\t    %d \t\t\t       %d\n", i+1, burst[i], com[i]);
    }

    line(64);
    return 0;
}

int fcfs_table(int burst[]){
	int com_1[p], com[p], i;
	int temp_1 = 0, temp = 0;

	for (i = 0; i < p ; i++){
		temp =  temp + burst[i];
		com[i] = temp;

	}

	for (i = 0; i < p ; i++){
		com_1[0] = 0;
		temp_1 =  temp_1 + burst[i];
		com_1[i+1] = temp_1;
	}

	line(175);
	printf(" \n\tProcess\t\t\tBurst Time\t\t\tCompletion Time\t\t\tTurn Around Time\t\t\tWaiting Time\t\t\tResponce Time\n");
	line(175);

	for(i=0; i < p ;++i)
    {
        printf("\n\t  P%d \t\t\t    %d \t\t\t\t       %d \t\t\t\t %d \t\t\t\t      %d \t\t\t       %d\n", i+1, burst[i], com[i], com[i], com_1[i], com_1[i]);
    }
    line(175);

	int val = 0;
    for(i=0;i<p;i++){
    	val = val + com_1[i];
    }

    float sum = com_1[i];
    float var = (float) val / (float) p;

    printf("\n\n\tTotal Time = %.2f", sum);
    printf("\n\n\tAverage Waiting Time = %.2f\n", var);
    return 0;

}

void line(int x){

	int i;

	printf("\t");

	for (i = 0; i < x; i++){
		printf("-");
	}
	printf("\n");
}