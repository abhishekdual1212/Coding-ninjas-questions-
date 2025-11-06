// User function template for C++


// sliding window question count occurrences of anagrams 
class Solution {
  public:
  bool allzero(vector<int> &counter){
      for(int &i : counter){
      if(i!=0)
      return false;
          
      }
      return true;
  }

    int search(string &pat, string &txt) {
        int n =txt.size();
        vector<int> counter(26,0);
        //count the frequency of each chars in pat
        
        for(int i =0;i<pat.length(); i++){
            char ch = pat[i];
            
            counter[ch -'a']++;
        }
        int i =0;
        int j=0;
        int result = 0;
        int k = pat.length();
        
        while(j<n){
            counter[txt[j]-'a']--;
            if(j-i+1==k){
                if(allzero(counter)){
                    result++;
                    }
                    counter[txt[i] -'a'] ++ ;
                    i++;
                    
            }
            j++;
        }
        
         return result;
    }
};
