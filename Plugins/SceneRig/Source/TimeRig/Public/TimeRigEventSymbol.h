#pragma once
#include "CoreMinimal.h"
#include "TimeRigEventSymbol.generated.h"

class UTimeRigElement;
class UTimeRigEvent;

USTRUCT(BlueprintType)
struct TIMERIG_API FTimeRigEventSymbol {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UTimeRigElement> OwningElement;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTimeRigEvent* Event;
    
    FTimeRigEventSymbol();
};

