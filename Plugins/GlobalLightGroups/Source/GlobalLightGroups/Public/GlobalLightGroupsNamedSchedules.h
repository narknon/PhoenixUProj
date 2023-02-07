#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GlobalLightGroupsScheduleMap.h"
#include "GlobalLightGroupsNamedSchedules.generated.h"

UCLASS(Abstract, Blueprintable)
class UGlobalLightGroupsNamedSchedules : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGlobalLightGroupsScheduleMap ScheduleMap;
    
    UGlobalLightGroupsNamedSchedules();
    UFUNCTION(BlueprintCallable)
    void RebuildSchedules();
    
};

