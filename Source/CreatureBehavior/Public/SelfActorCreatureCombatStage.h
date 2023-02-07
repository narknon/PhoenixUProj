#pragma once
#include "CoreMinimal.h"
#include "EUtilityArithmeticOperation.h"
#include "QualifierConsideration.h"
#include "SelfActorCreatureCombatStage.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USelfActorCreatureCombatStage : public UQualifierConsideration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUtilityArithmeticOperation Operation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StageIndex;
    
    USelfActorCreatureCombatStage();
};

