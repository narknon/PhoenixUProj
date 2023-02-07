#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser_AppendToBaseChooser.h"
#include "AblAppendToBaseChooser_EnemyDirectionToTarget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAppendToBaseChooser_EnemyDirectionToTarget : public UAblAnimationTagChooser_AppendToBaseChooser {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinFrontAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxFrontAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinLeftAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxRightAngle;
    
    UAblAppendToBaseChooser_EnemyDirectionToTarget();
};

