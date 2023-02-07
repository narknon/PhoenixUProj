#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser.h"
#include "GameplayTagContainer.h"
#include "ECreatureMovementSpeed.h"
#include "AblAnimationTagChooser_MountGait.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimationTagChooser_MountGait : public UAblAnimationTagChooser {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ECreatureMovementSpeed, FGameplayTagContainer> GaitToTagsMap;
    
    UAblAnimationTagChooser_MountGait();
};

