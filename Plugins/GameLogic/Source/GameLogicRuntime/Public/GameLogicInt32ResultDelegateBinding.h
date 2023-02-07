#pragma once
#include "CoreMinimal.h"
#include "Engine/DynamicBlueprintBinding.h"
#include "GameLogicBlueprintActionDelegateBinding.h"
#include "GameLogicInt32ResultDelegateBinding.generated.h"

UCLASS(Blueprintable)
class GAMELOGICRUNTIME_API UGameLogicInt32ResultDelegateBinding : public UDynamicBlueprintBinding {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameLogicBlueprintActionDelegateBinding> ActionDelegateBindings;
    
    UGameLogicInt32ResultDelegateBinding();
};

