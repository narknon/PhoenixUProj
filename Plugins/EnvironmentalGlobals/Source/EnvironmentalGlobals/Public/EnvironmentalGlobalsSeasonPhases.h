#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EnvironmentalGlobalsSeasonPhases.generated.h"

UCLASS(Blueprintable)
class ENVIRONMENTALGLOBALS_API UEnvironmentalGlobalsSeasonPhases : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 FallPhases;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WinterPhases;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpringPhases;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SummerPhases;
    
    UEnvironmentalGlobalsSeasonPhases();
};

