class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if (size <= 1) return s;

        int start;
        int maxLength = 0;

        int lPointer;
        int rPointer;
        int mPointer;

        for(mPointer = 0; mPointer < size - 1; mPointer++)
		{
			lPointer = mPointer;
			rPointer = lPointer;
			
			while(rPointer < size - 1 && s[rPointer+1] == s[lPointer])
				rPointer++;
			
			mPointer = rPointer;
			
			while(lPointer > 0 && rPointer < size -1 && s[lPointer-1] == s[rPointer+1])
			{
				lPointer--;
				rPointer++;
			}
			
			if(rPointer - lPointer + 1 > maxLength)
			{
				maxLength = rPointer - lPointer + 1;
				start = lPointer;
				
				if(size - lPointer <= maxLength) break;
			}	
		}

        return s.substr(start, maxLength);
    }
};