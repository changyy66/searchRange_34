// searchRange_34.cpp : 定义控制台应用程序的入口点。
//
/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

int searchOne(vector<int>& nums, int target, int left, int right,bool isLeft)
{
	if (left > right)return -1;
	if (left == right)
	{
		if (nums[left] == target)return left;
		return -1;
	}

	if (isLeft)
	{
		int mid = (left + right) / 2;
		if (nums[mid] == target)
		{
			return searchOne(nums, target, left, mid, isLeft);
		}
		return searchOne(nums, target, mid + 1, right, isLeft);
	}
	else
	{
		int mid = (left + right) / 2 + 1;
		if (nums[mid] == target)
		{
			return searchOne(nums, target, mid, right, isLeft);
		}
		return searchOne(nums, target, left, mid - 1, isLeft);
	}
}

vector<int> search(vector<int>& nums, int target,int left,int right) {
	vector<int> res;
	if (left>right) 
	{
		res.push_back(-1);
		res.push_back(-1);
		return res;
	}
	if (left == right && nums[left]==target)
	{
		res.push_back(left);
		res.push_back(left);
		return res;
	}
	int mid = (left + right) / 2;
	if (nums[mid]==target)
	{
		int n1 = searchOne(nums, target, left, mid,true);
		int n2 = searchOne(nums, target, mid, right,false);
		res.push_back(n1);
		res.push_back(n2);
		return res;
	}
	else if (nums[mid] < target)
	{
		return search(nums, target, mid + 1, right);
	}
	return search(nums, target, left, mid - 1);
}

vector<int> searchRange(vector<int>& nums, int target) {
	return search(nums, target, 0, nums.size() - 1);
}

int main()
{
	vector<int> nums = { 1,1,1,1,1,1,1 };
	vector<int> res = searchRange(nums, 2);
	for each (auto var in res)
	{
		cout << var << " ";
	}
    return 0;
}

