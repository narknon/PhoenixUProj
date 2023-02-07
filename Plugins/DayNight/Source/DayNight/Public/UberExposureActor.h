#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UberExposureActor.generated.h"

class UUberExposureComponent;

UCLASS(Blueprintable)
class DAYNIGHT_API AUberExposureActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUberExposureComponent* Component;
    
    AUberExposureActor();
};

