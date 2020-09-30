#include<stdio.h>

void merge(int [], int ,int,int);
void mergesort(int [], int,int);

int main()
{
  int i,j,k,arr[50],n;
  
  printf("Enter the no of elements in the array: ");
  scanf("%d",&n);
  
  printf("Enter array elements: \n");    // input array
  for (i=0; i<n; i++)
    scanf("%d",&arr[i]);
    
  mergesort(arr,0, n-1);                 // mergesort   
  
  printf("Sorted array is :");
  for(i=0; i<n; i++)                     //sorted array
    printf("%d \t",arr[i]);

return 0; 
}


void merge(int arr[], int l, int m, int h)
{
  int i,j,k,a,b;
  
  a = m - l +1;
  b = h - m;
  
  int la[a], ha[b];     // la{left array} , ha{right array}
  
  for(i=0; i<a; i++)
    la[i] = arr[l+i];
    
  for(j=0; j<b; j++)
    ha[j] = arr[m+1+j];
    
  i=0;
  j=0;
  k=0;
  
  while(i < a && j < b)
  {
    if(la[i] < ha[i])
    {
      arr[k] = la[i];
      i++;
    }
    else
    {
      arr[k] = ha[j];
      j++;
    }
    k++;
  }
  
  while(i < a)
  {
    arr[k] = la[i];
    i++;
    k++;
  }
  
  while(j < b)
  {
    arr[k] = ha[j];
    j++;
    k++;
  }
  
}


void mergesort(int arr[], int l, int h)
{
  int m;
  if(l < h)
  {
    m = 1 + ((h-l)/2);
    
    mergesort(arr, l, m-1);
    mergesort(arr, m, h);
    
    merge(arr, l, m, h);
  }
}

//It is of O(n log n) complexity.
