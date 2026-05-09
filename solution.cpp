class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if(num.empty()) return res;
        backtrack(res, num, target, "" , 0,0LL,0LL);
        return res;
    }
    void backtrack(vector<string>& res, string& num, int& target , string temp, int idx, long long curr, long long prev){
        if(idx==num.size()) {
            if(curr==target){
                res.push_back(temp);
            }
            return;
        }

        for( int j = idx;j<num.size();j++){
            if(j>idx && num[idx]=='0') break;
            long long currnum = stoll(num.substr(idx,j-idx+1));
            string currstr = num.substr(idx,j-idx+1);

            if(idx==0){
                backtrack(res,num,target,temp+currstr,j+1,curr+currnum,currnum);
            }else{
                backtrack(res,num,target,temp+"+"+currstr,j+1,curr+currnum,currnum);
                backtrack(res,num,target,temp+"-"+currstr,j+1,curr-currnum,-currnum);
                backtrack(res,num,target,temp+"*"+currstr,j+1,(curr-prev)+(prev*currnum),prev*currnum);
            }
        }
    }
};
