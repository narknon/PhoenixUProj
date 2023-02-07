#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AblAnimationTagChooser.h"
#include "AblAnimationTagChooser_AppendToBase.generated.h"

class UAblAnimationTagChooser_AppendToBaseChooser;

UCLASS(Blueprintable, EditInlineNew)
class ABLECORE_API UAblAnimationTagChooser_AppendToBase : public UAblAnimationTagChooser {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer BaseAnimationTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAblAnimationTagChooser_AppendToBaseChooser*> Choosers;
    
    UAblAnimationTagChooser_AppendToBase();
};

