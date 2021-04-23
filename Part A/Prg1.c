 /*Title: Program 1 
 Question : C program in which sender module should count the no of bytes in the
							  frame and reciever module should display each frame recieved
Author:Mukund.G -USN:1NT19IS417
 Date: 23/04/21*/ 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char res[100];
void sender()
{
		int n,i,len;
		char frm[100],l[100];
		printf("Enter the number of frames\n");
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{	
			printf("Enter the frame to be sent  %d\n",i+1);
			scanf("%s",&frm);
			len=strlen(frm);
			sprintf(l,"%d",len);
			strcat(l,frm);
			strcat(res,l);
		}
			printf("The final message to be sent is %s\n",res);
}
void reciever()
	{
		int len,i,j;
		printf("Received frames are \n");
		for(i=0;i<strlen(res);i++)
		{
				len=res[i]-'0';
				for(j=i+1;j<=(i+len);j++)
				printf("%c",res[j]);
				i=i+len;
				printf("\n");
		}
}
void main()
{
		sender();
		reciever();
		return 0;
}
