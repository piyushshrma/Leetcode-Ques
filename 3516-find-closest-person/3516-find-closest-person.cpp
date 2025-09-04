class Solution {
public:
    int findClosest(int x, int y, int z) {
        int diffXZ=abs(x-z)+1;
        int diffYZ=abs(y-z)+1;

        if(diffXZ>diffYZ){
            return 2;
        }
        else if(diffXZ<diffYZ){
            return 1;
        }
        return 0;
    }
};