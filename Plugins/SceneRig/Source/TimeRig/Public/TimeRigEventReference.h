#pragma once
#include "CoreMinimal.h"
#include "TimeRigEventReference.generated.h"

class UTimeRigElement;

USTRUCT(BlueprintType)
struct TIMERIG_API FTimeRigEventReference {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTimeRigElement> ReferenceElementSoftPtr;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UTimeRigElement> ReferenceElement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Name;
    
    FTimeRigEventReference();
};

