#pragma once
#include "CoreMinimal.h"
#include "CustomBlueprintStickInputDelegateBinding.h"
#include "CustomInputDelegateBinding.h"
#include "CustomStickInputActionDelegateBinding.generated.h"

UCLASS(Blueprintable)
class CONTROLMAPPER_API UCustomStickInputActionDelegateBinding : public UCustomInputDelegateBinding {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCustomBlueprintStickInputDelegateBinding> InputActionDelegateBindings;
    
    UCustomStickInputActionDelegateBinding();
};

