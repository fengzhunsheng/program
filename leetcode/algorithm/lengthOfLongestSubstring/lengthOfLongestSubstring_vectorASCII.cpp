class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // left用以记录合法的最远左边界位置
	    int maxLength = 0, left = 0, len = s.size();

        if(len <= 1) return len;
        
		// last记录字符上一次出现的位置，字符的值是0-128，初始值置为-1
		vector<int> last(128, -1);

		// i是隐藏的右边界
		for (int i = 0; i < len; i++) {
			// 右边界的值如果没出现应该为-1；不为-1说明该子串中出现了重复字符，需调整left
			if (last[s[i]] >= left) left = last[s[i]] + 1;

			// 更新右边界的值
			last[s[i]] = i;

			maxLength = max(maxLength, i - left + 1);
		}
		return maxLength;
    }
};