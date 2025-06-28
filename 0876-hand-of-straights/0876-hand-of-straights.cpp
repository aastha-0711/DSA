class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()% groupSize!=0){return false;}
        map<int, int> count;  // Sorted map for ordered keys (like heap of keys)
        for (int card : hand) {
            count[card]++;
        }
        while(!count.empty()){
            int first = count.begin()->first;
             for (int i = 0; i < groupSize; ++i) {
                int curr = first + i;
                if (count.find(curr) == count.end()) return false;
 count[curr]--;
                if (count[curr] == 0) {
                    count.erase(curr);  // Remove if used up
                }
            }
        }
        return true;
    }
};
