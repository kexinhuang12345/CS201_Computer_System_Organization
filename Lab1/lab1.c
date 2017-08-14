/*
 * IMPORTANT: WRITE YOUR NAME AND NetID BELOW.
 * 
 * Last Name:Huang	
 * First Name: Kexin	
 * Netid:kh2383
 * 
 * You will do your project in this file only.
 * Do not change function delarations. However, feel free to add new functions if you want.
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct _element
       { int x; 
	 struct _element * next;} element;

/* Function declarations: do not change that, but you may add your own functions */
void insertion_sort(int *, int);
void find_prime(int, int);
void flipping(unsigned int);
void file_histogram(char *);
void file2upper(char *);
void file_encrypt(char *);


/* Add here function declarations of your own, if any. */



/*********************************************************************************/

/* 
 * Do  NOT change anything in main function 
 */
int main(int argc, char * argv[])
{
  int option = 0;
  int i, j;
  int * list;
  
  if(argc < 2 )
  {
     fprintf(stderr,"Usage: lab1 num [input]\n");
     fprintf(stderr,"num: 1, 2, 3, 4, 5, or 6\n");
     exit(1);
  }
  
  option = atoi(argv[1]);
  
  switch(option)
  {
    case 1: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 1 num\n");
	      fprintf(stderr,"num: number of elements of the array to be sorted\n");
	      exit(1);
	    }
	    j = atoi(argv[2]);
	    list = (int *)malloc(j*sizeof(int));
	    if(!list)
	    {
	      fprintf(stderr,"Cannot allocate list in option 1\n");
	      exit(1);
	    }
	    
	    /* Gnerate random numbers in the range [0, 1000) */
	    for(i = 0; i < j; i++)
	      list[i] = rand()% 1000;
	    
	    /* Print the unsorted array */
	    printf("The unsorted array:\n");
	    for(i = 0; i < j; i++) 
	      printf("%d ", list[i]);
	    printf("\n");
	    
	    insertion_sort(list, j);
	    
	    break;
	    
	    
    case 2: if(argc != 4)
	    {
	      fprintf(stderr,"Usage: lab1 2 x y\n");
	      fprintf(stderr,"x and y: positive integers and x < y\n");
	      exit(1);
	    }
	    i = atoi(argv[2]);
	    j = atoi(argv[3]);
	    
	    find_prime(i, j);
	    
	    break;

	    
    case 3: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 3 num\n");
	      fprintf(stderr,"num: unsigned intger number\n");
	      exit(1);
	    }
	    
	    flipping( atof(argv[2]));
	    
	    break; 
	    
	    
    case 4: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 4 filename\n");
	      exit(1);
	    }
	    
	    file_histogram(argv[2]);
	    
	    break;

	    
    case 5: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 5 filename\n");
	      exit(1);
	    } 
	    
	    file2upper(argv[2]);
	    
	    break;

	    
    case 6: if(argc != 3)
	    {
	      fprintf(stderr,"Usage: lab1 46filename\n");
	      exit(1);
	    }
	    
	    file_encrypt(argv[2]);
	    
	    break;	      
	    
    default: fprintf(stderr, "You entered an invalid option!\n");
	     exit(1);
  }
  
  return 0;
}

/******* Start filling the blanks from here and add any extra functions you want, if any *****/

/*
 * Part 1:
 * In this function, you are given two inputs:
 * inputs: 
 * 	an array of int list[] 
 * 	The number of elements in that array: num
 * You need to use the insertion sort algorithm so sort this array in ascending order.
 * At the end, and before returning to main, print the sorted array on the screen.
 * */
void insertion_sort(int *list, int num)
{
	int i,j,target;
  	for(i=1;i<num;i++){
		target=list[i];
		j=i-1;
		while(j>-1&&list[j]>target){
			list[j+1]=list[j];
			j=j-1;
		}
		list[j+1]=target;
	}
	
	for(i=0;i<num;i++){
		printf("%d", list[i]);
		printf("\n");
	}
}


/*********************************************************************************/

/* 
 * Part 2:
 * In this part, you are given two positive integer, x and y, larger than 0.
 * You need to print all the prime numbers between x and y (NOT including x and y themselves), if any.
 */
void find_prime(int x, int y)
{
 int i,j;	
  for(i=x+1; i<y; i++){
	int z=1;//true 
	for(j=2; j<i; j++){
		if(i%j==0){
			z=0;//false 
			break;	
		}
	}
	
	if(z){
		printf("%d\n",i);
	}
  }
  
}



/*********************************************************************************/

/*
 * Part 3:
 * Given an unsigned integer (so has values of 0 and up), print on the screen 
 * the flipping of that number.
 * That is, if the number given is: 1234  then you print: 4321
 */
void flipping(unsigned int num)
{
	int ten,track,i;
	ten=1;
	track=1;
	while(num%ten!=num){
		ten=ten*10;
		track++;
	}
	track--;
	ten/=10;
	int array [track];
	for(i=0;i<track;i++){
		array[i]=num%10;
		num=(num-array[i])/10;
	}

	for(i=0;i<track;i++){
		printf("%d\n",array[i]);
	}
  
}

/*********************************************************************************/

/*
 * Part 4
 * The input is a filename.
 * The filename contains a string of lower case letters.
 * The output is a histogram of the file printed on the screen.
 * Example: 
 * The input file in.txt contains:  aaabbbbc
 * The output will be:
 * a: 3
 * b: 4
 * c: 1
 * .... and so one
 * The file will not contain spaces, only lower case alphabet letters.
 */
void file_histogram(char *filename)
{

 	FILE *fptr1;
	char letter[27]="abcdefghijklmnopqrstuvwxyz";
	int count[26]={0};
	int i,j;
	char ch;
	fptr1 = fopen(filename,"r");
	if(fptr1==NULL){
		printf ("File 'filename' did not open.\n") ;
	}
	else{
    		while( (ch = fgetc(fptr1)) != EOF) {
       			 j = 0;
      		  	while(letter[j] != '\0') {
	
           			 if(letter[j] == ch) {
               				 count[j]++; 
          			  }
            		  j++;
			}
       		 }
   	 
	
    	for(i = 0; i<26;i++) {
		if(count[i]!=0){
        		printf(" %c: %d \n",letter[i], count[i]);
		}
   	 }
}
		
	
	fclose(fptr1);
}

/*********************************************************************************/

/* 
 * Part 5:
 * Input: filename
 * Output:filenameCAPITAL
 * The output files contains the same characters as the input file but in upper case.
 * The input file will ONLY contain lower case letters and no spaces.
 * If the input filename is: in 
 * The output filename is: inCAPITAL
 */
void file2upper(char *filename)
{
  	FILE *fptr1,*fptr2;
	char ch;
	fptr1=fopen(filename,"r");

	if(fptr1==NULL)
		printf ("File 'filename' did not open.\n") ;

	char* newStr = malloc(strlen(filename)+8);
        strcpy(newStr, filename);
	strcat(newStr,"CAPITAL");
	fptr2=fopen(newStr,"w+");

	if(fptr2==NULL)
		printf ("File 'filename' did not open.\n") ;

	while((ch=fgetc(fptr1))!=EOF){
		ch=toupper(ch);
		fputc(ch,fptr2);
	}
	fclose(fptr1);

}

/*********************************************************************************/

/*
 * Part 6:
 * In that last part, you will learn to implement a very simple encryption.
 * Given a file that contains a series of lower case charaters (may be separated by white space),
 * replace all non-white space with the lower case letter that exists 3 letters before, in a circular way.
 * For example: 
 * e will be replaced with b
 * d will be replaced with a 
 * c will be replaced with z  <--- circular
 * b will be replaced with y  <--- circular
 * and white spaces will be left unchanged.
 * Print the output on the screen.
 */
void file_encrypt(char * filename)
{
 	
 	FILE *fptr1;
	char ch;
	fptr1=fopen(filename,"r");
	
	if(fptr1==NULL)
		printf ("File 'filename' did not open.\n") ;

	while((ch= fgetc(fptr1))!= EOF){
		if((ch =='a'||ch == 'b'||ch =='c')){
			ch+=23;
		}else if(ch>=100&&ch<=122){
			ch-=3;
		}else{

		}
		printf("%c",ch);	
	}

	fclose(fptr1);
}









