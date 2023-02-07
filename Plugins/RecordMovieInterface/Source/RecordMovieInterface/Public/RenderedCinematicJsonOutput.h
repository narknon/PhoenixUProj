#pragma once
#include "CoreMinimal.h"
#include "RenderedCinematicInfo.h"
#include "RenderedCinematicJsonOutput.generated.h"

USTRUCT(BlueprintType)
struct FRenderedCinematicJsonOutput {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRenderedCinematicInfo> CinematicInfos;
    
    RECORDMOVIEINTERFACE_API FRenderedCinematicJsonOutput();
};

