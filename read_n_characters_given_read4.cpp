// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int total = 0;
        for (int i = 0; i < n / 4; ++i) {
            int temp = read4(buf);
            total += temp;
            buf += temp;
            if (temp < 4) {
                break;
            }
        }
        if (n % 4) total += read4(buf);
        return min(total, n);
    }
};