#pragma once
#include "CoreMinimal.h"
#include "SceneRigStage_ParameterValue.h"
#include "SceneRigStage_StringValue.generated.h"

class UStringProvider;

UCLASS(Blueprintable)
class SCENERIG_API USceneRigStage_StringValue : public USceneRigStage_ParameterValue {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStringProvider* Provider;
    
    USceneRigStage_StringValue();
};

