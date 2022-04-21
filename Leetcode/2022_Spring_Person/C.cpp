#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD=1000000007;
ll seed,vmax;

class ChthollyTree
{
public:
	set<Node>s;

	ChthollyTree(int l, int r)
	{
		s.insert(Node(l, r, 0));
	}

	struct Node
	{
		int l,r;
		mutable ll value;//
		Node(int a,int b,long long c):l(a),r(b),value(c){}
		Node(int a):l(a),r(0),value(0){}
		bool operator < (const Node& o) const{
			return l<o.l;
		}
	};

	set<Node>::iterator split(int pos)
	{
		set<Node>::iterator it=s.lower_bound(Node(pos));
		if (it->l==pos && it!=s.end()) return it;// 
		--it;
		if (pos > it->r) return s.end();//
		int L=it->l,R=it->r;
		ll V=it->value;
		s.erase(it);
		s.insert(Node(L,pos-1,V));
		return s.insert(Node(pos,R,V)).first;
	}

	void assign(int l,int r,int v)
	{
		split(l);
		set<Node>::iterator R=split(r+1);
		set<Node>::iterator L=split(l);
		s.erase(L,R);
		s.insert(Node(l,r,v));
	}

	void add(int l,int r,int v)
	{
		split(l);
		auto R=split(r+1),L=split(l);
		for (;L!=R;++L){
			L->value += v;
		}
	}

	ll kth(int l,int r, int k)
	{
		split(l);
		vector< pair<ll,int> >q;
		q.clear();
		set<Node>::iterator R=split(r+1);
		set<Node>::iterator L=split(l);
		for (set<Node>::iterator it=L;it!=R;++it){
			q.push_back({ it->value , it->r - it->l + 1});
		}
		sort(q.begin(),q.end());//
		for (auto i:q)
		{
			k-=i.second;
			if (k<=0) return i.first; 
		}
		return -1;
	}

	ll qpow(ll a,ll x,ll y)
	{
		ll ans=1,res=a%y;
		while(x!=0)
		{
			if ( x & 1 ) {
				ans*=res;
				ans=ans%y;
			}
			res=res*res%y;
			x>>=1;
		}
		return ans%y;
	}

	ll sum(int l,int r)
	{
		split(l);
		ll ans=0;
		set<Node>::iterator R=split(r+1);
		set<Node>::iterator L=split(l);
		for (set<Node>::iterator it=L;it!=R;++it){
			if (it->val) ans+=( (ll)( it->r - it->l + 1 ));
		}
		return ans;
	}
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getNumber(TreeNode* root, vector<vector<int>>& ops) {
		vector<int>s;queue<TreeNode*>q;
		while(!q.empty())
		{
			TreeNode* nd = q.top();q.pop();
			s.push_back(nd.val);
			if (nd.left) q.push(nd.left);
			if (nd.right) q.push(nd.right);
		}
		sort(s.begin(),s.end());
		ChthollyTree CTree = ChthollyTree(0, s.size() - 1);
		return CTree.sum(0, s.size() - 1);
    }
};