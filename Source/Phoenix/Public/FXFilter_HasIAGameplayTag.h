#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FXFilter.h"
#include "EMultiFXActor.h"
#include "FXFilter_HasIAGameplayTag.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UFXFilter_HasIAGameplayTag : public UFXFilter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMultiFXActor Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag GameplayTag;
    
public:
    UFXFilter_HasIAGameplayTag();
};

