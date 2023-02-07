#pragma once
#include "CoreMinimal.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=Engine -ObjectName=ESeasonEnum -FallbackName=ESeasonEnum
#include "ESeasonEnum.h"
#include "WorldEventCondition.h"
#include "WorldEventCondition_Season.generated.h"

UCLASS(Blueprintable)
class UWorldEventCondition_Season : public UWorldEventCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ESeasonEnum> SeasonsToCheck;
    
    UWorldEventCondition_Season();
};

