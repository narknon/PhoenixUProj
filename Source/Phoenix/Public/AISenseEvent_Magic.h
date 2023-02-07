#pragma once
#include "CoreMinimal.h"
#include "Perception/AISenseEvent.h"
#include "AIMagicEvent.h"
#include "AISenseEvent_Magic.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAISenseEvent_Magic : public UAISenseEvent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIMagicEvent Event;
    
public:
    UAISenseEvent_Magic();
};

