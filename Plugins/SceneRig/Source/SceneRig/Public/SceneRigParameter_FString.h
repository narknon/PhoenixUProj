#pragma once
#include "CoreMinimal.h"
#include "SceneRigParameter.h"
#include "SceneRigParameter_FString.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class SCENERIG_API USceneRigParameter_FString : public USceneRigParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Value;
    
    USceneRigParameter_FString();
};

