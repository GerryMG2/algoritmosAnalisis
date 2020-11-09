#include <iostream>
using namespace std;

struct crew {
    int key;
    string name;
    string range; 

};

void swap(int*, int*);
int partition(int, int, int);
void quicksort(int, int, int);
void printArr(int, int);

int main(){
    
    int total = 0;
    string name = "", type = "";

    cout << "Total crew members: "<< endl;
    cin >> total;

    crew arrCrew[total];

    for (int i = 0; i <= total; i++){
        
        cout << "Name crew: " << endl;
        cin >> name;
        arrCrew[i].name = name;

        cout << "Type crew: " << endl;
        cin >> type;
        arrCrew[i].range = type;

        if(type == "rat"){
            arrCrew[i].key == 1;
        }else if(type == "woman" || type == "child"){
            arrCrew[i].key == 2;
        }else if(type == "man"){
            arrCrew[i].key == 3;
        }else if(type == "captain"){
            arrCrew[i].key == 4;
        }
    }

    int n = sizeof(arrCrew) / sizeof(arrCrew[0]);
    quicksort<crew>(arrCrew, 0, n - 1);

    return 0;
}



//Funcion de utilidad para intercambiar dos elementos
template <class Q>
void swap (Q* a, Q* b){
    Q t = *a;
    *a = *b;
    *b = t;
}


/*
La funcion toma el ultimo elemento como el pivote, 
coloca el elemnto pivote en su posicion correcta, 
coloca a todos los elementos más pequeños que el pivote 
a la izquierda y los elemetos más grandes, a la derecha.
*/
template <class Q>
int partition(Q arr[], int start, int finish){
    
    //pivote
    Q pivot = arr[finish];
    //el indice del elemento mas pequeño
    int i = start - 1;

    for (int j = start; j <= finish - 1; j++){
        //hace la comparacion su el elemento actual, es más pequeño que el pivote
        if(arr[finish] <= pivot){
            //incrementa el indice del elemento más pequeño
            i++;
            swap<Q>(&arr[i], &arr[j]);
        }
    }

    swap<Q>(&arr[i + 1], &arr[finish]);
    return(i + 1);
    
}

template <class Q>
void quicksort(Q arr[], int start, int finish){
    if(start < finish){
        
        //q es el indice de particion
        int q = partition<Q>(arr, start, finish);
        
        //elemntos desde start hasta una posición antes del pivote
        quicksort<Q>(arr, start, q - 1);
        //elementos después del pivote hasta finish
        quicksort<Q>(arr, q + 1, finish);
    }
}

//Funcion para imprimr el arreglo
/*void printArr(int arr[], int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
        cout << endl;
    }
    
}*/

/*void crewMember(string arrCrew[]){
    int total = 0;
    cout << "Total crew members: "<< endl;
    cin >> total;

    for (int i = 0; i <= total; i++){
        cout << "Name crew: " << endl;
        cin >> arrCrew[i];

        cout << "Type crew: " << endl;
        cin >> arrCrew[i];

    }
    return;
}*/
