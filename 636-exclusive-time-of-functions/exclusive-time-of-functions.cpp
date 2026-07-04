class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> result(n,0);
        stack<int> s;
        int lastTimeStamp = 0;

        for(string log : logs){
            // parse the string 

            stringstream ss(log);;
            string token;

            getline(ss, token, ':');
            int id = stoi(token);

            getline(ss, token, ':');
            string type = token;

            getline(ss, token, ':');
            int time = stoi(token);
        
            if(type == "start"){
                if(!s.empty())
                result[s.top()] += time - lastTimeStamp;
                
                s.push(id);
                lastTimeStamp = time;
            }else{
                result[s.top()] +=  time - lastTimeStamp + 1;
                s.pop();
                lastTimeStamp = time+1;
            }
        }
        return result;
    }
};