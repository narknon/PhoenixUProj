#pragma once
#include "CoreMinimal.h"
#include "ActorTracker.h"
#include "SocketTracker.generated.h"

class USceneComponent;

USTRUCT(BlueprintType)
struct SKINFX_API FSocketTracker : public FActorTracker {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<USceneComponent> SocketComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SocketName;
    
public:
    FSocketTracker();
};

