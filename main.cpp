#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define RANGE 500000
void bubble_sort(int array[],int n){
    int i,j,aux;
    for(i=0;i<n;i++){
        for(j=0;j<n-i;j++)
            if(array[j]>array[j+1]) {
                aux=array[j];
                array[j]=array[j+1];
                array[j+1]=aux;
            }
    }
}

void insertion_sort(int array[],int n){
    int i,j,x;
    for(i=1;i<n;i++){
        x=array[i];
        j=i-1;
        while(j>=0 && x<array[j]){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=x;
    }
}

void selection_sort(int array[],int n){
    int i,j,min_index,aux;
    for(i=0;i<n;i++){
        min_index=i;
        for(j=i+1;j<n;j++)
            if(array[j]<=array[min_index])
                min_index = j;
        aux=array[i];
        array[i]=array[min_index];
        array[min_index]=aux;
    }
}

void merge(int array[], int left, int middle, int right)
{
    int i,j,k,n1=middle-left+1,n2=right-middle;
    int left_array[n1], right_array[n2];
    for (i=0;i<n1;i++)
        left_array[i]=array[left+i];
    for (j=0;j<n2;j++)
        right_array[j]=array[middle+1+j];
    i=j=0;
    k=left;
    while(i<n1&&j<n2){
        if (left_array[i]<=right_array[j]){
            array[k]=left_array[i];
            i++;
        }
        else{
            array[k]=right_array[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        array[k]=left_array[i];
        i++;
        k++;
    }
    while(j<n2){
        array[k]=right_array[j];
        j++;
        k++;
    }
}
void merge_sort(int array[],int left,int right){
    if(left>=right){
        return;
    }
    int middle=(left+right-1)/2;
    merge_sort(array,left,middle);
    merge_sort(array,middle+1,right);
    merge(array,left,middle,right);
}

int partition(int array[], int start, int end)
{
    int pivot=array[start],count=0,i,j,pivot_index,aux;
    for (i=start+1;i<=end;i++) {
        if (array[i]<=pivot)
            count++;
    }
    pivot_index=start+count;
    aux=array[pivot_index];
    array[pivot_index]=array[start];
    array[start]=aux;
    i=start;
    j=end;
    while(i<pivot_index && j>pivot_index) {
        while (array[i]<=pivot){
            i++;
        }
        while (array[j]>pivot){
            j--;
        }
        if (i<pivot_index && j>pivot_index){
            aux=array[i];
            array[i]=array[j];
            array[j]=aux;
            i++;j--;
        }
    }
    return pivot_index;
}
void quick_sort(int array[], int start, int end)
{
    if(start>=end)
        return;
    int p=partition(array, start, end);
    quick_sort(array, start, p-1);
    quick_sort(array, p+1, end);
}

void heapify(int array[], int n, int root)
{
    int largest = root, left=2*root+1, right=2*root+2,aux;
    if (left<n && array[left]>array[largest])
        largest=left;
    if (right<n && array[right]>array[largest])
        largest=right;
    if (largest!=root) {
        aux=array[root];
        array[root]=array[largest];
        array[largest]=aux;
        heapify(array, n, largest);
    }
}
void heap_sort(int array[], int n)
{
    int i,aux;
    for(i = n/2-1;i>=0;i--)
        heapify(array, n, i);
    for (i=n-1;i>0;i--){
        aux=array[0];
        array[0]=array[i];
        array[i]=aux;
        heapify(array, i, 0);
    }
}

void counting_sort(int array[],int n)
{
    int output[n],count[RANGE+1],i;
    memset(count, 0, sizeof(count));
    for (i=0;array[i];++i)
        ++count[array[i]];
    for (i=1;i<=RANGE;++i)
        count[i]+=count[i-1];
    for (i=0;array[i];++i){
        output[count[array[i]]-1]=array[i];
        --count[array[i]];
    }
    for(i=0;array[i];++i)
        array[i]=output[i];
}

int get_max(int array[], int n)
{
    int max=array[0],i;
    for(i=1;i<n;i++)
        if (array[i]>max)
            max=array[i];
    return max;
}
void counting_sort_for_radix(int array[], int n, int div)
{
    int output[n],i,count[10]={0};
    for(i=0;i<n;i++)
        count[(array[i]/div)%10]++;
    for(i=1;i<10;i++)
        count[i]+=count[i-1];
    for(i=n-1;i>=0;i--)
    {
        output[count[(array[i]/div)%10]-1]=array[i];
        count[(array[i]/div)%10]--;
    }
    for(i=0;i<n;i++)
        array[i]=output[i];
}
void radix_sort(int arr[], int n)
{
    int m = get_max(arr,n),div;
    for (div = 1; m/div > 0; div *= 10)
        counting_sort_for_radix(arr,n,div);
}

void bucket_sort(int array[], int n) {
	int i,j,mx=get_max(array,n);
	int count_array[n];
	for (i=0;i<n;i++)count_array[i]=0;
	for (i=0;i<n;i++)(count_array[array[i]])++;
	for (i=0,j=0;i<n;i++){
		for (;count_array[i]>0;(count_array[i])--)array[j++]=i;
	}
	array[n-1]=mx;
}

void generate_sorted_array(int arr[],int SIZE){
    int i;
    for(i=0;i<SIZE;i++){
        arr[i]=i+1;
    }
}
void generate_decreasing_array(int arr[],int SIZE){
    int i,j;
    for(i=0,j=SIZE;i<SIZE;i++,j--){
        arr[i]=j;
    }
}
void generate_random_array(int arr[],int SIZE){
    int i;
    for(i=0;i<SIZE;i++)
      arr[i]=rand()%SIZE;
}

void print_array(int array[],int n){
    int i;
    for(i=0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<"\n";
}

int n,i,x;
int arr[1001];
int main() {
    n=1000;

    //generate_sorted_array(arr,n);
    //generate_decreasing_array(arr,n);
    //generate_random_array(arr,n);

    clock_t start,time;
    start = clock();

    //bubble_sort(arr,n);
    //insertion_sort(arr,n);
    //selection_sort(arr,n);
    //merge_sort(arr,1,n);
    //quick_sort(arr,1,n);
    //heap_sort(arr,n);
    //counting_sort(arr,n);
    //radix_sort(arr,n);
    //bucket_sort(arr,n);

    time = clock()-start;
    double time_taken = ((double)time)/CLOCKS_PER_SEC;
    cout<<time_taken;


    return 0;
}
