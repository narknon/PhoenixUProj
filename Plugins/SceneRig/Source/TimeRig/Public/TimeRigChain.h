#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TimeRigInterval.h"
#include "TimeRigChain.generated.h"

class UTimeRigElement;

UCLASS(Blueprintable, EditInlineNew)
class TIMERIG_API UTimeRigChain : public UTimeRigInterval {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor Color;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UTimeRigElement*> ChildElements;
    
    UTimeRigChain();
};

