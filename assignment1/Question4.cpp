#include<iostream>
using namespace std;
int main(){
    int size;
    cout<<"Enter size: ";
    cin>>size;
    int matrix[size][size];
    int number=1,top=0,bottom=size-1,left=0,right=size-1;

while(number<=size*size){
    for(int i=left;i<=right;i++)
    matrix[top][i]=number++;
    top++;

for(int i=top;i<=bottom;i++)
matrix[i][right]=number++;
right--;

if(top<=bottom)
for(int i=right;i>=left;i--)
matrix[bottom][i]=number++;
bottom--;

if(left<=right)
for(int i=bottom;i>=top;i--)
matrix[i][left]=number++;
left++;

}
cout<<"Spiral Matrix: "<<endl;
for(int i=0;i<size;i++){
    for(int j=0;j<size;j++)
    cout<<matrix[i][j]<<" ";
    cout<<endl;
    }
    
return 0;
    }
