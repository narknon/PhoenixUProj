#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_ExplodingSkeletonInfoBase.h"
#include "MultiFX2_ExplodingSkeletonFade.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_ExplodingSkeletonFade : public UMultiFX2_ExplodingSkeletonInfoBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FadeMaterialKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FadeMaterialParmeter;
    
    UMultiFX2_ExplodingSkeletonFade();
};

