//int dx[]={1,1,0,-1,-1,-1, 0, 1};
//int dy[]={0,1,1, 1, 0,-1,-1,-1};
#include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
	
 typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_set;
    typedef tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update > ordered_multiset;
     
    /* 
    Note :  There is a problem with erase() function in ordered_multiset (for less_equal<int> tag). 
            lower_bound() works as upper_bound() and vice-versa. 
            Be careful to use.
            i) find_by_order(k) : kth smallest element counting from 0 .
            ii) order_of_key(k) : number of elements strictly smaller than k.
    */

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int power(int a,int b)
{
	int ans=1;
	while(b>0)
	{
		if(b%2!=0)
			ans=(ans*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return ans;
}