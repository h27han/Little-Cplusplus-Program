#include <iostream>

using namespace std;


void display(int arr[],int length){
     for (int i=0;i<length;i++){
         cout<<arr[i]<<" ";    
     }     
     cout<<endl;
}

void swap(int arr[],int index1,int index2){
	int save = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = save;
	return;
}




//Choose the biggest/smallest of current and exclude it next loop
void SelectionSort(int arr[],int length){
	for (int i = 0; i < length - 1; i++){
		int minIndex = i;
		for (int r = i + 1; r < length - 1; r++){
		    if (arr[r]<arr[minIndex])
            {
               minIndex = r;
            }
		}
		swap(arr, i, minIndex);
	}
	return;
}

//Insert element one by one into sorted part
void InsertionSort(int arr[],int length){
     for (int i=0; i< length - 1;i++){
         int currentPosition = i;
         for (int r=i-1; r>=0;r--){
             if (arr[currentPosition]<arr[r]){
                 swap(arr,currentPosition,r);
                 currentPosition --; 
             }
         }    
     }
     return;    
}

//Compare two each time and loop 
void BubbleSort(int arr[],int length){
     for (int i=length-1;i>0;i--){
         for (int r=0;r<i;r++){
             if (arr[r]>arr[r+1]){
                swap(arr,r,r+1);                     
             }    
         }
     }

}






//Merge two sorted arrays into 1
//(using one array here)
void Merge(int arr[],int ibegin,int imiddle,int iend){
    
     //cout<<ibegin<<" to "<<imiddle<<" merging with "<<imiddle+1<<" to "<<iend<<endl;
     int backup[iend-ibegin+1];
     int count1=ibegin;
     int count2=imiddle+1;
   
     for (int i=0;i<iend-ibegin+1;i++){
         if ((count2>iend)||((arr[count1]>arr[count2])&&(count1<=imiddle))){
            backup[i]=arr[count1];
            count1++;                        
         }else{
            backup[i]=arr[count2];
            count2++;               
         }
     }
     
     for (int i=0;i<iend-ibegin+1;i++){
         arr[ibegin+i]=backup[i];
             
     }
}

void TopDownMergeSortWrapper(int arr[],int start,int end){  
     if (start==end){
        return;                
     }else{

        TopDownMergeSortWrapper(arr,start,(start+end)/2);
        TopDownMergeSortWrapper(arr,(start+end)/2+1,end);
        
       Merge(arr,start,(start+end)/2,end);     
     }
}

void TopDownMergeSort(int arr[],int length){
     TopDownMergeSortWrapper(arr,0,length-1);   
}


void BottomUpMergeSort(int arr[],int length){
     int i;
     for (i=1;i<length;i*=2){
         for (int r=0;r<length;r+=i){
             if(i!=1){
                   if (r+i-1>=length){
                      if (r!=length-1){
                         Merge(arr,r,(r+length-1)/2,length-1); 
                         }       
                   }else{
                      Merge(arr,r,(r+r+i-1)/2,r+i-1);
                   }
                   
             }
         } 
     }
     Merge(arr,0,i/2-1,length-1);
}






void QuickSortHelper(int arr[],int start,int end){
     
     if (start>=end){
        return;                
     }
     int pivot = arr[start];
     int pos = end;
     for (int i=end;i>start;i--){
         if (arr[i]>pivot){
            swap(arr,i,pos);                  
            pos--;   
         }
     }
     swap(arr,start,pos);
     QuickSortHelper(arr,start,pos-1);
     QuickSortHelper(arr,pos+1,end);
}


void QuickSort(int arr[],int length){
          
     QuickSortHelper(arr,0,length-1);
     
}






void MaxNode (int arr[],int start,int length){
     if ((start*2+1<length)&&(arr[start*2+1]>arr[start])){
        swap(arr,start,start*2+1); 
       
     }             
     if ((start*2+2<length)&&(arr[start*2+2]>arr[start])){
        swap(arr,start,start*2+2);            
                                    
     }
}

void MaxHeapify(int arr[],int length){
     for (int start = (length-2)/2;start>=0;start --){
         MaxNode(arr,start,length);
         }
}


void HeapSort(int arr[],int length){
     for (int i = length;i>1;i--){ 
             MaxHeapify(arr,i);
             swap(arr,0,i-1);
     }
     
}
     
int main(){
	int arr[] = { 5,3,1,6,2,8,20,1,4,98,-5 };
	int len = 11;

    //SelectionSort(arr,len);
    //InsertionSort(arr,len);
    //BubbleSort(arr,len);
    //TopDownMergeSort(arr,len);
    //BottomUpMergeSort(arr,len);
    //HeapSort(arr,len);
    //QuickSort(arr,len);
    display(arr,len);
    
    
    

    system("PAUSE");
	return 0;
}

