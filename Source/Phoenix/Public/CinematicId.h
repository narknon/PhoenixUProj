#pragma once
#include "CoreMinimal.h"
#include "CinematicId.generated.h"

USTRUCT(BlueprintType)
struct PHOENIX_API FCinematicId {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ID;
    
    FCinematicId();
};

