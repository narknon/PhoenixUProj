#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FastTravelPort.generated.h"

class AFastTravelPort;

UCLASS(Blueprintable)
class AFastTravelPort : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AFastTravelPort* DestinationPort;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DelayBeforeTeleport;
    
    AFastTravelPort(const FObjectInitializer& ObjectInitializer);
};

