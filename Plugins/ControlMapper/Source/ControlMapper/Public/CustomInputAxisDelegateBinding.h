#pragma once
#include "CoreMinimal.h"
#include "Engine/InputAxisDelegateBinding.h"
#include "CustomInputDelegateBinding.h"
#include "CustomInputAxisDelegateBinding.generated.h"

UCLASS(Blueprintable)
class CONTROLMAPPER_API UCustomInputAxisDelegateBinding : public UCustomInputDelegateBinding {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBlueprintInputAxisDelegateBinding> InputAxisDelegateBindings;
    
    UCustomInputAxisDelegateBinding();
};

