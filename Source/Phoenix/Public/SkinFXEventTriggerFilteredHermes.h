#pragma once
#include "CoreMinimal.h"
#include "SkinFXEventTriggerFilteredWithDistance.h"
#include "SkinFXEventTriggerFilteredHermes.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USkinFXEventTriggerFilteredHermes : public USkinFXEventTriggerFilteredWithDistance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HermesMessage;
    
    USkinFXEventTriggerFilteredHermes();
};

