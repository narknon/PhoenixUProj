#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "SanctuaryZoneStreamingVolume.generated.h"

UCLASS(Blueprintable)
class ASanctuaryZoneStreamingVolume : public AVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ZoneName;
    
    ASanctuaryZoneStreamingVolume();
};

