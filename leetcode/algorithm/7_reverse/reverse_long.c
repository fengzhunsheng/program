#define MIN 0x80000000

int reverse(int x){
    bool minus = x < 0;
    long long y = 0;

    if(x == MIN)
        return 0;

    x = abs(x);

    while(x != 0)
    {
        y = y*10 + x % 10;
        x /= 10;
    }

    if(minus)
        y = -y;

    if(y != (int)y )
        return 0;    

    return y;
}