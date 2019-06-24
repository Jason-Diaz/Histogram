#include <stdio.h>

/*
* Project 1: Histogram
*
* Creates a histogram of
* the word count from a file.
*
* Author: Jason Diaz
* Professor: Marc Zucker
*/

int kgetline();
void setarray(int a[],int size);
void valuesinhist(int in[], int out[],int size);

main()
{
	int i = 0;// keeps track of how many sentences the program counts
	int size = 0; // the size of the final array  
	int v,j;
	int wordCount = 0; //the number of words in each sentence
	int hist[55]; //the first array that will create the histogram
	

	while((wordCount = kgetline()) > -1){
		hist[i]=wordCount;
		i++;}
	
	for(v=0;v<i;++v) // to find the biggest number of words
	{
		if(hist[v]>size)
			size=hist[v];
	}	
	
	size += 1;
	int final[size];	
	setarray(final,size);
	valuesinhist(hist,final,i);

	for(v=0;v<size+1;++v) // prints out the histogram
	{
		if(size>2)
		{
		printf("%d : ",v);
		for(j=0;j<final[v];++j)
		{
			printf("*");
		}
		printf("\n");
		}
		else // condition for no sentences
		{
			printf("No sentences found!");
			v=size+1;
		}
	}
}

/*
* Function: kgetline()
*
* reads off characters from the file, for every space that till it
* reads the function increments the count by 1. When the function
* reaches a period or exclamation point or a question it stops
* and returns the count. The function will not increment count
* if it is the first thing it read because that is the space
* between the period and the first word. Once the function reaches
* the end of the file it will stop and return -1.
*/

int kgetline()
{
	int c, i;
	int count = 1;

	for (i=0;(c=getchar()) !=EOF && c!='.' && c!='!' && c!='?'; ++i)
	{
	if(i>0 && c == ' ')
		++count;
	}	
	if(c == EOF)
		return -1;
	if(i == 0 && c == '.')	
		count--;
	
	return count;
}

/*
* Function: setarray(int[], int)
*
* accepts an array and it's size. 
* Sets all the arrays elements to zero.
*/

void setarray(int a[],int size)
{
	int i;
	for(i=0; i<size; ++i)
	{
		a[i] = 0;
	}
}

/*
* Function: valuesinhist(int[], int[], int)
*
* this function takes two arrays, in is input, out is output.
* the input array has the sizes of each sentence. This function
* formats the output array by the element position. Therefore
* each time it encounters a number in the input array it will
* increment the element in the output array. The size is used
* to know how big the output will be. 
*/

void valuesinhist(int in[], int out[],int size)
{
	int i;
	int temp;
	int temp2;
	for(i=0; i<size; i++){
		temp = in[i];
		if(temp> 0)
		{
			temp2 = out[temp];
			++temp2;
			out[temp] = temp2;
		}
	}
	
}




