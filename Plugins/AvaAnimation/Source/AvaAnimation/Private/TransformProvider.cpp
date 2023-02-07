#include "TransformProvider.h"

class UObject;

FTransform UTransformProvider::GetTransformBP(const UObject* Context, float TimeOffset) const {
    return FTransform{};
}

UTransformProvider::UTransformProvider() {
}

