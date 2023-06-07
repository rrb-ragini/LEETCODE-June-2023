class Solution {
public:
    int minFlips(int a, int b, int c) {
    int flip = 0;
    while (c or a or b) {
        if ((c & 1) == 1) {
            if (((a & 1) == 0) and ((b & 1) == 0))
                flip++;
        } else {
            if ((a & 1) == 1)
                flip++;
            if ((b & 1) == 1)
                flip++;
        }
        c = c >> 1;
        a = a >> 1;
        b = b >> 1;
    }
    return flip;
}

};