#pragma once
#include "CoreMinimal.h"
#include "SceneAction_Adaptation.h"
#include "SceneAction_AdaptationHold.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class USceneAction_AdaptationHold : public USceneAction_Adaptation {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Affects;
    
    USceneAction_AdaptationHold();
};

