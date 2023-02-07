#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TimeRigInterval.h"
#include "TimeRigGroup.generated.h"

class UTimeRigElement;

UCLASS(Blueprintable, EditInlineNew)
class TIMERIG_API UTimeRigGroup : public UTimeRigInterval {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Color;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UTimeRigElement*> ChildElements;
    
    UTimeRigGroup();
};

