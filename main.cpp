#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <array>
using namespace std;

// ("",  '.') -> [""]
// ("11", '.') -> ["11"]
// ("..", '.') -> ["", "", ""]
// ("11.", '.') -> ["11", ""]
// (".11", '.') -> ["", "11"]
// ("11.22", '.') -> ["11", "22"]
std::vector<std::string> split(const std::string& str, char d)
{
    std::vector<std::string> r;

    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while (stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));

        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));

    return r;
}
bool myfun(vector<int> a, vector<int> b) {
    if (a[0] > b[0]) {
        return true;
    }
    else if (a[0] < b[0]) return false;
    else {
        if (a[1] > b[1]) return true;
        else if (a[1] < b[1]) return false;
        else {
            if (a[2] > b[2]) return true;
            else if (a[2] < b[2]) return false;
            else {
                if (a[3] > b[3]) return true;
                else if (a[3] < b[3]) return false;
                else return false;
            }
        }
    }

}
int main()
{
    try
    {
        std::vector<std::vector<int> > ip_pool;
        vector<string> tmp_vec;
        vector<int> tmp_int;
        int c= 0 ;
        for (std::string line; std::getline(std::cin, line);)
        {
           
            std::vector<std::string> v = split(line, '\t');
            tmp_vec = (split(v.at(0), '.'));

            for (int i = 0; i < 4; i++)
            {
                tmp_int.push_back(stoi(tmp_vec[i]));
            }
            
            ip_pool.push_back(tmp_int);
            tmp_int.clear();
        }
       sort(ip_pool.begin(), ip_pool.end(), myfun);
       for (int i = 0; i < ip_pool.size(); i++)
       {
           for (int j = 0; j < 4; j++)
           {
               if (j == 3) cout << ip_pool[i][j];
               else cout << ip_pool[i][j] << ".";
               
           }cout << endl;
       }
       cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
       for (int i = 0; i < ip_pool.size(); i++)
       {
           bool b = false;
           for (int j = 0; j < 4; j++)
           {
               if (ip_pool[i][0] == 1) {
                   b = true;
                   if (j == 3) cout << ip_pool[i][j];
                   else cout << ip_pool[i][j] << ".";
               }

           }if(b) cout << endl;
       }
       cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
       for (int i = 0; i < ip_pool.size(); i++)
       {
           bool b = false;
           for (int j = 0; j < 4; j++)
           {
               if (ip_pool[i][0] == 46 and ip_pool[i][1]== 70) {
                   b = true;
                   if (j == 3) cout << ip_pool[i][j];
                   else cout << ip_pool[i][j] << ".";
               }

           }if(b) cout << endl;
       }
       cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\n";
       for (int i = 0; i < ip_pool.size(); i++)
       {
           bool b = false;
           for (int k = 0; k < 4; k++)
           {
               if (ip_pool[i][k] == 46) {
                   for (int j = 0; j < 4; j++)
                   {
                       b = true;
                       if (j == 3) cout << ip_pool[i][j];
                       else cout << ip_pool[i][j] << ".";

                   }if(b)cout << endl;
               }
           }
         
       }
       
          // 222.173.235.246
          // 222.130.177.64
          // 222.82.198.61
          // ...
          // 1.70.44.170
          // 1.29.168.152
          // 1.1.234.8

          // TODO filter by first byte and output
          // ip = filter(1)

          // 1.231.69.33
          // 1.87.203.225
          // 1.70.44.170
          // 1.29.168.152
          // 1.1.234.8

          // TODO filter by first and second bytes and output
          // ip = filter(46, 70)

          // 46.70.225.39
          // 46.70.147.26
          // 46.70.113.73
          // 46.70.29.76

          // TODO filter by any byte and output
          // ip = filter_any(46)

          // 186.204.34.46
          // 186.46.222.194
          // 185.46.87.231
          // 185.46.86.132
          // 185.46.86.131
          // 185.46.86.131
          // 185.46.86.22
          // 185.46.85.204
          // 185.46.85.78
          // 68.46.218.208
          // 46.251.197.23
          // 46.223.254.56
          // 46.223.254.56
          // 46.182.19.219
          // 46.161.63.66
          // 46.161.61.51
          // 46.161.60.92
          // 46.161.60.35
          // 46.161.58.202
          // 46.161.56.241
          // 46.161.56.203
          // 46.161.56.174
          // 46.161.56.106
          // 46.161.56.106
          // 46.101.163.119
          // 46.101.127.145
          // 46.70.225.39
          // 46.70.147.26
          // 46.70.113.73
          // 46.70.29.76
          // 46.55.46.98
          // 46.49.43.85
          // 39.46.86.85
          // 5.189.203.46
            }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
            return 0;
    }
