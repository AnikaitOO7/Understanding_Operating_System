//FCFS if the arrival time same

#include<stdio.h>	//Preprocessor directive to include input output functions header file.
#include<stdlib.h>	//Preprocessor directive to include standard library header file.

int main(){	//start of main function body.
	int ch, i, p;	//declaring variable.
	int temp_1 = 0, temp = 0;	//declaring variable and inilization.

	printf("Enter the no. of Process : ");	//printf function call for entring no. of process.
	scanf("%d",&p);	//Taking input of p from user.

	int burst[p];	//declaring array variable with size p.
	int com_1[p], com[p]; 
	printf("\n\nEnter the Burst Time for each Process :\n" );
	for(i = 0; i < p; i++){
		scanf("%d",&burst[i]);
    }
    // for loop for calculating completion time and Turn Around Time.
    for (i = 0; i < p ; i++){
		temp =  temp + burst[i]; //storing value in temp variable whose initial value is equal to zero and will increase with each increment.
		com[i] = temp; //storing value of temp in array after each iteration.

	}
	// for loop for calculating Waiting Time and Responce time.
	for (i = 0; i < p ; i++){
		com_1[0] = 0; //First initilizating value at index zero equal to zero.
		temp_1 =  temp_1 + burst[i];	//storing value in temp_1 variable whose initial value is equal to zero and will increase with each increment.
		com_1[i+1] = temp_1;	//storing value of temp_1 in array from index one after each iteration.
	}

	printf(" \n\tProcess\t\t\tBurst Time\t\t\tCompletion Time\t\t\tTurn Around Time\t\t\tWaiting Time\t\t\tResponce Time\n");	//printf function call for printing headers for the table.

	//for loop for displaying calculated value.
	for(i=0; i < p ;++i)
    {
        printf("\n\t  P%d \t\t\t    %d \t\t\t\t       %d \t\t\t\t %d \t\t\t\t      %d \t\t\t       %d\n", i+1, burst[i], com[i], com[i], com_1[i], com_1[i]);
    }

    //for loop for adding waiting time.
	int val = 0;
    for(i=0;i<p;i++){
    	val = val + com_1[i];
    }

    float sum = com_1[i]; //variable to store total waiting time.
    float var = (float) val / (float) p; //variable to store average waiting time.

    printf("\n\n\tTotal Time = %.2f", sum);	//printf function call for total time.
    printf("\n\n\tAverage Waiting Time = %.2f\n", var);	//printf function call for average waiting time.
    return 0; //Return statment.
}	//End of the main function body.

