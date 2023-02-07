#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "MultiFX2_Filtered.h"
#include "MultiFX2_AddIAGameplayTags.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_AddIAGameplayTags : public UMultiFX2_Filtered {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GameplayTags;
    
public:
    UMultiFX2_AddIAGameplayTags();
};

