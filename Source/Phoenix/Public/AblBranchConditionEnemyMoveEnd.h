#pragma once
#include "CoreMinimal.h"
#include "AblBranchCondition.h"
#include "EEnemyMoveEndType.h"
#include "AblBranchConditionEnemyMoveEnd.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblBranchConditionEnemyMoveEnd : public UAblBranchCondition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EEnemyMoveEndType> MoveType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SlideLinkEndXYTolerance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SlideLinkEndZTolerance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSlideCheckSurfaceType;
    
public:
    UAblBranchConditionEnemyMoveEnd();
};

