#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser_EnemyContainer.h"
#include "EEnemy_AlertState.h"
#include "AblAnimationTagChooser_EnemyAlert.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimationTagChooser_EnemyAlert : public UAblAnimationTagChooser_EnemyContainer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_AlertState AlertState;
    
    UAblAnimationTagChooser_EnemyAlert();
};

