#pragma once
#include "CoreMinimal.h"
#include "MaterialPermuterDynamicTrigger.h"
#include "MaterialPermuterLoadTriggerProperty.h"
#include "MaterialPermuterDynamicTriggerNamed.generated.h"

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class MATERIALPERMUTER_API UMaterialPermuterDynamicTriggerNamed : public UMaterialPermuterDynamicTrigger {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterLoadTriggerProperty Trigger;
    
    UMaterialPermuterDynamicTriggerNamed();
};

