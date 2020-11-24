/*
#=====================================================================================================================#
# Author:- Rahul C. Dcosta                             		     						      #
# File Type :- Main Program File                                     				 		      #
# Description:-program that simulates the pipeline of the shell							      #
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

int main ()

{

	FILE *read_fp,*write_fp;
	char buffer[BUFSIZ +1];
	memset(buffer,'\0',sizeof(buffer));
	read_fp=popen("ls -l","r");
	write_fp=popen("wc ","w");
	if(read_fp !=NULL && write_fp !=NULL)
	{

	fread(buffer,sizeof(char),BUFSIZ,read_fp);	
	pclose(read_fp);
	fwrite(buffer,sizeof(char),strlen(buffer),write_fp);
	pclose(write_fp);
	exit(EXIT_SUCCESS);

	}
	exit(EXIT_FAILURE);




}
