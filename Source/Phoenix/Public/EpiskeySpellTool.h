#pragma once
#include "CoreMinimal.h"
#include "SpellTool.h"
#include "EpiskeySpellTool.generated.h"

UCLASS(Blueprintable)
class AEpiskeySpellTool : public ASpellTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealingAmount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    AEpiskeySpellTool();
};

