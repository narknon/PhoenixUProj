#include "NameProvider.h"

class UObject;

FName UNameProvider::GetNameBP(const UObject* Caller) const {
    return NAME_None;
}

UNameProvider::UNameProvider() {
}

