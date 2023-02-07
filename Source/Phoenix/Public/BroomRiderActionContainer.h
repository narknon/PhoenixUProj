#pragma once
#include "CoreMinimal.h"
#include "BroomRiderActionContainer.generated.h"

class UBroomRiderActionBase;

USTRUCT(BlueprintType)
struct FBroomRiderActionContainer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBroomRiderActionBase* Action;
    
    PHOENIX_API FBroomRiderActionContainer();
};

