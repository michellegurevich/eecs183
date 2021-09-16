/**
 * test.cpp
 *
 * EECS 183, Winter 2016
 * Assignment 4
 *
 * Michelle Gurevich
 * mgur
 *
 * Tests Point.cpp
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "Point.h"

void test_point();

int main() {
    test_point();
}

void test_point() {
    Point pt1;
    
    pt1.setX(15);
    
    cout << "pt1 is: " << pt1 << endl;
    
    ifstream input_file;
    input_file.open("data1.txt");
    pt1.read(input_file);
    cout << "pt1 is: " << pt1 << endl << endl;
    

    // testing new point
    Point pt2;
    
    pt2.setX(-5);
    pt2.setY(40);
    cout << "pt2 is: " << pt2 << endl;
    
    pt2.getX();
    pt2.getY();
    
    pt2.read(input_file);
    cout << "pt2 is: ";
    pt2.write(cout);
    cout << endl << endl;
    
    
    // testing new point
    Point pt3;
    
    pt3.setX(20);
    pt3.setY(101);
    cout << "pt3 is: " << pt3 << endl;
    
    pt3.getX();
    pt3.getY();

    pt3.read(input_file);
    cout << "pt3 is: ";
    pt3.write(cout);
    cout << endl << endl;
    
    
    // testing new point
    Point pt4;
    
    pt4.setX(0);
    pt4.setY(0);
    cout << "pt4 is: " << pt4 << endl;
    
    pt4.getX();
    pt4.getY();
    
    pt4.read(input_file);
    cout << "pt4 is: ";
    pt4.write(cout);
    cout << endl << endl;

    
    // testing new point
    Point pt5;
    
    pt5.setX(100);
    pt5.setY(40);
    cout << "pt5 is: " << pt5 << endl;

    pt5.getX();
    pt5.getY();
    
    pt5.read(input_file);
    cout << "pt5 is: ";
    pt5.write(cout);
    cout << endl << endl;
    
    
    // testing new point
    Point pt6;
    
    pt6.setX(40);
    pt6.setY(40);
    cout << "pt6 is: " << pt6 << endl;
    
    pt6.getX();
    pt6.getY();
    
    pt6.read(input_file);
    cout << "pt6 is: ";
    pt6.write(cout);
    cout << endl << endl;
    
    
    // testing new point
    Point pt7;
    
    cout << "pt7 is: " << pt7 << endl;
    
    pt7.getX();
    pt7.getY();
    
    pt7.read(input_file);
    cout << "pt7 is: ";
    pt7.write(cout);
    cout << endl << endl;
    
    
    // testing new point
    Point pt8;
    
    pt8.setX(101);
    pt8.setY(20);
    cout << "pt8 is: " << pt8 << endl;
    
    pt8.getX();
    pt8.getY();
    
    pt8.read(input_file);
    cout << "pt8 is: ";
    pt8.write(cout);
    cout << endl << endl;
    
    
    // testing non default
    Point pt9(-50,100);
    pt9.getX();
    pt9.getY();
    pt9.read(input_file);
    cout << "pt9 is: ";
    pt9.write(cout);
    cout << endl;
    
    Point pt10(100,-50);
    pt10.getX();
    pt10.getY();
    pt10.read(input_file);
    cout << "pt10 is: ";
    pt10.write(cout);
    cout << endl;
    
    Point pt11(101,101);
    pt11.getX();
    pt11.getY();
    pt11.read(input_file);
    cout << "pt11 is: ";
    pt11.write(cout);
    cout << endl;
    
    Point pt12(20,40);
    pt12.getX();
    pt12.getY();
    pt12.read(input_file);
    cout << "pt12 is: ";
    pt12.write(cout);
    cout << endl;
    
    
    // testing new point
    Point pt14;
    
    pt14.setX(240);
    pt14.setY(-5);
    cout << "pt14 is: " << pt14 << endl;
    
    pt14.getX();
    pt14.getY();
    
    pt14.read(input_file);
    cout << "pt14 is: ";
    pt14.write(cout);
    cout << endl << endl;
}
