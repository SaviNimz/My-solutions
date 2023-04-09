#include <iostream>
#include <vector>

using namespace std;
void running(vector<int> &vec , int val);
double get_median(vector<int> nums);
int main()
{
    int data_stream[10] = {7,3,5,2,10,6,9,12,7,4};

    vector<int> val = {};

    for (int i = 0 ; i < 10 ; i++){
        running(val , data_stream[i]);
        for (int i =0 ; i < val.size() ; i++){
            cout << val[i] << " ";
        }
        cout << " |median is : " << get_median(val) << endl;
    }
    return 0;
}

void running(vector<int> &vec , int val){
    if (vec.size() == 0){
        vec.push_back(val);
    }
    if (val > vec[vec.size()-1]){
        vec.push_back(val);
    }
    else{
    for (int i = 0 ; i < vec.size() ; i++){

        if (vec[i] > val){
            vec.insert(vec.begin() + i , val);
            break;
            }
        }
    }
}

double get_median(vector<int> nums) {
    int n = nums.size();
    if (n % 2 == 0) {
        return (double)(nums[n/2] + nums[n/2-1]) / 2;
    } else {
        return (double)nums[n/2];
    }
}
