const int tam = 1e5;
int lps;
int n, m;
string s, txt;

int solve() {
    int ans = 0;
    n = s.size();
    m = txt.size();
    computeLPS();
    int i = 0, j = 0;
    while( i < m ) {
        if( txt[i] == s[j] ) {
            i++;
            j++;
        }
        if( j == n ) {
            ans++;
            j = lps[j-1];
        } else {
            if( i < m && txt[i] != s[i] ) {
                if( j != 0 ) {
                    j = lps[j-1];
                } else {
                    i++;
                }
            }
        }
    } 
}

void computeLPS() {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while( i < n ) {
        if(s[i] == s[len])  {
            len++;
            lps[i] = len;
            i++;
        } else {
            if( len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}