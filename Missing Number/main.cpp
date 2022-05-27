/*By::Cebastain Santiago 
* Leetcode 268 Missing Number
*/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

int missingNumber(std::vector<int>& nums) {
	//variables
	std::set<int> sets;
	int zero = 0;
	//sort the vector
	std::sort(nums.begin(), nums.end());

	if (nums.size()-1 == 0){

		//insert the element into the sets
		for (size_t i = 0; i < nums.size(); i++) {
			sets.insert(nums[i]);
		}

		//Find Zero in the set
		auto it = sets.find(zero);

		if (it == sets.end()) {
			return zero;
		}

		int plus_one = nums[0] + 1;
		return plus_one;
	}

	//insert the element into the sets
	for (size_t i = 0; i < nums.size(); i++) {
		sets.insert(nums[i]);
	}

	//Find Zero in the set
	auto it = sets.find(zero);

	if (it == sets.end()){
		return zero;
	}


	//loop through the vector and return the missing number
	for (size_t i = 0; i < nums.size(); i++) {
		//check if the number +1 exists
		int temp = nums[i] + 1;

		auto it = sets.find(temp);

		//if auto comes back as end then we found the missing number
		if (it == sets.end()){
			return temp;
		}
	}

	return 0;
}

int main(int argc, char* argv[]) {
	std::vector<int> nums = { 1 };
	
	std::cout << missingNumber(nums) << std::endl;

	return 0;
}