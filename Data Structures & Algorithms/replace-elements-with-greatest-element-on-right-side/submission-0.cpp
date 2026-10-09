class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // vector<int> ans;
        for(int i =0;i<arr.size();i++){
            if(i == arr.size()-1){
                arr[i] = -1;
                break;
            }
            int temp = arr[i+1];
            for(int j =i+1;j<arr.size();j++){
                temp = max(temp,arr[j]);
            }
            arr[i] = temp;
        }
        return arr;
    }
};