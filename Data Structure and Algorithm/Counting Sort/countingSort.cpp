//
// Created by obaidsafi31 on 11/16/24.
//
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

void countingSort(vector<int> & arr)
{
    if(arr.empty()) return;

    int max_value = *max_element(arr.begin(), arr.end());
    int min_value = *min_element(arr.begin(),arr.end());

    int range = max_value - min_value +1;

    vector<int> count(range, 0);

    for (int num : arr) count[num-min_value]++;

    for (int i = 1; i < range; i++) count[i] += count[i-1];

    vector<int> output(arr.size());
    for(int i = arr.size()-1; i >=0 ; --i){
        output[count[arr[i]-min_value]-1] = arr[i];
        count[arr[i]-min_value]--;
    }
    arr = output;

}

int main()
{
    vector<int> arr = {4,2,2,8,3,3,1};
    countingSort(arr);
    cout << " Sorted Array : ";
    
    for (int num : arr) cout << num << " " ;
    
    cout << endl;
    return 0;
}