int reverse(int x){
    int nums[10] = {0};
    int index = 0;
    int y = 0;
    int MAX_INT = 2147483647;
    bool minus = x < 0;

    if(x == -(MAX_INT + 1))
        return 0;

    x = abs(x);

    while(x != 0)
    {
        nums[index++] = x % 10;
            x /= 10;
    }
    int C = 1;
    for(int i = index - 1; i >= 0; i--)
    {
        if(index == 10 && i == 0)
        {
            
            if(nums[i] > 2 || MAX_INT - nums[i]*C < y)
                return 0;
        }
        y += nums[i]*C;
        C *= 10;
    }

    if(minus)
        y = -y;

    return y;
}