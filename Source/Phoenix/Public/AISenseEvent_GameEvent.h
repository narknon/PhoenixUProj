#pragma once
#include "CoreMinimal.h"
#include "Perception/AISenseEvent.h"
#include "AIGameEvent.h"
#include "AISenseEvent_GameEvent.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAISenseEvent_GameEvent : public UAISenseEvent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAIGameEvent Event;
    
public:
    UAISenseEvent_GameEvent();
};

