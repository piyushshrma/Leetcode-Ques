class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int ans=0;

        priority_queue<int> pq(piles.begin(), piles.end());

        for(int i=0; i<piles.size(); i++){
            ans+=piles[i];
        }

        while(k--){
            int val=pq.top();
            pq.pop();
            int remove = floor(val/2);
            ans-=remove;
            pq.push(val-remove);
        }
        
        return ans;
    }
};