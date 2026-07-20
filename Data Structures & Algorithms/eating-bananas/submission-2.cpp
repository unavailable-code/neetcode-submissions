class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
    int maximum=0;
    for(int i=0;i<piles.size();i++){
        maximum=max(piles[i],maximum);
    }
    int ans=maximum;
    int l=1;
    while(l<=maximum){
        int mid=(l+maximum)/2;
        cout<<mid<<endl;
        int hours=0;
        for(int i=0;i<piles.size();i++){
            hours+=(piles[i]+mid-1)/mid;
            
        }
        if(hours>h){
            l=mid+1;
        }
        else{
            maximum=mid-1;
            ans=min(mid,ans);
        }
        
    }
    return ans;

    }
};
