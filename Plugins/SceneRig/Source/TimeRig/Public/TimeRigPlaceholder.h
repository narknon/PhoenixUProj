#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TimeRigElement.h"
#include "TimeRigPlaceholder.generated.h"

UCLASS(Blueprintable)
class TIMERIG_API UTimeRigPlaceholder : public UTimeRigElement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTimeRigElement> PlaceholderForType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UTimeRigElement*> ChildElements;
    
    UTimeRigPlaceholder();
};

