#include <iostream>
using namespace std;

// HeapSort
// void heapify(vector<int> &nums,int heap_size,int i){
//     int largerst = i;
//     int left = 2*largerst+1,right = 2*largerst+2;
//     if(left<heap_size && nums[left]>nums[largerst]) largerst = left;
//     if(right<heap_size && nums[right]>nums[largerst]) largerst = right;
//     if(largerst!=i){
//         swap(nums[i],nums[largerst]);
//         heapify(nums,heap_size,largerst);
//     }
// }

// int findKthLargest(vector<int>& nums, int k) {
//     int heap_size = nums.size();
//     for (int i = heap_size/2-1; i >= 0 ; i--) heapify(nums,heap_size,i);
//     for (int i = 0; i < k; i++) {
//         swap(nums[0],nums[heap_size-1]);
//         heap_size--;
//         heapify(nums,heap_size,0);
//     }
//     return nums[heap_size];
// }

// int findKthLargest(vector<int>& nums, int k) {
//     priority_queue<int,vector<int>,greater<int>> pq;
//     for (int i = 0; i < nums.size(); i++) {
//         pq.push(nums[i]);
//         if(pq.size()>k) pq.pop();
//     }
//     return pq.top();
// }

// quick sort 
int partition(vector<int> &nums,int left,int right){
    int pivot = nums[right],p_index = left;
    for (int i = left; i < right; i++) if(nums[i]>=pivot) swap(nums[p_index++],nums[i]);
    swap(nums[p_index],nums[right]);
    return p_index;
}

int findKthLargest(vector<int>& nums, int k) {
    int left = 0,right = nums.size()-1;
    while(true){
        int pivot_index = partition(nums,left,right);
        if(pivot_index == k-1) return nums[k-1];
        else if(k-1<pivot_index) right = pivot_index-1;
        else left = pivot_index+1;
    }
}

int main() {
	// leetcode
	// https://leetcode.com/problems/k-closest-points-to-origin/
	return 0;
}

