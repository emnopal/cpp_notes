#include <iostream>
#include <stdio.h> 
#include <stdlib.h> 

/*class test{ // classnya
public: 
	int test1;
	test() {test1 = 10;}
};

int main(){
	test testing = test(); // deklarasi
	test* test2 = &testing; // deklarasi
	std::cout << "dot operator: " << testing.test1 << std::endl; // dot operator
	
	/*
	arrow operator
	(pointer_name) -> (variable_name)
	* /

	std::cout << "arrow operator: " << test2 -> test1 << std::endl; // arrow operator
	return 0;
}*/

// Creating the structure 
struct student{ 
    char name[80]; 
    int age; 
    float percentage; 
}; 
  
// Creating the structure object 
struct student* emp = NULL; 
  
// Driver code 
int main(){ 
    // Assigning memory to struct variable emp 
    emp = (struct student*) 
        malloc(sizeof(struct student)); 
  
    // Assigning value to age variable 
    // of emp using arrow operator 
    emp->age = 18; 
  
    // Printing the assigned value to the variable 
    printf("%d", emp->age); 
  
    return 0; 
}
