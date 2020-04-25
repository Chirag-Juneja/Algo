/* 
Alog: Insertion Sort
Time Complexity: O(n)=n*n
*/

#include <iostream>
#define LOG(x) std::cout << x << std::endl

void insertionSort(int *array,int size){
    for(int j=1;j<size;j++){
        int key = array[j];
        int i = j-1;
        while(i >= 0 && array[i] > key){
            array[i+1]=array[i];
            i--;
        }
        array[i+1]=key;
    }
}

int main(int argc,char *argv[]){
    int array[]={9,7,4,3,5,68,1,6};
    
    insertionSort(array,sizeof(array)/4);

    for(int i =0;i<sizeof(array)/4;i++){
        LOG(array[i]);
    }
    return 0;
}