class Solution {
public:
    int expandcentre(string s , int left , int right){

        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }

        return right - left - 1;
    }
    string longestPalindrome(string s) {

        if (s.empty()) return "";

        int start = 0;
        int maxlen = -1;
        int n = s.size();

        for(int i = 0 ; i < n ; i++){

            int len1 = expandcentre(s , i , i);
            int len2 = expandcentre(s , i , i+1);

            int len = max(len1 , len2);

            if(len > maxlen){
                maxlen = len;
                start = i - (len-1)/2;
            }

        }

        return s.substr(start , maxlen);

        
    }
};
