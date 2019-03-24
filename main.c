#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

void bubble_sort(int list[], int n);
void insertion_sort(int list[], int n);
void selection_sort(int list[], int n);
void quick_sort(int list[],int first,int last);
void merge(int [],int ,int ,int );
void part(int [],int ,int ); //function for merge sort
void createHeap(int [], int );

int main()
{
     clock_t start, end; //Timers: start-> number of clocks when the algorithm begins         end-> number of clocks when the algorithm ends
     double cpu_time_used;


    int n = 15;
    int c,menu;

    int list[n];
    for (int i = 0; i < n; i++) { //Array initialization
    list[i] = rand();
}

    printf("Type 1 for bubble sort\n");
    printf("Type 2 for insertion sort\n");
    printf("Type 3 for selection sort\n");
    printf("Type 4 for quick sort\n");
    printf("Type 5 for merge sort\n");
    printf("Type 6 for heap sort\n");
    printf(">>");
    scanf("%d",&menu);

    if(menu == 1)
    {
        //BUBBLE SORT
        start = clock(); //Timer starts
        printf("\n\n>>start: %ld\n",start);

        bubble_sort(list, n);
        printf("Bubble sorted list: \n");

        for ( c = 0 ; c < n ; c++ )
            printf("%d ", list[c]);
    }

    else if(menu == 2)
    {
        //INSERTION SORT
        start = clock();//Timer starts
        printf("\n\n>>start: %ld\n",start);

        insertion_sort(list, n);
        printf(" insertion sorted list: \n");

        for ( c = 0 ; c < n ; c++ )
            printf("%d ", list[c]);
    }
    else if(menu == 3)
    {
        //SELECTION SORT
        start = clock(); //Timer starts
        printf("\n\n>>start: %ld\n",start);

        selection_sort(list, n);
        printf("\n\nSelection sorted list: \n");

        for ( c = 0 ; c < n ; c++ )
            printf("%d ", list[c]);
    }
    else if(menu == 4)
    {
        //QUICK SORT
        start = clock(); //Timer starts
        printf("\n\n>>start: %ld\n",start);

        quick_sort(list,0,n-1);
        printf("\nQuick sorted list: \n");

        for ( c = 0 ; c < n ; c++ )
            printf("%d ", list[c]);
    }
    else if(menu == 5){

        //MERGE SORT
        start = clock(); //Timer starts
        printf("\n\n>>start: %ld\n",start);

        int size = n;
        part(list,0,size-1);
        printf("\n\nMerge sorted list: \n");
        for(int i=0; i<size; i++)
        printf("%d ",list[i]);
    }

    else if(menu == 6){

        //HEAP SORT
        start = clock(); //Timer starts
        printf("\n\n>>start: %ld\n",start);

        createHeap(list, n);
    }

    else
    {
        printf("Wrong input. Try again.");
    }

     end = clock(); //Timer ends
     printf("\n\n>>end: %ld\n",end);
     cpu_time_used = ((double) (end-start)) / CLOCKS_PER_SEC;
     printf("\n\n>Bubble sort took >>%.8f<< seconds to execute \n", cpu_time_used);

    return 0;

}



// FUNCTIONS -- FUNCTIONS -- FUNCTIONS -- FUNCTIONS -- FUNCTIONS -- FUNCTIONS -- FUNCTIONS -- FUNCTIONS -- FUNCTIONS -- FUNCTIONS -- FUNCTIONS -- FUNCTIONS -- FUNCTIONS -- FUNCTIONS -- FUNCTIONS --





// BUBBLE SORT function
void bubble_sort(int list[], int n)
{
    int i, j, temp;

    for (i = 0 ; i < ( n - 1 ); i++)
    {
        for (j = 0 ; j < n - i - 1; j++)
        {
            if (list[j] > list[j+1])
            {
                /* Swapping */

                temp      = list[j];
                list[j]   = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}
// INSERTION SORT function
void insertion_sort(int list[], int n)
{
    int i,j,temp;
    for (i = 1 ; i <= n - 1; i++)
    {
        j = i;

        while ( j > 0 && list[j] < list[j-1])
        {
            temp          = list[j];
            list[j]   = list[j-1];
            list[j-1] = temp;

            j--;
        }
    }

}

// SELECTION SORT function
void selection_sort(int list[], int n)
{
    int i,j,swap,position;

    for ( i = 0 ; i < ( n - 1 ) ; i++ )
    {

        position = i;

        for ( j = i + 1 ; j < n ; j++ )
        {
            if ( list[position] > list[j] )
                position = j;
        }
        if ( position != i )
        {
            swap = list[i];
            list[i] = list[position];
            list[position] = swap;
        }
    }


}
// QUICK SORT function
void quick_sort(int list[],int first,int last)
{
    int pivot,j,temp,i;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;

        while(i<j)
        {
            while(list[i]<=list[pivot]&&i<last)
                i++;
            while(list[j]>list[pivot])
                j--;
            if(i<j)
            {
                temp=list[i];
                list[i]=list[j];
                list[j]=temp;
            }
        }

        temp=list[pivot];
        list[pivot]=list[j];
        list[j]=temp;
        quick_sort(list,first,j-1);
        quick_sort(list,j+1,last);

    }
}

//  MERGE SORT functions
void part(int arr[],int min,int max)
{
 int mid;
 if(min<max)
 {
   mid=(min+max)/2;
   part(arr,min,mid);
   part(arr,mid+1,max);
   merge(arr,min,mid,max);
 }
}


void merge(int arr[],int min,int mid,int max)
{
  int l = 2*max; //diplasio toy mege8oys
  int tmp[l]; //prin eixe 30 gia n=15
  int i,j,k,m;
  j=min;
  m=mid+1;
  for(i=min; j<=mid && m<=max ; i++)
  {
     if(arr[j]<=arr[m])
     {
         tmp[i]=arr[j];
         j++;
     }
     else
     {
         tmp[i]=arr[m];
         m++;
     }
  }
  if(j>mid)
  {
     for(k=m; k<=max; k++)
     {
         tmp[i]=arr[k];
         i++;
     }
  }
  else
  {
     for(k=j; k<=mid; k++)
     {
        tmp[i]=arr[k];
        i++;
     }
  }
  for(k=min; k<=max; k++)
     arr[k]=tmp[k];
}

//HEAP SORT function
void createHeap (int arr[], int n){
int no, i, j, c, root, temp;
no = n;

for ( i = 1; i < no; i++)
    {
        c = i;
        do
        {
            root = (c - 1) / 2;
            if (arr[root] < arr[c])   /* to create MAX heap array */
            {
                temp = arr[root];
                arr[root] = arr[c];
                arr[c] = temp;
            }
            c = root;
        } while (c != 0);
    }

     printf("Heap array : ");
        for (i = 0; i < no; i++)
        printf("\n%d", arr[i]);




        for (j = no - 1; j >= 0; j--) //SORTING HEAP
    {
        temp = arr[0];
        arr[0] = arr[j];    // swap max element with rightmost leaf element
        arr[j] = temp;
        root = 0;
        do
        {
            c = 2 * root + 1;    // left node of root element
            if ((arr[c] < arr[c + 1]) && c < j-1)
                c++;
            if (arr[root]<arr[c] && c<j)    // again rearrange to max heap array
            {
                temp = arr[root];
                arr[root] = arr[c];
                arr[c] = temp;
            }
            root = c;
        } while (c < j);
    }
    printf("\n The sorted array is : ");
    for (i = 0; i < no; i++)
       printf("\n%d", arr[i]);
}
