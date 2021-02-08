//==============================================
// Name:          Majd Homsi
// Date:          2021-02-05
// Student Number: 113692206
// Email:          mhomsi1@myseneca.ca
// Section:        NAA
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
//==============================================

#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds 
{
    
    class Food 
    {
        char m_foodName[31]; 
        int m_calNo;
        int m_consumeTime;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* item_name, int calories, int when);
        void display()const;
        bool isValid()const;
        int calorie()const;
    };
}

#endif // !SDDS_SUBJECT_H
