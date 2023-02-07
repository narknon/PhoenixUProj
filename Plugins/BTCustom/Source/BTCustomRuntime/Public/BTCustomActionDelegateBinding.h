#pragma once
#include "CoreMinimal.h"
#include "Engine/DynamicBlueprintBinding.h"
#include "BTCustomBlueprintActionDelegateBinding.h"
#include "BTCustomActionDelegateBinding.generated.h"

UCLASS(Blueprintable)
class BTCUSTOMRUNTIME_API UBTCustomActionDelegateBinding : public UDynamicBlueprintBinding {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBTCustomBlueprintActionDelegateBinding> ActionDelegateBindings;
    
    UBTCustomActionDelegateBinding();
};

