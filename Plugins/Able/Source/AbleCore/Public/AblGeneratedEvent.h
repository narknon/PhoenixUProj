#pragma once
#include "CoreMinimal.h"
#include "AblAbilityEvent.h"
#include "AblGeneratedEvent.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABLECORE_API UAblGeneratedEvent : public UAblAbilityEvent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRemovable;
    
public:
    UAblGeneratedEvent();
};

