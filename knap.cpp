#include<iostream>
#include <math.h> 
using namespace std;
//-------------------------------------------------program to print values----------------------------------------------
void printRes(int mr[], int x[], int m, int n) {
     /*
    Objective: to print the final positions selected for billboard from the set of available billboard position set.
    Input : - mr - the array that contains profit with repect to distance
    	      x  - the array that contain distance of each billboard
	      m  - total distance
	      n  - no of billiboards
    Return Value : None
    */
    int res[n];
    int cnt=0;

    for(int i=m; i>=0; i--) {
        if(mr[i]!=mr[i-1]) {
           res[cnt++]=i;
           i=i-5;
        }
    }

    cout<<"\n\nBillboards should be placed at positions: ";
    for(int i=cnt-2; i>0; i--)
        cout<<res[i]<<", ";
    cout<<res[0]<<endl;
}

//-------------------------------------------------------knapsack program--------------------------------------
void knapsack(int knap[],int x[],int r[],int size){
     /*
    Objective: to find the optimal solution
    Input : - knap - the array that contains profit with repect to distance
    	      x  -  the array that contain distance of each billboard
	      r  -  the array that contains the revenue w.r.t. to each billiboard 
	      size  - no of billiboards
    Return Value : None
    */
	
	int i=1,temp;
	for(int j=0;j<size;j++){
		if(j==0 || j < x[1]){
			knap[j] = 0;
		}
		else {
			if(j == x[i] ){
				temp = knap[j-1];
				if(x[i]-5 < 0 && temp < r[i]){
					temp = r[i];
				}
				else if(x[i]-6 < x[i-1] ){
				temp = max(temp,r[i]+knap[j-6]);
				
				}
				else{
					temp = r[i]+knap[j-1];
				}
				knap[j] = temp;
				i++;	
			}
			else{
				knap[j] = knap[j-1]; 
			}
		}
	}
}

//----------------------------------insertion sort function ---------------------------------------------------
void sort(int x[],int r[],int n){
     /*
    Objective: to print the final positions selected for billboard from the set of available billboard position set.
    Input : - r  -  the array that contains the revenue w.r.t. to each billiboard 
    	      x  - the array that contain distance of each billboard
	      n  - no of billiboards
    Return Value : None
    */
	
	for(int i=1;i<n;i++){
		int temp1 = x[i];
		int temp2 = r[i];
		int j=i-1;
		while(j>=0 && x[j] > temp1){
			x[j+1] = x[j];
			r[j+1] = r[j];
			j--;
		}
		x[j+1] = temp1;
		r[j+1] = temp2;
	}
}

//----------------------------------main module ---------------------------------------------------

int main() {
//-----------------------initialization of values ---------------------------------
	int n,max_wght;									// n for total no of billiboards and max_wght is
											// total distance 
	cout<<"\nEnter the number of available billboards: \n";
	cin>>n;
	cout<<"Enter the length of the road(in miles): ";

	cin>>max_wght;
	int x[n+1];									// for position of billi boards 
	int r[n+1];									//revenue for particular billiboard
	int knap[max_wght+1];                                                           // array that contain optimal profit for every length
	x[0] = r[0] = 0;
	cout<<"enter positions for billiboards\n";
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	
	cout<<"enter respective revenue \n";
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	
//-----------------------sorting --------------------------------------------------	
	sort(x,r,n);									// if position of billi board is not in ascending order
	
	
	for(int i=0;i<=max_wght;i++){							// for initializing profit to zero
		knap[i]=0;
	}
	
	
	knapsack(knap,x,r,max_wght+1);							// for finding optimal solution
	
	cout<<"---------------- optimal profit by placing billiboards is-------------------\n                       "<<knap[max_wght];
	
	printRes(knap,x,max_wght,n+1);							// for print the postion of billiboards 
											//bcz of which we ind optimal solution
	
	return 0;
}
