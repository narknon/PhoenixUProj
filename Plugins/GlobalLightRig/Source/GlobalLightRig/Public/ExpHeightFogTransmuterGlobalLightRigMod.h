#pragma once
#include "CoreMinimal.h"
#include "ExpHeightFogTransmuter.h"
#include "ExpHeightFogTransmuterGlobalLightRigMod.generated.h"

class UGlobalLightRigMod;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GLOBALLIGHTRIG_API UExpHeightFogTransmuterGlobalLightRigMod : public UExpHeightFogTransmuter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UGlobalLightRigMod*> Mods;
    
    UExpHeightFogTransmuterGlobalLightRigMod();
};

