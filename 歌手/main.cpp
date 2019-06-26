//
//  main.cpp
//  歌手
//
//  Created by s20181105880 on 2019/6/19.
//  Copyright © 2019 。. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
struct Referee{
    string name;
    double grade[6];
} referee[7];
struct Student{
    string Number;
    string name;
    string college;
    string sex;
    double grades[7];
    double sum=0;
}student[6];

int main()
{
    int i=0;
    ifstream Refereein("E:\裁判.txt");
    ifstream Studentin("E:\参赛者.txt");
    ofstream allout("E:\输出.xls");
    if(Refereein.is_open())//裁判输入
    {
        while(!Refereein.eof() && i<7)
        {
            Refereein>>referee[i].name>>referee[i].grade[0]>>referee[i].grade[1]>>referee[i].grade[2]>>referee[i].grade[3]>>referee[i].grade[4]>>referee[i].grade[5];
            i++;
        }
        Refereein.close();
    }
    if (Studentin.is_open())//参赛者输入
    {
       
        Studentin.close();
    }     return 0;
}
