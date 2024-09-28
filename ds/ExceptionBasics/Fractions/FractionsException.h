#include <stdexcept>
using std::runtime_error;

class FractionsException : public runtime_error{
    public: 
    FractionsException::FractionsException():runtime_error("attempted to divide by zero"){      
    }
};