#pragma once
#include "CoreMinimal.h"
#include "EMaterialPermuterLoadingPriority.h"
#include "MaterialPermuterKeyProperty.h"
#include "FXAutoTriggerPrerequisiteBase.h"
#include "FXAutoTriggerPrerequisiteIsBundleLoaded.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXAutoTriggerPrerequisiteIsBundleLoaded : public UFXAutoTriggerPrerequisiteBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMaterialPermuterKeyProperty Key;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMaterialPermuterLoadingPriority Priority;
    
    UFXAutoTriggerPrerequisiteIsBundleLoaded();
};

