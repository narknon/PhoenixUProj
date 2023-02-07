#pragma once
#include "CoreMinimal.h"
#include "ReferencedTimeRigBindings.generated.h"

class UTimeRig;
class UTimeRigElement;
class UTimeRigPlaceholder;

USTRUCT(BlueprintType)
struct TIMERIG_API FReferencedTimeRigBindings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTimeRig* ReferencedTimeRig;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<TSoftObjectPtr<UTimeRigPlaceholder>, UTimeRigElement*> ReferencedPlaceholderMap;
    
    FReferencedTimeRigBindings();
};

