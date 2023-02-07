#pragma once
#include "CoreMinimal.h"
#include "CustomBlueprintAnalogInputDelegateBinding.h"
#include "CustomInputDelegateBinding.h"
#include "CustomAnalogInputActionDelegateBinding.generated.h"

UCLASS(Blueprintable)
class CONTROLMAPPER_API UCustomAnalogInputActionDelegateBinding : public UCustomInputDelegateBinding {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCustomBlueprintAnalogInputDelegateBinding> InputActionDelegateBindings;
    
    UCustomAnalogInputActionDelegateBinding();
};

