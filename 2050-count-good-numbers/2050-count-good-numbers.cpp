class Solution {
    const long long MOD=1e9+7;
    long long power(long long count,long long n){
        if(n==0){return 1;}
        long long half=power(count,n/2);
        long long result=(half*half)%MOD;
        if(n%2==1){
            result=(result*count)%MOD;

        }
        return result;
    }
public:

    int countGoodNumbers(long long n) {
      long long evencount=(n+1)/2;
      long long oddcount=n/2;
      long long evenways=power(5,evencount);
      long long oddways=power(4,oddcount);
      return (evenways*oddways)%MOD;  
    }
};