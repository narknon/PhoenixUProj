#pragma once
#include "CoreMinimal.h"
#include "CustomBlueprintInputDelegateBinding.h"
#include "CustomInputDelegateBinding.h"
#include "CustomInputActionDelegateBinding.generated.h"

UCLASS(Blueprintable)
class CONTROLMAPPER_API UCustomInputActionDelegateBinding : public UCustomInputDelegateBinding {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCustomBlueprintInputDelegateBinding> InputActionDelegateBindings;
    
    UCustomInputActionDelegateBinding();
};

