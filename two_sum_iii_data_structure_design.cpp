class TwoSum {
private:
    unordered_map<int, int> m;
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    m[number]++;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    unordered_map<int, int>::iterator it;
	    for (it = m.begin(); it != m.end(); ++it) {
	        int x = it->first, y = value - x;
	        if (x == y) {
	            if (it->second > 1) return true;
	        }
	        else {
	            if (m.find(y) != m.end()) return true;
	        }
	    }
	    return false;
	}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);