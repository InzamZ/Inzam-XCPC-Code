#include <iostream>

int main()
{
	int A,B,C;
	std::cin>>A>>B>>C;
	if (A==B)
	{
		if (C==0) std::cout<<"Aoki"<<std::endl;
		else std::cout<<"Takahashi"<<std::endl;
	}
	else if (A>B) std::cout<<"Takahashi"<<std::endl;
	else std::cout<<"Aoki"<<std::endl;
	return 0;
}