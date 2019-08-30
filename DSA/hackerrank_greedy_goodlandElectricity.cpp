int pylons(int k, vector<int> arr) {

    int n = arr.size() ;
    bool vis = false ;
    int i = 0 ;
    int plants = 0 ;
    while(i < n)
    {
        vis = false ;
        int range = i+k-1 ;
        while(range >=0 && range > i-k+1 && arr[range]!=1) range-- ;
        if(arr[range] == 1) vis = true , plants++ ;
        else return -1 ;
        i = range+k ;
    }

    if(!vis) return -1 ;
    else return plants ;


}