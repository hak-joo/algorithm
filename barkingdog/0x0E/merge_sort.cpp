#include <iostream>

using namespace std;

int arr[1000001];
int tmp[1000001];
int n;

void merge(int start, int end);
void merge_sort(int start, int end);

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    for(int i=0; i<n; i++) cin >> arr[i];

    merge_sort(0,n);

    for(int i=0; i<n; i++) cout << arr[i] <<" ";
}

void merge(int start, int end){
    int mid = (start+end) / 2;
    int sIdx = start;
    int eIdx = mid;

    for(int i = start; i < end; i++){
        if(sIdx == mid) tmp[i] = arr[eIdx++];
        else if (eIdx == end) tmp[i] = arr[sIdx++];
        else if (arr[eIdx] < arr[sIdx]) tmp[i] = arr[eIdx++];
        else tmp[i] = arr[sIdx++];
    }
    for(int i=start; i<end; i++) {
        arr[i] = tmp[i];
    }
}

void merge_sort(int start, int end){
    if (start+1 == end) return;
    int mid = (start + end) / 2;
    merge_sort(start, mid);
    merge_sort(mid, end);
    merge(start, end);

}