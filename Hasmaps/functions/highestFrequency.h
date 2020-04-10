
int highestFrequency(int *a, int n){
    int maxOccuring=a[0];	 
    unordered_map<int, int> frequency;
    frequency[a[0]]++;
    for(int i=1; i<n; i++){
        frequency[a[i]]++;
        if (frequency[a[i]] > frequency[maxOccuring]){
            maxOccuring = a[i];
        }
    }
    return maxOccuring;
}

