#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


class BigInt {
private:
    string num = "";
public:
    BigInt() {};

    BigInt(string decStr) {
        num = decStr;
    }

    BigInt(int decInt) {
        while (decInt) {
            num.insert(num.begin(), char((decInt % 10) + '0'));
            decInt /= 10;
        }
    }

    int size(const string &s) {
        return s.size();
    }

    BigInt operator=(BigInt &obj) {
        num = obj.num;
        return *this;
    }

    BigInt operator-(BigInt &obj) {
        string firstNum = num, secondNum = obj.num;
        bool negative = false;

        if (secondNum[0] == '-') {
            secondNum.erase(secondNum.begin());
            BigInt res;
            obj.num = secondNum;
            res.num = firstNum;
            return res + obj;
        } else if (secondNum[0] != '-' and firstNum[0] == '-') {
            firstNum.erase(firstNum.begin());
            firstNum = firstNum;
            negative = 1;
            BigInt res;
            res.num = firstNum;
            obj.num = secondNum;
            BigInt final = res + obj;
            final.num = "-" + final.num;
            return final;
        } else if (secondNum[0] == '-' and firstNum[0] == '-') {
            firstNum.erase(firstNum.begin());
            secondNum.erase(secondNum.begin());
            negative = 1;
        }

        int mxSz = max(firstNum.size(), secondNum.size());

        while (firstNum.size() < mxSz) {
            firstNum = "0" + firstNum;
        }

        while (secondNum.size() < mxSz) {
            secondNum = "0" + secondNum;
        }

        if (firstNum < secondNum)swap(firstNum, secondNum), negative = 1;
        while (secondNum.size() < firstNum.size())secondNum = "0" + secondNum;

        int car = 0;
        BigInt res;
        for (int i = firstNum.size() - 1; i >= 0; --i) {
            int dig1 = firstNum[i] - '0', dig2 = secondNum[i] - '0';
            int resDig = dig1 - dig2 - car;

            car = (resDig < 0);
            resDig = resDig + (10 * car);
            res.num.insert(res.num.begin(), char(resDig + '0'));
        }

        while (res.num[0] == '0' and res.num.size() > 1)
            res.num.erase(res.num.begin());

        if (negative)res.num = "-" + res.num;
        return res;
    }


    BigInt operator+(BigInt &obj) {
        string firstNum = num, secondNum = obj.num;
        if (firstNum[0] != '-' and secondNum[0] == '-') {
            secondNum.erase(secondNum.begin());// remove '-'
            BigInt res;
            obj.num = secondNum;
            res.num = firstNum;
            return res - obj;
        } else if (firstNum[0] == '-' and secondNum[0] != '-') {
            firstNum.erase(firstNum.begin());// remove '-'
            BigInt res;
            res.num = firstNum;
            obj.num = secondNum;
            if (res.num > obj.num) {
                return res - obj;
            } else {
                return obj - res;
            }
        } else if (firstNum[0] == '-' and secondNum[0] == '-') {
            secondNum.erase(secondNum.begin());// remove '-'
            BigInt res;
            res.num = firstNum;
            obj.num = secondNum;
            BigInt final = res - obj;
            return final;
        } else {
            int mxSz = max(firstNum.size(), secondNum.size());

            while (firstNum.size() < mxSz) {
                firstNum = "0" + firstNum;
            }

            while (secondNum.size() < mxSz) {
                secondNum = "0" + secondNum;
            }

            BigInt res;
            int carry = 0;
            for (int i = mxSz - 1; i >= 0; i--) {
                int dig1 = firstNum[i] - '0', dig2 = secondNum[i] - '0';
                int digRes = dig1 + dig2 + carry;

                carry = (digRes > 9);

                res.num.insert(res.num.begin(), char((digRes % 10) + '0'));

            }
            res.num = char(carry + '0') + res.num;
            while (res.num[0] == '0' and res.num.size() > 1)
                res.num.erase(res.num.begin());
            return res;
        }
    }


    friend ostream &operator<<(ostream &out, BigInt b) {
        out << b.num;
        return out;
    }


};

ostream &operator<<(ostream &out, BigInt b);


int main() {
    //test Case1
    cout << "Test Case 1:\n"
            "  123456789012345678901234567890\n"
            "+ 113456789011345678901134567890\n"
            "---------------------------------\n"
            "= ";
    BigInt num1("123456789012345678901234567890"),
            num2("113456789011345678901134567890");
    BigInt result1 = num1 + num2;
    cout << result1 << endl << endl << endl;

    //test Case2
    cout << "Test Case 2:\n"
            "  123456789012345678901234567890\n"
            "- 113456789011345678901134567890\n"
            "---------------------------------\n"
            "= ";
    BigInt num3("123456789012345678901234567890"),
            num4("113456789011345678901134567890");
    BigInt result2 = num3 - num4;
    cout << result2 << endl << endl;

    //test Case3
    cout << "Test Case 3:\n"
            "   789012345678901231234564567890\n"
            "+ -134567890113411345678901567890\n"
            "---------------------------------\n"
            "= ";
    BigInt num5("789012345678901231234564567890"),
            num6("-134567890113411345678901567890");
    BigInt result3 = num5 + num6;
    cout << result3 << endl << endl << endl;

    //test Case4
    cout << "Test Case 4:\n"
            "  -456789012345678901234567890123\n"
            "+  789011345678901134567890113456\n"
            "---------------------------------\n"
            "= ";
    BigInt num7("-456789012345678901234567890123"),
            num8("789011345678901134567890113456");
    BigInt result4 = num7 + num8;
    cout << result4 << endl << endl << endl;

    //test Case5
    cout << "Test Case 5:\n"
            "  -567891234567890123456789012340\n"
            "- -789011134567890113456134567890\n"
            "---------------------------------\n"
            "= ";
    BigInt num9("-567891234567890123456789012340"),
            num10("-789011134567890113456134567890");
    BigInt result5 = num9 - num10;
    cout << result5 << endl << endl << endl;


    return 0;
}
