#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int n;cin >> n;
	string s;cin >> s;
	int ans = 0;
	for(int i = 1;i < n;i++){
		if(s[i] == s[i - 1])ans++;
	}
	cout << ans;
}