//https://leetcode.com/problems/sort-colors/

M1-using three count variable zero, one, two
count the occourence of all three numbers in nums
first filll 0 untill zero-- , then one-- fill 1, then two-- fill 2


M-2 using mid variable

void sortColors(vector<int>& nums) {
	int low=0,mid=0,high=nums.size()-1;
	while(mid<=high)
	{
		switch(nums[mid])
		{
			case 0: 
				swap(nums[low++],nums[mid++]);
				break;
			case 1:
				mid++;
				break;
			case 2:
				swap(nums[mid],nums[high--]);
				break;
		}
	}

}