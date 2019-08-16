int main() {
    vector<int> arr = {1, 2, 7, 1};
    int target = 3, sum = 0, n = arr.size();
    
    unordered_map <int, int> curr;
    curr.insert(make_pair(0, 1));
    
    for(auto item: arr){
        unordered_map <int, int> newh;
        for(auto i = curr.begin(); i != curr.end(); i++){
            newh[((*i).first) + item] += (*i).second;
            newh[((*i).first) - item] += (*i).second;
        }
        curr = newh;
    }
    
    cout << curr[target];
    
}