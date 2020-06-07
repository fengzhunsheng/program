class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int maxLength = 0;
       int lPos = 0;
       int rPos = 0;

       while(rPos < s.length())
       {
            // 当前从lPos到rPos这一无重复字串
            if(rPos - lPos + 1 > maxLength)
            {
                maxLength = rPos - lPos + 1 ;
            }

            // 右边界向右移动一个字符
            rPos++;

            string subStr = s.substr(lPos, rPos - lPos);

            int idx = subStr.find(s[rPos]);
            if( idx != string::npos)
            {
                lPos += idx + 1;
            }
       }
       return maxLength;
    }
};