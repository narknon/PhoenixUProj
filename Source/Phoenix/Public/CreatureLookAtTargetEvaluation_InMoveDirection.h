#pragma once
#include "CoreMinimal.h"
#include "CreatureLookAtTargetEvaluation_Bool.h"
#include "CreatureLookAtTargetEvaluation_InMoveDirection.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UCreatureLookAtTargetEvaluation_InMoveDirection : public UCreatureLookAtTargetEvaluation_Bool {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StopMaxHeadingAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WalkMaxHeadingAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float JogMaxHeadingAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SprintMaxHeadingAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FlyingMaxHeadingAngle;
    
    UCreatureLookAtTargetEvaluation_InMoveDirection();
};

