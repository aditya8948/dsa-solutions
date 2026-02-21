class Solution {
public:
    int countBit(int num){
        long mask = 1L<<31;
        int count = 0;
        while(mask){
            if(num & mask) count++;
            mask>>=1;
        }
        return count ;
    }
      bool isPrime(int num){
        if(num < 2) return false;
        for(int i = 2; i * i <= num; i++){
            if(num % i == 0) return false;
        }
        return true;
    }


    int countPrimeSetBits(int left, int right) {
        int bitCount =  0;
        while(left <= right){
          bool prime = isPrime(countBit(left));
          if(prime) bitCount++;
          left++;
        }
        return bitCount;
    }

};