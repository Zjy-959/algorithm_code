#include<stdio.h>
#include<iostream>
#include<math.h>
#include"RandomNuber.h"

using namespace std;
class Queen{
	friend void nQueen(int);
private:
	bool Place(int k);
	bool QueenLV(void);
	int n;
	int x;
	int y;
};
bool Queen::Place(int k){
	for(int j=1;j<k;j++){
		if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k])){
			return false;
		}
	}
	return true;
}
bool Queen::QueensLV(void){
	RandomNumber rnd;
	int k=1;
	int count=1;
	while((k<n)&&(count>0)){
		count=0;
		for(int i=1;i<=n;i++){
			x[k]=i;
			if(Place(k)){
				y[count++]=i;
			}
		}
		if(count>0){
			x[k++]=y[rnd.Random(count)];
		}
	}
	return (count>0);
}
void nQueen(int n){
	Queen X;
	X.n=n;
	int *p=new int [n+1];
	for(int i=0;i<=n;i++){
		p[i]=0;
	}
	X.x=p;
	while(!X.QueensLV());
	for(int i=1;i<-n;i++){
		cout<<p[i]<<"";
	cout<<endl;
	delete p;
	}
}
int main(){
	int n;
	cout<<"n=";
	cin>>n;
	nQueen(n);
}
