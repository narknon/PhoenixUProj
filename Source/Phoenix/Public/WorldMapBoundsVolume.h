#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "WorldMapBoundsVolume.generated.h"

UCLASS(Blueprintable)
class AWorldMapBoundsVolume : public AVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsWorldMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString MapName;
    
    AWorldMapBoundsVolume();
};

