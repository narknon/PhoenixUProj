#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "TimeRigElementState.generated.h"

class UTimeRigElement;
class UTimeRigInstanceContext;

UCLASS(Blueprintable)
class TIMERIG_API UTimeRigElementState : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTimeRigInstanceContext* Context;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTimeRigElement* BaseDefinition;
    
    UTimeRigElementState();
};

