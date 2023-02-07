#include "GlobalLightingCustomBlendablesLibrary.h"

class UObject;

bool UGlobalLightingCustomBlendablesLibrary::GetGlobalLightingCustomBlendableScalarName(UObject* WorldContextObject, FName ScalarName, float& ScalarValue) {
    return false;
}

bool UGlobalLightingCustomBlendablesLibrary::GetGlobalLightingCustomBlendableScalar(UObject* WorldContextObject, FGlobalLightingCustomBlendableNameScalar Scalar, float& ScalarValue) {
    return false;
}

bool UGlobalLightingCustomBlendablesLibrary::GetGlobalLightingCustomBlendableLinearColorName(UObject* WorldContextObject, FName ColorName, FLinearColor& ColorValue) {
    return false;
}

bool UGlobalLightingCustomBlendablesLibrary::GetGlobalLightingCustomBlendableLinearColor(UObject* WorldContextObject, FGlobalLightingCustomBlendableNameLinearColor Color, FLinearColor& ColorValue) {
    return false;
}

bool UGlobalLightingCustomBlendablesLibrary::GetDefaultGlobalLightingCustomBlendableScalarName(FName ScalarName, float& ScalarValue) {
    return false;
}

bool UGlobalLightingCustomBlendablesLibrary::GetDefaultGlobalLightingCustomBlendableScalar(FGlobalLightingCustomBlendableNameScalar Scalar, float& ScalarValue) {
    return false;
}

bool UGlobalLightingCustomBlendablesLibrary::GetDefaultGlobalLightingCustomBlendableLinearColorName(FName ColorName, FLinearColor& ColorValue) {
    return false;
}

bool UGlobalLightingCustomBlendablesLibrary::GetDefaultGlobalLightingCustomBlendableLinearColor(FGlobalLightingCustomBlendableNameLinearColor Color, FLinearColor& ColorValue) {
    return false;
}

UGlobalLightingCustomBlendablesLibrary::UGlobalLightingCustomBlendablesLibrary() {
}

