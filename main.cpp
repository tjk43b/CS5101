#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

class Model {
  public:
    void receiveInput(const float& firstNumber, const char& operator, const float& secondNumber)
    {
        m_firstNumber = firstNumber;
        m_operator = operator;
        m_secondNumber = secondNumber;

        if(m_operator == '+') {
            m_result = ( m_firstNumber + m_secondNumber );
        }
        else if(m_operator == '-') {
            m_result = ( m_firstNumber - m_secondNumber );
        }
        else if(m_operator == '*') {
            m_result = ( m_firstNumber * m_secondNumber );
        }
        else if(m_operator == '/') {
            m_result = ( m_firstNumber / m_secondNumber );
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
        char operator;
        cout << "\nEnter an operator, choosing between '+' , '-' , '*' or '/')";
        cin  >> operator;
        cout << "\nEnter 2nd number: ";
        cin  >> secondNumber;
        model.receiveInput(firstNumber, operator, secondNumber);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}