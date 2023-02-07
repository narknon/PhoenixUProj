#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterValue.h"
#include "SceneRigStage_BoolValue.generated.h"

class UBoolProvider;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigStage_BoolValue : public USceneRigStage_ParameterValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoolProvider* Provider;
    
    USceneRigStage_BoolValue();
};

