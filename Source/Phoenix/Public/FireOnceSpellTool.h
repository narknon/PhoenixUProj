#pragma once
#include "CoreMinimal.h"
#include "AdditionalProjectiles.h"
#include "SpellTool.h"
#include "FireOnceSpellTool.generated.h"

UCLASS(Blueprintable)
class AFireOnceSpellTool : public ASpellTool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAdditionalProjectiles> AdditionalProjectiles;
    
    AFireOnceSpellTool(const FObjectInitializer& ObjectInitializer);
};

