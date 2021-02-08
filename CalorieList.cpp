//==============================================
// Name:          Majd Homsi
// Date:          2021-02-05
// Student Number: 113692206
// Email:          mhomsi1@myseneca.ca
// Section:        NAA
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "CalorieList.h"

using namespace std;

namespace sdds 
{

    int CalorieList::totalCalorie() const //adding everything that requires a price meanwhile returning the sum of them as well
    {
        int sum = 0;
        for (int i = 0; i < m_noOfItems; i++)
        {
            sum += m_items[i].calorie();
        }

        return sum;
    }
    
    void CalorieList::Title() const  
    {
        cout << "+----------------------------------------------------+" << endl;
        if (isValid())
        {
            cout << "|  Daily Calorie Consumption                         |" << endl;
        }
        else
        {
            cout << "| Invalid Calorie Consumption list                   |" << endl;
        }
        cout << "+--------------------------------+------+------------+" << endl;
        cout << "| Food name                      | Cals | When       |" << endl;
        cout << "+--------------------------------+------+------------+" << endl;
    }

    void CalorieList::footer() const
    {
        cout << "+--------------------------------+------+------------+" << endl;
        if (isValid())
        {
            cout << "|    Total Calories for today:";
            cout.width(9);
            cout << right << totalCalorie();
            cout << " | ";

            cout.width(12);
            cout << setfill(' ');
            cout << " |" << endl;

        }
        else
        {
            cout << "|    Invalid Calorie Consumption list                |" << endl;
        }
        cout << "+----------------------------------------------------+" << endl;
    }

    void CalorieList::setEmpty()
    {
        m_items = nullptr;
    }

    bool CalorieList::isValid() const
    {
        bool state = true; // set state to true, 
        int i;
        state = m_items != nullptr;
        for (i = 0; state == true && i < m_noOfItems; i++)
        {
            state = state && m_items[i].isValid(); 
        }

        return state;
    }

    void CalorieList::init(int size)
    {
        if (size < 1)
        {
            m_noOfItems = 0;
            m_itemsAdded = 0;
        }
        else
        {
            m_noOfItems = size;
            m_itemsAdded = 0;
            m_items = new Food[m_noOfItems];
            for (int i = 0; i < m_noOfItems; i++)
                m_items[i].setEmpty();
        }

    }

    bool CalorieList::add(const char* item_name, int calories, int when)
    {
        if (m_itemsAdded < m_noOfItems)
        {
            m_items[m_itemsAdded].set(item_name, calories, when);
            m_itemsAdded++;
            return true;
        }
        return false;
    }

    void CalorieList::display() const
    {
        Title();
        for (int i = 0; i < m_noOfItems; i++)
        {
            m_items[i].display();
        }
        footer();
    }

    
    void CalorieList::deallocate() // dellocate m_items and set * to NULL
    {
        delete[] m_items;  
    }
}