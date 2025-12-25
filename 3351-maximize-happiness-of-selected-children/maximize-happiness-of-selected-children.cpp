class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        
        long long int count = 0, sum = 0;
        long long int i=happiness.size()-1;
        while(count != k && i>=0)
        {
            if(happiness[i] <= 0)
            return sum;

            sum = sum + happiness[i];
            count++;
            if(count==k)
            return sum;

            if(happiness[i-1] > 0)
            happiness[i-1] -= count;
            i--;
        }
        return sum;
    }
};