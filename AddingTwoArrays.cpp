#include<bits/stdc++.h>
using namespace std;

vector<int> Sum(vector<int> &input1, vector<int> &input2) {
	reverse(input1.begin(), input1.end());
	reverse(input2.begin(), input2.end());
	int i = 0, j = 0;
	vector<int> output;
	int carry = 0;
	while(i < input1.size() && j < input2.size()) {
		int sum = input1[i] + input2[j] + carry;
		if(sum < 10) {
			output.push_back(sum);
			carry = 0;
		} else {
			output.push_back(sum % 10);
			carry = sum/10;
		}
		i++;
		j++;
	}
	while(i < input1.size() && carry > 0) {
		int sum = input1[i] + carry;
		if(sum < 10) {
			output.push_back(sum);
			carry = 0;
		} else {
			output.push_back(sum % 10);
			carry = sum/10;
		}
		i++;
	}
	while(j < input2.size() && carry > 0) {
		int sum = input2[j] + carry;
		if(sum < 10) {
			output.push_back(sum);
			carry = 0;
		} else {
			output.push_back(sum % 10);
			carry = sum/10;
		}
		j++;
	}
	while(i == input1.size() && j == input2.size() && carry > 0) {
		output.push_back(carry % 10);
		carry /= 10;
	}
	while(i < input1.size() && carry == 0) {
		output.push_back(input1[i]);
		i++;
	}
	while(j < input2.size() && carry == 0) {
		output.push_back(input2[j]);
		j++;
	}
	reverse(output.begin(), output.end());
	return output;
}

int main() {
	vector<int> input1, input2;
	int n1, n2;
	cout<<"Enter n1: ";
	cin>>n1;
	cout<<"Enter n2: ";
	cin>>n2;
	cout<<"Enter for input1: ";
	for(int i=0;i<n1;i++) {
		int val;
		cin>>val;
		input1.push_back(val);
	}
	cout<<"Enter for input2: ";
	for(int i=0;i<n2;i++) {
		int val;
		cin>>val;
		input2.push_back(val);
	}
	vector<int> output = Sum(input1, input2);
	for(int i=0;i<output.size();i++) {
		cout<<output[i]<<" ";
	}
	return 0;
}
