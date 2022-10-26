#include <map>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// problem 1
int color(string str){
    int cnt = 0;
    int n = str.size();
    vector<int> flag(n, 0);

    for(int i=1; i<n; ++i){
        if(str[i] == str[i-1] && flag[i] == 0 && flag[i-1] == 0){
            flag[i] = 1;
            flag[i-1] = 1;
            cnt += 2;
        }
    }
    return cnt;
}

void problem1(){
    string str;
    cin>>str;
    int res = color(str);
    cout << res << endl;
}


// problem 2
void creatGraph(vector<int>& dis){
    //获取数组大小
    int n = dis.size();
    //按照距离排序存入mp,相同距离节点存入同一个vertor<int>中
    map<int, vector<int>> mp;
    for(int i=1; i<n; ++i){
        if(mp.find(dis[i])!=mp.end()){
            mp[dis[i]].emplace_back(i+1);
        }else{
            mp[dis[i]] = vector<int>{i+1};
        };
    }

    //获取最远距离
    int mx = *max_element(dis.begin(), dis.end());
    //    cout<<"mx:"<<mx<<endl;
    vector<vector<int>> ret;
    int start = 1;
    for(int i=1; i<=mx; i++){
        if(mp.find(i)==mp.end()){ //如果某个距离不存在，则距离不连续，返回-1
            cout<<-1;
            return;
        }
        //否则每次将所有节点连接到上一个距离节点的第一个节点
        int n_vertexs = mp[i].size();
        for(int j=0; j<n_vertexs; j++){
            ret.push_back(vector<int>{start, mp[i][j]});
        }
        start = mp[i][0];
    }

    cout<<ret.size()<<endl;
    for(int i=0; i<ret.size(); ++i){
        cout<<ret[i][0]<<" "<<ret[i][1]<<endl;
    }

}

int main() {
    //problem 1
//    problem1();

    // problem 2
    //输入n
    int n;
    cin>>n;
    // check n
    // cout<<"n:"<<n<<endl;

    //输入距离
    vector<int> dis(n, 0);
    for(int i=0; i<n; ++i){
        cin>>dis[i];
    }
    // check dis
//    for(int i=0; i<n; ++i){
//        cout<<dis[i]<<endl;
//    }
    //调用函数
    creatGraph(dis);
    return 0;
}