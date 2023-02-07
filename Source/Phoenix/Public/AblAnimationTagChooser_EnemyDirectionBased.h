#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser.h"
#include "AblAnimationTagChooser_EnemyDirectionBased.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimationTagChooser_EnemyDirectionBased : public UAblAnimationTagChooser {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCloseBackAngle;
    
    UAblAnimationTagChooser_EnemyDirectionBased();
};

