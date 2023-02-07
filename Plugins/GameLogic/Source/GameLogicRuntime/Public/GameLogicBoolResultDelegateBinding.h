#pragma once
#include "CoreMinimal.h"
#include "Engine/DynamicBlueprintBinding.h"
#include "GameLogicBlueprintActionDelegateBinding.h"
#include "GameLogicBoolResultDelegateBinding.generated.h"

UCLASS(Blueprintable)
class GAMELOGICRUNTIME_API UGameLogicBoolResultDelegateBinding : public UDynamicBlueprintBinding {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameLogicBlueprintActionDelegateBinding> ActionDelegateBindings;
    
    UGameLogicBoolResultDelegateBinding();
};

