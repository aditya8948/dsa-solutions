class Solution {
public:
    bool countBit(int num){
        long mask = 1L<<22;
        int count = 0;
        while(mask){
            if(num & mask) count++;
            mask>>=1;
        }
        // value can be only 20  bit so only 1 to 20 number are possible
        vector<int>prime = {2,3,5,7,11,13,17,19};
        for(int i = 0 ; i < prime.size() ;i++){
            if(count == prime[i]) return true;
        }
        return  false ;
    }
    // check prime 

    //   bool isPrime(int num){
    //     if(num < 2) return false;
    //     for(int i = 2; i * i <= num; i++){
    //         if(num % i == 0) return false;
    //     }
    //     return true;
    // }


    int countPrimeSetBits(int left, int right) {
        int bitCount =  0;
        while(left <= right){
          bool prime = countBit(left);
          if(prime) bitCount++;
          left++;
        }
        return bitCount;
    }

};