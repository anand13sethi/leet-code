/*
Link - https://leetcode.com/problems/isomorphic-strings
*/



int x = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  return 0;
}();

bool isIsomorphic(string s, string t) {
    int arr1[256] = {0}, arr2[256] = {0};
    for(int i = 0; i < s.size(); i++){
        if(arr1[s[i]] != arr2[t[i]])
            return false;
        arr1[s[i]] = i+1;
        arr2[t[i]] = i+1;
    }
    return true;
}