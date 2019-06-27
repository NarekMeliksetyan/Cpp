#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

vector <string> get_translate() {
    const char delim = ',';
    vector <string> v;
    string tr;
    int prev_pos = 0, pos = 0;

    getline(cin, tr);
    while ((pos = tr.find(delim, prev_pos)) != string::npos) {
        v.push_back(tr.substr(prev_pos, pos - prev_pos));
        prev_pos = pos + 2;
    }

    v.push_back(tr.substr(prev_pos, tr.size() - prev_pos));

    return v;
}

map <string, vector<string>>& fill_map(map<string, vector<string>>& m, int n) {
    string s;
    char delim;

    for (int i = 0; i < n; ++i) {
        cin >> s >> delim;
        cin.get(); // remove space after delimiter
        m[s] = get_translate();
    }

    return m;
}

map <string, vector<string>> eng_to_lat(const map<string, vector<string>>& m) {
    map<string, vector<string>> tmp;

    for (map<string, vector<string>>::const_iterator it = m.begin(); it != m.end(); ++it) {
        for (int i = 0; i < it->second.size(); ++i) {
            tmp[it->second[i]].push_back(it->first);
        }
    }

    return tmp;
}

int main() {
    int n;
    cin >> n;
    
    map <string, vector<string>> eng_lat;
    map <string, vector<string>> lat_eng;
    
    eng_lat = fill_map(eng_lat, n);
    lat_eng = eng_to_lat(eng_lat);

    cout << lat_eng.size() << endl;
    for (map <string, vector <string>>::const_iterator it = lat_eng.begin(); it != lat_eng.end(); it++) {
        cout << it->first << " - ";
        for (int i = 0; i < it->second.size(); i++) {
            cout << it->second[i];
            if (i + 1 < it->second.size()) {
                cout << ", ";
            }
        }
        cout << endl;
    }

    return 0;
}
