#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

bool checkExist(int big, map<int,int>find){
    
        int base=1;
        while (big>=base){
            base*=2;
        }
        base/=2;
    
        int temp=big;
       // cout<<"Checking for "<<big<<" :"<<endl;
        while (base!=0){
           // cout<<base<<endl;
            
            if (find.count(base)==0){
                
            }else{
                find.erase(base);
            }
            temp=temp-base;
            while(temp<base){
                base/=2;
            }
        }
    
        for (map<int,int>::iterator f=find.begin();f!=find.end();f++){
            if(f->second==1){
                return false;
            }
        }

        return true;
     
}

int main() {
    map<int,int> nim;
    int n;
    int A[n];
    cout<<"Input the row of the matches"<<endl;
    cin>>n;
    cout<<"Input the matches on each row in a line seperated by space"<<endl;
    for (int i=0;i<n;i++){
        cin>>A[i];
    }
    
    for (int i=0;i<n;i++){
            
        int base=1;

        while (A[i]>=base){
            base*=2;
        }

        base/=2;
        int temp=A[i];
        while (base!=0){
            if (nim.count(base)==0){
                nim[base]=1;
            }else{
                nim[base]=nim[base]+1;
            }
            temp=temp-base;
            while(temp<base){
                base/=2;
            }
        }
    }
    
    
    for (map<int,int>::iterator f=nim.begin();f!=nim.end();f++){
       // cout<<"Number "<<f->first<<" has "<<f->second<<endl;
        if (f->second%2==0){
            nim.erase(f->first);
            f=nim.begin();
        }else{
            nim[f->first]=1;
        }
    }
    if (nim.begin()->second%2==0){
        nim.erase(nim.begin()->first);
    }else{
        nim[nim.begin()->first]=1;
    }
    int sum=0;
    for (map<int,int>::iterator f=nim.begin();f!=nim.end();f++){
        sum+=f->first;
        cout<<"Number "<<f->first<<" is left without a pair "<<endl;
    }
    
    int answer=0;
    if (nim.size()==0){
        cout<<"0"<<endl;
    }else{
        for (int i=0;i<n;i++){
            if (checkExist(A[i],nim)){
                cout<<"You could try take out "<<sum<<" at row "<<i+1<<" :"<<A[i]<<endl;   
                answer++;
            }
        }
        cout<<"There are "<<answer<<" ways of making the rest nim"<<endl;
    }
    return 0;
}
