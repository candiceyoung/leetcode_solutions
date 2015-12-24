#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int size = citations.size();
        int low = 0; int high = size - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (citations[mid] < (size - mid)) {
                low = mid + 1;
            }
            else if (citations[mid] > (size - mid)){
                high = mid - 1;
            }
            else return size - mid;
        }
        return size - low;
    }
};
int main(void) {
    return 0;
}