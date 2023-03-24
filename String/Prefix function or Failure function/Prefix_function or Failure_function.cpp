
#define MAX 100000
int failure[MAX];

void build_failure_function(string pattern, int m) {
  failure[0] = 0 
  failure[1] = 0; 
  
  for(int i = 2; i <= m; i++) {  
    
    int j = failure[i - 1];
    while(true) {
      if(pattern[j] == pattern[i - 1]) { 
        failure[i] = j + 1; 
        break; 
      }
      if(j == 0) { 
          failure[i] = 0; 
          break; 
      }
      j = failure[j];
    }
  }   
}