#include <bits/stdc++.h>
using namespace std;

int main() {
    unordered_map<string, vector<string>> adj = {
        {"Kashmere Gate", {"Chandni Chowk"}},
        {"Chandni Chowk", {"Kashmere Gate", "New Delhi"}},
        {"New Delhi", {"Chandni Chowk", "Rajiv Chowk"}},
        {"Rajiv Chowk", {"New Delhi", "HUDA City Centre"}},
        {"HUDA City Centre", {"Rajiv Chowk"}}
    };
    
    // SHOW ALL STATIONS (debug)
    cout << "Available stations:\n";
    for(auto& p : adj) {
        cout << "- " << p.first << endl;
    }
    
    string start, end;
    cout << "\nSource: ";
    getline(cin, start);
    cout << "Destination: ";
    getline(cin, end);
    
    // SHOW WHAT YOU TYPED
    cout << "You typed source: '" << start << "'\n";
    cout << "You typed dest: '" << end << "'\n";
    
    // BFS code same...
    unordered_map<string, string> parent;
    queue<string> q; 
    q.push(start); 
    parent[start] = "-1";
    
    while(!q.empty() && parent.find(end) == parent.end()) {
        string curr = q.front(); q.pop();
        for(string next : adj[curr]) {
            if(parent.find(next) == parent.end()) {
                parent[next] = curr; 
                q.push(next);
            }
        }
    }
    
    if(parent.find(end) == parent.end()) {
        cout << "No route! Check spelling.\n"; 
        return 0;
    }
    
    cout << "Route: ";
    for(string at = end; at != "-1"; at = parent[at])
        cout << at << " ← ";
    cout << endl;
    
    return 0;
}
