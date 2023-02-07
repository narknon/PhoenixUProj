#pragma once
#include "CoreMinimal.h"
#include "GlobalLightingBlendableModsBase.h"
#include "GlobalLightingBlendableMods.generated.h"

class UGlobalLightRigMod;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UGlobalLightingBlendableMods : public UGlobalLightingBlendableModsBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UGlobalLightRigMod*> Mods;
    
    UGlobalLightingBlendableMods();
};

