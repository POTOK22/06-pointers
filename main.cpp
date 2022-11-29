/*
06 - Recursion, pointers and references
Homework
by Grzegorz Potocki
*/

#include <iostream>
#include <limits>
#include <string.h>

void small_to_capital(char a[]){
    for(int i=0; i<strlen(a); i++){ //as long as i is smaller than the length of array
        a[i]=toupper(a[i]);         //every element of an array will be changed to uppercase
    }
}
void bubble_sort(char a[], int b){
    for(int i=0; i<b-1; i++){
        for(int j=1;j<b-i; j++){
            if(a[j-1]>a[j]){
                std::swap(a[j-1], a[j]);
            }
        }
    }
    for(int i=0; i<b; i++){
        std::cout<<a[i]<<std::endl;
    }
}
void statistics(char a[]){
    int counter;
    int visited[strlen(a)];
    for(int i=0; i<strlen(a); i++){
        if(visited[i]==1){
            continue;
        }
        else {
            counter=0;
            for(int j=0; j<strlen(a); j++){
                if(a[i]==a[j]){
                    visited[j]=1;
                    counter++;
                }
            }
        }
        std::cout<<a[i]<<": "<<counter<<" ";
    }
}
void h_mean(int a[], int b){
    float den=0.0;
    for(int i=0; i<b; i++){
        den+=1/static_cast<float>(a[i]);
    }
    float mean=b/den;
    std::cout<<"harmonic mean: "<<mean<<std::endl;
}
void cipher(char a[]){
    for(int i=0; i<strlen(a); i++){
        if(a[i]>='A' && a[i]<='Z'){
            a[i]=('Z'-(a[i]-'A'));
        }
        else if(a[i]>='a' && a[i]<='z'){
            a[i]=('z'-(a[i]-'a'));
        }
    }
    std::cout<<a;
}
void decipher(char a[]){
    for(int i=0; i<strlen(a); i++){
        if(a[i]>='A' && a[i]<='Z'){
            a[i]=('A'-(a[i]-'Z'));
        }
        else if(a[i]>='a' && a[i]<='z'){
            a[i]=('a'-(a[i]-'z'));
        }
    }
    std::cout<<a;
}

int main()
{
    bool end_h=false;
    do{
        int user_choice;
        std::cout<<"Choose an option:\n1 - Exercise 1\n2 - Exercise 2\n3 - Exercise 3\n4 - Homework 1\n5 - Homework 2\nEverything else - Exit"<<std::endl;
        std::cin>>user_choice;
        switch(user_choice){
            case 1:{
                char arr[100];
                std::cout<<"Enter the letters to the array: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.getline(arr, 100);
                small_to_capital(arr);
                std::cout<<arr<<std::endl;
                break;
            }
            case 2:{
                int size_arr;
                std::cout<<"Enter the size of an array: ";
                std::cin>>size_arr;
                char arr[size_arr];
                std::cout<<"Enter the values to an array: ";
                std::cin>>arr;
                bubble_sort(arr, size_arr);
                break;
            }
            case 3:{
                char text[100];
                std::cout<<"Enter text: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.getline(text, 100);
                statistics(text);
                std::cout<<std::endl;
                break;
            }
            case 4:{
                int size_arr;
                std::cout<<"Enter the size of an array: "<<std::endl;
                std::cin>>size_arr;
                int arr[size_arr];
                std::cout<<"Enter the values into an array: "<<std::endl;
                for(int i=0; i<size_arr; i++){
                    std::cin>>arr[i];
                }
                h_mean(arr, size_arr);
                break;
            }
            case 5:{
                char text[100];
                std::cout<<"Enter text: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cin.getline(text, 100);
                cipher(text);
                std::cout<<std::endl;
                decipher(text);
                std::cout<<std::endl;
                break;
            }
            default:{
                std::cout<<"Exiting homeworks"<<std::endl;
                end_h=true;
            }

        }

    }
    while(!end_h);
}
