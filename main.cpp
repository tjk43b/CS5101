#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>
// #include "unitTest.cpp"

using namespace std;
class UnitTest {
public:
    void Unittest (const float& u_firstNumber, const char& u_operator,  float u_secondNumber) {
        float result;
        //currently switch statement for future unit test implementation
        switch (u_operator) {
            case '+' :
                result = (u_firstNumber + u_secondNumber);
                assert(result == (u_firstNumber + u_secondNumber));
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
        else
        {
            cout << "Invalid Input!" << endl;
            exit(0);
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

//#define USE_MODEL_VIEW_CONTROLLER
int main() {
    Model      model;
    View       view;
    Controller controller;

    controller.getAndSendUserInput(model); // send User Input *to* the Model
    view.displayData(model); // Display data *from* the model.

    return 0;
}