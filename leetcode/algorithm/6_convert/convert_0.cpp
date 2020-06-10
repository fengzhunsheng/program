class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        if(numRows <= 1 || size <= 2) return s;

        int step;
        string res(size, 0);
        int index = 0;

        for(int i = 0; i < numRows; i++)
        {   
            step = (numRows - 1 -i)*2;
            int j = i;
            while(j < size)
            {
                res[index++] = s[j];
                if(step != (numRows-1)*2 && step != 0)
                {
                    j += step;
                    step = (numRows-1)*2 - step;
                }
                else if(step == 0)
                {
                    step = (numRows-1)*2 - step;
                    j += step;
                }
                else j += step;
            }
        }
        return res;
    }

};