#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ETimeRigFadeEventType.h"
#include "DialogueLineRule.h"
#include "DialogueLineRule_ScreenFade.generated.h"

class UBoolProvider;
class UFloatProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class UDialogueLineRule_ScreenFade : public UDialogueLineRule {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OffsetFromDialogueLine;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* InitialScreenFade;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* FinalScreenFade;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* BlendTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETimeRigFadeEventType FadeEventType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoolProvider* KeepStateOnCompletion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoolProvider* KeepFadeAfterSceneRigCompletion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoolProvider* EnableFading;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor FadeColor;
    
    UDialogueLineRule_ScreenFade();
};

