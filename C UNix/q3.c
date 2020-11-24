/*
#=====================================================================================================================#
# Author:- Rahul C. Dcosta                             		     						      #
# File Type :- Main Program File                                     				 		      #
# Description:-program that uses a pipe to communicate  between a parent and child process. 			      # 
	       Display the message sent by parent to child. 							      #
# Date Created:-04/03/2014                             		     						      #
# Date Modified:-05/03/2014                            		     						      #
# Copyrights:- All Rights to TroubleShooter	   		     					              #
#=====================================================================================================================#
*/



#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define SIZE 200

int main()
{


int file_pipes[2];
char some_data[] = "Hello World";
char buffer[BUFSIZ +1];
int fork_result;
memset(buffer,'\0',sizeof(buffer));

if (pipe(file_pipes) == 0)
{
	fork_result=fork();
   if(fork_result == -1)
   {
	fprintf(stderr,"Fork Creation Failure");
	exit(EXIT_FAILURE);

	}

  if(fork_result==0)
{

read(file_pipes[0],buffer,BUFSIZ);
printf("Child Process : %s\n",buffer);
exit(EXIT_SUCCESS);


}
else
{
	 write(file_pipes[1],some_data,strlen(some_data));
	printf("Parent Process:%s\n",buffer);

}


}

exit(EXIT_SUCCESS);


}
