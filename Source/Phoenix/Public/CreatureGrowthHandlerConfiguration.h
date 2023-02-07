#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CreatureGrowthHandlerConfiguration.generated.h"

class ACreatureGiveBirthHandler;
class ACreatureGrowUpHandler;
class ACreatureHatchHandler;

UCLASS(Blueprintable)
class UCreatureGrowthHandlerConfiguration : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ACreatureHatchHandler> HatchHandler;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ACreatureGiveBirthHandler> GiveBirthHandler;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ACreatureGrowUpHandler> GrowUpHandler;
    
    UCreatureGrowthHandlerConfiguration();
};

