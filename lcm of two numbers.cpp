#include<iostream>
using namespace std;
int lcm(int a, int b)
{
	int i;
	for( i=1; i<=a*b ;i++)
	{
	if(i%a==0 && i%b==0)//checking whether the value of i is multiple of both a and b.
    return i;//This returns the least common multiple of a and b.
}
}
main()
{
	int a,b;
	cout<<"Enter two numbers\n";
	cin>>a>>b;//Taking two numbers a and b as input.
	cout<<"The LCM of "<<a<<" and "<<b<<":\t"<<lcm(a,b);//Printing the lcm of given two numbers.
}

