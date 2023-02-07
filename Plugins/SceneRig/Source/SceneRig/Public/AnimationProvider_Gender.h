#pragma once
#include "CoreMinimal.h"
#include "AnimationProvider.h"
#include "AnimationProvider_Gender.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API UAnimationProvider_Gender : public UAnimationProvider {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationProvider* MaleAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAnimationProvider* FemaleAnimation;
    
    UAnimationProvider_Gender();
};

