#include <stdio.h>
/*
to swap the elements while sorting
*/
void swap( int* x, int* y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
/*
to create and add elements on array
*/
void inputArr(int arr[], int size){
    // int size;
    printf("\nEnter the element of arry and press enter:\n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
}
/*
to display the array
*/
void displayArr(int arr[], int size ){
    // int size;
    for(int i=0;i<size;i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");

}
void bubbleSort(int arr[]){
    int n;
    printf("\nEnter the size of array:");
    scanf("%d",&n);
    inputArr(arr,n);
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++ ){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }   
    }
    displayArr(arr,n); 
}
void insertionSort(int arr[]){
    int  temp;
    int n;
    printf("\nEnter the size of array:");
    scanf("%d",&n);
    inputArr(arr, n);
    for(int i=0;i<n;i++){
        temp=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;

    }
    displayArr(arr, n);
}

void selectionSort(int arr[]){
    int n;
    int i=0;
    printf("\nEnter the size of array:");
    scanf("%d",&n);
    inputArr(arr, n);
    for(i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min])
            min=j;
        }
        if(min!=i){
            swap(&arr[i],&arr[min]);
        }
    }
    displayArr(arr,n);
}
void shellSort(int arr[]){
    int n, i, j, gap;
    printf("\nEnter the size of array:");
    scanf("%d",&n);
    inputArr(arr, n);
    for(gap=n/2;gap>0; gap/=2){
        for(i=gap;i<n;i++){
            int temp=arr[i];
            for(j=i;j>=gap&&arr[j-gap]>temp;j-=gap){
                arr[j]=arr[j-gap];
            }
            arr[j]=temp;

        }
    }
    displayArr(arr,n);

}

int main(){
    int arr[100];
    int ch;
    int n; //for input array
    do{
        printf("Select any sorting operation:\n  1.BUbble sort \t 2.Insertation Sort \n  3.Selection Sort\t 4.Shell sort\n  5.Exit.\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            bubbleSort(arr);
            
            break;
        case 2:
            insertionSort(arr);
            break;
        case 3:
            selectionSort(arr);
            break;
        case 4:
            shellSort(arr);
            break;
        case 5:
            ch=0;
            printf("\nThank You!!!\nOperation Sucessful");
        
        default:
            break;
        }

    }while(ch!=0);
    return 0;
}