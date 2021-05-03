//This program creates a max heap and allows for insertion and removal.
//Author: Kevin Lei
//Date: 4/23/2021

#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>
#include <stdlib.h>

using namespace std;

//Function Prototypes
void ADD(int heap[101]);
void UPHEAP(int heap[101], int index);
void REMOVE(int heap[101]);
void DOWNHEAP(int heap[101], int index);
void DISPLAY(int heap[101], int index, int depth);


//Main Method
int main() {

  //Creating heap
  int heap[101] = {};
  heap[0] = -1;
  for (int i = 1; i < 101; i++) {
    heap[i] = 0;
  }

  cout << "Welcome to Heap";
  char input[10];

  //Program will continue to run as long as user doesn't input QUIT
  while (strcmp(input, "QUIT") != 0) {
    cout << endl << "Type ADD, REMOVE, DISPLAY or QUIT" << endl;
    cin >> input;

    if (strcmp(input, "ADD") == 0) {
      ADD(heap);
    } else if (strcmp(input, "REMOVE") == 0) {
      REMOVE(heap);
    } else if (strcmp(input, "DISPLAY") == 0) {
      DISPLAY(heap, 1, 0);
    } else if (strcmp(input, "QUIT") != 0) {
      cout << "Invalid command";

    }
  }

  cout << "Goodbye" << endl;
  return 0;
}

//ADD function allows user to add numbers to the max heap
void ADD(int heap[101]) {
  char data[500];
  int i = 1;
  
  char method[10];
  cout << "Type INPUT or FILE" << endl;
  cin >> method;

  //Allows user to input numbers through the console
  if (strcmp(method, "INPUT") == 0) {
    cout << "Please type the numbers to be added to the heap:" << endl;
    cin.get();
    cin.get(data, 500);
    cin.get();

    char* ptr;
    ptr = strtok(data, " ");
    while (ptr != NULL) {
      if (i > 100) {
	cout << "Heap is full" << endl;
	return;
      }
      while (heap[i] != 0) {
	i++;
      }
      heap[i] = atoi(ptr);
      UPHEAP(heap, i);
      ptr = strtok(NULL, " ");
    }

    //Allows user to input numbers using a file
  } else if (strcmp(method, "FILE") == 0) {
    char fileName[50];
    cout << "Please type the file name:" << endl;
    cin >> fileName;

    ifstream file;
    srand(time(0));
    file.open(fileName);
    if (file == NULL) {
      cout << fileName << " could not be accessed" << endl;
      return;
    }
    while (file >> data) {
      if (i > 100) {
	cout << "Heap is full" << endl;
	return;
      }
      while (heap[i] != 0) {
	i++;
      }
      heap[i] = atoi(data);
      UPHEAP(heap, i);
    }

  } else {
    cout << "Invalid command" << endl;
    return;
  }
}

//Function that helps to restore the heap property after inserting numbers
void UPHEAP(int heap[101], int index) {
  if (index == 1) {
    return;
  }
  if (heap[index] > heap[/*floor*/(index/2)]) {
    int temp = heap[index];
    heap[index] = heap[/*floor*/(index/2)];
    heap[/*floor*/(index/2)] = temp;
    UPHEAP(heap, /*floor*/(index/2));
  } else {
    return;
  }
}

//REMOVE function prints out all the numbers in the heap from greatest to least
//and removes the numbers from the heap
void REMOVE(int heap[101]) {
  int a = 1;
  while (heap[a] != 0) {
    cout << heap[a] << " ";
    a++;
  }
  cout << endl;
  
  int lastIndex = 100;
  while (heap[1] != 0) {
    cout << heap[1] << " ";
    while (heap[lastIndex] == 0) {
      lastIndex--;
    }
    /*if (lastIndex == 1) {
      return;
      }*/
    heap[1] = heap[lastIndex];
    heap[lastIndex] = 0;
    DOWNHEAP(heap, 1);
  }
  cout << endl;
}

//Function that helps to restore the heap property after removal
void DOWNHEAP(int heap[101], int index) {
  if ((heap[index] < heap[index*2]) || (heap[index] < heap[(index*2)+1])/* && (index < 51)*/) {
    int temp = 0;
    if (heap[index*2] > heap[(index*2)+1]) {
      temp = heap[index*2];
      heap[index*2] = heap[index];
      heap[index] = temp;
      //DISPLAY(heap, 1, 0);
      //cout << endl;
      DOWNHEAP(heap, index*2);
    } else {
      temp = heap[(index*2)+1];
      heap[(index*2)+1] = heap[index];
      heap[index] = temp;
      //DISPLAY(heap, 1, 0);
      //cout << endl;
      DOWNHEAP(heap, (index*2)+1);
    }
  }
  return;
}

/*void DISPLAY(int heap[101]) {
  if (heap[1] != 0) {
    cout << heap[1];
  } else {
    return;
  }
  cout << endl;

  for (int index = 2; index < 4; index++) {
    if (heap[index] != 0) {
      cout << heap[index];
      for (int i = 1; i < 33; i++) {
	cout << "    ";
      }
    } else {
      return;
    }
  }
  cout << endl;

  for (int index = 4; index < 8; index++) {
    if (heap[index] != 0) {
      cout << heap[index];
      for (int i = 1; i < 17; i++) {
	cout << "    ";
      }
    } else {
      return;
    }
  }
  cout << endl;

  for (int index = 8; index < 16; index++) {
    if (heap[index] != 0) {
      cout << heap[index];
      for (int i = 1; i < 9; i++) {
	cout << "    ";
      }
    } else {
      return;
    }
  }
  cout << endl;

  for (int index = 16; index < 32; index++) {
    if (heap[index] != 0) {
      cout << heap[index];
      for (int i = 1; i < 5; i++) {
	cout << "    ";
      }
    } else {
      return;
    }
  }
  cout << endl;

  for (int index = 32; index < 64; index++) {
    if (heap[index] != 0) {
      cout << heap[index];
      for (int i = 1; i < 3; i++) {
	cout << "    ";
      }
    } else {
      return;
    }
  }
  cout << endl;

  for (int index = 64; index < 101; index++) {
    if (heap[index] != 0) {
      cout << heap[index];
      cout << " ";
    } else {
      return;
    }
  }
  cout << endl;
}*/

//Function that displays the heap nicely.
void DISPLAY(int heap[], int index, int depth) {
  if ((heap[index] != 0) && (index <= 100)) {
    DISPLAY(heap, index * 2, depth + 1);
    for (int i = 0; i < depth; i++) {
      cout << "    ";
    }
    cout << heap[index] << "\n";
    DISPLAY(heap, (index * 2) + 1, depth + 1);
  }
  return;
}
