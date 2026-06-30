class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> value;
    for(int x: nums){
        value.insert(x);
    }
    set<int>::iterator it=value.begin();
    cout<<value.count(2);
    int max=0,count=0,target=0;
    target=*(it);
    for(int i=0;i<value.size();i++){
        if(value.count(target)){
            count++;
            target++;
        }
        else{
            target=*(it)+1;
            count =1;
        }
        if(max<=count){
            max=count;
        }
        it++;
    }       
    return max;
    }
};
