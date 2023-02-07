#pragma once
#include "CoreMinimal.h"
#include "AblStartPositionGetter_MatchAnimationPosition.h"
#include "Templates/SubclassOf.h"
#include "AblStartPositionGetter_MountRider.generated.h"

class UAblAbility;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAblStartPositionGetter_MountRider : public UAblStartPositionGetter_MatchAnimationPosition {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAblAbility> RequiredAbility;
    
public:
    UAblStartPositionGetter_MountRider();
};

