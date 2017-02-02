#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cassert>

using namespace std;

class Model {
  public:
    void receiveInput(const float& firstNumber, const char& Operator, const float& secondNumber)
    {
        m_firstNumber = firstNumber;
        m_operator = Operator;
        m_secondNumber = secondNumber;

        if(m_operator == '+') {
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
        cout << "Enter 1st number: ";
        cin  >> firstNumber;//input;
        char Operator;
        cout << "Enter an operator, choosing '+' , '-' , '*' or '/')\n";
        cin  >> Operator;
        cout << "Enter 2nd number: ";
        cin  >> secondNumber;
        model.receiveInput(firstNumber, Operator, secondNumber);
    }
};
#define USE_MODEL_VIEW_CONTROLLER
int main() {
    Model      model;
    View       view;
    Controller controller;
    float expectedValPlusOperator = 20; //  16 + 4
    float actualVal;

    controller.getAndSendUserInput(model); // send User Input *to* the Model
    actualVal = model.getData();
    assert( actualVal == expectedValPlusOperator );
    view.displayData(model); // Display data *from* the model.

    return 0;
}