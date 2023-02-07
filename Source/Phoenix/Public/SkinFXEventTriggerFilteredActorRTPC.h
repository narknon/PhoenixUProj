#pragma once
#include "CoreMinimal.h"
#include "SkinFXEventTriggerFilteredWithDistance.h"
#include "SkinFXEventTriggerFilteredActorRTPC.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USkinFXEventTriggerFilteredActorRTPC : public USkinFXEventTriggerFilteredWithDistance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RTPC;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 InterpolationTime;
    
    USkinFXEventTriggerFilteredActorRTPC();
};

