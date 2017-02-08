// Names: Tyler Kaufman
//        Brady Snedden
// Class: CS5101
// Assignment 2

#include <string>
#include <iostream>5
#include <iomanip>
#include <cstdlib>
#include <cassert>


using namespace std;
class Model;
class View;
class Controller;

class UnitTest {
public:
    void Unittest (const float& u_firstNumber, const char& u_operator,  const float& u_secondNumber) {
        float result;
        float mult;
        float div;
        float firstNum = u_firstNumber;
        float secondNum = u_secondNumber;

        switch (u_operator) {
            case '+' :
                result = (u_firstNumber + u_secondNumber);
                assert(result == (u_firstNumber + u_secondNumber));
                break;

            case '-' :
                result = (u_firstNumber - u_secondNumber);
                assert(result == (u_firstNumber - u_secondNumber));
                break;

            case '*' :
                result = (firstNum * secondNum);
                mult = (u_firstNumber * u_secondNumber);
                assert(result == mult);
                break;

            case '/' :
                assert(u_secondNumber  != 0);
                result = (u_firstNumber / u_secondNumber);
                div = (firstNum / secondNum);
                assert(result == div);
                break;
        }
    }
};

class Model {

public:
    void calc(const float& firstNumber, const char& Operator, const float& secondNumber)
    {
        m_firstNumber = firstNumber;
        m_operator = Operator;
        m_secondNumber = secondNumber;
        UnitTest test;

        if(m_operator == '+') {
            test.Unittest(m_firstNumber, m_operator, m_secondNumber);
            m_result = ( m_firstNumber + m_secondNumber );
        }
        else if (m_operator == '-') {
            test.Unittest(m_firstNumber, m_operator, m_secondNumber);
            m_result = (m_firstNumber - m_secondNumber);
        }
        else if (m_operator == '*') {
            test.Unittest(m_firstNumber, m_operator, m_secondNumber);
            m_result = (m_firstNumber * m_secondNumber);
        }
        else if (m_operator == '/') {
            if (m_secondNumber == 0) {
                while (m_secondNumber == 0) {
                    float newSecondNumber;
                    cout<<"Can't divide by 0! Enter new 2nd number: ";
                    cin>>newSecondNumber;
                    m_secondNumber = newSecondNumber;
            }
                test.Unittest(m_firstNumber, m_operator, m_secondNumber);
                m_result = (m_firstNumber / m_secondNumber);

            } else {
                test.Unittest(m_firstNumber, m_operator, m_secondNumber);
                m_result = (m_firstNumber / m_secondNumber);
            }
        }
    }
    const float& getData() const
    {
        return m_result;
    }
private:
    float m_firstNumber;
    float m_secondNumber;
    char m_operator;
    float m_result;
};

class View {
public:
    void displayData(const Model& model)
    {
        cout << "Displaying result: " << fixed << setprecision(3) << model.getData() << "!\n" << endl;
    }

};

class Controller {
public:
    void getAndSendUserInput(Model& model)
    {
        float firstNumber, secondNumber;
        char Operator;
        cout << "Enter 1st number: ";
        cin  >> firstNumber;
        do
        {
            cout << "Enter an operator, choosing '+' , '-' , '*' or '/')\n";
            cin  >> Operator;
        } while(!isOperator(Operator));

        cout << endl;
        cout << "Enter 2nd number: ";
        cin  >> secondNumber;
        cout<<endl;
        model.calc(firstNumber, Operator, secondNumber);
    }

    bool isOperator(const char& Operator)
    {
        if(Operator == '+'
           || Operator == '-'
           || Operator == '*'
           || Operator == '/')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main() {
    Model      model;
    View       view;
    Controller controller;

    controller.getAndSendUserInput(model); // send User Input *to* the Model
    view.displayData(model); // Display data *from* the model.

    return 0;
}