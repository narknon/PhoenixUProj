#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AnimatedLightsSingleton.generated.h"

class UAnimatedLightWorldData;

UCLASS(Blueprintable, NotPlaceable, Transient)
class ANIMATEDLIGHTS_API AAnimatedLightsSingleton : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimatedLightWorldData* WorldData;
    
    AAnimatedLightsSingleton();
};

