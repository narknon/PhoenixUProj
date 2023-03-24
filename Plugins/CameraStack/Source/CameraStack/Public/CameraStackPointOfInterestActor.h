#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraStackPointOfInterestActor.generated.h"

UCLASS(Blueprintable, MinimalAPI)
class ACameraStackPointOfInterestActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDistance;
    
    ACameraStackPointOfInterestActor(const FObjectInitializer& ObjectInitializer);
};

