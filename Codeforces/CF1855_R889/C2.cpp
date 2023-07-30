#define main fakemain
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define f(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define F(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
const int maxn = 5e5 + 10;
const int maxb = 110;
int T = 1, n, ans = 0, a[maxn];
vector<pii>v1, v2;

int solve() {
    int maxNum, minNum, maxPos, minPos;
    cin >> n;
    v1.clear();
    v2.clear();
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (i == 1) {
            maxNum = minNum = a[i];
            maxPos = minPos = i;
        }
        else {
            if (a[i] > maxNum) {
                maxNum = a[i];
                maxPos = i;
            }
            if (a[i] < minNum) {
                minNum = a[i];
                minPos = i;
            }
        }
    }
    if (minNum >= 0) {
        for (int i = 2; i <= n; ++i) {
            v1.push_back(make_pair(i, i - 1));
        }
        cout << v1.size() << '\n';
        for (auto i : v1)
            cout << i.first << ' ' << i.second << '\n';
        return 0;
    }
    else if (maxNum <= 0) {
        for (int i = n - 1; i >= 1; --i) {
            v1.push_back(make_pair(i, i + 1));
        }
        cout << v1.size() << '\n';
        for (auto i : v1)
            cout << i.first << ' ' << i.second << '\n';
        return 0;
    }
    else if (maxNum > -minNum) {
        for (int i = 1; i <= n; ++i) {
            if (a[i] < 0) 
                v1.push_back(make_pair(i, maxPos));
        }
        for (int i = 2; i <= n; ++i) {
            v1.push_back(make_pair(i, i - 1));
        }
        while ( -minNum < a[maxPos]) {
            minNum += minNum;
            v2.push_back(make_pair(minPos, minPos));
        }
        for (int i = 1; i <= n; ++i) {
            if (a[i] > 0) 
                v2.push_back(make_pair(i, minPos));
        }
        for (int i = n - 1; i >= 1; --i) {
            v2.push_back(make_pair(i, i + 1));
        }
    }
    else {
        for (int i = 1; i <= n; ++i) {
            if (a[i] > 0) 
                v1.push_back(make_pair(i, minPos));
        }
        for (int i = n - 1; i >= 1; --i) {
            v1.push_back(make_pair(i, i + 1));
        }
        while (maxNum < -a[minPos]) {
            maxNum += maxNum;
            v2.push_back(make_pair(maxPos, maxPos));
        }
        for (int i = 1; i <= n; ++i) {
            if (a[i] < 0) 
                v2.push_back(make_pair(i, maxPos));
        }
        for (int i = 2; i <= n; ++i) {
            v2.push_back(make_pair(i, i - 1));
        }
    }
    cout << min(v1.size(), v2.size()) << '\n';
    if (v1.size() < v2.size()) {
        for (int i = 0; i < v1.size(); ++i) {
            cout << v1[i].first << ' ' << v1[i].second << '\n';
        }
    }
    else {
        for (int i = 0; i < v2.size(); ++i) {
            cout << v2[i].first << ' ' << v2[i].second << '\n';
        }
    }
    return 0;
}
void main()
{
#ifdef ONLINE_JUDGE //don't mix cin/scanf, cout/printf!
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
#endif
	
    cin >> T;
    while (T--) {
    // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
}


#undef main
#undef int
#ifndef ONLINE_JUDGE
// *INDENT-OFF*
void rmv_() {remove("IN_TEMP_C1_wjiM88K");remove("OUT_TEMP_C1_wjiM88K");} /*edit if you want to don't want your temps removed*/ string to_str__booster__(int x) {char buf[100];snprintf(buf,sizeof(int),"%d",x);return buf;} vector<string> clean__booster___(string u){u.push_back('\n');vector<string> w;string c;for(auto t:u){if(t=='\n'||t=='\r'){while(c.size()&&c.back()==' ') c.pop_back();if(c.size()) w.push_back(c);c.clear();}else c.push_back(t);}return w;}int to_num__booster__(string s){int w=atoi(s.c_str());char buf[10];snprintf(buf,sizeof(int),"%d",w);if(buf==s) return w;return -1;}signed main(int argc,char**argv){if(argc==2&&(string)argv[1]=="r") {fakemain();return 0;}vector<string> code;{std::ifstream t(__FILE__);std::stringstream buffer;buffer << t.rdbuf();t.close(); code=clean__booster___(buffer.str());}int num_samples=0;map<pair<int,int>,string> samples;{string cs="";pair<int,int> id(-1,-1);for(auto s:code){if(s.substr(0,4)=="*o* "){if(id.second!=-1)samples[id]=cs;id=make_pair(-1,-1),cs="";string g=s.substr(4);string si="Sample Input ";string so="Sample Output ";if(g.back()==':'&&g.substr(0,si.size())==si){int w=to_num__booster__(g.substr(si.size(),g.size()-si.size()-1));if(w>=1) id=make_pair(w,0);}if(g.back()==':'&&g.substr(0,so.size())==so){int w=to_num__booster__(g.substr(so.size(),g.size()-so.size()-1));if(w>=1) id=make_pair(w,1);}}else cs=cs+s+"\n";}while(samples.count(make_pair(num_samples+1,0))&&samples.count(make_pair(num_samples+1,1)))++num_samples;}if(!num_samples){fakemain();return 0;}int w; int cap=1,sil=0; if(argc==2) {w=to_num__booster__(argv[1]); cerr<<w<<"... "; cap=2;} else {cerr<<num_samples<<" samples. autofeed: ";cerr.flush();string u;getline(cin,u);if(u=="a"){cerr<<"testing all samples..."<<endl;for(int i=1;i<=num_samples;++i) {cerr<<"testing sample ";int rt=system(((string)"\""+argv[0]+"\" "+to_str__booster__(i)).c_str()); if(rt) cerr<<endl<<"WA/RE (return value "<<rt<<")\n",exit(-1);}cerr<<"all samples passed!"<<endl;exit(0);}while(1){if(u.size()&&u.back()=='r')u.pop_back(),cap=0;else if(u.size()&&u.back()=='s')u.pop_back(),sil=1,cap=0;else break;}w=to_num__booster__(u);}string in,out;rmv_();if(w>=1&&w<=num_samples){in=samples[make_pair(w,0)];out=samples[make_pair(w,1)];ofstream o("IN_TEMP_C1_wjiM88K");o<<in; o.close();freopen("IN_TEMP_C1_wjiM88K","r",stdin);if(cap){if(cap!=2) cerr<<"============= testcase "<<w<<" (captured) ============="<<endl;freopen("OUT_TEMP_C1_wjiM88K","w",stdout);}else{cerr<<"================== testcase "<<w<<" ==================="<<endl;}}else{cap=0; cerr<<"=============== normal run ================"<<endl;}time_t start_time=clock(); fakemain(); time_t end_time=clock(); bool force_stop=false;if(w>=1&&w<=num_samples){string out_str;if(cap){fclose(stdout);std::ifstream t("OUT_TEMP_C1_wjiM88K");std::stringstream buffer;buffer << t.rdbuf();t.close();out_str=buffer.str();if(cap!=2) cerr<<out_str;}if(sil);else{if(cap!=2) cerr<<endl<<"================================================="<<endl<<"sample output:"<<endl<<out<<endl;if(cap){if(clean__booster___(out)==clean__booster___(out_str))cerr<<"compare passed ("<<int((end_time - start_time)*1000.0/CLOCKS_PER_SEC+0.5)<<"ms)!"<<endl;else {cerr<<"compare failed ("<<int((end_time - start_time)*1000.0/CLOCKS_PER_SEC+0.5)<<"ms)!"<<endl; force_stop=true; if(cap==2) {cerr<<"=============== your output ==============="<<endl<<out_str<<endl<<"============== sample output =============="<<endl<<out<<endl;}}}}}fclose(stdin);rmv_(); if(force_stop) exit(-1);}
// *INDENT-ON*
#else
signed main(){fakemain();}
#endif
/*
*o* Sample Input 1:
10
2
2 1
4
1 2 -10 3
5
2 1 1 1 1
8
0 0 0 0 0 0 0 0
5
1 2 -4 3 -10
10
11 12 13 14 15 -15 -16 -17 -18 -19
7
1 9 3 -4 -3 -2 -1
3
10 9 8
20
1 -14 2 -10 6 -5 10 -13 10 7 -14 19 -5 19 1 18 -16 -7 12 8
20
-15 -17 -13 8 14 -13 10 -4 11 -4 -16 -6 15 -4 -2 7 -9 5 -5 17
*o* Sample Output 1:
1
2 1
3
4 4
4 4
3 4
4
2 1
3 1
4 1
5 1
0
7
3 4
3 4
5 4
5 4
5 4
5 4
5 4
15
6 1
6 1
6 1
7 2
7 2
7 2
8 3
8 3
8 3
9 4
9 4
9 4
10 5
10 5
10 5
8
3 4
3 4
2 4
2 4
2 4
2 4
1 4
1 4
3
2 1
3 1
3 1
31
14 1
18 7
13 11
15 11
6 4
5 17
19 6
19 12
10 5
11 12
1 17
15 19
16 10
14 2
16 11
20 7
7 6
9 5
3 6
6 14
17 18
18 14
12 3
17 16
8 18
13 16
9 8
14 8
16 2
11 8
12 7
31
5 12
19 13
9 1
5 17
18 19
6 16
15 8
6 9
15 14
7 10
19 7
17 20
14 4
15 20
4 3
1 8
16 12
16 15
5 6
12 10
11 15
20 3
20 19
13 14
11 14
18 10
7 3
12 17
4 7
13 2
11 13
*o* This chunk of comment is used for auto-testing. Please don't modify.
*/