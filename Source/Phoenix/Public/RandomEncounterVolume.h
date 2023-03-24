#pragma once
#include "CoreMinimal.h"
#include "PhoenixTrackingVolume.h"
#include "RandomEncounterVolume.generated.h"

UCLASS(Blueprintable)
class ARandomEncounterVolume : public APhoenixTrackingVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString EncounterDBName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SearchRadius;
    
    ARandomEncounterVolume(const FObjectInitializer& ObjectInitializer);
};

