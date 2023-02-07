#pragma once
#include "CoreMinimal.h"
#include "SkinFXEventTriggerFilteredWithDistance.h"
#include "SkinFXEventTriggerFilteredMultiFX2.generated.h"

class UMultiFX2_Base;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USkinFXEventTriggerFilteredMultiFX2 : public USkinFXEventTriggerFilteredWithDistance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UMultiFX2_Base* FX;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttachPointName;
    
    USkinFXEventTriggerFilteredMultiFX2();
};

