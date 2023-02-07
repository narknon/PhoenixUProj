#pragma once
#include "CoreMinimal.h"
#include "SkinFXEventTrigger.h"
#include "SkinFXEventTriggerFiltered.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class SKINFX_API USkinFXEventTriggerFiltered : public USkinFXEventTrigger {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Events;
    
    USkinFXEventTriggerFiltered();
};

