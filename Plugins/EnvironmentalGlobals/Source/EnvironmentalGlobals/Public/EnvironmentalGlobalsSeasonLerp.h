#pragma once
#include "CoreMinimal.h"
#include "ESeasonEnum.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ESeasonEnum -FallbackName=ESeasonEnum
#include "EnvironmentalGlobalsSeasonLerp.generated.h"

USTRUCT(BlueprintType)
struct FEnvironmentalGlobalsSeasonLerp {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESeasonEnum Season;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Phases;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Phase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Lerp;
    
    ENVIRONMENTALGLOBALS_API FEnvironmentalGlobalsSeasonLerp();
};

