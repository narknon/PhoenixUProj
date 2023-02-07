#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser.h"
#include "EEnemy_TagContainer.h"
#include "AblAnimationTagChooser_Enemy.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimationTagChooser_Enemy : public UAblAnimationTagChooser {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEnemy_TagContainer TagContainer;
    
    UAblAnimationTagChooser_Enemy();
};

