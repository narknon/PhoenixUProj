#pragma once
#include "CoreMinimal.h"
#include "BTCustomAction.generated.h"

USTRUCT(BlueprintType)
struct BTCUSTOMRUNTIME_API FBTCustomAction {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ActionName;
    
    FBTCustomAction();
};

