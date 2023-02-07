#pragma once
#include "CoreMinimal.h"
#include "SceneAction_LumosDynamicScalability.h"
#include "SceneAction_LumosDynamicScalabilityOverride.generated.h"

class ULumosScalabilityOverrideBase;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_LumosDynamicScalabilityOverride : public USceneAction_LumosDynamicScalability {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULumosScalabilityOverrideBase* ScalabilityOverride;
    
    USceneAction_LumosDynamicScalabilityOverride();
};

