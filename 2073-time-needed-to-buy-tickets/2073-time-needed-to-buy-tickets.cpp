class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int count=0; 
        for(int i=0;i<tickets.size();i++)
        {if(tickets[i]<tickets[k])
        {
            count+=tickets[i];
            
        }
         else
             
         {
             count+=tickets[k];
         }
         if(i>k and tickets[i]>=tickets[k])
         {
             count--;
         }
        }
        return count;}};