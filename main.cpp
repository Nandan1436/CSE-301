#include <bits/stdc++.h>

using namespace std;

struct item{
    int value;
    int weight;
};

void sortBasedOnRatio(struct item items[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1;j++){
            if( (double)(items[j].value/items[j].weight) < (double)(items[j+1].value/items[j+1].weight) ){
                struct item temp=items[j];
                items[j]=items[j+1];
                items[j+1]=temp;
            }
        }
    }
}

int findKnapsack(struct item items[],int totalWeight,int numOfItems){
    sortBasedOnRatio(items,numOfItems);
    int ans=0,currWeight=0,i=0;
    while(currWeight<=totalWeight){
        if(totalWeight>=currWeight+items[i].weight){
            ans+=items[i].value;
            currWeight+=items[i].weight;
            i++;
            continue;
        }
        double fraction=double(items[i].value/items[i].weight);
        ans+=fraction*(totalWeight-currWeight);
        break;
    }

    return ans;
}

int main()
{
    freopen("knapsack.txt","r",stdin);
    int numOfItems,totalWeight;
    cin>>numOfItems;
    struct item items[numOfItems];
    for(int i=0;i<numOfItems;i++) cin>>items[i].value>>items[i].weight;
    cin>>totalWeight;
    int ans = findKnapsack(items,totalWeight,numOfItems);
    for(int i=0;i<numOfItems;i++)cout<<items[i].value<<" "<<items[i].weight<<endl;
    cout<<"Total profit: "<<ans;

    return 0;
}
