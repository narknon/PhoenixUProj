#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ESeasonEnum -FallbackName=ESeasonEnum
#include "ESeasonEnum.h"
#include "SeasonOverrideVolume.h"
#include "SeasonFXOverrideVolume.generated.h"

UCLASS(Blueprintable)
class ENVIRONMENTALGLOBALS_API ASeasonFXOverrideVolume : public ASeasonOverrideVolume {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESeasonEnum SeasonOverride;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PhaseOverride;
    
    ASeasonFXOverrideVolume(const FObjectInitializer& ObjectInitializer);
};

