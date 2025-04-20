#include <iostream>
#include <pthread.h>
using namespace std;

int arr[1000];
int ans[1000];

void* left_sort(void* arg){
    int size = *(int*)arg / 2;
    for(int i = 0; i < size; i++){
        int min = i;
        for(int j = i; j < size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
    pthread_exit(NULL);
}

void* right_sort(void* arg){
    int n = *(int*)arg;
    int size = n / 2;
    for(int i = size; i < n; i++){   
        int min = i;
        for(int j = i; j < n; j++){    
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
    pthread_exit(NULL);
}

void* merge(void* arg){
    int n = *(int*)arg;
    int size = n / 2;
    int left_index = 0;
    int right_index = size;
    int idx = 0;

    while(left_index < size && right_index < n){
        if(arr[left_index] < arr[right_index]){
            ans[idx++] = arr[left_index++];
        }
        else{
            ans[idx++] = arr[right_index++];
        }
    }

    while(left_index < size){
        ans[idx++] = arr[left_index++];
    }

    while(right_index < n){
        ans[idx++] = arr[right_index++];
    }

    pthread_exit(NULL);
}

int main(){
    const int NUM_THREADS = 3;
    pthread_t threads[NUM_THREADS];

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    pthread_create(&threads[0], NULL, left_sort, &n);
    pthread_create(&threads[1], NULL, right_sort, &n);

    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_create(&threads[2], NULL, merge, &n);

    pthread_join(threads[2], NULL);

    cout << "Sorted Array:\n";
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
