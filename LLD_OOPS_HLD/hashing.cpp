#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << " is " << x << '\n';
#define int long long int

/**
 * Observations:
 */

 /**
  * Proof:
  * 
  */


struct Connection{
      string srcIp,destIp;
      int srcPort,destPort;


      bool operator==(const Connection &other) const  {
            return srcIp == other.srcIp;
      }
};


struct ConnectionHash{
      size_t operator()(const Connection &c ) const {
            size_t h1 = hash<string>() (c.srcIp);
            size_t h2 = hash<string>() (c.destIp);
            size_t h3 = hash<int>() (c.srcPort);
            size_t h4 = hash<int>() (c.destPort);
            cout << h1 << " " << h2 << " " << h3  << " " << h4 << endl;
            return ((h1 ^ (h2 <<1 )) >> 1 ) ^ (h3 <<1) ^ (h4 << 2);

      }
};


class Router {
      private:
      map<pair<string,string>, pair<string,string>> mpp;
      public:
      void add_connection(string src_ip,string src_port, string dest_ip, string dest_port) {
            mpp[{src_ip,src_port}] = {
                  dest_ip,dest_port
            };
      }

      bool check_connection(string src_ip, string src_port, string dest_ip, string dest_port) {
            if(mpp.find({src_ip,src_port}) != mpp.end()) {
                  return true;
            }

            return false;
      }


};
void solve(){
      unordered_map<Connection, bool,ConnectionHash> mpp;
      mpp[{ "fjsgdjf", "fkjdsbf", 49328759320403294, 4983249832 }] = true;
      cout << mpp[{ "fjsgdjf", "fkjdsbf", 49328759320403294, 4983249832 }];
      
    
}
bool multi = false;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    if(multi) cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
/**
 * Golden rule no. 1:
 *    Solutions are simple.
 * Golden rule no. 2:
 *    Implementation is simple
 * Golden rule no. 3:
 *    Above two are always correct
 */
