#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <string>
#include <fstream>  // For file handling
#include <sstream>  // For ostringstream
using namespace std;

string removeTrailingZeros(string s) {
    s.erase(s.find_last_not_of('0') + 1, string::npos);
    if (s.back() == '.') s.pop_back();
    return s;
}

void solve(ifstream &infile, ofstream &outfile) {
    int T;
    infile >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        infile >> N;
        double max_speed = 0.0;
        double min_speed = numeric_limits<double>::infinity();
        
        for (int i = 1; i <= N; ++i) {
            int A, B;
            infile >> A >> B;
            
            if (B > 0) {
                max_speed = max(max_speed, static_cast<double>(i) / B);
            }
            
            if (A > 0) {
                min_speed = min(min_speed, static_cast<double>(i) / A);
            }
        }
        
        outfile << "Case #" << t << ": ";
        if (max_speed <= min_speed) {
            ostringstream oss;
            oss << fixed << setprecision(6) << max_speed;
            outfile << removeTrailingZeros(oss.str()) << endl;
        } else {
            outfile << "-1" << endl;
        }
    }
}

int main() {
    ifstream infile("input.txt");
    ofstream outfile("output.txt");

    if (!infile.is_open() || !outfile.is_open()) {
        cerr << "Error opening file" << endl;
        return 1;
    }

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(infile, outfile);

    infile.close();
    outfile.close();
    return 0;
}