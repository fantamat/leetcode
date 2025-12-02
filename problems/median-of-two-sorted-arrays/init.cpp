#include <vector>
#include <stdio.h>

using namespace std;

#define SMALL_LIST 5
#define SMALL_SIZE 10

class Solution {
public:
    int findNewStartForSingleLargeList(vector<int>& nums, int otherListSize) {
        return (
            ((nums.size()-1) / 2) // standard median
            - otherListSize // possible other values from another nums list
            - 2 // to be sure
        );
    }

    void findNewStartForLargeLists(vector<int>& nums1, vector<int>& nums2, int& start1, int& start2) {
        int totalSizeHalf = (nums1.size() + nums2.size()) / 2;
        while (totalSizeHalf - start1 - start2 > SMALL_SIZE) {
            
        }
    }


    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalSize = nums1.size() + nums2.size();

        int start1 = 0;
        int start2 = 0;
        if (totalSize > SMALL_SIZE) {
            if (nums1.size() < SMALL_LIST) {
                start2 = findNewStartForSingleLargeList(nums2, nums1.size());
            } else if (nums2.size() < SMALL_LIST) {
                start1 = findNewStartForSingleLargeList(nums1, nums2.size());
            } else {
                // not needed
                // findNewStartForLargeLists(nums1, nums2, start1, start2);
            }
        }

        return findMedianSortedArraysDirect(nums1, nums2, start1, start2);
    }


    double findMedianSortedArraysDirect(vector<int>& nums1, vector<int>& nums2, int start1, int start2) {
        
        bool isSizeSumEven = ((nums1.size() + nums2.size()) % 2) == 0;
        int toBeEliminated = (nums1.size() + nums2.size() - 1) / 2;

        while (start1 + start2 < toBeEliminated) {
            if (start1 == nums1.size()) {
                start2 = toBeEliminated - start1;
                break;
            } else if (start2 == nums2.size()) {
                start1 = toBeEliminated - start2;
                break;
            } else if (nums1[start1] > nums2[start2]) {
                start2++;
            } else {
                start1++;
            }
        }

        if (start1 == nums1.size()) {
            if (isSizeSumEven) {

                return 0.5*(nums2[start2] + nums2[start2+1]);
            } else {

                return nums2[start2];
            }
        } else if (start2 == nums2.size()) {
            if (isSizeSumEven) {

                return 0.5*(nums1[start1] + nums1[start1+1]);
            } else {

                return nums1[start1];
            }
        } else if (nums1[start1] > nums2[start2]) {
            if (isSizeSumEven) {
                if ((start2 < nums2.size()-1) && (nums1[start1] > nums2[start2+1]))
                    nums1[start1] = nums2[start2+1];
                return 0.5*(nums2[start2] + nums1[start1]);
            } else {
                return nums2[start2];
            }
        } else {
            if (isSizeSumEven) {
                if ((start1 < nums1.size()-1) && (nums2[start2] > nums1[start1+1]))
                    nums2[start2] = nums1[start1+1];
                return 0.5*(nums2[start2] + nums1[start1]);
            } else {
                return nums1[start1];
            }
        }
        
    }




    // ---------------------------------------------------------------------------------------
    // the first attempt, too complicated and not working correctly

    double findMedianSortedArrayPart(vector<int>& nums) {
        int size = nums.size();
        int halfIdx = size / 2;
        if (size % 2 == 0) {
            return 0.5*(nums[halfIdx-1] + nums[halfIdx]);
        } else {
            return nums[halfIdx];
        }
    }

    double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0) {
            return findMedianSortedArrayPart(nums2);
        } else if (nums2.size() == 0) {
            return findMedianSortedArrayPart(nums1);
        }

        int start1 = 0;
        int end1 = nums1.size()-1;
        int start2 = 0;
        int end2 = nums2.size()-1;
        
        bool isSizeSumEven = ((nums1.size() + nums2.size()) % 2) == 0;
        int toBeEliminated = (nums1.size() + nums2.size() - 1) / 2;
        int eliminatedLeft = 0;
        int eliminatedRight = 0;
        bool noElimination = false;


        while ((eliminatedLeft < toBeEliminated)&&(eliminatedRight < toBeEliminated)) {

            printf("toBeEliminated: %d    eliminatedLeft: %d  eliminatedRight: %d\n", toBeEliminated, eliminatedLeft, eliminatedRight);
            
            if (noElimination) {
                if (end1 - start1 == 1) {
                    if (nums1[start1] <= nums2[start2]) {
                        noElimination = false;
                        eliminatedLeft += 1;
                        start1 += 1;
                        continue;
                    } else if (nums1[end1] >= nums2[end2]) {
                        noElimination = false;
                        eliminatedRight += 1;
                        end1 -= 1;
                        continue;
                    }
                } else if (end2 - start2 == 1) {
                    noElimination = false;
                    if (nums2[start2] <= nums1[start1]) {
                        noElimination = false;
                        eliminatedLeft += 1;
                        start2 += 1;
                        continue;
                    } else if (nums2[end2] >= nums1[end1]) {
                        noElimination = false;
                        eliminatedRight += 1;
                        end2 -= 1;
                        continue;
                    }
                }
            }


            int middle1 = (start1 + end1+1) / 2;
            int middle2 = (start2 + end2+1) / 2;

            printf("start1: %d end1: %d   ", start1, end1);

            printf("start2: %d end2: %d   ", start2, end2);

            printf("middle1: %d middle2: %d\n", middle1, middle2);

            if (nums1[middle1] < nums2[middle2]) {
                noElimination = (middle1==start1) && (middle2==end2);

                eliminatedLeft += middle1 - start1;
                start1 = middle1;
                eliminatedRight += end2 - middle2;
                end2 = middle2;
            } else {
                noElimination = (middle2==start2) && (middle1==end1);

                eliminatedLeft += middle2 - start2;
                start2 = middle2;
                eliminatedRight += end1 - middle1;
                end1 = middle1;
            }
        }


        printf("Finished toBeEliminated: %d    eliminatedLeft: %d  eliminatedRight: %d\n", toBeEliminated, eliminatedLeft, eliminatedRight);
        printf("start1: %d end1: %d   ", start1, end1);
        printf("start2: %d end2: %d   \n", start2, end2);

        if (eliminatedLeft >= toBeEliminated) {
            if (eliminatedLeft > toBeEliminated)
                printf("ajaja eliminatedLeft > toBeEliminated");
            
            if (isSizeSumEven) {
                int first, second;

                if ((start1 > 0) && (nums1[start1-1] > nums2[start2]))
                    nums2[start2] = nums1[start1-1];
                
                if ((start2 > 0) && (nums2[start2-1] > nums1[start1]))
                    nums1[start1] = nums2[start2-1];

                if (nums1[start1] < nums2[start2]) {
                    first = nums1[start1];
                    if ((end1 > start1) && (nums1[start1 + 1] < nums2[start2]))
                        second = nums1[start1 + 1];
                    else
                        second = nums2[start2];
                } else {
                    first = nums2[start2];
                    if ((end2 > start2) && (nums2[start2 + 1] < nums1[start1]))
                        second = nums2[start2 + 1];
                    else
                        second = nums1[start1];
                }
                return 0.5*(first + second);
            } else {
                if (nums1[start1] < nums2[start2])
                    return nums1[start1];
                else
                    return nums2[start2];
            }
            
        } else {
            if (eliminatedRight > toBeEliminated)
                printf("ajaja eliminatedLeft > toBeEliminated");
            
            if (isSizeSumEven) {
                int first, second;

                if ((end1 < nums1.size()-1) && (nums1[end1+1] < nums2[end2]))
                    nums2[end2] = nums1[end1+1];
                
                if ((end2 < nums2.size()-1) && (nums2[end2+1] < nums1[end1]))
                    nums1[end1] = nums2[end2+1];

                if (nums1[end1] > nums2[end2]) {
                    first = nums1[end1];
                    if ((end1 > start1) && (nums1[end1 - 1] > nums2[end2]))
                        second = nums1[end1 - 1];
                    else
                        second = nums2[end2];
                } else {
                    first = nums2[end2];
                    if ((end2 > start2) && (nums2[end2 - 1] > nums1[end1]))
                        second = nums2[end2 - 1];
                    else
                        second = nums1[end1];
                }
                return 0.5*(first + second);
            } else {
                if (nums1[end1] > nums2[end2])
                    return nums1[end1];
                else
                    return nums2[end2];
            }
        }

        return 0.0;
    }
};