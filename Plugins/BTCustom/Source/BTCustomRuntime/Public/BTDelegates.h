#pragma once
#include "CoreMinimal.h"
#include "BTCustomActionDelegateDelegate.h"
#include "BTDelegates.generated.h"

USTRUCT(BlueprintType)
struct FBTDelegates {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FBTCustomActionDelegate> DelegateList;
    
    BTCUSTOMRUNTIME_API FBTDelegates();
};

