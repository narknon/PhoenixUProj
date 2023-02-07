#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "CameraFixupOperationState.generated.h"

UCLASS(Blueprintable)
class AVAANIMATION_API UCameraFixupOperationState : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UObject* Context;
    
    UCameraFixupOperationState();
};

