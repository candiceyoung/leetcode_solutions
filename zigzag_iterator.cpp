class ZigzagIterator {
private:
    vector<int>::iterator it1, it2;
    int len1, len2;
    int i1, i2;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        it1 = v1.begin();
        it2 = v2.begin();
        i1 = 0; i2 = 0;
        len1 = v1.size();
        len2 = v2.size();
    }

    int next() {
        if (i1 == len1) { i2++; return *(it2++); }
        if (i2 == len2) { i1++; return *(it1++); }
        if (i1 == i2) { i1++; return *(it1++); }
        else { i2++; return *(it2++); }
    }

    bool hasNext() {
        if (i1 < len1 || i2 < len2) return true;
        else return false;
    }
};
/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */