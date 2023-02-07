#pragma once
#include "CoreMinimal.h"
#include "FireOnceSpellTool.h"
#include "PetrificusSpellTool.generated.h"

class UInteractionArchitectAsset;
class UMultiFX2_Base;

UCLASS(Blueprintable)
class APetrificusSpellTool : public AFireOnceSpellTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UInteractionArchitectAsset* ChargedEndMunitionDataAsset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UMultiFX2_Base*> PetrificusFX2;
    
    APetrificusSpellTool();
};

