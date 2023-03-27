//using namespace std;

namespace ariel{
    class Card{
        private:
        int val;
        char sign;

        public:
        Card(int val, char sign);
        int getVal();
        char getSign();
    };
}