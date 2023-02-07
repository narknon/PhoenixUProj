#pragma once
#include "CoreMinimal.h"
#include "GameLogicBlueprintActionDelegateBinding.generated.h"

USTRUCT(BlueprintType)
struct GAMELOGICRUNTIME_API FGameLogicBlueprintActionDelegateBinding {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ElementName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FunctionNameToBind;
    
    FGameLogicBlueprintActionDelegateBinding();
};

