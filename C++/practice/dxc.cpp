#include <bits/stdc++.h>
using namespace std;

void* hello(void* args) {
    cout << "Hello World!" << endl;
}

int main() {
    pthread_t tids[5];
    for (int i = 0; i < 5; i++) {
        int retN = pthread_create(&tids[i], NULL, hello, NULL);
        if (retN != 0)
            cout << "error" << retN << endl;
    }
    pthread_exit(NULL);
    return 0;
}