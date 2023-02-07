#pragma once
#include "CoreMinimal.h"
#include "LocatorTracker.h"
#include "ActorTracker.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct SKINFX_API FActorTracker : public FLocatorTracker {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> Actor;
    
public:
    FActorTracker();
};

