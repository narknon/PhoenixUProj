#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CinematicId.h"
#include "CinematicRenderJob.h"
#include "CinematicBatch.generated.h"

UCLASS(Blueprintable)
class PHOENIX_API UCinematicBatch : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCinematicId ShotgunCinematicID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCinematicRenderJob> Jobs;
    
    UCinematicBatch();
};

