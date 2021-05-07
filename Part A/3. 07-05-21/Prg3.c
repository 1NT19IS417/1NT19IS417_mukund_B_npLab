 /*Title: Program 3
 Question : C program in which we check for the CRC values 
							  check if error is detected or not 
Author:Mukund.G -USN:1NT19IS417
 Date: 07/05/21*/ 




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char data[100], gen[100], code[50];
int datalen, genlen;

void doXor(int i) {
  if (code[i] == gen[i])
    code[i] = '0';
  else
    code[i] = '1';
}

void crc() {
  int i, j;
  for (i = 0; i < genlen; i++) {
    code[i] = data[i];
  }
  do { 
    if (code[0] == '1') {
      for (j = 1; j < genlen; j++) {
        doXor(j);
      }
    }
    for (j = 0; j < genlen - 1; j++)
      code[j] = code[j + 1];

    code[j] = data[i++];
  } while (i <= datalen + genlen - 1);
}

void clean() {
  int i;
  for (i = 0; i < 50; i++) {
    code[i] = '0';
  }
}

void sender() {
  int i;
  printf("Enter the Data: ");
  scanf("%s", data);
    
  printf("Enter the polynomial: ");
  scanf("%s", gen);
    
  datalen = strlen(data);
  genlen = strlen(gen);

  for(i = datalen; i < datalen + genlen - 1; i++)
    data[i] = '0';
  crc();
  for(i = datalen; i < datalen + genlen - 1; i++)
    data[i] = code[i - datalen];
        
  printf("\nComputed CRC is : %s\n", code);
  printf("Coded polynomial is : %s\n\n", data);
}

int receiver() {
  int i;
  printf("Enter the data received: ");
  scanf("%s", data);
  datalen = strlen(data);
  int flag = 0;
  crc();

  // check for error
  for(i = 0; i < strlen(code); i++) {
    if(code[i]=='1')
      flag = 1;
  }

  return flag;
}

void main() {
  sender();
  int flag = receiver();

  printf(flag == 1 ? "\nLooks like an error was encountered in transmission \n" : "\nNo error has been detected in the transmission\n");
}
