#pragma once
#include "CoreMinimal.h"
#include "BTDelegates.h"
#include "EBTCustomActionType.h"
#include "NameToType.generated.h"

USTRUCT(BlueprintType)
struct FNameToType {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TEnumAsByte<EBTCustomActionType::Type>, FBTDelegates> ActionTypeToDelegatesMap;
    
    BTCUSTOMRUNTIME_API FNameToType();
};

