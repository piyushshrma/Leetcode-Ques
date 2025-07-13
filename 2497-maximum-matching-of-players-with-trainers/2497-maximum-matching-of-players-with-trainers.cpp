class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(trainers.begin(), trainers.end());
        sort(players.begin(), players.end());
        int ct=0;

        int i=0, j=0;

        while(i < players.size() && j < trainers.size()){
            if(players[i]<=trainers[j]){
                ct++;
                i++;
            }
            j++;
        }


        return ct;
    }
};