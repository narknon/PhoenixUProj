#pragma once
#include "CoreMinimal.h"
#include "SceneRigObjectActionBase.h"
#include "EFacialEmotion.h"
#include "EManagedFacialEmotionPriority.h"
#include "SceneAction_FacialEmotions.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_FacialEmotions : public USceneRigObjectActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFacialEmotion Emotion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EManagedFacialEmotionPriority Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BlendInTime;
    
    USceneAction_FacialEmotions();
};

