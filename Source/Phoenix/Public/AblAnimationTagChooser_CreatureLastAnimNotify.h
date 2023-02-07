#pragma once
#include "CoreMinimal.h"
#include "AblAnimationTagChooser.h"
#include "AblAnimationTagChooser_CreatureLastAnimNotify.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAblAnimationTagChooser_CreatureLastAnimNotify : public UAblAnimationTagChooser {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Names;
    
    UAblAnimationTagChooser_CreatureLastAnimNotify();
};

