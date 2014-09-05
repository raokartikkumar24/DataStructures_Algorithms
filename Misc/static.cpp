#include<iostream>

using namespace std;

class statictest {

public:

void updateStaticItem()
{//we can access the static member variable becos , static dont need no this pointer
	x = 100;
}

static void updatey()
{ // i dont think we can access y here. becos static methods dont have the this pointer
	//y = 200;
}

private :
static int x;
int y;
};

int main()
{

	return 0;

}
