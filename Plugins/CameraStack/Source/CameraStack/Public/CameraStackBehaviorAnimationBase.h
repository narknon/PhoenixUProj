#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "CameraOptionName.h"
#include "CameraStackAnimData.h"
#include "CameraStackBehaviorBlend.h"
#include "ECameraStackAnimationFrame.h"
#include "ECameraStackAnimationLoopMode.h"
#include "CameraStackBehaviorAnimationBase.generated.h"

class UAnimSequenceBase;
class UCameraStackSecondaryTargetGetter;

UCLASS(Abstract, Blueprintable, CollapseCategories, EditInlineNew)
class CAMERASTACK_API UCameraStackBehaviorAnimationBase : public UCameraStackBehaviorBlend {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECameraStackAnimationLoopMode LoopMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ECameraStackAnimationFrame AnimationFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCameraStackSecondaryTargetGetter* SecondaryTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlayRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector AdditiveTranslationFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator AdditiveRotationFactor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraOptionName AdditiveFactorOptionName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraOptionName PlayRateFactorOptionName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCameraStackAnimData AnimData;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimSequenceBase* AnimSequence;
    
public:
    UCameraStackBehaviorAnimationBase();
};

