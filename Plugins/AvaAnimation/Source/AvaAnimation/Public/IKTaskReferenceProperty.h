#pragma once
#include "CoreMinimal.h"
#include "IKTaskReferenceProperty.generated.h"

USTRUCT(BlueprintType)
struct AVAANIMATION_API FIKTaskReferenceProperty {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 TaskIndex;
    
    FIKTaskReferenceProperty();
};

