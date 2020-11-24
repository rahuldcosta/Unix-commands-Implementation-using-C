/*
#=====================================================================================================================#
# Author:- Rahul C. Dcosta                             		     						      #
# File Type :- Main Program File                                     				 		      #
# Description:-display the following contents of a directory (default is current directory) depending on the options  #
# Date Created:-04/03/2014                             		     						      #
# Date Modified:-05/03/2014                            		     						      #
# Copyrights:- All Rights to TroubleShooter	   		     					              #
#=====================================================================================================================#
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<dirent.h>
#define PATHLENGTH 210
main(int argc,char *argv[])
{
char directory[PATHLENGTH + 1 ];
int regularcount=0,directcount=0;
struct dirent *p;
DIR *dp;
struct stat b;


if (argc >=2 && argc <=3 && argv[1][0]=='-')
{
	
   switch(argv[1][1])

{

   case 'p' : 
		if(argv[2]!=NULL)
		{
		if ( chdir(argv[2]) == -1 )
	{ printf("Failed to Change Directory\n");
	return;
	}
		getcwd(directory,PATHLENGTH);
		printf("%s\n",directory);
		}
		else
		{
		  getcwd(directory,PATHLENGTH);
		  printf("%s\n",directory);
		  
		}
		break;
  
   case 'l' : 
		//----------start----//
	if(argv[2]==NULL)
		{
		dp=opendir(".");
		}
	else
		{
	
		if ( chdir(argv[2]) == -1 )
	{ printf("Failed to Change Directory\n");
	return;
	}
		dp=opendir(".");
		}
if(dp==NULL)
{
printf("\nDirectory opening problem\n");
return;
}
while((p=readdir(dp))!=NULL)
{
if(stat(p->d_name,&b)< 0)
{
printf("\nStat failure \n");
exit(0);
}
switch(b.st_mode & S_IFMT )
{

case S_IFREG:
printf("-");
break;

case S_IFDIR:
printf("d");
break;

case S_IFCHR:
printf("c");
break;

case S_IFBLK:
printf("b");
break;

case S_IFLNK:
printf("l");
break;

case S_IFSOCK:
printf("s");
break;
case S_IFIFO:
printf("p");
break;

}
if(S_IRUSR & b.st_mode)
printf("r");
else
printf("-");

if(S_IWUSR & b.st_mode)
printf("w");
else
printf("-");

if(S_IXUSR & b.st_mode)
printf("x");
else
printf("-");

if(S_IRGRP & b.st_mode)
printf("r");
else
printf("-");

if(S_IWGRP & b.st_mode)
printf("w");
else
printf("-");

if(S_IXGRP & b.st_mode)
printf("x");
else
printf("-");

if(S_IROTH & b.st_mode)
printf("r");
else
printf("-");

if(S_IWOTH & b.st_mode)
printf("w");
else
printf("-");

if(S_IXOTH & b.st_mode)
printf("x");
else
printf("-");

printf("%3d ",b.st_nlink);
printf("%4d ",b.st_uid);
printf("%4d ",b.st_gid);
printf("%6d  ",b.st_size);
printf("%9ld",b.st_ctime);
printf("  %s\n",p->d_name);
}
		//--end--//
		
		break;

   case 'd' :

	if(argv[2]==NULL)
		{
		dp=opendir(".");
		}
	else
		{
	
		if ( chdir(argv[2]) == -1 )
	{ printf("Failed to Change Directory\n");
	return;
	}
		dp=opendir(".");
		}
if(dp==NULL)
{
printf("\nDirectory opening problem\n");
return;
}
	while((p=readdir(dp))!=NULL)
{

if(stat(p->d_name,&b)< 0)
{
printf("\nStat failure \n");
exit(0);
}
switch (b.st_mode & S_IFMT ) 
{
case S_IFDIR :

printf("d"); 
if(S_IRUSR & b.st_mode)
printf("r");
else
printf("-");

if(S_IWUSR & b.st_mode)
printf("w");
else
printf("-");

if(S_IXUSR & b.st_mode)
printf("x");
else
printf("-");

if(S_IRGRP & b.st_mode)
printf("r");
else
printf("-");

if(S_IWGRP & b.st_mode)
printf("w");
else
printf("-");

if(S_IXGRP & b.st_mode)
printf("x");
else
printf("-");

if(S_IROTH & b.st_mode)
printf("r");
else
printf("-");

if(S_IWOTH & b.st_mode)
printf("w");
else
printf("-");

if(S_IXOTH & b.st_mode)
printf("x");
else
printf("-");

printf("%3d ",b.st_nlink);
printf("%4d ",b.st_uid);
printf("%4d ",b.st_gid);
printf("%6d  ",b.st_size);
printf("%9ld",b.st_ctime);
printf("  %s\n",p->d_name);
}

}
break;

case 'r' :
if(argv[2]==NULL)
		{
		dp=opendir(".");
		}
	else
		{
	
		if ( chdir(argv[2]) == -1 )
	{ printf("Failed to Change Directory\n");
	return;
	}
		dp=opendir(".");
		}
if(dp==NULL)
{
printf("\nDirectory opening problem\n");
return;
}
	while((p=readdir(dp))!=NULL)
{

if(stat(p->d_name,&b)< 0)
{
printf("\nStat failure \n");
exit(0);
}
switch (b.st_mode & S_IFMT ) 
{
case S_IFREG :

printf("-"); 
if(S_IRUSR & b.st_mode)
printf("r");
else
printf("-");

if(S_IWUSR & b.st_mode)
printf("w");
else
printf("-");

if(S_IXUSR & b.st_mode)
printf("x");
else
printf("-");

if(S_IRGRP & b.st_mode)
printf("r");
else
printf("-");

if(S_IWGRP & b.st_mode)
printf("w");
else
printf("-");

if(S_IXGRP & b.st_mode)
printf("x");
else
printf("-");

if(S_IROTH & b.st_mode)
printf("r");
else
printf("-");

if(S_IWOTH & b.st_mode)
printf("w");
else
printf("-");

if(S_IXOTH & b.st_mode)
printf("x");
else
printf("-");

printf("%3d ",b.st_nlink);
printf("%4d ",b.st_uid);
printf("%4d ",b.st_gid);
printf("%6d  ",b.st_size);
printf("%9ld",b.st_ctime);
printf("  %s\n",p->d_name);
}

}
break;

case 'c' :

if(argv[2]==NULL)
		{
		dp=opendir(".");
		}
	else
		{
	
		if ( chdir(argv[2]) == -1 )
	{ printf("Failed to Change Directory\n");
	return;
	}
		dp=opendir(".");
		}
if(dp==NULL)
{
printf("\nDirectory opening problem\n");
return;
}
	while((p=readdir(dp))!=NULL)
{

if(stat(p->d_name,&b)< 0)
{
printf("\nStat failure \n");
exit(0);
}
switch (b.st_mode & S_IFMT ) 
{
case S_IFREG :
		regularcount++;
		break;

case S_IFDIR :

		directcount++;
		break; 		
}
	
}

	printf("Regular Files Count =%d\nDirectory Files Count =%d\nTotal Count=%d\n",regularcount,directcount,regularcount+directcount);
	break;


}

}
else
printf("Invalid No. of Arguments\n Usage : ./%s -(OPTION) [PATH] \n",argv[0]);

}
