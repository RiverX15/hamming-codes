#include<iostream>
#include<vector>
#include<math.h>
#include<bitset>

using namespace std;

bool isInteger(double val) {
    int truncated=(int)val;
    return (val==truncated);
}

void inputVector(vector<int>& v, int n) {
    for (int i=0; i<n; ++i) {
        int val;
        cin >> val;
        v.push_back(val);
    }
}

void printVector(vector<int>& v) {
    for (int i=0; i<v.size(); ++i) {
        cout << v[i] << " ";
    }
}

void createSquareMatrix(vector<int>& v, vector<vector<int>>& m) {
    int n=sqrt(v.size());
    int k=0;
    for (int i=0; i<n; ++i) {
        vector<int> temp;
        for (int j=0; j<n; ++j) {
            temp.push_back(v[k]);
            ++k;
        }
        m.push_back(temp);
    }
}

void createVector(vector<vector<int>>& m, vector<int>& v) {
    for (int i=0; i<m.size(); ++i) {
        for (int j=0; j<m[i].size(); ++j) {
            v.push_back(m[i][j]);
        }
    }
}

void printSquareMatrix(vector<vector<int>>& m) {
    for (int i=0; i<m.size(); ++i) {
        for (int j=0; j<m[i].size(); ++j) {
            cout << m[i][j] << "\t";
        }
        cout << endl;
    }
}

void addParityBits(vector<int>& msg, vector<int>& msg_par) {
    int j=0;
    msg_par.push_back(-1);
    for (int i=1; i<16; ++i) {
        if (!isInteger(log2(i))) {
            msg_par.push_back(msg[j]);
            ++j;
        }
        else {
            msg_par.push_back(-1);
        }
    }
    vector<vector<int>> msg_par_m;
    createSquareMatrix(msg_par, msg_par_m);
    msg_par.clear();
    int count_1=0;
    for (int i=0; i<4; ++i) {
        for (int j=1; j<4; j+=2) {
            if (msg_par_m[i][j]==1) {
                ++count_1;
            }
        }
    }
    msg_par_m[0][1]=count_1%2;
    count_1=0;
    for (int i=0; i<4; ++i) {
        for (int j=2; j<4; ++j) {
            if (msg_par_m[i][j]==1) {
                ++count_1;
            }
        }
    }
    msg_par_m[0][2]=count_1%2;
    count_1=0;
    for (int i=1; i<4; i+=2) {
        for (int j=0; j<4; ++j) {
            if (msg_par_m[i][j]==1) {
                ++count_1;
            }
        }
    }
    msg_par_m[1][0]=count_1%2;
    count_1=0;
    for (int i=2; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            if (msg_par_m[i][j]==1) {
                ++count_1;
            }
        }
    }
    msg_par_m[2][0]=count_1%2;
    count_1=0;
    for (int i=0; i<4; ++i) {
        for (int j=0; j<4; ++j) {
            if (msg_par_m[i][j]==1) {
                ++count_1;
            }
        }
    }
    msg_par_m[0][0]=count_1%2;
    createVector(msg_par_m, msg_par);
}

int main() {
    vector<int> msg, rcvd, msg_par;
    cout << "Enter the 11 (space separated) data bits originally sent out by the sender:" << endl;
    inputVector(msg, 11);
    cout << endl;
    vector<vector<int>> msg_par_m;
    addParityBits(msg, msg_par);
    createSquareMatrix(msg_par, msg_par_m);
    cout << "The message you wish to transmit with the parity bits added is:" << endl;
    printVector(msg_par);
    cout << endl << endl;
    cout << "The message in the form of a matrix is:" << endl;
    printSquareMatrix(msg_par_m);
    cout << endl << endl;
    cout << "Enter the 16 (space separated) message bits actually received by the receiver:" << endl;
    inputVector(rcvd, 16);
    cout << endl;
    int err=0, count_1=0;
    for (int i=0; i<16; ++i) {
        if (rcvd[i]==1) {
            err^=i;
        }
    }
    for (int i=1; i<16; ++i) {
        if (rcvd[i]==1) {
            ++count_1;
        }
    }
    if (err==0) {
        cout << "No error. Message looks clean." << endl;
    }
    else {
        if ((count_1%2==0 && rcvd[0]==1) || (count_1%2!=0 && rcvd[0]==0)) {
            cout << "1 bit flip detected at position " << err+1 << "." << endl;
            rcvd[err]=1-rcvd[err];
            cout << "The correct message is:" << endl;
            printVector(rcvd);
            cout << endl << endl << "The message in the form of matrix is:" << endl;
            vector<vector<int>> rcvd_m;
            createSquareMatrix(rcvd, rcvd_m);
            printSquareMatrix(rcvd_m);
        }
        else {
            cout << "2 bit flips detected." << endl;
        }
    }
    return 0;
}