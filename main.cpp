#include <iostream>
#include <string>

using namespace std;

class activity {
      public:
      string virtual type()= 0;
};

class typeFun: public activity {
    public:
      string type() {
        return "I am having fun";
      }
};

class typeNoFun: public activity {
  public:
    string type(){
      return "I am not having fun, please help";
    }
};

class person {
  private:
    int number;
    string name;
    static int counter;

  protected:
        activity * activitytype;
  public:
    person() {
      this-> number = counter++;
      this -> name = string("generic person #") + to_string(this -> number);
      this->activitytype = new typeFun();
    }
    void foo(){
        cout << "I'm " + this-> name << endl;
        cout << this-> display() << endl;
        cout << this->activitytype->type() << endl;
    }

    string virtual display() = 0;
        ~person() {
          delete activitytype;
        }
};

int person:: counter = 0;
class generic1 : public person {
  public:
  string display(){
    return "I am Jim Bob Jones III, Esquire";
  }
  void NFA() {
    this->activitytype = new typeNoFun();
  }
};

int main() {
  person* fool = new generic1();
  fool-> foo();

((generic1 *)fool)->NFA();
fool-> foo();
  
}



