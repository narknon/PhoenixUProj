#pragma once
#include "CoreMinimal.h"
#include "Engine/InputDelegateBinding.h"
#include "BlueprintCustomInputAxisDelegateBinding.generated.h"

USTRUCT(BlueprintType)
struct CONTROLMAPPER_API FBlueprintCustomInputAxisDelegateBinding : public FBlueprintInputDelegateBinding {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName InputAxisName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FunctionNameToBind;
    
    FBlueprintCustomInputAxisDelegateBinding();
};

