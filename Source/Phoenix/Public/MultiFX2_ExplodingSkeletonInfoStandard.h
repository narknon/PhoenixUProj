#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_ExplodingSkeletonInfoBase.h"
#include "MultiFX2_ExplodingSkeletonInfoStandard.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_ExplodingSkeletonInfoStandard : public UMultiFX2_ExplodingSkeletonInfoBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseDitheredAlphaFade;
    
    UMultiFX2_ExplodingSkeletonInfoStandard();
};

