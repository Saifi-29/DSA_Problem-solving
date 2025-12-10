class Solution {
    long long int factorial(int n)
    {
        long long int ans = 1;
        while(n>0)
        {
            ans = ans%1000000007 * n%1000000007;
            n--;
        }
        return ans;
    }
public:
    int countPermutations(vector<int>& complexity) {
        // sort(complexity.begin(), complexity.end());
        int min = complexity[0];
        for(int i=1;i<complexity.size();i++)
        {
            if(complexity[0] == complexity[i])
            return 0;
            if(complexity[i]<min)
            return 0;
        }
        return factorial(complexity.size()-1);


    }
};