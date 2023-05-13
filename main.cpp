#include <bits/stdc++.h>
using namespace std;

vector<string> split_string(string);

// Complete the flatlandSpaceStations function below.
int flatlandSpaceStations(int n, vector<int> c) {

    sort(c.begin(),c.end());
    int c_size = c.size();

    vector<bool> SpStPos;
    SpStPos.resize(n,false);
    for(int i=0; i<c_size; i++) SpStPos[c[i]] = true;
    for(int i=0; i<n; i++) cout << SpStPos[i];
    cout << endl;

    int tmp_dist = 0;
    int max_dist = 0;


    if(c_size>1)
    {
        for(int i=0; i<c_size; i++)
        {
        if(i==0)
        {
            cout << "Poczatek | ";
            tmp_dist = c[i];                            // To Left
            cout << tmp_dist << " ";                    //
            if(tmp_dist>max_dist) max_dist = tmp_dist;  //


            tmp_dist = c[i+1] - c[i] - 1;               // To Right
            cout << "t: " << tmp_dist << " ";           //
            if(tmp_dist%2) tmp_dist++ ;                 //
            tmp_dist /=2;                               //
            cout << tmp_dist << " " << endl;            //
            if(tmp_dist>max_dist) max_dist = tmp_dist;  //
        }
        else if(i==c_size-1)
        {
            cout << "koniec   | ";
            tmp_dist = c[i] - c[i-1]-1;                 // To Left
            cout << "t: " << tmp_dist << " ";           //
            if(tmp_dist%2) tmp_dist-- ;
            tmp_dist /=2;                              //
            cout << tmp_dist << " " ;                   //
            if(tmp_dist>max_dist) max_dist = tmp_dist;  //

            tmp_dist = n - c[i] - 1;                    // To Right
            cout << tmp_dist << " " << endl;            //
            if(tmp_dist>max_dist) max_dist = tmp_dist;  //


        }
        else
        {
            cout << "srodek   | ";
            tmp_dist = c[i] - c[i-1]-1;                 // To Left
            cout << "t: " << tmp_dist << " ";           //
            if(tmp_dist%2) tmp_dist++ ;                 //
            tmp_dist /=2;                               //
            cout << tmp_dist << " ";            //
            if(tmp_dist>max_dist) max_dist = tmp_dist;  //

            tmp_dist = c[i+1] - c[i] - 1;
            cout << "t: " << tmp_dist << " ";           //
            if(tmp_dist%2) tmp_dist-- ;
            tmp_dist /=2;
            cout << tmp_dist << " " << endl;
            if(tmp_dist>max_dist) max_dist = tmp_dist;      //
        }
        }
    }
    else
    {
        if(c[0] == 0)
        {
            max_dist = n - 1;
        }
        else if(c[0] == n-1 )
        {
            max_dist = n - 1;
        }
        else
        {
            max_dist = c[0];
            tmp_dist = n-c[0] - 1;
            if(tmp_dist>max_dist) max_dist = tmp_dist;
        }
    }
    return max_dist;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(m);

    for (int i = 0; i < m; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = flatlandSpaceStations(n, c);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
