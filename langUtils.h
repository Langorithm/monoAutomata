#include<string>
#include<vector>
#include<iostream>
#include<math.h>
template <class T>
std::vector<T> digitize(T n){
	std::string aux = std::to_string(n);
	
	std::vector<T> res(aux.size());
	//std::vector res(aux.size());
	
	for (int i = 0; i< aux.size(); i++)
		res[i] = int(aux[i]) - int('0');
	
	return res;
}

int decToBinF(int n, int counter){
	if (n < 2) 
		return n * std::pow(10,counter);
	else
		return n%2 * std::pow(10,counter) + decToBinF(n/2, counter+1);

}

int decToBin(int n){
	return decToBinF(n,0);
}

template <class T>
void printVector(std::vector<T> v){
		
	std::cout << '[';

	for (int i = 0; i < v.size() ; i++){
		std::cout << v[i];
		if ( i+1 != v.size() )
			std::cout << ',';
	}

	std::cout << ']' << std::endl;

}



