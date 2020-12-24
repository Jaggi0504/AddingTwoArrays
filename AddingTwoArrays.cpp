#include<bits/stdc++.h>
using namespace std;

vector<int> add(vector<int> &input1, vector<int> &input2) {
	vector<int> ans;
	int carry = 0;
	reverse(input1.begin(), input1.end());
	reverse(input2.begin(), input2.end());
	int i, j;
	for(i=0, j=0; i<input1.size(), j<input2.size();i++,j++) {
		int num = input1[i] + input2[j] + carry;
		if(num < 10) {
			ans.push_back(num);
			carry = 0;
		}  else {
			ans.push_back(num % 10);
			carry = num / 10;
		} 
	}
	while(carry) {
		ans.push_back(carry % 10);
		carry = carry / 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	int n1, n2;
	vector<int> input1, input2;
	cout<<"Enter n1:";
	cin>>n1;
	cout<<"Enter elements for n1"<<endl;
	for(int i=0;i<n1;i++) {
		int val;
		cin>>val;
		input1.push_back(val);
	}
	cout<<"Enter n2:";
	cin>>n2;
	cout<<"Enter elements for n2"<<endl;
	for(int i=0;i<n2;i++) {
		int val;
		cin>>val;
		input2.push_back(val);
	}
	cout<<"Sum"<<endl;
	vector<int> ans = add(input1, input2);
	for(int i=0;i<ans.size();i++) {
		cout<<ans[i]<<" ";
	}
}
