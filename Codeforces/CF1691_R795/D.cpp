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
string s;

int solve() {
    ans = 0;
    int lft = -1, lmx = -1;
    v.clear();
    b[0] = 0;
    cin >> n;
    f(i, 1, n) {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
        if (a[i] > 0)
            v.push_back(i);
        // if (n == 199997 && i >= 149990)
        //     cout << i << ' ' <<  a[i] << "\n";
    }
    if (ans != -1)
        for (int i = 1; i < v.size(); i++) {
            if (min(a[v[i - 1]], a[v[i]]) + b[v[i] - 1] - b[v[i - 1]] > 0ll) {
                ans = -1;
                break;
            }
            if (i == 1) {
                lmx = v[i - 1];
                lft = a[v[i - 1]] + b[v[i] - 1] - b[v[i - 1]];
                lft = max(lft, 0ll);
            }
            else {
                if (a[v[i - 1]] > a[lmx]) {
                    if (lft > 0) {
                        ans = -1;
                        break;
                    }
                    for (lmx ;lmx <= i-1 && a[lmx] > a[v[i - 1]]; lmx++)
                    {
                        if (-b[lmx] + b[v[i - 1]] > 0ll) {
                            ans = -1;
                            break;
                        }
                    }
                    lft = max(lft, 0ll);
                    lft += b[v[i] - 1] - b[v[i - 1]] + a[v[i - 1]];
                }
                else {
                    lft +=  a[v[i - 1]];
                    if (lft > lmx) {
                        ans = -1;
                        break;
                    }
                    lft += b[v[i] - 1] - b[v[i - 1]];
                }
                if (a[v[i]] >= lmx && lft > 0) {
                    ans = -1;
                    break;
                }
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
    while (T--) {
        // cout << "Case #" << T + 1 << ":" << endl;
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
4
6
-4 4 -3 3 -3 3
5
4 -3 3 -3 5
11
5 -1 2 -2 3 -3 4 -2 1 -2 1
20
-680896910 862281557 -803798947 -5665992 637332593 -334972380 264567669 -291145921 475603275 -324548977 -921880954 -589678065 -160354019 436371070 -745445581 820916182 -327279238 -112430752 397311313 -137310267
*o* Sample Output 2:
YES
NO
NO
NO
*o* This chunk of comment is used for auto-testing. Please don't modify.
*/