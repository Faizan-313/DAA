#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);
void print(int [], int );


int partition(int arr[], int s, int e){
    int count = 0;
    for(int i = s+1;i<=e;i++){
        if(arr[i]<arr[s]) count++;
    }

    int index = s+count;
    swap(&arr[s],&arr[index]);

    for(int i = s,j=e;i<index,j>index;i++,j--){
        if(arr[i]>arr[index] && arr[j]<arr[index]) swap(&arr[i],&arr[j]);
        else if(arr[i]<arr[index]) i++;
        else if(arr[j]>arr[index]) j--;
    }
    return index;
}


void quick_sort(int arr[],int s,int e){
    if(s>=e) return;

    int p = partition(arr,s,e);

    quick_sort(arr,s,p-1);
    quick_sort(arr,p+1,e);
}




int main(){
    int n;

    printf("enter the size of array: ");
    scanf("%d",&n);

    int *arr = (int *)malloc(n*sizeof(int));
    if(arr == NULL){
        printf("Memory allocation failed");
        return 0;
    }

    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    quick_sort(arr,0,n-1);
    print(arr,n-1);
}












void swap(int *i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}




void print(int arr[], int n){
    for(int i =0;i<=n;i++){
        printf("%d ",arr[i]);
    }
}