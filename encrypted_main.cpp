#include<bits/stdc++.h>
using namespace std;
string inname;
string outname;
string encrypt;
string option;
int main(){
	cout<<"enter key: ";
	getline(cin,option);
	cout<<endl;
	if(option=="pencil"){
		cout<<"input from file (with extension): ";
		getline(cin,inname);
		ifstream input;
		input.open(inname.c_str());
		cout<<endl<<"output to file (with extension): ";
		getline(cin,outname);
		ofstream output;
		output.open(outname.c_str());
		int line=1,temp=0;;
		while(getline(input,encrypt)){
			for(int j=0;j<line;j++){
				if(temp%2==0){
					for(int i=encrypt.length()-1;i>=0;i--){
						output<<encrypt.at(i)<<char((i+temp)%94+32);
					}
				}
				else{
					for(int i=0;i<=encrypt.length()-1;i++){
						output<<encrypt.at(i)<<char((line+i+j)%94+32);
					}
				}
				temp++;
				if(temp==2) temp=0;
			}
			output<<endl;
			line++;
		}
		input.close();
		output.close();
	}
	else if(option=="register"){
		cout<<"input from file (with extension): ";
		getline(cin,inname);
		ifstream input;
		input.open(inname.c_str());
		cout<<endl<<"output to file (with extension): ";
		getline(cin,outname);
		ofstream output;
		output.open(outname.c_str());
		int line=1,temp=0;
		while(getline(input,encrypt)){
			if(temp%2==0){
				int count=encrypt.length()/2;
				if(line%4==1){
					for(int i=encrypt.length()-2;i>=0;i-=2){
						count-=line;
						if(count<0) break;
						output<<encrypt.at(i);
					}
				}
				else{
					for(int i=0;i<=encrypt.length()-2;i+=2){
						count-=line;
						if(count<0) break;
						output<<encrypt.at(i);
					}
				}
			}
			else{
				if(line%4==2){
					for(int i=0;i<encrypt.length()/line;i+=2) output<<encrypt.at(i);
				}
				else{
					for(int i=encrypt.length()/line-2;i>=0;i-=2) output<<encrypt.at(i);
				}
			}
			temp++;
			if(temp==2) temp=0;
			line++;
			output<<endl;
		}
	}
	else cout<<"unable to provide service without valid key"<<endl;
	return 0;
}
