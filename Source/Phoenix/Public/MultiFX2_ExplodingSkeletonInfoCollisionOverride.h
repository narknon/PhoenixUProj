#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_ExplodingSkeletonInfoBase.h"
#include "MultiFX2_ExplodingSkeletonInfoCollisionOverride.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_ExplodingSkeletonInfoCollisionOverride : public UMultiFX2_ExplodingSkeletonInfoBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CollisionProfileName;
    
    UMultiFX2_ExplodingSkeletonInfoCollisionOverride();
};

