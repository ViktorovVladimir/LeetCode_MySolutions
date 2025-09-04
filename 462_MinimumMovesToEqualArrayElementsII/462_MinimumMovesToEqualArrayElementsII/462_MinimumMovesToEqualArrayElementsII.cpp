/*

Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
In one move, you can increment or decrement an element of the array by 1.
Test cases are designed so that the answer will fit in a 32 - bit integer.

Example 1:
    Input: nums = [1, 2, 3]
    Output : 2

Explanation :
    Only two moves are needed(remember each move increments or decrements one element) :
    [1, 2, 3] = > [2, 2, 3] = > [2, 2, 2]

Example 2:
    Input: nums = [1, 10, 2, 9]
    Output : 16


Constraints:
    n == nums.length
    1 <= nums.length <= 105
    - 109 <= nums[i] <= 109

*/


#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
    
    //--.
    void minMoves2( std::vector<int>& nums )
    {
        int iOutput;
        //--.
        iOutput = getMedian( nums );
        
        //--.
        viewResult( nums, iOutput );
    }


private:
    //--.
    int getMedian(std::vector<int>& nums)
    {
        std::sort( nums.begin(), nums.end() );
        //--.
        int iMedian = nums[nums.size() / 2];
        int iMoves = 0;
        //--.
        for( int num : nums )
            iMoves += abs(num - iMedian);
        //--.
        return iMoves;
    }

    //--.
    void viewResult( std::vector<int>& vIn, int iAverageValue )
    {
        int i;
        //--.
        printf("\n Input: nums = [ ");
        
        for( i = 0; i < vIn.size()-1; i++)
            printf("%d, ", vIn[i]);        
        printf("%d ] \n", vIn[i]);

        //--.
        printf(" Output: %d \n", iAverageValue);
    }

};


//-----------------------------------------------------------
//--.
int main()
{
    Solution sln;
    
    //01.
    std::vector<int> v1 = { 1,2,3 };
    sln.minMoves2(v1);

    //02.
    std::vector<int> v2 = { 1,10,2,9 };
    sln.minMoves2(v2);

    //03.
    std::vector<int> v3 = { 1,10,16,2,9 };
    sln.minMoves2(v3);


    //--.
    return 0;
}

