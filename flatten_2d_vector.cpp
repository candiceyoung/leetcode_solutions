class Vector2D {
private:
    vector<vector<int>>::iterator it1, it3;
    vector<int>::iterator it2;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        it1 = vec2d.begin();
        it3 = vec2d.end();
        if (it1 != it3) it2 = it1->begin();
        
    }

    int next() {
        int result = *it2;
        it2++;
        return result;
    }

    bool hasNext() {
        if (it1 == it3) return false;
        if (it2 == it1->end()) {
            it1++;
            while (it1 != it3 && it1->begin() == it1->end()) it1++;
            if (it1 == it3) return false;
            else {
                it2 = it1->begin();
                return true;
            }
        }
        else return true;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */