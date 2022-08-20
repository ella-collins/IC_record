//
// Created by Jiahua Chen on 2022/8/20.
//
#include<bits/stdc++.h>
using namespace std;

string barbeque(int n, string meats, string vegts){
    string bbq;
    for(int i=0; i<n; ++i){
        string temp1(meats.begin()+i, meats.begin()+i+1);
        bbq.append(temp1);
        temp1.clear();
        string temp2(vegts.begin()+i, vegts.begin()+i+1);
        bbq.append(temp2);
    }
    return bbq;
}

float maxGain(int m, vector<int>& probs, vector<int>& scores){
    vector<float> gains(probs.size());
    float ret = 0.0;
    for(int i=0; i<probs.size(); ++i){
        gains[i] = (100.0-probs[i])/100*scores[i];
        ret += probs[i]/100.0*scores[i];
    }

    sort(gains.begin(), gains.end());

    for(int i=0; i<probs.size(); ++i){
        cout<<gains[i]<<" ";
    }
    for(int i=gains.size()-1; i>gains.size()-1-m; --i){
        ret += gains[i];
    }
    return ret;
}


int main(){
    //p1
//    int n;
//    cin>>n;
//    string meats, vegts;
//    cin>>meats;
//    cin>>vegts;
//    string res(barbeque(n, meats, vegts));
//    cout<<barbeque(n, meats, vegts)<<endl;

    //p2
    int n,m;
    cin>>n>>m;
    vector<int> probs(n), scores(n);
    int i = 0;
    for(int i=0; i<n; ++i){
        cin>>probs[i];
    }

    for(int i=0; i<n; ++i){
        cin>>scores[i];
    }

    cout<<maxGain(m, probs, scores)<<endl;

}