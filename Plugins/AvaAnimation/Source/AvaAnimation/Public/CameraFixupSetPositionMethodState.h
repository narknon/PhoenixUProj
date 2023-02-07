#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CameraFixupSetPositionMethodState.generated.h"

UCLASS(Blueprintable)
class AVAANIMATION_API UCameraFixupSetPositionMethodState : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* Context;
    
    UCameraFixupSetPositionMethodState();
};

