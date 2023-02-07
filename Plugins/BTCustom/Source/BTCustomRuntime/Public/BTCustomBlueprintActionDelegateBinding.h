#pragma once
#include "CoreMinimal.h"
#include "EBTCustomActionType.h"
#include "BTCustomBlueprintActionDelegateBinding.generated.h"

USTRUCT(BlueprintType)
struct BTCUSTOMRUNTIME_API FBTCustomBlueprintActionDelegateBinding {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ActionName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EBTCustomActionType::Type> ActionType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FunctionNameToBind;
    
    FBTCustomBlueprintActionDelegateBinding();
};

