#pragma once
#include "CoreMinimal.h"
#include "Engine/DynamicBlueprintBinding.h"
#include "GameLogicBlueprintActionDelegateBinding.h"
#include "GameLogicFloatResultDelegateBinding.generated.h"

UCLASS(Blueprintable)
class GAMELOGICRUNTIME_API UGameLogicFloatResultDelegateBinding : public UDynamicBlueprintBinding {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameLogicBlueprintActionDelegateBinding> ActionDelegateBindings;
    
    UGameLogicFloatResultDelegateBinding();
};

