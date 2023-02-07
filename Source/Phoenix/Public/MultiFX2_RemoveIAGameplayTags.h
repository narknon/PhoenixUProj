#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "MultiFX2_Filtered.h"
#include "MultiFX2_RemoveIAGameplayTags.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_RemoveIAGameplayTags : public UMultiFX2_Filtered {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    
public:
    UMultiFX2_RemoveIAGameplayTags();
};

