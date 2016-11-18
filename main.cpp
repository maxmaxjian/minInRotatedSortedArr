#include <iostream>
#include <vector>
#include <algorithm>

class solution {
public:
  int findMin(const std::vector<int> & nums) {
    size_t begin = 0, end = nums.size()-1;
    if (nums[begin] < nums[end])
      return nums[begin];
    else {
      size_t mid;
      while (begin < end-1) {
	mid = (begin+end)/2;
	if (nums[mid] >= nums[begin])
	  begin = mid;
	else if (nums[mid] <= nums[end])
	  end = mid;
      }
      return std::min(nums[begin], nums[end]);
    }
  }
};

int main() {
  std::vector<int> nums(10);
  srand(time(0));
  std::generate(nums.begin(), nums.end(), [&](){ return rand()%nums.size(); });
  std::sort(nums.begin(), nums.end());
  size_t pivot = rand()%nums.size();
  std::rotate(nums.begin(), nums.begin()+pivot, nums.end());
  std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;

  solution soln;
  int min = soln.findMin(nums);
  std::cout << "The minimum number is:\n"
	    << min << std::endl;
}
