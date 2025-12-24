class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(apple.begin(), apple.end());
        sort(capacity.begin(), capacity.end());


        int totalApple = 0;
        for(auto app : apple)
        {
            totalApple += app;
        }
        cout<<totalApple<<endl;

        int maxi = 0;
        int i = 0;
        int n = capacity.size();
        while(totalApple>0 && i<capacity.size())
        {
                maxi++;
                totalApple -= capacity[n-i-1];
                cout<<totalApple<<"\t";
            
            i++;
        }

        return maxi;
        
    }
};