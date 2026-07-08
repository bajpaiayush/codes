#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int n=s.length();
        int ans=0;
        int count=0;
        unordered_map<char,int>m;
        for(int r=0;r<n;r++)
        {
            m[s[r]]++;
            count=max(count,m[s[r]]);
            while((r-l+1)-count>k)
            {
                m[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};
int main()
{
    string s;
    int k;
    cin>>s>>k;
    Solution sol;
    cout<<sol.characterReplacement(s,k)<<endl;
    return 0;
}