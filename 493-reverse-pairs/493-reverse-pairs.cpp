class Solution {
public:
//     int merge(vector<int> &a, int low, int mid, int high)
//     {
//         int total =0;
//         int j =mid+1;
//         for(int i=low; i<mid+1; i++)
//         {
//             while(j<=high && a[i]>2LL*a[j])
//             {
//                 j++;
//             }
//             total =(j-(mid+1));
//         }
//         vector<int> t;
//         int left =low;
//         int right = mid+1;
//         while(left<=mid && right<=high)
//         {
//             if(a[left]<=a[right])
//             {
//                 t.push_back(a[left++]);
//             }
//             else
//             {
//                 t.push_back(a[right++]);
//             }
//         }
//         while(left<=mid)
//         {
//             t.push_back(a[left++]);
//         }
//         while(right<=high)
//         {
//             t.push_back(a[right++]);
//         }
//         for(int i=low; i<=high; i++)
//         {
//             a[i]=t[i-low];
//         }
//         return total;
//     }
    
//     int mergesort(vector<int> &arr, int left, int right)
//     {
//         int inv=0;
//         if(left>=right)
//         {
//             return 0;
//         }
//         else
//         {
//             int mid = (left+right)/2;
//             inv = mergesort(arr,left, mid);
//             inv+= mergesort(arr,mid+1,right);
//             inv+=merge(arr, left,mid,right);
//         }
//         return inv;
//     }
    
//     int reversePairs(vector<int>& nums) {
//         int n = nums.size();
//         // int pairs =0;
//         // for(int i =0; i<n; i++)
//         // {
//         //     for(int j=i+1; j<n;j++)
//         //     {
//         //         if(nums[i]>(2*nums[j]))
//         //         {
//         //             pairs++;
//         //         }
//         //     }
//         // }
//         // return pairs;
//         return mergesort(nums, 0, n-1);
//     }
    int Merge(vector < int > & nums, int low, int mid, int high) {
  int total = 0;
  int j = mid + 1;
  for (int i = low; i <= mid; i++) {
    while (j <= high && nums[i] > 2LL * nums[j]) {
      j++;
    }
    total += (j - (mid + 1));
  }

  vector < int > t;
  int left = low, right = mid + 1;

  while (left <= mid && right <= high) {

    if (nums[left] <= nums[right]) {
      t.push_back(nums[left++]);
    } else {
      t.push_back(nums[right++]);
    }
  }

  while (left <= mid) {
    t.push_back(nums[left++]);
  }
  while (right <= high) {
    t.push_back(nums[right++]);
  }

  for (int i = low; i <= high; i++) {
    nums[i] = t[i - low];
  }
  return total;
}
int MergeSort(vector < int > & nums, int low, int high) {

  if (low >= high) return 0;
  int mid = (low + high) / 2;
  int inv = MergeSort(nums, low, mid);
  inv += MergeSort(nums, mid + 1, high);
  inv += Merge(nums, low, mid, high);
  return inv;
}
int reversePairs(vector < int > & arr) {
  return MergeSort(arr, 0, arr.size() - 1);
}
};