#include <iostream>
#include <vector>
using namespace std;


const int maxn = 101;
int n;
vector<int> nums;
vector<char> ops;
void foo()
{
    cout << "=" << nums[0];
    if (ops.empty())
    {
        return;
    }
    for (int i = 0; i < ops.size(); i++)
    {
        cout << ops[i] << nums[i + 1];
    }
    cout << endl;
    int p = 0;
    if (ops[p] == '+' || ops[p] == '-')
    {
        for (int j = p + 1;j < ops.size();j++)
        {
            if (ops[j] == '*' || ops[j] == '/')
            {
                p = j;
                break;
            }
        }
    }
    int a = nums[p];
    int b = nums[p + 1];
    char op = ops[p];
    int c = 0;
    if (op == '+')
        c = a + b;
    else if (op == '-')
        c = a - b;
    else if (op == '*')
        c = a * b;
    else
        c = a / b;
    nums.erase(nums.begin() + p);
    nums.erase(nums.begin() + p);
    nums.insert(nums.begin() + p, c);
    ops.erase(ops.begin() + p);
}
int main()
{
    cin >> n;
    nums.resize(n);
    ops.resize(n - 1);
    for (int i = 0;
         i < n;
         i++)
        cin >> nums[i];
    for (int i = 0;
         i < n - 1;
         i++)
        cin >> ops[i];
    while (n--)
        foo();
    return 0;
}
