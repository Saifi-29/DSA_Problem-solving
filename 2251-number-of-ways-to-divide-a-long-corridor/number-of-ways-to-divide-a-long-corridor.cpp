#define ll long long int
#define mod 1000000007

class Solution {
public:
    int numberOfWays(string corridor) {
        ll ans = 1;
        int noofseats = 0, n = corridor.size(), last = -1;

        for(int i=0;i<n;i++)
        {
            if(corridor[i]=='P')
            continue;

            noofseats++;
            if(noofseats>=3 && noofseats%2==1)
            {
                int partition = i - last;
                ans = (ans * partition)%mod;
            }

            last = i;
        }
        return (noofseats == 0 || noofseats%2 == 1) ? 0 : ans;
        
    }
};