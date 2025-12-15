#define ll long long int
#define mod 1000000007
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        ll ans = 0;
        ll cnt = 1;
        for(int i=0;i<prices.size()-1;i++)
        {
            if(prices[i] - prices[i+1] == 1)
            {
                cnt++;
                if(i == prices.size()-2)
                {
                    ans = ans + (cnt%mod)*((cnt+1)%mod)/2;
                    return ans;

                    break;
                }
                continue;
            }
            ans = ans + (cnt%mod)*((cnt+1)%mod)/2;
            cnt = 1;
        }
        return ans+1;
        
    }
};