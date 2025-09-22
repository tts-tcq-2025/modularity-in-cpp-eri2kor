#pragma once
#include <string>

namespace TelCoColorCoder {

enum MajorColor { WHITE, RED, BLACK, YELLOW, VIOLET };
enum MinorColor { BLUE, ORANGE, GREEN, BROWN, SLATE };

class ColorPair {
 public:
    ColorPair(MajorColor major, MinorColor minor);
    MajorColor getMajor() const;
    MinorColor getMinor() const;
    std::string ToString() const;
 private:
    MajorColor majorColor;
    MinorColor minorColor;
};

ColorPair GetColorFromPairNumber(int pairNumber);
int GetPairNumberFromColor(MajorColor major, MinorColor minor);

}  // namespace TelCoColorCoder
