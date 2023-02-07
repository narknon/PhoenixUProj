#pragma once
#include "CoreMinimal.h"
#include "SceneAction_LumosDynamicScalability.h"
#include "SceneAction_LumosDynamicScalabilityMod.generated.h"

class ULumosScalabilityModifyBase;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_LumosDynamicScalabilityMod : public USceneAction_LumosDynamicScalability {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    ULumosScalabilityModifyBase* ScalabilityMod;
    
    USceneAction_LumosDynamicScalabilityMod();
};

