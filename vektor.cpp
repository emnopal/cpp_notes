#include "std_lib_facilities.h"

int main(){
    cout << "masukkan angka: \n" 
    << "keterangan: masukkan karakter selain"
    << "angka untuk evaluasi hasil\n";
	vector<float> temps;
	float temp;
	while (cin>>temp)  temps.push_back(temp);
	float sum = 0;
	for (int i = 0; i< temps.size(); ++i) sum += temps[i];
	cout << "Mean temperature: " << sum/temps.size() << '\n';
	sort(temps);
	cout << "Median temperature: " << temps[temps.size()/2] << '\n';
}