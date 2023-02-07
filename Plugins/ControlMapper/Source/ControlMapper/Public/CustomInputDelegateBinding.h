#pragma once
#include "CoreMinimal.h"
#include "Engine/InputDelegateBinding.h"
#include "CustomInputDelegateBinding.generated.h"

UCLASS(Abstract, Blueprintable)
class CONTROLMAPPER_API UCustomInputDelegateBinding : public UInputDelegateBinding {
    GENERATED_BODY()
public:
    UCustomInputDelegateBinding();
};

