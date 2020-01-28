/*myvector.h*/

// 
// <Hongcheng Wu>
// U. of Illinois, Chicago
// CS 251: Fall 2019
// 
// Project #01: myvector class that mimics std::vector, but with my own
// implemenation outlined as follows:
//
// I use a struct node and pointer hd and pointer tl, so I am be able to push_back in O(1)
//

#pragma once

#include <iostream>  // print debugging
#include <cstdlib>   // malloc, free

using namespace std;

template<typename T>
class myvector
{
  private:
	//T* A;
	struct NODE
	{
		T A;
		NODE* next;
	};
	int  Size;
	NODE* hd;
	NODE* tl;

  public:
	// default constructor:
	myvector()  {
		Size = 0;
		hd = nullptr;
		tl = nullptr;
	}

	// constructor with initial size:
	myvector(int initial_size){
		Size = initial_size;
		if(Size < 1){
			hd = nullptr;
			tl = nullptr;
		}
		else{
			hd = new NODE();
			hd->A = 0;
			hd->next = nullptr;
			tl = hd;
			
			int counter = 1;
			while(counter < Size){
				NODE* temp = new NODE();
				temp->A = 0;
				temp->next = nullptr;
				tl->next = temp;
				tl = temp;
				counter++;
			}
		}
	}
	
	// copy constructor for parameter passing:
	myvector(const myvector& other){
		NODE* temp = other.hd;
		hd = nullptr;
		tl = nullptr;
		Size = 0;
		while(temp!=nullptr){
			push_back(temp->A);
			temp = temp->next;
		}
	}

	int size()
	{
		return Size;
	}

	//return the ith of the node
	T& at(int i){
		int counter = 0;
		
		NODE* temp = hd;
		while(temp != nullptr){
			if(counter == i){
			  return temp->A;
			}
			counter++;
			temp = temp->next;
		}
		return temp->A;	//should not run here, is just for stop warnning
	}
  
	void push_back(T value)
	{
		NODE* temp = new NODE();
		temp->A = value;
		temp->next = nullptr;
		
		if(hd == nullptr){
			hd = temp;
			tl = hd;
		}
		else{
			tl->next = temp;
			tl = temp;
		}
		Size++;
	}
	
	//return the element to be delete
	T erase(int i){
		NODE* curr = hd;
		NODE* tobeDelete = hd;
		if(i == 0){
			hd = curr->next;
			Size--;
			return curr->A;
		}
		
		for (int j=0; curr!=NULL && j<i-1; j++) 
			curr = curr->next;
		
		NODE* next = curr->next->next;
		tobeDelete = curr->next;
		curr->next = next;
		Size--;
		return tobeDelete->A;
	}
	
	//does not work for delete tail
	T erase_bug(int i){
		NODE* curr = hd;
		NODE* prev = hd;
		int counter = 0;

		//earse head
		if (curr != nullptr && counter == i){ 
			hd = curr->next;
			Size--;
			return curr->A; 
		}
		
		//not head, counter add up to 1
		counter++;
		while(curr != nullptr && counter != i){
			prev = curr;
			curr = curr->next;
			counter++;
		}
		if(curr == nullptr) return -1;
		
		prev->next = curr->next;
		Size--;
		return curr->next->A ;
	}
	
	//debug
	void display(){
		NODE* temp = hd;
		if(temp == nullptr) cout << "empty" << endl;
		while(temp != nullptr){
			cout << temp->A << "-";
			temp = temp->next;
		}
		cout << "display complete" << endl;
		return;
	}
	
	T& operator[](int i){
		return at(i);
	}
	
	T* rangeof(int i, int j){
		T* array = new T[Size];
		int counter = 0;
		NODE* temp = hd;
		
		for(int k = 0; k < Size; ++k){
			if( j >= k && k >= i){
				array[counter] = temp->A;
				counter++;
			}
			temp = temp->next;
		}
		return array;
	}
	
	//debug
	void displayArray(T* array){
		size_t n = sizeof(array)/sizeof(array[0]);
		for(size_t i = 0; i < n; i++){
			cout << array[i];
		}
	}
};
