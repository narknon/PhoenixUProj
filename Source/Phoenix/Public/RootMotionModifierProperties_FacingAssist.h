#pragma once
#include "CoreMinimal.h"
#include "RootMotionModifierProperties.h"
#include "ECustomInterpType.h"
#include "ERootMotionModTurnAssistUseDirection.h"
#include "RootMotionModifierProperties_FacingAssist.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URootMotionModifierProperties_FacingAssist : public URootMotionModifierProperties {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ERootMotionModTurnAssistUseDirection::Type> UseDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFaceNegativeDirectionIfCloser;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreTargetTracker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllowDesiredDirectionUpdates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRotateRootTranslationIntoDesiredDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<ECustomInterpType::Type> InterpType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InterpSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InterpTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDebug;
    
    URootMotionModifierProperties_FacingAssist();
};

