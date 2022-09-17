#include<bits/stdc++.h>
using namespace std;

// 选择题11
class A{
    int a1;
public:
    A():a1(0){
    }
    void f(){
        cout<<a1<<" ";
    }
};

class B:public A{
    int b1;
public:
    B():b1(1){
    }
    void g(){
        f();
        cout<<b1<<" ";
    }
};

class C:public B{
    int c1;
public:
    C():c1(2){  //___________
    }
    void h(){
        g();
        cout<<c1;
    }
};

void run_choice11(){
    C ob1;
    ob1.h();
}


// 选择题15
class D{
    int a;
    static int b;
public:
    D(){
        a=0;
        b++;
    }
    void f2(){
        cout<<a<<" "<<b;
    }
};
int D::b=0;
void run_choice15(){
    D o1;
    o1.f2();
}

// 选择题25
class E{
    int a1;
public:
    E():a1(0){}
    void f(){cout<<a1<<" ";}
};
class F:public E{
    int b1;
public:
    F():b1(1){}
    void f(){
        E::f();
        cout<<b1<<" ";
    }
};
void run_choice25(){
    F ob1;
    E *p = & ob1;
    p->f();
}

// 选择题26
class G{
    void f1(){};
public:
    static void f2(){};
    friend void f3(){};
};
void f4(){};

//coding problem 1---笔试的时候写的,思路是有问题的
int maxGameNum(vector<int>& a, vector<int>& b, int t){
    int n=a.size(), m = b.size();
    int i=0, j=0;
    int cnt = 0;
    int time = t;
    while((i<n || j<m) && time > 0){
        if(i==n){
            if(time >= b[j]){
                time -= b[j];
                cnt++;
                j++;
            }else{
                break;
            }
        }else if(j==m){
            if(time >= a[i]){
                time -= a[i];
                cnt++;
                i++;
            }else{
                break;
            }
        }else{
            if(a[i]<=b[j]){
                if(time>=a[i]){
                    time -= a[i];
                    cnt++;
                    i++;
                }else {
                    break;
                }
            }else{
                if(time>=b[j]){
                    time -= b[j];
                    cnt++;
                    j++;
                }else {
                    break;
                }
            }
        }
    }
    return cnt;
}
//这个方法貌似是可以的
int maxGameNum2(vector<int>& a, vector<int>& b, int t) {
    int n=a.size(), m = b.size();
    int cnt = -1;
    for(int i=0; i<n; ++i){
        int temp = accumulate(a.begin(), a.begin()+i+1,0);
        if(temp>t) {
            break;
        }
        int j=0;
        for(; j<m; ++j){
            temp += b[j];
            if(temp>t){
                cnt = i+1+j>cnt ? i+j+1 : cnt;
                break;
            }
        }
        if(j==m){
            cnt = i+1+m>cnt ? i+1+m : cnt;
        }
    }
    return cnt;
}

void run_coding1(){
    //coding problem 1
    int n, m, t;
    cin>>n>>m>>t;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0; i<n; ++i){
        cin>>a[i];
    }
    for(int i=0; i<m; ++i){
        cin>>b[i];
    }
    int ret = maxGameNum2(a, b, t);
    cout<<ret<<endl;

}

//coding problem2
void run_coding2(){
    int n, m;
    cin>>n>>m;
    vector<int> nums(n);
    for(int i=0; i<n; ++i){
        cin>>nums[i];
    }
    stack<pair<int, int>> q, q2;
    int t, k;
    for(int i=0; i<m; ++i){
        cin>>t>>k;
        while(!q.empty() && q.top().second<k){
            q.pop();
        }
        q.push({t, k});
    }
    while(!q.empty()){
        q2.push(q.top());
        q.pop();
    }

    while(!q2.empty()){
        auto temp = q2.top();
        if(temp.first == 1){
            sort(nums.begin(), nums.begin()+temp.second);
        }else{
            sort(nums.begin(), nums.begin()+temp.second, [](int& a, int& b){return a>b;} );
        }
        q2.pop();
    }
    for(int i=0; i<n; ++i){
        cout<<nums[i]<<" ";
    }
    return;
}


int main(){
//    run_choice25();
//    run_coding1();
    run_coding2();

    return 0;
}