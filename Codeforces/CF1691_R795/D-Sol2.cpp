#define main fakemain
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, m, k, ans = 0, a[maxn], b[maxn];
vector<int>v;
pii p[maxn];
string s;
#define lo (tree[o].son[0])
#define ro (tree[o].son[1])
#define len(a,b) ((b)-(a)+1)

class SegmentTree {


  public:

    int tot = 0;
    struct node {
        int vmx, vmn, lazy;
        int son[2];
    } tree[maxn * 4];

    void build(int o, int L, int R) {
        // tree[o].lazy = 0;
        if (L == R) {
            tree[o].vmx = tree[o].vmn = b[L];
            return ;
        }
        int M = (L + R) / 2ll;
        tree[o].son[0] = ++tot;
        build(lo, L, M);
        tree[o].son[1] = ++tot;
        build(ro, M + 1, R);
        tree[o].vmx = max(tree[lo].vmx, tree[ro].vmx);
        tree[o].vmn = min(tree[lo].vmn, tree[ro].vmn);
    }

    int querymx(int o, int L, int R, int ql, int qr) {
        if (L > qr || R < ql)
            return LLONG_MIN;
        if (L >= ql && R <= qr)
            return tree[o].vmx;
        int M = (L + R) / 2, tmp = LLONG_MIN;
        tmp = max(querymx(lo, L, M, ql, qr), tmp);
        tmp = max(querymx(ro, M + 1, R, ql, qr), tmp);
        return tmp;
    }

    int querymn(int o, int L, int R, int ql, int qr) {
        if (L > qr || R < ql)
            return LLONG_MAX;
        if (L >= ql && R <= qr)
            return tree[o].vmn;
        int M = (L + R) / 2, tmp = LLONG_MAX;
        tmp = min(querymn(lo, L, M, ql, qr), tmp);
        tmp = min(querymn(ro, M + 1, R, ql, qr), tmp);
        return tmp;
    }
} Tre;

int solve() {
    ans = 0;
    v.clear();
    stack<pair<int, int> >st;
    st.push({LLONG_MAX, 0});
    b[0] = 0;
    cin >> n;
    f(i, 1, n) {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
        if (a[i] > 0) {
            while (st.top().first < a[i]) {
                p[st.top().second].second = i - 1;
                st.pop();
            }
            p[i].first = 1ll + st.top().second;
            st.push({a[i], i});
            v.push_back(i);
        }
    }
    Tre.tot = 1;
    Tre.build(1, 0, n);
    while (!st.empty()) {
        p[st.top().second].second = n;
        st.pop();
    }
    // f(i, 1, n) {
    //     cout << p[i].first << " " << p[i].second << endl;
    // }
    for (auto x : v) {
        int l = p[x].first, r = p[x].second, tmp = 0;
        if (l == r && l == x && n != 1) {
            ans = -1;
            break;
        }
        else if (r == x)
            tmp = b[r] - Tre.querymn(1, 0, n, l - 1, x - 1);
        else if (l == x)
            tmp = Tre.querymx(1, 0, n, x, r) - b[l - 1];
        else
            tmp = Tre.querymx(1, 0, n, x, r) - Tre.querymn(1, 0, n, l - 1, x - 1);
        if (tmp > a[x]) {
            ans = -1;
            break;
        }
    }
    if (ans == -1)
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}

void main() {
#ifdef ONLINE_JUDGE //don't mix cin/scanf, cout/printf!
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
#endif
    cin >> T;
    f(i, 1, T) {
        // cout << "Case #" << T + 1 << ":" << endl;
        Tre.tot = 0;
        solve();
    }
}


#undef main
#undef int
#ifndef ONLINE_JUDGE
// *INDENT-OFF*
void rmv_() {remove("IN_TEMP_D_kwX7UAC");remove("OUT_TEMP_D_kwX7UAC");} /*edit if you want to don't want your temps removed*/ string to_str__booster__(int x) {char buf[100];sprintf(buf,"%d",x);return buf;} vector<string> clean__booster___(string u){u.push_back('\n');vector<string> w;string c;for(auto t:u){if(t=='\n'||t=='\r'){while(c.size()&&c.back()==' ') c.pop_back();if(c.size()) w.push_back(c);c.clear();}else c.push_back(t);}return w;}int to_num__booster__(string s){int w=atoi(s.c_str());char buf[10];sprintf(buf,"%d",w);if(buf==s) return w;return -1;}signed main(int argc,char**argv){if(argc==2&&(string)argv[1]=="r") {fakemain();return 0;}vector<string> code;{std::ifstream t(__FILE__);std::stringstream buffer;buffer << t.rdbuf();t.close(); code=clean__booster___(buffer.str());}int num_samples=0;map<pair<int,int>,string> samples;{string cs="";pair<int,int> id(-1,-1);for(auto s:code){if(s.substr(0,4)=="*o* "){if(id.second!=-1)samples[id]=cs;id=make_pair(-1,-1),cs="";string g=s.substr(4);string si="Sample Input ";string so="Sample Output ";if(g.back()==':'&&g.substr(0,si.size())==si){int w=to_num__booster__(g.substr(si.size(),g.size()-si.size()-1));if(w>=1) id=make_pair(w,0);}if(g.back()==':'&&g.substr(0,so.size())==so){int w=to_num__booster__(g.substr(so.size(),g.size()-so.size()-1));if(w>=1) id=make_pair(w,1);}}else cs=cs+s+"\n";}while(samples.count(make_pair(num_samples+1,0))&&samples.count(make_pair(num_samples+1,1)))++num_samples;}if(!num_samples){fakemain();return 0;}int w; int cap=1,sil=0; if(argc==2) {w=to_num__booster__(argv[1]); cerr<<w<<"... "; cap=2;} else {cerr<<num_samples<<" samples. autofeed: ";cerr.flush();string u;getline(cin,u);if(u=="a"){cerr<<"testing all samples..."<<endl;for(int i=1;i<=num_samples;++i) {cerr<<"testing sample ";int rt=system(((string)"\""+argv[0]+"\" "+to_str__booster__(i)).c_str()); if(rt) cerr<<endl<<"WA/RE (return value "<<rt<<")\n",exit(-1);}cerr<<"all samples passed!"<<endl;exit(0);}while(1){if(u.size()&&u.back()=='r')u.pop_back(),cap=0;else if(u.size()&&u.back()=='s')u.pop_back(),sil=1,cap=0;else break;}w=to_num__booster__(u);}string in,out;rmv_();if(w>=1&&w<=num_samples){in=samples[make_pair(w,0)];out=samples[make_pair(w,1)];ofstream o("IN_TEMP_D_kwX7UAC");o<<in; o.close();freopen("IN_TEMP_D_kwX7UAC","r",stdin);if(cap){if(cap!=2) cerr<<"============= testcase "<<w<<" (captured) ============="<<endl;freopen("OUT_TEMP_D_kwX7UAC","w",stdout);}else{cerr<<"================== testcase "<<w<<" ==================="<<endl;}}else{cap=0; cerr<<"=============== normal run ================"<<endl;}time_t start_time=clock(); fakemain(); time_t end_time=clock(); bool force_stop=false;if(w>=1&&w<=num_samples){string out_str;if(cap){fclose(stdout);std::ifstream t("OUT_TEMP_D_kwX7UAC");std::stringstream buffer;buffer << t.rdbuf();t.close();out_str=buffer.str();if(cap!=2) cerr<<out_str;}if(sil);else{if(cap!=2) cerr<<endl<<"================================================="<<endl<<"sample output:"<<endl<<out<<endl;if(cap){if(clean__booster___(out)==clean__booster___(out_str))cerr<<"compare passed ("<<int((end_time - start_time)*1000.0/CLOCKS_PER_SEC+0.5)<<"ms)!"<<endl;else {cerr<<"compare failed ("<<int((end_time - start_time)*1000.0/CLOCKS_PER_SEC+0.5)<<"ms)!"<<endl; force_stop=true; if(cap==2) {cerr<<"=============== your output ==============="<<endl<<out_str<<endl<<"============== sample output =============="<<endl<<out<<endl;}}}}}fclose(stdin);rmv_(); if(force_stop) exit(-1);}
// *INDENT-ON*
#else
signed main() {
    fakemain();
}
#endif
/*
*o* Sample Input 1:
3
4
-1 1 -1 2
5
-1 2 -3 2 -1
3
2 3 -1
*o* Sample Output 1:
YES
YES
NO
*o* Sample Input 2:
6
6
-4 4 -3 3 -3 3
5
4 -3 3 -3 5
11
5 -1 2 -2 3 -3 4 -2 1 -2 1
20
-680896910 862281557 -803798947 -5665992 637332593 -334972380 264567669 -291145921 475603275 -324548977 -921880954 -589678065 -160354019 436371070 -745445581 820916182 -327279238 -112430752 397311313 -137310267
5
-10 3 2 4 -10
1
2
*o* Sample Output 2:
YES
NO
NO
NO
NO
YES
*o* Sample Input 3:
2
4
9 -8 -4 -4 
8
-7 -3 0 -9 -8 -3 6 -1 
*o* Sample Output 3:
YES
YES
*o* This chunk of comment is used for auto-testing. Please don't modify.
*/