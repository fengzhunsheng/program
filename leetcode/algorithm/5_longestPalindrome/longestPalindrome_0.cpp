class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size <= 1) return s;

        int start;
        int maxLength = 0;

        int lPointer = 0;
        int rPointer = 0;
        float mPointer = 0;

        int cur_l = lPointer;
        int cur_r = rPointer;
        while (mPointer < size - 1)
        {
            if (cur_l >= cur_r)
            {
                if (rPointer - lPointer + 1 > maxLength)
                {
                    start = lPointer;
                    maxLength = rPointer - lPointer + 1;
                }

                mPointer += 0.5;
                lPointer = 0;
                rPointer = (int)(2 * mPointer - lPointer);
                if (rPointer > size - 1)
                {
                    rPointer = size - 1;
                }
                lPointer = 2 * mPointer - rPointer;

                cur_l = lPointer;
                cur_r = rPointer;
            }
            else
            {
                if (s[cur_l] == s[cur_r])
                {
                    cur_l++;
                    cur_r--;
                }
                else
                {
                    lPointer++;
                    rPointer--;

                    cur_l = lPointer;
                    cur_r = rPointer;
                }
            }
        }

        return s.substr(start, maxLength);
    }
};