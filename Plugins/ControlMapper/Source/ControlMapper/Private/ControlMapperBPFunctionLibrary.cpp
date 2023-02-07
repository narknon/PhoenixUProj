#include "ControlMapperBPFunctionLibrary.h"

class AActor;
class UInputComponent;
class UObject;

float UControlMapperBPFunctionLibrary::GetInputAxisValue(AActor* InputComponentOwner, const FName InputAxisName) {
    return 0.0f;
}

void UControlMapperBPFunctionLibrary::EnableCustomInput(UObject* InputReceiver, UInputComponent* InputComponent) {
}

void UControlMapperBPFunctionLibrary::DisableCustomInput(UObject* InputReceiver, UInputComponent* InputComponent) {
}

UControlMapperBPFunctionLibrary::UControlMapperBPFunctionLibrary() {
}

