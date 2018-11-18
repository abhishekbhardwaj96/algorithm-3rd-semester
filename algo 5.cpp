#include<iostream>
#include<string>
using namespace std;

bool isSubString(string str,string substr){
    	/*
    	Objective : To check if the subseqyence entered occurs in sequence inputted in O(m+n) 
    	Input :     str:-string that is n no of events
    		    substr;- substring that is to be search in a string
	Return values : None 
   	 */
	
	int len,sublen,i,j=0,temp=0;
	len = str.length();
	sublen = substr.length();
	
	for(int i=0;i<len;i++){ 								// loop till the vlength of a string
		if(str[i]==substr[j]){								// if character matches
			j++;
		}
		else{										//temp is a variable that is used to store a positon example:- if buy flip is in string and we 
			j = temp;								// have buy flipkart in substring then k will not match and searching has to be strted from 
		}										//start of the word buy flipkart
		if(substr[i] == ','){
			temp = j+1;
		}
		
	}
	if(j == sublen&& j!=0){						            	   //if j is equal to sublen means we have reach at the end of substr
		return true;
	}
	return false;
}

int main(){
  	
	string str,substr;
	cout<<"enter n  events separated by ',' \n";
	getline(cin,str);
	cout<<"enter substring \n";
	getline(cin,substr);
	
	
	if(isSubString(str,substr)){
		cout<<"\n it is a substring   \n";
	}
	else{
		cout<<"\n it is not a substring   \n";
	}
	
		return 0;
}
