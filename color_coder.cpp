#include "color_coder.h"
#include <stdexcept>

namespace TelCoColorCoder {

static const char* kMajorColorNames[] = { "White", "Red", "Black", "Yellow", "Violet" };
static const char* kMinorColorNames[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
static const int kNumberOfMajorColors = sizeof(kMajorColorNames) / sizeof(kMajorColorNames[0]);
static const int kNumberOfMinorColors = sizeof(kMinorColorNames) / sizeof(kMinorColorNames[0]);

ColorPair::ColorPair(MajorColor major, MinorColor minor)
    : majorColor(major), minorColor(minor) {}

MajorColor ColorPair::getMajor() const { return majorColor; }
MinorColor ColorPair::getMinor() const { return minorColor; }

std::string ColorPair::ToString() const {
    return std::string(kMajorColorNames[majorColor]) + " " +
           kMinorColorNames[minorColor];
}

ColorPair GetColorFromPairNumber(int pairNumber) {
    if (pairNumber < 1 || pairNumber > kNumberOfMajorColors * kNumberOfMinorColors) {
        throw std::out_of_range("Invalid pair number");
    }
    int zeroBased = pairNumber - 1;
    MajorColor major = static_cast<MajorColor>(zeroBased / kNumberOfMinorColors);
    MinorColor minor = static_cast<MinorColor>(zeroBased % kNumberOfMinorColors);
    return ColorPair(major, minor);
}

int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
    return major * kNumberOfMinorColors + minor + 1;
}

}  // namespace TelCoColorCoder
