#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TimeRigInputSymbol.h"
#include "TimeRigOutputSymbol.h"
#include "EStandardManagedPriority.h"
#include "SceneRigActionBase.h"
#include "SceneAction_FadeOutFadeIn.generated.h"

class UFloatProvider;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneAction_FadeOutFadeIn : public USceneRigActionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStandardManagedPriority FadePriority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFloatProvider* BlendTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor FadeColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigInputSymbol StartBlendOut;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigOutputSymbol BlendIn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimeRigOutputSymbol BlendOut;
    
    USceneAction_FadeOutFadeIn();
};

