bool isPalindrome(int x){
    if(x < 0 || (x % 10 == 0 && x != 0))
        return false;

    int y = 0;
	// 反转一半
    while(y < x)
    {
        y = y*10 + x % 10;
        x /= 10;
    }

	// 奇数个数字和偶数个数字，反转一半不同
    return (y == x) || (y / 10 == x);
}