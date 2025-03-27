class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        set<int> st1(nums1.begin(),nums1.end());
        set<int> st2(nums2.begin(),nums2.end());
        set<int> st3(nums3.begin(),nums3.end());
        set<int> ans;
        vector<int> ansINvec;

        for(auto& num : st1){
            if(st2.count(num) || st3.count(num)){
                ans.insert(num);
            }
        }

        for(auto& num : st2){
            if(st1.count(num) || st3.count(num)){
                ans.insert(num);
            }
        }

        for(auto& num : st3){
            if(st2.count(num) || st1.count(num)){
                ans.insert(num);
            }
        }

        for(auto& i : ans){
            ansINvec.push_back(i);
        }

        return ansINvec;
    }
};

// class Solution {
// public:
//     vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
//         vector<int> ans;
//         map<int, int> mp1;
//         map<int, int> mp2;
//         map<int, int> mp3;

//         for(auto& i : nums1){
//             mp1[i]=1;
//         }
//         // for(auto& i : mp){
//         //     if(i.second>1){
//         //         i.second=1;
//         //     }
//         // }

//         for(auto& i : nums2){
//             mp2[i]=1;
//         }
//         // for(auto& i : mp){
//         //     if(i.second>1){
//         //         i.second=1;
//         //     }
//         // }

//         for(auto& i : nums3){
//             mp3[i]=1;
//         }
//         // for(auto& i : mp){
//         //     if(i.second>1){
//         //         i.second=1;
//         //     }
//         // }

//         for(auto& i : mp1){
//             if(mp2.count(i.first) || mp3.count(i.first)){
//                 ans.push_back(i.first);
//             }
//         }

//         for(auto& i : mp2){
//             if(mp1.count(i.first) || mp3.count(i.first)){
//                 ans.push_back(i.first);
//             }
//         }

//         for(auto& i : mp3){
//             if(mp2.count(i.first) || mp1.count(i.first)){
//                 ans.push_back(i.first);
//             }
//         }
//         return ans;
//     }
// };