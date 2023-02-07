#pragma once
#include "CoreMinimal.h"
#include "AblAnimNotify.h"
#include "GameplayTagContainer.h"
#include "AblSetTagNotify.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class UAblSetTagNotify : public UAblAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag EventTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AddThisTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RemoveThisTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ApplyToAnimationArchitect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ApplyToInteractionArchitect;
    
    UAblSetTagNotify();
};

