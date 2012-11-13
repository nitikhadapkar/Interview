#include <iostream>

using namespace std;
class Print
{
	static int n;

	public:
		Print()
		{
			cout<<n<<endl;
			n++;
		}
		~Print(){}
};

int Print::n = 1;

int main()
{
	Print p[10];
	return 0;
}
