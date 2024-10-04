#include <ListNode.cpp>

int main()
{
    // ListNode *n0 = new ListNode(1);
    // ListNode *n1 = new ListNode(3);
    // ListNode *n2 = new ListNode(2);
    // ListNode *n3 = new ListNode(5);
    // ListNode *n4 = new ListNode(4);

    // n0->next = n2;
    // n2->next = n1;
    // n1->next = n4;
    // n4->next = n3;

    // delete n0;
    // delete n1;
    // delete n2;
    // delete n3;
    // delete n4;

    // vector<int> nums1;
    vector<int> nums = {1, 2, 3, 4, 5};

    int num = nums[1];
    nums[1] = 0;

    nums.clear();
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(4);

    nums.insert(nums.begin() + 3, 6);

    /*
    错误做法nums.insert(nums + 3, 6);
    因为nums不是指针
    */

    nums.erase(nums.begin() + 3);

    int count = 0;
    /* 通过索引遍历列表 */
    for (int i = 0; i < nums.size(); i++)
    {
        count += nums[i];
    }

    count = 0;
    /* 直接遍历列表元素 */
    for (int num : nums)
    {
        count += num;
    }

    /*拼接列表list(cpp里面是vector)*/
    vector<int> nums1 = {6, 7, 8, 9, 10};
    /*把nums1拼接到nums之后*/
    nums.insert(nums.end(), nums1.begin(), nums1.end());

    sort(nums.begin(), nums.end());

    for (int num : nums)
    {
        cout << num << endl;
    }
    return 0;
}

/*
由于vector没有重载<<运算符，因此cout不能直接输出vector类型的nums cout << nums << endl;
*/
