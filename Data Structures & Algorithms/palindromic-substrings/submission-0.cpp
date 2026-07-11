class Solution {
public:

   int expandcentre(string s , int left , int right){
        int cnt = 0;

        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
            cnt++;
        }

        return cnt;
    }

    int countSubstrings(string s) {

        int start = 0;
        int maxlen = -1;
        int n = s.size();
        int count = 0;

        for(int i = 0 ; i < n ; i++){

            int len1 = expandcentre(s , i , i);
            int len2 = expandcentre(s , i , i+1);

            count += len1 + len2;

            // if(len > maxlen){
            //     maxlen = len;
            //     start = i - (len-1)/2;
            // }

        }

        return count;

        
        
    }
};
