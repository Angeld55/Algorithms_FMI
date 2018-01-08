package com.company;

import com.sun.deploy.panel.AbstractRadioPropertyGroup;
import com.sun.org.apache.bcel.internal.generic.RET;
import com.sun.xml.internal.bind.v2.runtime.output.SAXOutput;

import javax.swing.*;
import java.util.ArrayList;


public class Main
{

    public static void main(String[] args)
    {
        int[] arr = new int[44];
        Student[] students = new Student[5];
        students[0]=new Student("Angel","D",2);
        students[1]=new Student("Viktor","j",3);
        students[2]=new Student ("Jasmina","I",1);
        students[3]=new Student("Nikola","K",-1);
        students[4]=new Student("Georgi","P",6);

        BubbleSort(students);

        for (int i = 0; i < students.length; i++) {
            System.out.println(students[i].firstName);
        }
    }
    public static  void swap(Student[] arr,int i,int j)
    {
        Student temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    public static void BubbleSort(Student[] arr)
    {
        int lastSwap = arr.length-1;
        for (int j = 0; j < arr.length; j++) {
            boolean isSwapped = false;
            int lastSwapTemp=lastSwap;
            for (int i = 0; i < lastSwap; i++) {
                if(arr[i].grade>arr[i+1].grade)
                {
                    swap(arr,i,i+1);
                    lastSwap=i+1;
                    isSwapped=true;
                }
            }
            if(!isSwapped)
                return;
        }

    }

}

class Human
{
    String firstName;
    String familyName;
    Human(String firstName, String familyName)
    {
        this.firstName=firstName;
        this.familyName=familyName;
    }
}
class Student extends  Human
{
    int grade;
    Student(String firstName,String familyName,int grade)
    {
        super(firstName,familyName);
        this.grade=grade;
    }
}
class Worker extends Human
{
    int wage;
    int hoursWorked;
    Worker(String firstName,String familyName,int wage,int hoursWorked)
    {
        super(firstName,familyName);
        this.wage=wage;
        this.hoursWorked=hoursWorked;
    }
    double SalaryPerHour()
    {
        return wage/hoursWorked;
    }

}
