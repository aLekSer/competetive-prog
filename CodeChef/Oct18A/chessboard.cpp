    #include <iostream>
    #include <vector>
    using namespace std;

    //Command to add debuging symbols for VS Code
    // g++ -g -o ./a.out ./SHKSTR.cpp

    typedef long long ll;int X[] = {0, -1, 0, 1};
int Y[] = {1, 0, -1, 0};

bool validateConfiguration(vector<vector<char>>  &v, int l, int p) 
{
  bool isValid = true;
  for (int i = l; i < v.size(); i++)
  {
    for (int j = p; j < v[0].size(); j++)
    {
      for (int k = 0; k < 4; k++)
      {
         int newX = i + X[k];
         int newY = j + Y[k];
         if ( (newX < v.size()) && newY >= 0 &&
             newY >= 0 && v[newX][newY] == v[i][j])
         {
              isValid = false;
         } 
       }
     }
  }
  return isValid;
}

int countNotValid(vector<vector<char>> &v, int l , int p, int size ) {
  int count= 0;
  if (l +size > v.size() || p + size > v[0].size()) {
      return -1;
  }
  for (int i = l; i < l +size; i++)
  {
    for (int j = p; j < p +size; j++)
    {
        int sumIdx = (i + j);
        if (( sumIdx % 2) == v[i][j])
            count++;
    }
  }
  return min(count, size * size - count);
}
// We can check if this is  a valid chessboard by checking the position of every [i][j] element if (i+j) %2 == v[i][j] it is fine, otherwise s++
// How can we use the dynamic approach to move size by one each time?

    int maxS(vector<vector<char>>  &v, vector<int> & d, int n, int m, vector<int> & res) { 
        res = vector<int>(d.size());
        vector<vector<char>> v2 (n, vector<char>(m, 0));
        bool skip = false;
        for (int l = 0 ; l < d.size(); l++)
        {
            skip = false;
            for (int t = min(v.size(), v[0].size()); t > 0; t--)
            {
                cerr << "Iter " << t;
                for (int i = 0 ; i < n; i++)
                {
                    for (int j = 0 ; j < m; j++)
                    {
                            int ret = countNotValid(v, i, j, t) ;
                            if (ret != -1 && ret <= d[l] )
                            {
                                skip = true;
                                res[l] = t;
                                break;
                            }
                    }
                    if (skip)
                        break;
                }
                if (skip)
                    break;
            }
        }
        return 0;

    }
    int main() {
        // your code goes here
        int n, m;
        cin >> n >> m;
        vector<vector<char>> v (n, vector<char>(m, 0));
        for (int i = 0 ; i < n; i++)
        {
            for (int j = 0 ; j < m; j++)
            {
                char c;
                cin >> c;
                v[i][j] = c == '0' ? 0 : 1;
            }
        }
        int q;
        cin>>q;
        vector<int> d(q);
        for (int i = 0 ; i < q; i++)
        {
            cin >> d[i] ;
        }
        vector<int> res = vector<int>(d.size());
         maxS(v, d, n, m, res);
        for (int i = 0 ; i < q; i++)
        {
            cout << res[i] << endl ;
        }

        return 0;
    }