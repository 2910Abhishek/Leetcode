/*https://www.codingninjas.com/studio/problems/next-smaller-element_1112581?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&campaign=Lovebabbarcodestudio&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbarcodestudio*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n);

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> result = nextSmallerElement(arr, n);

    cout << "Next smaller elements:\n";
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }
    
    return 0;
}


vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> st;
    st.push(-1);
    vector<int> ans(n);
    for(int i = n - 1 ; i >= 0 ; i--)
    {
        int curr = arr[i];
        while(st.top() >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}