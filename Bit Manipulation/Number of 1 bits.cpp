int setBits(int N) {
        int count=0;
        while(N!=0){
            if((N&1)!=0){
                count++;
            }
            N=N>>1;
        }
        return count;
}
