#include<iostream>
int v = 100; //Global Variable
int temp()
{
	int j = 10;
	return j;
}
int main()
{
    /*
		Random Comment
	*/
	//Okay this is just another comment

    int x = 5, p = 1;
    int a = 10;
    c = 10;
    //Showing the usage of brackets and for loops
    for (int i = 1; i <= x; i++)
    {
        p = x * i;
        int j = 7;
    }
	//Usage of if and else conditions
    if (x <= 0)
    {
        if (x < 0)
        {
            x = x + 1;
        }
        else
        {
            x = x * 2;
        }
    }
    //Showing the working of the same without braces. 
    else if (x > 5)
        x = 10;
    else if (x < 0)
        x = x * 10;
    else
        x = 0;
    return 0;
}
