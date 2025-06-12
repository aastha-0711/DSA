class Solution {
    private:
    bool possible(vector<int> &bloomDay,int day, int m, int k){
        int count=0;
        int number=0;
        
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                count++;
            }

            else{
number+=count/k;
count=0;
            }}
            number+=count/k;
        
        if(number>=m){
            return true;
        }
        else{ return false;}
    }
public:
int minDays(vector<int>& bloomDay, int m, int k) {
    if(1LL * m * k > bloomDay.size()) return -1;

    int minn = *min_element(bloomDay.begin(), bloomDay.end());
    int maxx = *max_element(bloomDay.begin(), bloomDay.end());
    int day = -1;

    while(minn <= maxx){
        int mid = minn + (maxx - minn) / 2;
        if(possible(bloomDay, mid, m, k)){
            day = mid;
            maxx = mid - 1;
        } else {
            minn = mid + 1;
        }
    }

    return day;
}};
