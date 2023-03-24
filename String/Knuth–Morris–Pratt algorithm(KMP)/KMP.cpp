
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


bool kmp(string text, string pattern)
{
  int n = text.size();
  int m = pattern.size();
  build_failure_function(pattern, m); 

  int i = 0;

  int j = 0; 
  
  while(true) {
    if(j == n) {
        return false;
    }

    if(text[j] == pattern[i]) {
      i++;
      j++;
      if(i == m) {
          return true;
      }
    } else {
        if (i == 0) {
            j++;
        }
        else {
            i = failure[i];
        }
    }
  }
  return false;
}