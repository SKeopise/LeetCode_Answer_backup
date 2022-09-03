int reverse(int x) {

    int y = 0;
    int buf = 0;
    buf = x;

    while (x != 0)
    {
        if (y > pow(2, 31) / 10 || y < pow(-2, 31) / 10)
        {
            return 0;
        }
        buf = x % 10;
        y = y * 10 + buf % 10;
        x = x / 10;

    }

    return y;
}