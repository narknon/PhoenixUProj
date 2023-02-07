#pragma once
#include "CoreMinimal.h"
#include "AnimationTransformProvider.h"
#include "Transform_AnimationActor.generated.h"

class UActorProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class AVAANIMATION_API UTransform_AnimationActor : public UAnimationTransformProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UActorProvider* Actor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BoneName;
    
    UTransform_AnimationActor();
};

