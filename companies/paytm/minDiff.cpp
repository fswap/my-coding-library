#include <bits/stdc++.h>
using namespace std;

int ans,sum;

void helper(int *a,int n,int selected,int currsum,int idx)
{
    if(selected==n/2)
    {
        int rem=sum-currsum;
        ans=min(ans,abs(currsum-rem));
        return;
    }
    if(idx>=n)
        return;
    helper(a,n,selected+1,currsum+a[idx],idx+1);
    helper(a,n,selected,currsum,idx+1);
}

int minDiff(int *a,int n)
{
    int i;
    sum=0,ans=INT_MAX;
    for(i=0;i<n;i++)
        sum+=a[i];
    helper(a,n,0,0,0);
    return ans;
}

void solve()
{
    int i,j,n,m;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<minDiff(a,n)<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    t=1;
    //cin>>t;
    while(t--)
        solve();
}

/*

void TOWUtil(int* arr, int n, bool* curr_elements, int no_of_selected_elements, 
             bool* soln, int* min_diff, int sum, int curr_sum, int curr_position) 
{ 
    // checks whether the it is going out of bound 
    if (curr_position == n) 
        return; 
  
    // checks that the numbers of elements left are not less than the 
    // number of elements required to form the solution 
    if ((n/2 - no_of_selected_elements) > (n - curr_position)) 
        return; 
  
    // consider the cases when current element is not included in the solution 
    TOWUtil(arr, n, curr_elements, no_of_selected_elements, 
              soln, min_diff, sum, curr_sum, curr_position+1); 
  
    // add the current element to the solution 
    no_of_selected_elements++; 
    curr_sum = curr_sum + arr[curr_position]; 
    curr_elements[curr_position] = true; 
  
    // checks if a solution is formed 
    if (no_of_selected_elements == n/2) 
    { 
        // checks if the solution formed is better than the best solution so far 
        if (abs(sum/2 - curr_sum) < *min_diff) 
        { 
            *min_diff = abs(sum/2 - curr_sum); 
            for (int i = 0; i<n; i++) 
                soln[i] = curr_elements[i]; 
        } 
    } 
    else
    { 
        // consider the cases where current element is included in the solution 
        TOWUtil(arr, n, curr_elements, no_of_selected_elements, soln, 
                  min_diff, sum, curr_sum, curr_position+1); 
    } 
  
    // removes current element before returning to the caller of this function 
    curr_elements[curr_position] = false; 
} 
  
// main function that generate an arr 
void tugOfWar(int *arr, int n) 
{ 
    // the boolean array that contains the inclusion and exclusion of an element 
    // in current set. The number excluded automatically form the other set 
    bool* curr_elements = new bool[n]; 
  
    // The inclusion/exclusion array for final solution 
    bool* soln = new bool[n]; 
  
    int min_diff = INT_MAX; 
  
    int sum = 0; 
    for (int i=0; i<n; i++) 
    { 
        sum += arr[i]; 
        curr_elements[i] =  soln[i] = false; 
    } 
  
    // Find the solution using recursive function TOWUtil() 
    TOWUtil(arr, n, curr_elements, 0, soln, &min_diff, sum, 0, 0); 
  
    // Print the solution 
    cout << "The first subset is: "; 
    for (int i=0; i<n; i++) 
    { 
        if (soln[i] == true) 
            cout << arr[i] << " "; 
    } 
    cout << "\nThe second subset is: "; 
    for (int i=0; i<n; i++) 
    { 
        if (soln[i] == false) 
            cout << arr[i] << " "; 
    } 
} 

*/