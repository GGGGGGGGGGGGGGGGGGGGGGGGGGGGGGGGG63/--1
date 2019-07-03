//
//  main.cpp
//  歌手
//
//  Created by s20181105880 on 2019/6/19.
//  Copyright © 2019 。. All rights reserved.
#define STUDENTNUMBER 6
#define REFEREENUMBER 7
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
struct Referee{
    string name;
    double grade[STUDENTNUMBER];
}referee[REFEREENUMBER];
struct Student{
    string Number;
    string name;
    string college;
    string sex;
    double grades[REFEREENUMBER];
    double sum=0;
}student[STUDENTNUMBER];
bool judge(Student &object1,Student &object2)
{
    if(object1.sum>object2.sum)
        return true;
    else
        return false;
}
int main()
{   int i=0;
    ifstream Refereein("/Users/s20181105880/Desktop/裁判.txt");
    ifstream Studentin("/Users/s20181105880/Desktop/参赛者.txt");
    ofstream allout   ("/Users/s20181105880/Desktop/输出.xls");
    if(Refereein.is_open())//裁判输入
    {
        while(!Refereein.eof() && i<REFEREENUMBER)
        {
            Refereein>>referee[i].name;
            for(int k=0;k<STUDENTNUMBER;k++)
            {
                Refereein>>referee[i].grade[k];
            }
            i++;
            /*Refereein>>referee[i].grade[0];
            Refereein>>referee[i].grade[1];
            Refereein>>referee[i].grade[2];
            Refereein>>referee[i].grade[3];
            Refereein>>referee[i].grade[4];
            Refereein>>referee[i].grade[5];
            i++;*/
        }
        Refereein.close();
    }
    i=0;
    if (Studentin.is_open())//参赛者输入
    {
        while(!Studentin.eof() && i<STUDENTNUMBER)
        {
            Studentin>>student[i].Number;
            Studentin>>student[i].name;
            Studentin>>student[i].sex;
            Studentin>>student[i].college;
            i++;
        }
        Studentin.close();
    }
    for(int i=0;i<STUDENTNUMBER;i++)
    {
        for(int j=0;j<REFEREENUMBER;j++)
            student[i].grades[j]=referee[j].grade[i];
        double midnumber=0;
        for(int k=0;k<REFEREENUMBER-1;k++)
        {
            for(int j=0;j<REFEREENUMBER-1;j++)
            {
                if(student[i].grades[j]>student[i].grades[j+1])
                {
                    midnumber=student[i].grades[j];
                    student[i].grades[j]=student[i].grades[j+1];
                    student[i].grades[j+1]=midnumber;
                }
            }
        }
        for(int k=1;k<STUDENTNUMBER;k++)
            student[i].sum+=student[i].grades[k];
            student[i].sum=student[i].sum/(REFEREENUMBER-2);
    }
    sort(student,student+STUDENTNUMBER,judge);
    for(int i=0;i<STUDENTNUMBER;i++)
    {
        allout<<student[i].Number;
        allout<<" "<<student[i].name;
        allout<<" "<<student[i].sex;
        allout<<" "<<student[i].college;
        allout<<" "<<student[i].sum;
        allout<<endl;
    }
    for(int i=0;i<STUDENTNUMBER;i++)
    {
        cout<<student[i].Number;
        cout<<" "<<student[i].name;
        cout<<" "<<student[i].sex;
        cout<<" "<<student[i].college;
        cout<<" "<<student[i].sum;
        cout<<endl;
    }
    return 0;
}
