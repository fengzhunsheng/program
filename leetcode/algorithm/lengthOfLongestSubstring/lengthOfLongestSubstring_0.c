int lengthOfLongestSubstring(char * s){
    int maxLength = 0;
    int r;
    int l = 0;
    int i;

    for(r = 0; r < strlen(s); r++)
    {
        for(i = l; i < r; i++)
        {
            if(s[i] == s[r])
            {
                l = i + 1;
                break;
            }
        }

        if(r - l + 1> maxLength)
        {
            maxLength = r - l + 1;
        }
    }

    return maxLength;
}