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
int posa[maxn], posb[maxn];
pii prea[maxn], preb[maxn];

int solve() {
    ans = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        posa[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
        posb[b[i]] = i;
    }
    prea[1] = {posa[1], posa[1]};
    preb[1] = {posb[1], posb[1]};
    for (int i = 2; i <= n; ++i) {
        prea[i] = prea[i - 1];
        preb[i] = preb[i - 1];
        prea[i].first = min(prea[i].first, posa[i]);
        prea[i].second = max(prea[i].second, posa[i]);
        preb[i].first = min(preb[i].first, posb[i]);
        preb[i].second = max(preb[i].second, posb[i]);
    }
    ans = 1;
    for (int i = 1; i <= n; ++i) {
        if (i == 1){
            int not_include_point_a = posa[i], not_include_point_b = posb[i];
            pii must_not_include = {min(posa[i], posb[i]), max(posa[i], posb[i])};
            ans += (must_not_include.first - 1) * (must_not_include.first - 2) / 2;
            ans += (n - must_not_include.second) * (n - must_not_include.second - 1) / 2;
            ans += (must_not_include.first - 1) + (n - must_not_include.second);
            ans += (must_not_include.second - must_not_include.first - 1) * (must_not_include.second - must_not_include.first - 2) / 2;
            ans += (must_not_include.second - must_not_include.first - 1);
            // cout << ans << endl;
            continue;
        }
        pii must_include = {min(prea[i - 1].first, preb[i - 1].first), max(prea[i - 1].second, preb[i - 1].second)};
        int not_include_point_a = posa[i], not_include_point_b = posb[i];
        if (not_include_point_a > not_include_point_b)
            swap(not_include_point_a, not_include_point_b);
        if (not_include_point_a > must_include.first && not_include_point_a < must_include.second)
            continue;
        if (not_include_point_b > must_include.first && not_include_point_b < must_include.second)
            continue;
        if (must_include.first > not_include_point_b)
            ans += (must_include.first - not_include_point_b) * (n - must_include.second + 1);
        else if (must_include.second < not_include_point_a)
            ans += (not_include_point_a - must_include.second) * (must_include.first);
        else
            ans += (must_include.first - not_include_point_a) * (not_include_point_b - must_include.second);
    }
    cout << ans << endl;
    return 0;
}
void main() {
#ifdef ONLINE_JUDGE //don't mix cin/scanf, cout/printf!
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(0);
#endif
    // cin >> T;
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
        solve();
    }
}


#undef main
#undef int
#ifndef ONLINE_JUDGE
// *INDENT-OFF*
void rmv_() {remove("IN_TEMP_D_Tg7cqiv");remove("OUT_TEMP_D_Tg7cqiv");} /*edit if you want to don't want your temps removed*/ string to_str__booster__(int x) {char buf[100];sprintf(buf,"%d",x);return buf;} vector<string> clean__booster___(string u){u.push_back('\n');vector<string> w;string c;for(auto t:u){if(t=='\n'||t=='\r'){while(c.size()&&c.back()==' ') c.pop_back();if(c.size()) w.push_back(c);c.clear();}else c.push_back(t);}return w;}int to_num__booster__(string s){int w=atoi(s.c_str());char buf[10];sprintf(buf,"%d",w);if(buf==s) return w;return -1;}signed main(int argc,char**argv){if(argc==2&&(string)argv[1]=="r") {fakemain();return 0;}vector<string> code;{std::ifstream t(__FILE__);std::stringstream buffer;buffer << t.rdbuf();t.close(); code=clean__booster___(buffer.str());}int num_samples=0;map<pair<int,int>,string> samples;{string cs="";pair<int,int> id(-1,-1);for(auto s:code){if(s.substr(0,4)=="*o* "){if(id.second!=-1)samples[id]=cs;id=make_pair(-1,-1),cs="";string g=s.substr(4);string si="Sample Input ";string so="Sample Output ";if(g.back()==':'&&g.substr(0,si.size())==si){int w=to_num__booster__(g.substr(si.size(),g.size()-si.size()-1));if(w>=1) id=make_pair(w,0);}if(g.back()==':'&&g.substr(0,so.size())==so){int w=to_num__booster__(g.substr(so.size(),g.size()-so.size()-1));if(w>=1) id=make_pair(w,1);}}else cs=cs+s+"\n";}while(samples.count(make_pair(num_samples+1,0))&&samples.count(make_pair(num_samples+1,1)))++num_samples;}if(!num_samples){fakemain();return 0;}int w; int cap=1,sil=0; if(argc==2) {w=to_num__booster__(argv[1]); cerr<<w<<"... "; cap=2;} else {cerr<<num_samples<<" samples. autofeed: ";cerr.flush();string u;getline(cin,u);if(u=="a"){cerr<<"testing all samples..."<<endl;for(int i=1;i<=num_samples;++i) {cerr<<"testing sample ";int rt=system(((string)"\""+argv[0]+"\" "+to_str__booster__(i)).c_str()); if(rt) cerr<<endl<<"WA/RE (return value "<<rt<<")\n",exit(-1);}cerr<<"all samples passed!"<<endl;exit(0);}while(1){if(u.size()&&u.back()=='r')u.pop_back(),cap=0;else if(u.size()&&u.back()=='s')u.pop_back(),sil=1,cap=0;else break;}w=to_num__booster__(u);}string in,out;rmv_();if(w>=1&&w<=num_samples){in=samples[make_pair(w,0)];out=samples[make_pair(w,1)];ofstream o("IN_TEMP_D_Tg7cqiv");o<<in; o.close();freopen("IN_TEMP_D_Tg7cqiv","r",stdin);if(cap){if(cap!=2) cerr<<"============= testcase "<<w<<" (captured) ============="<<endl;freopen("OUT_TEMP_D_Tg7cqiv","w",stdout);}else{cerr<<"================== testcase "<<w<<" ==================="<<endl;}}else{cap=0; cerr<<"=============== normal run ================"<<endl;}time_t start_time=clock(); fakemain(); time_t end_time=clock(); bool force_stop=false;if(w>=1&&w<=num_samples){string out_str;if(cap){fclose(stdout);std::ifstream t("OUT_TEMP_D_Tg7cqiv");std::stringstream buffer;buffer << t.rdbuf();t.close();out_str=buffer.str();if(cap!=2) cerr<<out_str;}if(sil);else{if(cap!=2) cerr<<endl<<"================================================="<<endl<<"sample output:"<<endl<<out<<endl;if(cap){if(clean__booster___(out)==clean__booster___(out_str))cerr<<"compare passed ("<<int((end_time - start_time)*1000.0/CLOCKS_PER_SEC+0.5)<<"ms)!"<<endl;else {cerr<<"compare failed ("<<int((end_time - start_time)*1000.0/CLOCKS_PER_SEC+0.5)<<"ms)!"<<endl; force_stop=true; if(cap==2) {cerr<<"=============== your output ==============="<<endl<<out_str<<endl<<"============== sample output =============="<<endl<<out<<endl;}}}}}fclose(stdin);rmv_(); if(force_stop) exit(-1);}
// *INDENT-ON*
#else
signed main() {
    fakemain();
}
#endif
/*
*o* Sample Input 1:
3
1 3 2
2 1 3
*o* Sample Output 1:
2
*o* Sample Input 2:
7
7 3 6 2 1 5 4
6 7 2 5 3 1 4
*o* Sample Output 2:
16
*o* Sample Input 3:
6
1 2 3 4 5 6
6 5 4 3 2 1
*o* Sample Output 3:
11
*o* This chunk of comment is used for auto-testing. Please don't modify.
*/