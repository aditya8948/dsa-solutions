class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();
        int start = 0;     
        int tank = 0;      
        int gasSum = 0;    
        int costSum = 0;   

        for(int i = 0; i < n; i++){
            gasSum = gasSum + gas[i];     // total gas jod rahe
            costSum = costSum + cost[i]; // total cost jod rahe

            tank = tank + gas[i] - cost[i]; // is station ke baad tank me kitni gas bachi

            // agar tank negative ho gaya
            // matlab current start se journey possible nahi
            if(tank < 0){
                start = i + 1;  // next station se start karenge
                tank = 0;       // tank ko reset
            }
        }

        // agar total gas hi kam hai total cost se
        // to koi bhi start se pura round possible nahi
        if(gasSum < costSum)
            return -1;

        return start;
    }
};
