#include <bits/stdc++.h>

using namespace std;

int L[100];
int L2[100];
int previous[100];
int index;

void LIS(int num[],int n)
{
    int i,index=0,prev[n+1];
    L[0]=-INT_MAX;
    L2[0]=-1;
    previous[0]=-1;
    for(i=1;i<=n;i++){
        if(L[index]<=num[i]){
            L[++index]=num[i];
            L2[index]=i;
            previous[i]=L2[index-1];
        }
        else {
            int s=0,h=index;
            while(s<h){
                int mid=(s+h)/2;
                if(L[mid]<num[i])s=mid+1;
                else h=mid;
            }
            L[s]=num[i];
            L2[s]=i;
            previous[i]=L2[s-1];
        }
        for(int k=1;k<=index;k++)cout<<L[k]<<" ";
        cout<<endl;

    }
    for(i=0;i<=n;i++)cout<<previous[i]<<" ";
    cout<<endl;
    //for(i=1;i<=index;i++)cout<<L[i]<<" ";
}

void printLIS(int num[],int n)
{
    int j=0,i,largest=-INT_MAX;
    int arr[n+1];
    for(i=0;i<=n;i++){
        if(L[i]>largest){
            largest=L[i];
        }
    }
    for(i=0;i<=n;i++)if(num[i]==largest)break;
    while(i!=-1){
        arr[j++]=num[i];
        i=previous[i];
    }
    cout<<"LIS is: ";
    j--;
    while(j>=0){
        cout<<arr[j]<<" ";
        j--;
    }

}

int main()
{
    freopen("myFile.txt","r",stdin);
    int i,n;
    cin>>n;
    int num[n+1];
    num[0]=0;
    for(i=1;i<=n;i++){
        cin>>num[i];
    }
    cout<<"Given array: ";
    for(i=1;i<=n;i++)cout<<num[i]<<" ";
    cout<<endl;
    LIS(num,n);
    printLIS(num,n);

    return 0;
}
