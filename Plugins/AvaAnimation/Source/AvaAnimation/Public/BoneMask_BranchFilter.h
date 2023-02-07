#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimData/BoneMaskFilter.h"
#include "BoneMaskBase.h"
#include "BoneMask_BranchFilter.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UBoneMask_BranchFilter : public UBoneMaskBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBranchFilter> BranchFilters;
    
    UBoneMask_BranchFilter();
};

