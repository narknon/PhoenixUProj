#pragma once
#include "CoreMinimal.h"
#include "MultiFX2_ExplodingSkeletonInfoBase.h"
#include "Templates/SubclassOf.h"
#include "MultiFX2_ExplodingSkeletonSkinFX.generated.h"

class ASkinFXDefinition;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UMultiFX2_ExplodingSkeletonSkinFX : public UMultiFX2_ExplodingSkeletonInfoBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASkinFXDefinition> SkinFXEffect;
    
    UMultiFX2_ExplodingSkeletonSkinFX();
};

