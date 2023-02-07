#pragma once
#include "CoreMinimal.h"
#include "ESceneActionAdaptationSoftDisableMethod.h"
#include "SceneAction_Adaptation.h"
#include "SceneAction_AdaptationSoftDisable.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_AdaptationSoftDisable : public USceneAction_Adaptation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Affects;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESceneActionAdaptationSoftDisableMethod Method;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIncludeBias;
    
    USceneAction_AdaptationSoftDisable();
};

