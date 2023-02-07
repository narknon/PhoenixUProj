#pragma once
#include "CoreMinimal.h"
#include "AnimationClip_TagLookup.h"
#include "AnimationMatchFlags.h"
#include "AnimationTypeToFetch.h"
#include "AnimationClip_TagLookupAndMatchTransform.generated.h"

class UTransformProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UAnimationClip_TagLookupAndMatchTransform : public UAnimationClip_TagLookup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* TransformToMatchProvider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTransformProvider* AnchorTransformProvider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<AnimationMatchFlags> AnimationMatchFlag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<AnimationTypeToFetch> FetchAnims;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSearchAnimationArchitect;
    
    UAnimationClip_TagLookupAndMatchTransform();
};

