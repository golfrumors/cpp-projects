#include <iostream>

void ioError(int n){
	n += int('0');
	std::cout<<"Error: " << char(n) << " is not a valid input\n";
}

void ioError(char t){
	std::cout<<"Error: " << t << " is not a valid input\n";
}

void invalidMove(int n){
	std::cout<<"Error: The move " << n << " is not a valid move\n";
}

void printBoard(int a[]){

	std::cout<<" " << a[0] << " | " << a[1] << " | " << a[2] <<" \n";

	std::cout<<"-----------\n";

	std::cout<<" " << a[3] << " | " << a[4] << " | " << a[5] <<" \n";

	std::cout<<"-----------\n";

	std::cout<<" " << a[6] << " | " << a[7] << " | " << a[8] <<" \n";

}

bool isTwoPlayers (){
	bool flag;
	char tmp;

	do{
		try{
			std::cout<<"Are you playing with two players? Y/N: ";
			std::cin>>tmp;

			if(tmp == 'Y' || tmp == 'N'){
				break;
			} else {
				throw(tmp);
			}

		} catch (char tmp){ ioError(tmp); }
	}while(tmp != 'Y' || tmp != 'N');

	(tmp == 'Y') ? flag = true : flag = false;

	return flag;
}

void validateMove(int a[]){
	char n;
	int ia = 0;
	int l = sizeof(a) / sizeof(*a);

	std::cout << "Please select your move from the avaliable numbers: \n";

	printBoard(a);

	do{
		try{
			std::cout << "Input: ";
			std::cin>>n;
			int ia = n - '0';

			if(ia >= 1 && ia <= 9){

				bool exists = false;

				for(int i = 0; i < l; i++){
					if(a[i] == n){
						exists = true;
						break;
					} else {
						exists = false;
						invalidMove(n);
						}

				}

				if(exists){
					std::cout << "found at : " << std::distance(a, a+n) << std::endl;
				} else {
					std::cout << "not found :( ";
				}


			} else {

				throw(ia);

			}

		} catch(int n){ ioError(n); }

	}while(ia < 1 || ia > 9);

}



int main(){

	int boardState[] = {1,2,3,4,5,6,7,8,9};
	bool twoPlayers = isTwoPlayers();
	validateMove(boardState);

	printBoard(boardState);


	return 0;
}
