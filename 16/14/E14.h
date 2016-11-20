#ifndef E14_H
#define E14_H

#include <string>
#include <iostream>

using namespace std;

typedef string::size_type pos;

template<pos H, pos W>
class Screen {
public:
	Screen() = default;
	Screen(char c) : height(H), width(W), contents(H * W, c) {}
	char get() const { return contents[cursor]; }
	inline char get(pos ht, pos wd) const;
	Screen &move(pos r, pos c);
    friend ostream& operator<<(ostream& os, const Screen<H,W>& s){
        for(int i = 0; i < H; ++i){
            os << s.contents.substr(0, W) << endl;
        }
        return os;
    }
    friend istream& operator>>(istream& in, Screen<H,W>& s){
        char c;
        in >> c;
        string m(H*W,c);
        s.contents = m;
        return in;
    }
private:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;
};

//template<pos H, pos W>
//ostream& operator<<(ostream& os, const Screen<H,W>& s){
//    for(int i = 0; i < H; ++i){
//    os << s.contents.substr(0, W) << endl;
//}
//return os;
//}
//
//template<pos H, pos W>
//istream& operator>>(istream& in, Screen<H,W>& s){
//    char c;
//    in >> c;
//    string m(H*W,c);
//    s.contents = m;
//    return in;
//}

template<pos H, pos W>
inline
Screen<H,W> &Screen<H,W>::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}

template<pos H, pos W>
char Screen<H,W>::get(pos r, pos c) const {
	pos row = r*width;
	return contents[row + c];
}
#endif
