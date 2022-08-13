class Solution {
public:
    void merge(vector<int>&nums,int l,int mid,int r)
    {
        if(l>=r)
            return;
        int i=l;
        int j=mid+1;
        vector<int>sorted;
        while(i<=mid&&j<=r)
        {
            if(nums[i]<=nums[j])
                sorted.push_back(nums[i]),i++;
            else
                sorted.push_back(nums[j]),j++;
        }
        if(i>mid)
        {
            while(j<=r)
                sorted.push_back(nums[j]),j++;
        }
        else
        {
            while(i<=mid)
                sorted.push_back(nums[i]),i++;
        }
        int k=0;
        for(int i=l;i<=r;i++)
        {
            nums[i]=sorted[k];
            k++;
        }
    }
    void mergesort(vector<int>&nums,int l,int r)
    {
        if(l<r){
        int mid=(l+r)/2;
        mergesort(nums,l,mid);
        mergesort(nums,mid+1,r);
        merge(nums,l,mid,r);
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};