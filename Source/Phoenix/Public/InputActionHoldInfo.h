#pragma once
#include "CoreMinimal.h"
#include "EUMGInputAction.h"
#include "InputActionHoldInfo.generated.h"

USTRUCT(BlueprintType)
struct FInputActionHoldInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUMGInputAction InputAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMustHold;
    
    PHOENIX_API FInputActionHoldInfo();
};

