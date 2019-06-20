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
        int i;
        int a[7];
        cout<<"file is ok"<<endl;
        for(i=0;i<7;i++)
        {
            GG>>a[i];
        }
        for(i=0;i<7;i++)
        {
            cout<<a[i]<<endl;
        }
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
