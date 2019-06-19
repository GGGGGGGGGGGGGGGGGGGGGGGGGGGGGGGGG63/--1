//
//  main.cpp
//  歌手
//
//  Created by s20181105880 on 2019/6/19.
//  Copyright © 2019 。. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main() {
    int a,b;
    ofstream gg("/Users/s20181105880/Desktop/歌手.txt");
    ifstream GG("/Users/s20181105880/Desktop/歌手的副本.txt");
    if(GG.is_open())
    {
        cout<<"file is ok"<<endl;
        GG>>a>>b;
        cout<<a<<"   "<<b<<endl;
        GG.close();
    }
    if (gg.is_open())
    {
        gg << "c="<<a+b<<endl;
        cout<<"c="<<a+b<<endl;
        gg.close();
    }
    
    return 0;
}
