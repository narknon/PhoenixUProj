#pragma once
#include "CoreMinimal.h"
#include "SkinFXEventTriggerFilteredWithDistance.h"
#include "SkinFXEventTriggerFilteredHermesSimple.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USkinFXEventTriggerFilteredHermesSimple : public USkinFXEventTriggerFilteredWithDistance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HermesMessage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MessageData;
    
    USkinFXEventTriggerFilteredHermesSimple();
};

