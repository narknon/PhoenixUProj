#pragma once
#include "CoreMinimal.h"
#include "CogGroupEvaluation_CombinedBase.h"
#include "CogGroupEvaluation_CombinedTargeting.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCogGroupEvaluation_CombinedTargeting : public UCogGroupEvaluation_CombinedBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxFOVForScoringEnemies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinFOVScoreForEnemies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinHeightScore;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NearDistanceBoostPctNonCombat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NearDistanceBoostPctCombatGamepad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NearDistanceBoostPctCombatMouse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BelowMouseCursorBoostPct;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpellComboBoostPct;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StickyBoostPct;
    
public:
    UCogGroupEvaluation_CombinedTargeting();
};

