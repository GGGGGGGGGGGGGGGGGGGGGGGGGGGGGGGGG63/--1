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
{   int i;
    ifstream Refereein("/Users/s20181105880/Desktop/裁判.txt");
    ifstream Studentin("/Users/s20181105880/Desktop/参赛者.txt");
    ofstream allout("/Users/s20181105880/Desktop/输出.xls");
    if(Refereein.is_open())//裁判输入
    {
        while(!Refereein.eof() && i<7)
        {
        Refereein>>referee[i].name>>referee[i].grade[0]>>referee[i].grade[1]>>referee[i].grade[2]>>referee[i].grade[3]>>referee[i].grade[4]>>referee[i].grade[5];
            i++;
        }
        Refereein.close();
    }
    i=0;
    if (Studentin.is_open())//参赛者输入
    {
        while(!Studentin.eof() && i<6)
        {
         Studentin>>student[i].Number>>student[i].name>>student[i].sex>>student[i].college;
             i++;
        }
        Studentin.close();
    }
    for(int i=0;i<6;i++)
    {
        for(int j=0;j<7;j++)
        {
            student[i].grades[j]=referee[j].grade[i];
        }
        
        sort(student[i].grades,student[i].grades+7);
        
        for(int k=1;k<6;k++)
        {
            student[i].sum+=student[i].grades[k];
        }
        student[i].sum=student[i].sum/5;
    }

    
    return 0;
}
