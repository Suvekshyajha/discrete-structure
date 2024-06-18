#include<iostream>
#include<vector>
using namespace std;
void getinput(int r,int c,vector<vector<int> >&matrix){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			do{
				cout<<"enter the element in index matrix["<<i<<"]["<<j<<"]"<<endl;
			cin>>matrix[i][j];
			if(matrix[i][j]!=0 &&matrix[i][j]!=1){
				cout<<"Enter valid input that is 0 or 1"<<endl;
			}
			}while(matrix[i][j]!=0 &&matrix[i][j]!=1);
			
		}
	}
}
void print(int r,int c,vector<vector<int> >&matrix){
	int i,j;
	for(i=0;i<r;i++){
		for(j=0;j<c;j++){
			cout<<matrix[i][j]<<" ";
			
		}
		cout<<endl;
	}
}
void boolean(int r1,int c1,const vector<vector<int> >&mat1,const vector<vector<int> >&mat2 ){
	int i,j;
	cout<<"boolean join:"<<endl;
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			cout<<(mat1[i][j] || mat2[i][j])<< " ";
		}
		cout<<endl;
	}
	cout<<"boolean meet/bolean product:"<<endl;//in boolean algebra both boolean meet and product use same and operator
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++){
			cout<<(mat1[i][j] && mat2[i][j])<< " ";
		}
		cout<<endl;
	}
}

int main(){
	int r1,r2,c1,c2;
	cout<<"enter the no of rows and column of first matrix"<<endl;
	cin>>r1>>c1;
	cout<<"enter the no of rows and column of second matrix"<<endl;
	cin>>r2>>c2;
	if(r1!=r2||c1!=c2){
		cout<<"to perform operations the rows and columns of both matrix must be equal"<<endl;
		return 1;//exit program wiht error status 1
	}
	vector<vector<int> >mata(r1,vector<int>(c1));
	vector<vector<int> >matb(r2,vector<int>(c2));
	getinput(r1,c1,mata);
	getinput(r2,c2,matb);
	cout<<"first matrix:"<<endl;
	print(r1,c1,mata);
	cout<<"second matrix"<<endl;
	print(r2,c2,matb);
	if(r1==r2&& c1==c2){
		boolean(r1,c1,mata,matb);
	}
	
}
