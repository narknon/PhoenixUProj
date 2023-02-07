#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterValue.h"
#include "SceneRigStage_NameValue.generated.h"

class UNameProvider;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigStage_NameValue : public USceneRigStage_ParameterValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UNameProvider* Provider;
    
    USceneRigStage_NameValue();
};

